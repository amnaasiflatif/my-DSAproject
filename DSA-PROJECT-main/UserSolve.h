#ifndef USERSOLVE_H
#define USERSOLVE_H
#include <iostream>
#include <windows.h>
#include <GridSolver.h>
#include <Grid.h>
#include <Node.h>

using namespace std;

class UserSolve : public GridSolver
{
    public:
        // Constructor
        UserSolve(Grid& grid);
        // Destructor
        virtual ~UserSolve();
        // Solve the grid
        bool solve();

    protected:

    private:
        // Takes coordinates of the word needed to search in a grid
        bool input_coordiantes(int r_st, int c_st, int r_end, int c_end);
        // To check if the word exists and if it exists then mark
        bool helper_solve(Node* node, WORD& color, int length, int r, int c, int dr, int dc);
};

#endif // USERSOLVE_H
