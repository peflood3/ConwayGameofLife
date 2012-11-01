#include <iostream>
#define size 50 // To adjust the size of the game board, just change this value (assuming a sqare board is needed).
using namespace std;

// Author: Paul E. Flood, III
// Created: 10-30-2012
// Modified: 10-31-2012
// Purpose: To recreate Conway's Game of Life. Written using Xcode on OS X 10.8.2.

void print_array(char field[size][size]);

int main()
{
    char field[size][size]; int row = 0; int col = 0; // Setting variables equal to zero just to prevent the extremely unlikely event that both of these variables were equal to 52 before initialization.
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            field[i][j] = ' '; // This simulation uses blanks for dead cells and zeros for live ones.
    int answer;
    cout << "Would you like to simulate a glider gun or manually initialize cells?" << endl;
    cout << "1: Gilder gun." << endl;
    cout << "2: Manual configuration." << endl;
    cin >> answer;
    switch (answer)
    {
        case 1:
            field[2][26] = '0'; // There is no simple way to come up with this pattern, so it is hard-coded.
            field[3][24] = '0';
            field[3][26] = '0';
            field[4][14] = '0';
            field[4][15] = '0';
            field[4][22] = '0';
            field[4][23] = '0';
            field[5][13] = '0';
            field[5][17] = '0';
            field[5][22] = '0';
            field[5][23] = '0';
            field[5][36] = '0';
            field[5][37] = '0';
            field[6][2] = '0';
            field[6][3] = '0';
            field[6][12] = '0';
            field[6][18] = '0';
            field[6][22] = '0';
            field[6][23] = '0';
            field[6][36] = '0';
            field[6][37] = '0';
            field[7][2] = '0';
            field[7][3] = '0';
            field[7][12] = '0';
            field[7][16] = '0';
            field[7][18] = '0';
            field[7][19] = '0';
            field[7][24] = '0';
            field[7][26] = '0';
            field[8][12] = '0';
            field[8][18] = '0';
            field[8][26] = '0';
            field[9][13] = '0';
            field[9][17] = '0';
            field[10][14] = '0';
            field[10][15] = '0';
            cout << "You have opted to use the glider gun!" << endl;
            break;
        case 2:
            cout << "You have opted for manual data entry! This field measures 50 cells by 50 cells. Enter 51 for the row and 51 for the column to cease entry." << endl;
            while (row != 52 && col != 52)
            {
                cout << "Row to activate?: ";
                cin >> row;
                row +=1 ;
                cout << "Column to activate?: ";
                cin >> col;
                col += 1;
                if (row < 1 || row > 50 || col < 1 || col > 50)
                {
                    if (row != 52 && col != 52)
                        cout << "Invalid entry. Use only numbers between 1 and 50." << endl;
                }
                else
                {
                    field[row - 1][col - 1] = '0';
                    cout << "The cell in row " << row - 1 << ", column " << col - 1 << " has been set to '0'." << endl;
                }
            }
            break;
        default: cout << "Invalid entry. Exiting program." << endl;
    }
    
    int iterations; int response = 1;
    cout << "How many iterations would you like to simulate?" << endl;
    cin >> iterations;
    for (int i = 0; i < iterations; i++)
    {
        if (response == 1)
        {
            print_array(field);
            cout << "Enter the number '1' to continue or anything else to stop." << endl;
            cin >> response;
        }
        {
        else
            cout << "Invalid entry. Enter 1 to resume." << endl;
            cin >> response;
        }
    }
    
    cout << "Simulation complete. Thank you for playing Conway's Game of Life!" << endl;
    
    return 0;
}

void print_array(char field[size][size])
{
    char dynamic[size][size]; int count; // Values must be temporarily stored in a secondary array (dynamic) to prevent unwanted changes to the original array.
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            dynamic[i][j] = ' ';
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            count = 0;
            if (field[i-1][j-1] == '0')
                count++;
            if (field[i-1][j] == '0')
                count++;
            if (field[i-1][j+1] == '0')
                count++;
            if (field[i][j-1] == '0')
                count++;
            if (field[i][j+1] == '0')
                count++;
            if (field[i+1][j-1] == '0')
                count++;
            if (field[i+1][j] == '0')
                count++;
            if (field[i+1][j+1] == '0')
                count++;
            
            if (field[i][j] == '0' && count < 2)
                dynamic[i][j] = ' ';
            else if (field[i][j] == '0' && count < 4 && count > 1)
                dynamic[i][j] = '0';
            else if (field[i][j] == '0' && count > 3)
                dynamic[i][j] = ' ';
            else if (field[i][j] == ' ' && count == 3)
                dynamic[i][j] = '0';
        }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            field[i][j] = dynamic[i][j];
            cout << field[i][j];
        }
        cout << endl;
    }
    
}