#include <iostream>
#include <array>

using namespace std;

array<char, 9> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

int coord_to_index(int, int);
void print_board(string, string);
bool is_filled(int);
bool check_win(int, int);

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

    while (true)
    {
        print_board(player1, player2);
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
        if (check_win(x, y))
        {
            print_board(player1, player2);
            if (token == 'X')
            {
                cout << player1 << " won!\n";
            }
            else
            {
                cout << player2 << " won!\n";
            }
            break;
        }
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

bool check_win(int x, int y)
{
    if ( (board[coord_to_index(x, 1)] == board[coord_to_index(x, 2)]) && (board[coord_to_index(x, 2)] == board[coord_to_index(x, 3)]) ) {
        return true;
    }
    else if ( (board[coord_to_index(1, y)] == board[coord_to_index(2, y)]) && (board[coord_to_index(2, y)] == board[coord_to_index(3, y)]) ) {
        return true;
    }
    else if ( (board[coord_to_index(1, 1)] == board[coord_to_index(2, 2)]) && (board[coord_to_index(2, 2)] == board[coord_to_index(3, 3)]) ) {
        if ( board[coord_to_index(1, 1)] != ' ' && board[coord_to_index(2, 2)] != ' ' && board[coord_to_index(3, 3)] != ' ') {
            return true;
        }
    }
    else if ( (board[coord_to_index(3, 1)] == board[coord_to_index(2, 2)]) && (board[coord_to_index(2, 2)] == board[coord_to_index(1, 3)]) ) {
        if (board[coord_to_index(3, 1)] != ' ' && board[coord_to_index(2, 2)] != ' ' && board[coord_to_index(1, 3)] != ' ') {
            return true;
        }
    }
    return false;
}

void print_board(string player1, string player2)
{
    cout << '\n'
         << "Player 1: " << player1 << '\n';
    cout << '\n'
         << "Player 2: " << player2 << '\n';
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
}

bool is_filled(int index)
{
    if (board[index] == ' ')
        return false;
    else
        return true;
}