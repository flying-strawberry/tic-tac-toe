#include <iostream>
#include <array>

using namespace std;

array<char, 9> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

int coord_to_index(int, int);

int main() {
    cout << "Welcome to \n";

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
