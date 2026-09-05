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
    cout << "\n===================================\n";
    cout << " Welcome to the Impossible Mission! \n";
    cout << "===================================\n\n";

    cout << "You are standing at the gate of a top-secret intelligence agency headquarters.\n";
    cout << "There are security guards and officers all around you.\n\n";
    cout << "What do you do?\n";

    cout << "1. Scan your forged ID card and go inside.\n";
    cout << "2. Walk around to the other entrance.\n";
    cout << "3. Run away. This was a terrible idea.\n\n";

    int choice; // This creates a variable to store the player's choice

    cout << "Enter your choice (1, 2, or 3): ";
    cin >> choice; // This reads what the player types

    // This "if/else if/else" block runs different code based on the choice
    if (choice == 1) {
        scene_inside(); // Go to the inside scene
    } else if (choice == 2) {
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
    cout << "You found the hidden treasure! You win!\n";
}

// ============================================================
// ENDING: The Bad Ending
// ============================================================
void scene_ending_bad() {
    cout << "\n*** GAME OVER ***\n";
    cout << "You didn't make it out. Better luck next time.\n";
}
