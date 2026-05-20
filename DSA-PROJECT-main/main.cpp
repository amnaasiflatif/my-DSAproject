#include <iostream>
#include <string>
#include <vector>
#include <InputGrid.h>
#include <GridSolver.h>
#include <Grid_Generator.h>
#include <AutoSolve.h>
#include <UserSolve.h>
#include <ctime>

using namespace std;

// Function to clear the console
void clr()
{
    // calling function that clears the console
    system("cls");
}

// To make the decision whether to proceed or not
void decision()
{
    // variable that checks whether to proceed or not
    char input;
    // Loop for making decision
    while(1)
    {
        cout << "Enter y/Y to proceed : ";
        // Taking input
        cin >> input;
        // If the input matches simply go out of the loop
        if(input == 'y' || input == 'Y')
        break;
    }
    // Clear the console before returning
    clr();
}

// Function to call the auto solver
void auto_solve(GridSolver*& solver, Grid& grid)
{
    // Make the object of auto solver and pass grid to it
    solver = new AutoSolve(grid);
    // call the function that solves the grid
    solver->solve();
    // Make decision before returning
    decision();
}

// Function that solves grid by user input
void user_solve(GridSolver*& solver, Grid& grid)
{
    // Make the object of the user solver and pass the grid to it
    solver = new UserSolve(grid);
    // Call to solve it if the user can't solve it returns false
    if(!solver->solve())
    {
        // delete the object of user solve
        delete solver;
        // pass it to solve by auto solver
        auto_solve(solver, grid);
    }
    // Make decision before returning
    decision();
}

// Exit screen
void exit()
{
    // Print the following screen
    cout << "=================================================" << endl;
    cout << "|\t\t\t\t\t\t|" << endl;
    cout << "|\t\t\t\t\t\t|" << endl;
    cout << "|\t\t\t\t\t\t|" << endl;
    cout << "|\t\t\t\t\t\t|" << endl;
    cout << "|\t\t----GAME EXITED----\t\t|" << endl;
    cout << "|\t\t\t\t\t\t|" << endl;
    cout << "|\t\t\t\t\t\t|" << endl;
    cout << "|\t\t\t\t\t\t|" << endl;
    cout << "|\t\t\t\t\t\t|" << endl;
    cout << "=================================================" << endl;
    // Simply exit
    exit(0);
}

// Function that solves the grid
void solver(Grid& grid)
{
    // Grid solver object
    GridSolver* solver;
    // Loop executes until valid command enters
    while(1)
    {
        // Options
        cout << "1. Solve by User" << endl;
        cout << "2. Auto Solve" << endl;
        cout << "3. Exit" << endl;
        int command;
        // Ask for the command
        cout << "Enter the command : ";
        // Input command
        cin >> command;
        // Match the command
        switch(command)
        {
            // Command 1 calls user solver
            case 1:
                user_solve(solver, grid);
                return;
            case 2:
            // Command 2 calls auto solver
                auto_solve(solver, grid);
                return;
            // Command 3 calls to exit game
            case 3:
                exit();
            break;
            // If command is invalid
            default:
                cout << "Invalid Input" << endl;
        }
        // make the cin get ready to take new input
        cin.clear();
        // flush out the invalid characters in the cin
        cin.ignore(1, '\n');
    }
}

// Function to ask the user to input the grid
void input_grid()
{
    int rows, cols, numberOfWords;
    cout << "================ REQUIRED INPUTS ===============" << endl;
    // Checks valid row enter
    while(1)
    {
        cout << "Enter number of rows in a grid : ";
        cin >> rows;
        // If the row is valid break the loop
        if(rows > 4)
        break;
        // If the row is invalid print the statement
        cout << "Invalid Rows" << endl;
    }
    // Checks valid cols enter
    while(1)
    {
        cout << "Enter number of columns in  a grid : ";
        cin >> cols;
        // If the cols is valid break the loop
        if(cols > 4)
        break;
        // If the cols is invalid print the statement
        cout << "Invalid Columns" << endl;
    }
    // Checks valid row enter
    while(1)
    {
        cout << "Enter number of words in a game : ";
        cin >> numberOfWords;
        // If the number of words is valid break the loop
        if(numberOfWords > 0)
        break;
        // If the number of words is invalid print the statement
        cout << "Invalid Number of Words" << endl;
    }
    // simply clear the console
    clr();
    // Create grid
    Grid g(rows, cols);
    // Make the object of input grid that takes grid and fills the input in it
    InputGrid* inputGrid = new InputGrid(g, numberOfWords);
    // delete the object of input grid as grid is now filled
    delete inputGrid;
    // print the grid
    g.print_Grid();
    // call the solver to solve it
    solver(g);
    cout << "===============================================" << endl;
}

// Function to generate the grid randomly
void generate_grid()
{
    // To generate the random grid every time
    srand(time(NULL));
    cout << "==================== GRID ====================" << endl;
    // Make the grid object
    Grid g;
    // call grid generator to fill the grid randomly
    Grid_Generator* generator = new Grid_Generator(g);
    // delete the generator as grid is now filled
    delete generator;
    cout << "================= Word Bank ==================";
    cout << endl;
    // Print the words that needed to search in a grid
    for(string s : g.get_words())
    cout << s << " ";
    cout << endl;
    cout << "==============================================" << endl;
    // Print the grid
    g.print_Grid();
    cout << "==============================================" << endl;
    // Call solver to solve the grid
    solver(g);
}

int main()
{
    // To take instruction from the user
    int command;
    // Loop to control the flow of the game
    while(1)
    {
        // Display options available in the game
        cout << "============ WELCOME TO THE GAME =============" << endl;
        cout << "1. Start Game." << endl;
        cout << "2. Input Grid To Solve it." << endl;
        cout << "3. Exit Game." << endl;
        cout << "==============================================" << endl;
        cout << "Enter Command : ";
        // Ask for the input
        cin >> command;
        // Clear screen
        clr();
        switch(command)
        {
            // If command 1 matches the grid is generated randomly
            case 1:
                generate_grid();
            break;
            // If command 2 matches it asks user to input the grid
            case 2:
                input_grid();
            break;
            // If command 3 matches simply shows the exit screen and get exit
            case 3:
                exit();
            break;
            // If the command does not match show the invalid command message
            default:
                cout << "Invalid Command!" << endl;
        }
        // Clear screen
        clr();
        // make the cin get ready to take new input
        cin.clear();
        // flush out the invalid characters in the cin
        cin.ignore(1, '\n');
    }
}
