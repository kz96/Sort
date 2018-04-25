#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <iomanip>
#include "Sorting.h"

using namespace std;

void menu() {
    cout << "\n\nMENU" << endl;
    cout << "1. SORTING" << endl;
    cout << "2. REVERSE" << endl;
    cout << "3. CHECK CORRECTNESS" << endl;
    cout << "4. END" << endl;
}

int main() {
    srand(time(NULL));

    char c;

    Sorting<int> s;

    while(c != '4') {
        menu();
        cin >> c;
        float* A;

        switch (c) {
            case '1':
                int arraySize;
                cout << "Podaj dlugosc tablicy" << endl;
                cin >> arraySize;
                A = new int[arraySize];

                for (int i = 0; i < arraySize; i++) {
                    A[i] = rand() % 9999;
                }
                s.sorting(A,arraySize);
                break;
            case '2':
                    s.reverse(A, arraySize);
                    s.print(A, arraySize);
                    break;
            case '3':
                s.ifCorrect(A,arraySize);
                break;
            default:
                if (c != '4') {
                    cout << "ZLA DANA" << endl;
                }
                break;

        }
    }

}