#include <iostream>
using namespace std;

int main() {
   const int rows = 11;
   const int columns = 22;
   char maze[rows][columns + 1] = {
       "++++++++++++++++++++++",
       "+   +   ++ ++     +   ",
       "+ +   +       +++ + ++",
       "+ + +  ++  ++++   + ++",
       "+++ ++++++    +++ +  +",
       "+          ++  ++    +",
       "+++++ ++++++   +++++ +",
       "+     +   +++++++  + +",
       "+ +++++++      S +   +",
       "+                + +++",
       "++++++++++++++++++ +++"
   };

   int playerRow = 0;
   int playerColumn = 0;
    int playerHealth = 10;

   for (int row = 0; row < rows; ++row) {
       for (int column = 0; column < columns; ++column) {
           if (maze[row][column] == 'S') {
               playerRow = row;
               playerColumn = column;
           }
       }
   }

   std::cout << "Welcome to the labyrinth." << std::endl;
   std::cout << "Move with <, >, ^, or v. Enter q to quit." << std::endl;
   std::cout << "Your position is shown as @." << std::endl << std::endl;

   char move;
   while (true) {
       for (int row = 0; row < rows; ++row) {
           for (int column = 0; column < columns; ++column) {
               if (row == playerRow && column == playerColumn) {
                   std::cout << '@';
               } else {
                   std::cout << maze[row][column];
               }
           }
           std::cout << '\n';
       }


       if (playerRow == 10 && playerColumn == 18) {
           std::cout << "You found the exit!\n";
           break;
       }


       std::cout << "Move: ";
       std::cin >> move;
       if (move == 'q' || move == 'Q') {
           break;
       }


       int nextRow = playerRow;
       int nextColumn = playerColumn;
       if (move == '<') {
           --nextColumn;
       } else if (move == '>') {
           ++nextColumn;
       } else if (move == '^') {
           --nextRow;
       } else if (move == 'v') {
           ++nextRow;
       } else {
           std::cout << "Use <, >, ^, or v to move.\n\n";
           continue;
       }


       if (nextRow >= 0 && nextRow < rows && nextColumn >= 0 &&
           nextColumn < columns && maze[nextRow][nextColumn] != '+') {
           playerRow = nextRow;
           playerColumn = nextColumn;
       } else {
           if (playerHealth > 1) {
               playerHealth--;
               cout << "You have lost 1 health, you are now at " << playerHealth << " health.\n";
               std::cout << "That move is blocked.\n\n";
           }
           else {
               cout << "You have lost all your health and will have to redo.\n";
               cout << "Click enter to continue or q to exit...\n\n";
               cin >> move;
               if (move == 'q' || move == 'Q') {
                   break;
               }
               else {
                   playerHealth = 10;
                   playerRow = 0;
                   playerColumn = 0;
               }
           }
       }
   }
   return 0;
}
