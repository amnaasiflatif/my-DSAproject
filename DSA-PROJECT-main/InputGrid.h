#ifndef INPUTGRID_H
#define INPUTGRID_H
#include <iostream>
#include <vector>
#include <string>
#include <Grid.h>

using namespace std;

class InputGrid
{
    public:
        // Constructor
        InputGrid(Grid& grid, int numberOfwords);
        // Destructor
        virtual ~InputGrid();
        // Input grid from the player
        void input_grid(Grid& grid);
        // Input Words needed to search
        void input_words(Grid& grid, int numberOfwords);

    protected:

    private:
};

#endif // INPUTGRID_H
