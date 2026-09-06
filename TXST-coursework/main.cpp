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
void scene_inside(string car, int miles, int moneyLeft);
void scene_ending_good();
void scene_ending_bad();

void output_metrics(string car, int miles, int moneyLeft);
void maintenance_scene(string car, int miles, int moneyLeft); 
void road_scene(string car, int moneyLeft);

int get_insurance(string car);
int get_maintenance(string car);

int calculate_miles(string car, int moneyLeft);

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

    int moneyLeft = 20000;
    int choice; // This creates a variable to store the player's choice
    int miles = 0;
    string car;

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
        car = "Toyota GT-86";
        moneyLeft -= 20000;
        output_metrics(car, miles, moneyLeft);
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
    cout << "\n\nYou now have to buy insurance, as well as do a routine maintenance check.\n";
    cout << "Rates and prices for these functions depend on the vehicle you chose.\n\n";
    cout << "What do you do?\n";

    cout << "1. Buy insurance and do the routine maintenance check. ($" << insurance + maintenance << " incl. taxes) \n";
    cout << "2. Depart on road trip with just insurance. ($" << insurance << " incl. taxes)\n\n";

    int choice;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        moneyLeft -= insurance + maintenance;
        road_scene(car, moneyLeft);
    } else {
        moneyLeft -= insurance;
        maintenance_scene(car, miles, moneyLeft);
    }
}

// Method to calculate insurance based on car
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
// Method to calculate maintenance based on car
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

int calculate_miles(string car, int moneyLeft){
    int miles;
    if (car == "Honda Civic"){
        // Intentional truncation to conform to odometer style
        const double COST_PER_MILE = 0.11;
        miles = moneyLeft / COST_PER_MILE;
    }
    else {
        // Intentional truncation to conform to odometer style
        const double COST_PER_MILE = 0.19;
        miles = moneyLeft / COST_PER_MILE;
    }

    return miles;
}

// ============================================================
// SCENE 3: Start of Road Trip
// ============================================================
void road_scene(string car, int moneyLeft) {
    
    cout << "You have taken all the necessary precautions for the road trip.\n\n";
    cout << "Are you ready to start?\n";
    cout << "1. Yes.\n";
    cout << "2. NO, give up.\n\n";

    int choice;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1){
        int miles = calculate_miles(car, moneyLeft);
        moneyLeft = 0;
        output_metrics(car, miles, moneyLeft);
        scene_ending_good();
    }
    else{
        int miles = 0;
        output_metrics(car, miles, moneyLeft);
        scene_ending_bad();
    }
}

// ============================================================
// ALT SCENE 3: Start of Road Trip (Vehicle Breaks Down)
// ============================================================
void maintenance_scene(string car, int miles, int moneyLeft) {
    int fix_price = get_maintenance(car) * 2;
    int choice;

    cout << "\nUnfortunately, your car broke down right before starting.\n";
    cout << "You now have to pay $" << fix_price << " to fix your car and continue. \n\n";
    cout << "What do you do?\n";
    cout << "1. Quit the Road Trip\n";
    cout << "2. Pay and Start the Road Trip\n";

    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 2){
        moneyLeft -= fix_price;
        road_scene(car, moneyLeft);
    }
    else {
        output_metrics(car, miles, moneyLeft);
        scene_ending_bad();
    }

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
    cout << "\n\n*** GAME OVER ***\n";
    cout << "Unfortunately you have made the incorrect choice.\n";
    cout << "You didn't make it out. Better luck next time.\n";
}

// Method to print out all saved variables
void output_metrics(string car, int miles, int moneyLeft) {
    cout << "\nYou have bought " <<  car << " and driven " << miles << " miles so far." << endl;
    cout << "After that, currently you now only have $" << moneyLeft << " left";
}
