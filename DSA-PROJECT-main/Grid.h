#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class Grid
{
    public:
        // number of rows in a grid
        int rows;
        // number of cols in a grid
        int cols;
        // Constructor
        Grid(int rows= 8, int cols= 8);
        // Copy Constructor
        Grid(Grid& other_grid);
        // Destructor
        virtual ~Grid();
        // Display the whole grid
        void print_Grid()const;
        // push the string in a vector
        void push_word(string word);
        // return the vector of type string
        vector<string> get_words();
        // Grid using 2D vector of type pair in which character and color is stored
        vector<vector<pair<char, WORD>>> grid;
        // To print the words of the game
        void print_words();
        // Track the number of words
        int counter;

    protected:

    private:
        // vector of strings
        vector<string> words;
};

#endif // GRID_H
