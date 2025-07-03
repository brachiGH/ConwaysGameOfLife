#ifndef CELL_H
#define CELL_H


void draw_cell(int row, int col, const char symb);

class cell
{
private:
    bool alive;
public:
    cell(): alive(false) {};
    cell(bool status): alive(status) {};
    void create() { alive = true; };
    void erase() { alive = false; };
    bool is_alive() const { return alive == true; };
};

#endif