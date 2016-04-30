#include <field.h>
#include <vector>

using namespace std;

void generate_field(vector<rect>& field) {
    point corner_ld(0, 0), corner_lu(0, 500), corner_rd(400, 0);
    field.resize(3);
    field[0].corner = corner_ld;
    field[1].corner = corner_ld;
    field[2].corner = corner_rd;
    vec side[4];
    side[0] = vec(30, 0);
    side[1] = vec(0, 30);
    side[2] = vec(400, 0);
    side[3] = vec(0, 500);
    field[0].side1 = side[1];
    field[0].side2 = side[2];
    field[1].side1 = side[0];
    field[1].side2 = side[3];
    field[2].side1 = side[0];
    field[2].side2 = side[3];
    field[0].speed_mod = vec(10, 0);
    field[1].speed_mod = vec(0, 10);
    field[2].speed_mod = vec(-10, 10);
}
