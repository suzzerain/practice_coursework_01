#include <iostream>
#include "main1.cpp"
#include "main2.cpp"
#include "main3.cpp"
#include "main4.cpp"
using namespace std;
int main() {
    while (true) {
        system("cls");

        cout << "Choose the lab work to start:";
    cout << "\n1 - Data types and theit internal representation in memory";
    cout << "\n2 - One-dimensional static arrays";
    cout << "\n3 - Two-dimensional static arrays. Pointers";
    cout << "\n4 - Strings. Searching substring in string\n";
    cout << "\n0 - Exit\n";

    int userChoice;
    cin >> userChoice;
        if (userChoice==0){
            break;
        }
        switch (userChoice) {

            case 1:
                system("cls");
                main1();
                break;

            case 2:
                system("cls");
                main2();
                break;

            case 3:
                system("cls");
                main3();
                break;

            case 4:
                system("cls");
                main4();
                break;

            default:
                cout << "Unknown command\n";


        }

    }
}
