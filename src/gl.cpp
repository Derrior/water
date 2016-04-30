#include <gl.h>
#include <engine.h>

using namespace std;

unsigned int vbo, vbo_buffer, program, f_color_loc, move_loc;
vector<ball> balls;
vector<rect> field;
click pointer;
float box[4] = {0.4, 0.4, 0.4, 1}, ball[4] = {0, 0, 0.7, 0.5};

static void ClickEvent(int button, int state, int x, int y) {
    y = 768 - y;
    pointer = click(x, y);
    pointer.activate(clock() / CLOCKS_PER_SEC);

}

static void RenderScene() {
    move_balls((float)clock() / CLOCKS_PER_SEC);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.9, 0.9, 0.9, 0);
    for (int i = 0; i < field.size(); i++) {
        glUniform2f(move_loc, 0, 0);
        glUniform4fv(f_color_loc, 1, &box[0]);
        glBegin(GL_QUADS);
        point p1 = field[i].corner, p2, p3, p4;
        p2 = p1 + field[i].side1;
        p4 = p1 + field[i].side2;
        p3 = p2 + field[i].side2;
        glVertex3f(p1.x, p1.y, 1);
        glVertex3f(p2.x, p2.y, 1);
        glVertex3f(p3.x, p3.y, 1);
        glVertex3f(p4.x, p4.y, 1);
        glEnd();

    }
   
    glUniform4fv(f_color_loc, 1, &ball[0]);
    for (int i = 0; i < balls.size(); i++) {
        glUniform2f(move_loc, balls[i].centre.x, balls[i].centre.y);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, circle_vbo);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawArrays(GL_POLYGON, 1, 64);
        glDisableVertexAttribArray(0);

    }
    glutSwapBuffers();
}

static void init_resources() {
    GLuint vs = create_shader("shaders/vertex.glsl", GL_VERTEX_SHADER);
    GLuint fs = create_shader("shaders/fragment.glsl", GL_FRAGMENT_SHADER);
    program = create_program(vs, fs);
    glUseProgram(program);
    glDepthMask(false);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_CULL_FACE);
    init_circle_object();
    generate_balls(balls);
    f_color_loc = glGetUniformLocation(program, "f_color");
    move_loc = glGetUniformLocation(program, "move");

    generate_field(field);
}

static void InitializeGlutCallbacks() {
    glutDisplayFunc(RenderScene);
    glutIdleFunc(RenderScene);
    glutMouseFunc(ClickEvent);

}

static void init_glut() {
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
     glutInitWindowPosition(0, 0);
     glutCreateWindow("Tutorial 01");
     glutFullScreen();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    init_glut();
    InitializeGlutCallbacks();
    GLenum res = glewInit();
    if (res != GLEW_OK)     {
         fprintf(stderr, "Error: %s\n", glewGetErrorString(res));
         return 1;
    }

    init_resources();
    glutMainLoop();

}
