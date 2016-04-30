attribute vec2 v_coord;
uniform vec2 move;

void main(void) {
    vec2 new_c = v_coord + move;
    gl_Position = vec4(new_c.x / 683 - 1, new_c.y / 384 - 1, 1, 1); 
}
