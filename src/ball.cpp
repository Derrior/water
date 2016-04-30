#include <ball.h>
#include <vector>
#include <cstdlib>
using namespace std;

void generate_balls(vector<ball>& balls) {
     balls.resize(BALLS_AMOUNT);
     for (int i = 0; i < BALLS_AMOUNT; i++) {
        balls[i].centre.x = rand() % 390 + 10;
        balls[i].centre.y = rand() % 1000 + 20;
     }
}


