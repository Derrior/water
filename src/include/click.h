#ifndef CLICK_H
#define CLICK_H

#define MAX_TIME 5
#define MAX_SIZE 10

struct click {
    int x, y;
    float time_begin;
    float size;
    bool is_activated;
    click() {
        x = y = 0;
        is_activated = false;
    }
    click(int _x, int _y) {
        x = _x;
        y = _y;
        is_activated = false;
    }
    void update(float curr_time) {
        if (!is_activated or (curr_time - time_begin) > 2 * MAX_TIME) {
            is_activated = false;
            return;
        } else if (curr_time - time_begin > MAX_TIME) {
            size = 2 * MAX_TIME - (curr_time - time_begin);
        } else {
            size = (curr_time - time_begin) / MAX_TIME;
        }
        size *= size;
        size *= MAX_SIZE;
        is_activated = true;
    }
    void activate(float curr_time) {
        is_activated = true;
        time_begin = curr_time;
    }
};

#endif // CLICK_H
