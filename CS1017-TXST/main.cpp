
#include <iostream>
using namespace std;

int main() {
   int dogYears;
   int humanYears;
   
   cin  >> dogYears;   
   humanYears = 7 * dogYears;

   cout << dogYears;
   cout << " dog years is about ";
   cout << humanYears;
   cout << " human years.";
   cout << endl;
   
   return 0;
}

/*
// Basic Wage Program

#include <iostream>
using namespace std;

int main() {
   int wage;

   wage = 20;

   cout << "Salary is ";
   cout << wage * 40 * 52;
   cout << endl;

   return 0;
}
*/