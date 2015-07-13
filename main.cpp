#include <iostream>
using namespace std;

//cell class correlating to the grid
class cell
{
public:
    cell()
    {
        isX = ' ';
        value = 0;
    }
    void set(string whichLetter)
    {
        if(whichLetter == "X")
        {
            isX = "X";
            value = 1;
        }
        else
        {
            isX = "O";
            value = -1;
        }
    }
    string getLetter()
    {
        return isX;
    }
    int getVal()
    {
        return value;
    }
private:
    string isX;
    int value;
};

//creates a grid of 9 cells corresponding to the 9 tic tac toe cells
void setGrid(cell *grid[9])
{
    for(int i = 0; i < 9; i++)
    {
        grid[i] = new cell;
    }
}

bool evaluate(cell *grid[9], int numComp)
{
    int horiz1 = grid[0]->getVal() + grid[1]->getVal() + grid[2]->getVal();
    int horiz2 = grid[3]->getVal() + grid[4]->getVal() + grid[5]->getVal();
    int horiz3 = grid[6]->getVal() + grid[6]->getVal() + grid[8]->getVal();
    int vert1 = grid[0]->getVal() + grid[3]->getVal() + grid[6]->getVal();
    int vert2 = grid[1]->getVal() + grid[4]->getVal() + grid[7]->getVal();
    int vert3 = grid[2]->getVal() + grid[5]->getVal() + grid[8]->getVal();
    int diag1 = grid[0]->getVal() + grid[4]->getVal() + grid[8]->getVal();
    int diag2 = grid[2]->getVal() + grid[4]->getVal() + grid[6]->getVal();
    numComp *= 3;
    if(horiz1 == numComp || horiz2 == numComp || horiz3 == numComp || vert1 == numComp
       || vert2 == numComp || vert3 == numComp || diag1 == numComp || diag2 ==numComp)
        return true;
    return false;
}
void deleteGrid(cell *grid[9])
{
    for(int i = 0; i < 9; i++)
    {
        delete grid[i];
    }
}

int main(int argc, const char * argv[]) {

    bool game_continue=true;
    int turnNum = 1;
    cell *grid[9];
    setGrid(grid);
    cout << "Enter position you wish to play in\n" <<
    " 1 * 2 * 3\n" <<
    "***********\n" <<
    " 4 * 5 * 6\n" <<
    "***********\n" <<
    " 7 * 8 * 9\n";

     while(game_continue)
    {
        string letter;
        if(turnNum == 9)
            game_continue = false;
        if(turnNum%2 == 0)
            letter = "X";
        else letter = "O";
        turnNum++;
        int input;
        cin >> input;
        if(input > 0 && input < 10 && grid[input-1]->getLetter() == " ")
            grid[input-1]->set(letter);
        else{
            bool done = false;
            do{
                cout << "ERROR. Enter a valid square." << endl;
                cin >> input;
                if(input > 0 && input < 10 && grid[input-1]->getLetter() == " ")
                {
                    grid[input-1]->set(letter);
                    done = true;
                }
            }while(!done);
        }
        cout << " " + grid[0]->getLetter() + " * " + grid[1]->getLetter() + " * " + grid[2]->getLetter() +" \n" +
        "***********\n" +
        " " + grid[3]->getLetter() + " * " + grid[4]->getLetter() + " * " + grid[5]->getLetter() +" \n" +
        "***********\n" +
        " " + grid[6]->getLetter() + " * " + grid[7]->getLetter()+ " * " + grid[8]->getLetter() +" \n";
        
        if(turnNum % 2 == 0)
        {
            if(evaluate(grid, -1))
            {
                cout << "*********** THE CHAMPION IS 'O'. WELL PLAYED ***********" << endl;
                break;
            }
        }
        else
        {
            if(evaluate(grid, 1))
            {
                cout << "*********** THE CHAMPION IS 'X'. WELL PLAYED ***********" << endl;
                break;
            }
        }
        
    }
    if (turnNum == 10) cout << "*********** DRAW ***********" << endl;
    deleteGrid(grid);
}

