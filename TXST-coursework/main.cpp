// ============================================================
// Game Title: The Ultimate Road Trip
// Your Name: Sarveshwar Senthil Kumar
// Course: TXST US1100.167
// Description: The objective of the game is to buy a car and make a series of correct decisions to get to the final destination.
// ============================================================

#include <iostream> // This lets us use cout and cin (print and read input)
#include <string> // This lets us use the string type
using namespace std; // This saves us from typing "std::" everywhere
// A "function" is a reusable block of code. We'll use one per scene.
// You'll make your own functions later!

void scene_intro(); // This is a "declaration" - we're telling C++ these functions exist
void scene_inside();
void scene_back();
void scene_ending_good();
void scene_ending_bad();

// ============================================================
// main() is where every C++ program starts running
// ============================================================

int main() {
    scene_intro(); // Start the game at the intro scene
    return 0; // Tell the computer the program finished successfully
}

// ============================================================
// SCENE 1: The Introduction
// ============================================================
void scene_intro() {

    int moneyLeft;
    int choice; // This creates a variable to store the player's choice
    int miles;
    string car;

    moneyLeft = 20000;

    cout << "\n===================================\n";
    cout << " Welcome to the Ultimate Road Trip! \n";
    cout << "===================================\n\n";

    cout << "The first decision you need to make for this road trip is choose the perfect vehicle.\n";
    cout << "You have $" << moneyLeft << " saved up for this road trip. You have arrived at the dealership." << "\n\n";
    cout << "Which car do you buy?\n";

    cout << "1. Toyota GT-86 ($20,000 incl. taxes)\n";
    cout << "2. Honda Civic ($12,000 incl. taxes)\n";
    cout << "3. Audi A4 ($14,000 incl. taxes).\n\n";

    cout << "Enter your choice (1, 2, or 3): ";
    cin >> choice; // This reads what the player types

    // This "if/else if/else" block runs different code based on the choice
    if (choice == 2) {
        car = "Honda Civic";
        moneyLeft -= 12000;
        scene_inside(); // Go to the inside scene
    } else if (choice == 3) {
        car = "Audi A4";
        moneyLeft -= 14000;
        scene_back(); // Go to the back scene
    } else {
        scene_ending_bad(); // Any other input = run away ending
    }
}

// ============================================================
// SCENE 2: Inside the Mansion
// ============================================================
void scene_inside() {
    cout << "\nYou go inside the headquarters. There are high-tech cameras and surveillance systems throughout the office everwhere.\n";
    cout << "Various rooms and labs line the walls. However, you find the right room with the vault.\n\n";
    cout << "What do you do?\n";
    cout << "1. Go directly inside the room using your ID.\n";
    cout << "2. Reroute and find the air vents.\n\n";
    int choice;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    if (choice == 2) {
        scene_ending_good();
    } else {
        scene_ending_bad();
    }
}

// ============================================================
// SCENE 3: Behind the Mansion
// ============================================================
void scene_back() {
    // TODO: Write your own description here!
    // Use cout << "Your text here.\n"; to print text
    // Then add choices and use cin >> choice; to read the player's input
    cout << "[This scene is under construction...]\n";
}

// ============================================================
// ENDING: The Good Ending
// ============================================================
void scene_ending_good() {
    cout << "\n*** THE END ***\n";
    cout << "";
    cout << "You have completed the ultimate road trip! You win!\n";
}

// ============================================================
// ENDING: The Bad Ending
// ============================================================
void scene_ending_bad() {
    cout << "\n*** GAME OVER ***\n";
    cout << "Unfortunately you have run out of money.\n";
    cout << "You didn't make it out. Better luck next time.\n";
}

// Method to print out all saved variables
void output_metrics(string car, int miles) {
    cout << "You have bought " <<  car << " and driven " << miles << endl;
}
