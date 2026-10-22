
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ofstream fout;
    string userInput;

    cout << "Enter input: ";
    getline(cin, userInput);

    fout.open("input.txt");
    if (!fout.is_open()) {
        cout << "File not open";
    }
    fout << userInput << endl;
    fout.close();
    
    return 0;
}
