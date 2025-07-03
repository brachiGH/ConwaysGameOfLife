#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "cell.h"


const char live_cell{'X'};
const char dead_cell{' '};

// Game dimentions
const int rowmax = 23;
const int colmax = 79;

// Game parameters
const int min_neighbours = 2;
const int max_neighbours = 3;
const int min_parents = 3;
const int max_parents = 3;




// Game logic

class game_grid
{
private:
    //
    cell cells[rowmax + 2][colmax + 2];

    void draw_boarder() const;
public:
    game_grid() { draw_boarder(); };
    game_grid(const game_grid& other);
    void randomGeneration();
    bool will_survive(int i, int j);
    bool will_born(int i, int j);
    void calculate_nextGeneration(game_grid& ng_grid);
    void draw() const;
    void clear();
    game_grid& operator=(const game_grid& other);
};


#endif