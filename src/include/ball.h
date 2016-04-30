#ifndef BALL_H
#define BALL_H
#define BALLS_AMOUNT 1000
#include <vector>
#include <geom.h>

struct ball {
    point centre;
    float color[3];
    vec speed;
};

void generate_balls(std::vector<ball>& balls);
#endif //BALL_H
