#include "game_of_life.h"
#include <iostream>


int main(int argc, char** argv) {
    std::cout << "Welcome to Conway's game of life" << std::endl;
    std::cout << "Press the enter key to draw the next generation" << std::endl;

    game_grid current_generation, next_generation;
    current_generation.randomGeneration();

    while (1)
    {
        current_generation.draw();
        
        // Populate the next generation
        current_generation.calculate_nextGeneration(next_generation);

        // Wait for user input to draw the generation
        std::cin.get();

        // Switch to the next generation
        current_generation = next_generation;

        // clearing the next generation grid
        next_generation.clear();
    }
    
}