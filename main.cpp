#include <iostream>
#include <array>

using namespace std;

array<char, 9> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

int coord_to_index(int, int);
void print_board(string, string);
bool is_filled(int);

int main()
{
    int noOfPlayers;
    string player1;
    string player2;
    char token = 'X';
    int row;
    int column;
    cout << "  Welcome to the Tic Tac Toe  \n";
    cout << "Enter the Numbers of player(1/2)";
    cin >> noOfPlayers;
    cout << "Enter player 1 name: \n";
    cin >> player1;
    cout << "Enter player 2 name: \n";
    cin >> player2;

    print_board(player1, player2);
    while (true)
    {
        int x, y;
        if (token == 'X')
        {
            cout << player1 << " enter your choice: ";
            cin >> x >> y;
        }
        if (token == 'O')
        {
            cout << player2 << " enter your choice: ";
            cin >> x >> y;
        }
        int index = coord_to_index(x, y);
        if (index == -1)
        {
            continue;
        }
        if (is_filled(index))
        {
            continue;
        }
        board[index] = token;
        if (token == 'X')
        {
            token = 'O';
        }
        else
        {
            token = 'X';
        }
    }
    return 0;
}

int coord_to_index(int x, int y)
{
    if (x > 3 || y > 3)
    {
        return -1;
    }
    else
    {
        y--, x--;
        return 3 * y + x;
    }
}

void print_board(string player1, string player2)
{
    cout << '\n'
         << "Player 1: " << player1 << '\n';
    cout << "____________\n";
    int j = 0;
    for (int i = 0; i < 3; i++)
    {
        cout << "|   |   |   |\n";
        cout << "| " << board[j] << " | " << board[j + 1] << " | " << board[j + 2] << " |\n";
        cout << "|   |   |   |\n";
        cout << "____________\n";
        j += 3;
    }
    cout << '\n'
         << "Player 2: " << player2 << '\n';
}

bool is_filled(int index)
{
    if (board[index] == ' ')
        return false;
    else
        return true;
}