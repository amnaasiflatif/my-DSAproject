#ifndef GRID_GENERATOR_H
#define GRID_GENERATOR_H
#include <iostream>
#include <vector>
#include <string.h>
#include <Grid.h>
#include <fstream>
#include <windows.h>
#include <Maxheap.h>

using namespace std;

class Grid_Generator
{
    public:
        Grid_Generator();
        // Constructor
        Grid_Generator(Grid& grid);
        // Destructor
        virtual ~Grid_Generator();

    protected:

    private:
        // heap to store words in greater length order
        Maxheap heap;
        // To bring words for the game
        void word_fetcher(Grid& grid);
        // To place the word in a grid randomly
        void placer(Grid& grid);
        // Fill the empty space with random characters
        void random_chars(Grid& grid);
        // To check if the word can be placed
        bool canPlace(Grid& grid, string& word, int word_length, int r_st, int c_st, int dr, int dc);
};

#endif // GRID_GENERATOR_H
