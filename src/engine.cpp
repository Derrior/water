#include <gl.h>
#include <engine.h>
#include <geom.h>
#include <ball.h>

using namespace std;

float curr_time;

void move_ball(int idx, float time) {
    vec speed_mod;
    float speed_abs = balls[idx].speed.len();
    for (int i = 0; i < balls.size(); i++) {
        if (i != idx) {
            float d = dist(balls[idx].centre, balls[i].centre);
            if (d < 2 * RAD) {
                balls[idx].speed = balls[i].speed = (balls[idx].speed + balls[i].speed) * (0.5);
            }
        }
    }
    for (int i = 0; i < field.size(); i++) {
        if (in_rect(field[i], balls[idx].centre)) {
            speed_mod = field[i].speed_mod;
        }
    }
    if (pointer.is_activated) {
        if (dist(balls[idx].centre, point(pointer.x, pointer.y)) < RAD + pointer.size) {
            speed_mod = vec(point(pointer.x, pointer.y), balls[idx].centre) * 10;
        }
    }
    balls[idx].speed = speed_mod + balls[idx].speed;
    balls[idx].speed.resize(speed_abs);
    if (balls[idx].centre.y + time * balls[idx].speed.y < 10) {
        balls[idx].centre.y += (time - 2 * (balls[idx].centre.y - 10) / balls[idx].speed.y) * -(balls[idx].speed.y) / 2;
        balls[idx].speed.y /= -2;
        balls[idx].speed.y += 1;
    } else {
        balls[idx].centre.y += time * balls[idx].speed.y;
    }
    balls[idx].centre.x += balls[idx].speed.x * time;
    
}

void move_balls(float time) {
    pointer.update(time);
    for (int i = 0; i < balls.size(); i++) {
        move_ball(i, time - curr_time);
    }
    for (int i = 0; i < balls.size(); i++) {
        balls[i].speed.y -= F * 100 * (time - curr_time);
    }
    curr_time = time;
}
