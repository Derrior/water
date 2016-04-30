#ifndef GL_H
#define GL_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <shader.h>
#include <circle.h>
#include <field.h>
#include <click.h>
#include <ball.h>
#include <geom.h>
#include <ctime>

extern unsigned int vbo, vbo_buffer, program, f_color_loc, move_loc;
extern std::vector<ball> balls;
extern std::vector<rect> field;
extern click pointer;

#endif //GL_H
