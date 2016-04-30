#include <iostream>
#include <circle.h>
#include <vector>
#include <geom.h>
#include <gl.h>
using namespace std;
unsigned int circle_vbo, circle_ibo, circle_ibo_size;
float circle_vbo_data[1000] = {};
unsigned int* circle_ibo_data;
void init_circle_object() {
    vector<int> ibo;
    vec v(RAD, 0);
    int idx = 2;
    for (int i = 0; i < 64; i++) {
        circle_vbo_data[idx] = v.x;
        circle_vbo_data[idx + 1] = v.y;
        cout << v.x << ' ' << v.y << endl;
        idx += 2;
        v = v.rotate(M_PI / 16);
        ibo.push_back(0);
        ibo.push_back(i % 64 + 1);
        ibo.push_back((i + 1) % 64 + 1);
    }
    
    glGenBuffers(1, &circle_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, circle_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(circle_vbo_data),
                 circle_vbo_data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    circle_ibo_data = new unsigned int[ibo.size()];
    circle_ibo_size = ibo.size();
    glGenBuffers(1, &circle_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, circle_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, circle_ibo_size *
              sizeof(unsigned int), circle_ibo_data, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

