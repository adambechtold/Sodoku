#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    //===========TEST ZONE==========
    Board b = Board("Soduku1.txt");

    cout << b;

    return 0;
}