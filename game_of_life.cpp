#include "game_of_life.h"
#include "cell.h"
#include <cstddef>
#include <random>


game_grid::game_grid(const game_grid& other)
{
    (*this) = other;
};

game_grid& game_grid::operator=(const game_grid& other)
{
    for (size_t i = 1; i < rowmax-1; i++)
    {
        for (size_t j = 1; j < colmax-1; j++)
        {
            this->cells[i][j] = cell(other.cells[i][j].is_alive());
        }
        
    }

    return *this;
}

void game_grid::randomGeneration()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);

    for (size_t i = 1; i < rowmax-1; i++)
    {
        for (size_t j = 1; j < colmax-1; j++)
        {
            this->cells[i][j] = cell{distrib(gen) == 1 && distrib(gen) == 1};
        }
        
    }
}


void game_grid::draw_boarder() const
{
    // Top boarder
    for (size_t i = 0; i < colmax; i++)
    {
        draw_cell(0, i, '-');
    }


    // bottom boarder
    for (size_t i = 0; i < colmax; i++)
    {
        draw_cell(rowmax-1, i, '-');
    }


    // left boarder
    for (size_t i = 0; i < rowmax; i++)
    {
        draw_cell(i, colmax-1, '|');
    }


    // right boarder
    for (size_t i = 0; i < rowmax; i++)
    {
        draw_cell(i, 0, '|');
    }
}

void game_grid::draw() const
{
    for (size_t i = 1; i < rowmax-1; i++)
    {
        for (size_t j = 1; j < colmax-1; j++)
        {
            cell c = this->cells[i][j];
            draw_cell(i, j, c.is_alive()? live_cell : dead_cell);
        }
        
    }
}


void game_grid::clear()
{
    for (size_t i = 1; i < rowmax-1; i++)
    {
        for (size_t j = 1; j < colmax-1; j++)
        {
            this->cells[i][j] = cell(false);
        }
        
    }
}

bool game_grid::will_survive(int i, int j)
{
    if (!cells[i][j].is_alive())
    {
        // Cell already dead
        return false;
    }


    // Find the number of alive neighberous
    int neigherous = cells[i-1][j].is_alive() +
                    cells[i-1][j+1].is_alive() +
                    cells[i][j+1].is_alive() +
                    cells[i+1][j+1].is_alive() +
                    cells[i+1][j].is_alive() +
                    cells[i+1][j-1].is_alive() +
                    cells[i-1][j-1].is_alive();

    if (neigherous < min_neighbours || neigherous > max_neighbours) {
        return false;
    }

    // The cell suvived
    return true;
}

bool game_grid::will_born(int i, int j)
{
    if (cells[i][j].is_alive())
    {
        // Cell already exist
        return false;
    }


    // Find the number of alive parents
    int parents = cells[i-1][j].is_alive() +
                    cells[i-1][j+1].is_alive() +
                    cells[i][j+1].is_alive() +
                    cells[i+1][j+1].is_alive() +
                    cells[i+1][j].is_alive() +
                    cells[i+1][j-1].is_alive() +
                    cells[i-1][j-1].is_alive();

    if (parents < min_parents || parents > max_parents) {
        return false;
    }

    // The cell suvived
    return true;
}


void game_grid::calculate_nextGeneration(game_grid& ng)
{
    for (size_t i = 1; i < rowmax-1; i++)
    {
        for (size_t j = 1; j < colmax-1; j++)
        {
            // will the cell survive to the next gen
            if (this->will_survive(i, j))
            {
                ng.cells[i][j].create();
            } 
            // will a cell be born
            else if (this->will_born(i, j))
            {
                ng.cells[i][j].create();
            }

        }
        
    }
}