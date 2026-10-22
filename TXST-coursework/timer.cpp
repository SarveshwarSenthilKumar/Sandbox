
#include <iostream>
#include <cstdio>
#include <sys/time.h>
using namespace std;

int main() {
    while (true) {
        char input = ' ';
        cout << "Enter any character to start the timer:" << endl;
        cin >> input;
        timeval beg, end;
        gettimeofday(&beg, NULL);


        cout << "Enter any character to stop the timer:" << endl;
        cin >> input;
        gettimeofday(&end, NULL);


        const double timer = end.tv_sec - beg.tv_sec + (end.tv_usec - beg.tv_usec) / 1000000.0;
        printf("time: %.6f s\n", timer);
        cout << "Enter q to quit. Else press any other character to continue and start a new timer: ";
        cin >> input;
        if (input == 'q' || input == 'Q') {
            break;
        }
    }
    return 0;
}
