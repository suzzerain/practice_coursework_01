#include <iostream>
using namespace std;
int main1() {
    // 1 razdel pracc PAB0Tbl

    cout << "int:" << sizeof(int) << "\n" << "short int:" << sizeof(short int) << "\n" << "long int:"
         << sizeof(long int) << "\n" << "float:" << sizeof(float) << "\n" << "double:" << sizeof(double) << "\n"
         << "long double:" << sizeof(long double) << "\n" << "char:" << sizeof(char) << "\n" << "bool:" << sizeof(bool)
         << "\n";
    //2 razdel

    int binaryInt;
    cout << "Enter data of type int:\n";
    while (!(cin >> binaryInt)) {
        cout << "error, expecting a num value\n";
        cin.clear();
        fflush(stdin);
    }
    int b = sizeof(binaryInt) * 8 - 1;
    int maskInt = 1 << b;
    int arrInt[32];
    for (int i = 0; i <= b; i++) {
        if (i == 1 || i % 8 == 0) {
            putchar(' ');
        }

        putchar(binaryInt & maskInt ? '1' : '0');
        if (binaryInt & maskInt){
            arrInt[i]=1;
        }
        else {
            arrInt[i]=0;

        }

        binaryInt = binaryInt << 1;
    }

    cout << "\nDo you want to shift all the bits equal to one to the left?\n'1'- Yes '2' - No\n";
    int userChoiceInt;
    while (!(cin >> userChoiceInt)) {
        cout << "error, expecting a num value\n";
        cin.clear();
        fflush(stdin);
    }
    if (userChoiceInt != 1 && userChoiceInt !=2){
        cout << "error, expecting '1' or '2' value:\n";
        cin >> userChoiceInt;
    }
    if (userChoiceInt == 1) {


       if (arrInt[0]==1){
           arrInt[0]=0;
       }

       for (int g=1; g<32;g++) {
           if (arrInt[g] == 1) {
               arrInt[g] = 0;
               arrInt[g-1] = 1;
           }
       }
        for ( int c =0;c<32;c++){
            if (c == 1 || c % 8 == 0) {
                putchar(' ');
            }
            cout<<arrInt[c];
        }


       }


    int d = 0;
    do {

        int Type;
        cout << "\n Select type:\nfloat - 1 \ndouble - 2 \n";
        while (!(cin >> Type)) {
            cout << "error, expecting  '1' or '2' value\n";
            cin.clear();
            fflush(stdin);
        }
        if (Type != 1 && Type !=2){
            cout << "error, expecting '1' or '2' value:\n";
            cin >> Type;
        }
        if (Type == 1) {
            //3 razdel
            cout << "\n";
            cout << "Enter data of type float: \n";
            union {
                float binaryFloat;
                int value;
            };
            unsigned order = sizeof(float) * 8;
            unsigned mask = 1 << order - 1;
            int arrFloat[32];
            while (!(cin >> binaryFloat)) {
                cout << "error, expecting num value\n";
                cin.clear();
                fflush(stdin);
            }
            for (int i = 0; i <= order-1; ++i) {
                if (i == 1 || i == 9) {
                    putchar(' ');
                }
                putchar(value & mask ? '1' : '0');


                if (value & mask){
                    arrFloat[i]=1;
                }
                else {
                    arrFloat[i]=0;
                }
                value <<= 1;

            }
            cout << endl;
            cout << "\nDo you want to shift all the bits equal to one to the left?\n'1'- Yes '2' - No\n";
            int userChoiceFloat;
            while (!(cin >> userChoiceFloat)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }
            if (userChoiceFloat != 1 && userChoiceFloat !=2){
                cout << "error, expecting '1' or '2' value:\n";
                cin >> userChoiceInt;
            }
            if (userChoiceFloat == 1) {

                if (arrFloat[0]==1){
                    arrFloat[0]=0;
                }

                for (int g=1; g<32;g++) {
                    if (arrFloat[g] == 1) {
                        arrFloat[g] = 0;
                        arrFloat[g-1] = 1;
                    }
                }

                for ( int c =0;c<32;c++){
                    if (c == 1 || c == 9) {
                        putchar(' ');
                    }
                    cout<<arrFloat[c];
                }

            }
        }


        if (Type == 2) {
            //4 razdel
            cout << "\n";
            cout << "Enter data of type double: \n";
            union {
                double binaryDouble;
                int arr[2];
            };
            while (!(cin >> binaryDouble)) {
                cout << "error, expecting num value\n";
                cin.clear();
                fflush(stdin);
            }
            int arrDouble[64];
            int orderg = sizeof(double) * 8;
            int gmaskk = 1 << (orderg - 1);
            for (int j = 1; j >= 0; j--) {
                for (int i = 0; i <= (orderg / 2)-1; i++)
                {
                    putchar(arr[j] & gmaskk ? '1' : '0');
                    if (j==1) {

                        if (arr[j] & gmaskk) {
                            arrDouble[i] = 1;
                        } else {
                            arrDouble[i] = 0;
                        }
                    }
                    if (j==0){
                        if (arr[j] & gmaskk) {
                            arrDouble[i+32] = 1;
                        } else {
                            arrDouble[i+32] = 0;

                        }

                    }
                    arr[j] <<= 1;

                    if ((i == 0 || i == 11) && j == 1) {
                        putchar(' ');

                    }
                }
            }
            cout << "\nDo you want to shift all the bits equal to one to the left?\n'1'- Yes '2' - No\n";
            int userChoiceDouble;
            while (!(cin >> userChoiceDouble)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }
            if (userChoiceDouble != 1 && userChoiceDouble !=2){
                cout << "error, expecting '1' or '2' value:\n";
                cin >> userChoiceInt;
            }
            if (userChoiceDouble == 1) {

                if (arrDouble[0]==1){
                    arrDouble[0]=0;
                }

                for (int g=1; g<64;g++) {
                    if (arrDouble[g] == 1) {
                        arrDouble[g] = 0;
                        arrDouble[g-1] = 1;
                    }
                }

                for ( int c =0;c<64;c++){
                    if (c == 1 || c == 12) {
                        putchar(' ');
                    }
                    cout<<arrDouble[c];
                }

            }
        }

        cout <<  "\nDo you want to exit, or you want to continue? \n1 - continue 2 - exit\n";
        cin >> d;
    } while (d!=2);

}

