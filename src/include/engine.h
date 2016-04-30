#ifndef ENGINE_H
#define ENGINE_H

#include <gl.h>
#include <geom.h>
#include <ball.h>


#define F 10
extern float curr_time;

void move_ball(int idx);
void move_balls(float time);
#endif
