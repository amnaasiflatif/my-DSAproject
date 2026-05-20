#ifndef AUTOSOLVE_H
#define AUTOSOLVE_H
#include <GridSolver.h>
#include <Node.h>
#include <Grid.h>
#include <windows.h>

using namespace std;

// Inheritance from class GridSolver
class AutoSolve : public GridSolver
{
    public:
        // Constructor
        AutoSolve(Grid& grid);
        // Destructor
        virtual ~AutoSolve();
        bool solve();

    protected:

    private:
        // Function that helps to solve the grid
        bool helper_solve(Node* node, WORD& color, int r, int c, int dr, int dc, vector<vector<bool>>& visited);
};

#endif // AUTOSOLVE_H
