#ifndef GRIDSOLVER_H
#define GRIDSOLVER_H
#include <iostream>
#include <vector>
#include <string>
#include <Grid.h>
#include <DictionaryTrie.h>

using namespace std;

class GridSolver
{
    public:
        // Constructor
        GridSolver(Grid& other_grid);
        // Pure virtual function inherited by two different classes
        virtual bool solve() = 0;
        // Destructor
        virtual ~GridSolver();

    protected:
        // Grid that will be solved
        Grid grid;
        // Trie object that store the game words
        DictionaryTrie t;
        // To build the trie from given words
        void build_trie(Grid& other_grid);
        // The function that displays the word bank
        void display_wordBank();

    private:
};

#endif // GRIDSOLVER_H
