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
void maintenance_scene();

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
    cout << "2. Honda Civic ($14,000 incl. taxes)\n";
    cout << "3. Audi A4 ($17,000 incl. taxes).\n\n";

    cout << "Enter your choice (1, 2, or 3): ";
    cin >> choice; // This reads what the player types

    // This "if/else if/else" block runs different code based on the choice
    if (choice == 2) {
        car = "Honda Civic";
        moneyLeft -= 14000;
        scene_inside(car, miles, moneyLeft); // Go to the inside scene
    } else if (choice == 3) {
        car = "Audi A4";
        moneyLeft -= 17000;
        scene_inside(car, miles, moneyLeft); // Go to the back scene
    } else {
        moneyLeft -= 20000;
        scene_ending_bad(); // Any other input = bad ending
    }
}

// ============================================================
// SCENE 2: Insurance and Maintenance Pre-Road Trip
// ============================================================
void scene_inside(string car, int miles, int moneyLeft) {

    int insurance = get_insurance(car);
    int maintenance = get_maintenance(car);
    output_metrics(car, miles, moneyLeft);
    cout << "\nYou now have to buy insurance, as well as do a routine maintenance check.\n";
    cout << "Rates and prices for these functions depend on the vehicle you chose.\n\n";
    cout << "What do you do?\n";

    cout << "1. Buy insurance and do the routine maintenance check. ($" << insurance + maintenance << " incl. taxes) \n";
    cout << "2. Depart on road trip with just insurance. ($" << insurance << " incl. taxes)\n\n";

    int choice;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        moneyLeft -= insurance + maintenance;
        scene_ending_good();
    } else {
        moneyLeft -= insurance;
        maintenance_scene(maintenance, moneyLeft);
    }
}

int get_insurance(string car){
    int insurance;

    if (car == "Honda Civic"){
        insurance = 350;
    }
    else if (car == "Audi A4"){
        insurance = 750;
    }

    return insurance;
}
int get_maintenance(string car){
    int maintenance;

    if (car == "Honda Civic"){
        maintenance = 300;
    }
    else if (car == "Audi A4"){
        maintenance = 950;
    }

    return maintenance;
}

// ============================================================
// SCENE 3: Start of Road Trip
// ============================================================
void scene_back() {
    // TODO: Write your own description here!
    // Use cout << "Your text here.\n"; to print text
    // Then add choices and use cin >> choice; to read the player's input
    cout << "[This scene is under construction...]\n";
}

// ============================================================
// ALT SCENE 3: Start of Road Trip (Vehicle Breaks Down)
// ============================================================
void maintenance_scene(int maintenance, int moneyLeft) {
    int fix_price = maintenance * 2;
    cout << "Unfortunately, your car broke down right before starting.\n";
    cout << "You now have to pay " << fix_price << " to fix your car and continue.";
    cout << "" 
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
void output_metrics(string car, int miles, int moneyLeft) {
    cout << "You have bought " <<  car << " and driven " << miles << " so far." << endl;
}
