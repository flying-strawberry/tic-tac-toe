#include <iostream>
#include <array>

using namespace std;

array<char, 9> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

int coord_to_index(int, int);
void print_board(string, string);

int main() {
    int noOfPlayers;
    string player1;
    string player2;
    cout<<"  Welcome to the Tic Tac Toe  \n";
    cout<<"Enter the Numbers of player(1/2)";
    cin>>noOfPlayers;
    cout<<"Enter player 1 name: \n";
    cin>>player1;
    cout<<"Enter player 2 name: \n";
    cin>>player2;
    
    

    return 0;
}

int coord_to_index(int x, int y) {
    if (x > 3 || y > 3) {
        return -1;
    } else {
        y--, x--;
        return 3 * y + x;
    }
}
