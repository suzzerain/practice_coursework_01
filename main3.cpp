#include <iostream>
#include <Windows.h>
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <ctime>


using namespace std;

int randInt(int from, int to) {
    return from + std::rand() % to;
}
void setCursorPosition(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printMatrix(int *first,int N){
    for (int *i = first, *end = i + N*N-1, count = 1; i <= end; count++, i++){
        cout.width(6);
        cout << *i << " ";
        if (count % N == 0){ cout << "\n" ;}

    }
    cout << "\n";
}

void spiralFill(int *start, int N){
    int countPrinted = 0;
    int countIterations = 0;
//    getchar();
//    system("cls");


    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int countGlobalIterations = 0;
    for (;countPrinted != N * N;) {

        for (int *first = (start + countPrinted), *last = first + (N - 1), i = countGlobalIterations * (countGlobalIterations > 0? 3:0);
        i < ((N * 3) - (3* countGlobalIterations)) &&  first <= last; i += 3, first++) {

            setCursorPosition(i,countGlobalIterations);
            *first = randInt(1,N*N);
            cout << *first;
            countPrinted += 1;
            cout.flush();
            Sleep(300);

        }
        for (int *first = (start + countPrinted), *last = first + (N - 1), i = countGlobalIterations + 1;
        i < (N - countGlobalIterations) &&  first < last; first++, i++) {
            setCursorPosition((N-1) * 3 - countGlobalIterations*3,i);
            *first = randInt(1,N*N);

            cout << *first;
            countPrinted += 1;

            cout.flush();
            Sleep(300);

        }
        for (int *first = (start + countPrinted), *last = first + (N - 1), i = (N-1) * 3 - (countGlobalIterations +1)*3;
             i >= countGlobalIterations * 3 && first <= last; first++, i -= 3) {


            setCursorPosition(i, N -1 - countGlobalIterations);
            *first = randInt(1,N*N);


            cout << *first;
            countPrinted += 1;


            cout.flush();
            Sleep(300);

        }

        for (int *first = (start + countPrinted), *last = first + (N - 1), i = N - 2 - countGlobalIterations;
        i >= (1 + countGlobalIterations) && first <= last; i--, first++) {

            setCursorPosition(countGlobalIterations * 3, i);

            *first = randInt(1,N*N);
            cout << *first;
            countPrinted += 1;


            cout.flush();
            Sleep(300);

        }
        countGlobalIterations +=1;
    }

}

void snakeFill(int *start, int N){
//    getchar();
//    system("cls");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int countPrinted = 0;
    int countGlobalIterations = 0;
    int countIterations = 0;

    for (;countPrinted != N * N;) {

        for (int *first = (start + countPrinted), *last = first + (N - 1), i = 0; first <= last; i++, first++) {
            setCursorPosition((countIterations * 3 + (countGlobalIterations>0?1:0) + (N-1)*3*2), i);
            *first = randInt(1,N*N);
            cout << *first;
            countPrinted += 1;


            cout.flush();
            Sleep(300);
        }
        countIterations +=1;

        for (int *first = (start + countPrinted), *last = first + (N - 1), i = N-1; first <= last; i--, first++) {
            setCursorPosition((countIterations * 3 + (countGlobalIterations>0?1:0) + (N-1)*3*2), i);
            *first = randInt(1,N*N);
            cout << *first;
            countPrinted += 1;

            cout.flush();
            Sleep(300);

        }
        countIterations +=1;

        countGlobalIterations += 1;
    }

}

        void arrsForSwap(int *start, int*start1, int*start2, int*start3, int*start4, int N){
    int count = 0;
    for (int k = 1; k<=N/2; k++) {
        for (int *first = start + count, *end = first + N-1, x = 0; first <= end; first++, x++) {

            if (x < N/2) {
                *start1 = *first;
                start1 += 1;
                count +=1;
            }
            if (x >= N/2) {
                *start2 = *first;
                start2 += 1;
                count +=1;
            }
        }
    }
            for (int k = 1; k<=N/2; k++) {
                for (int *first = start + count, *end = first + N-1, x = 0; first <= end; first++, x++) {

                    if (x < N/2) {
                        *start4 = *first;
                        start4 += 1;
                        count +=1;
                    }
                    if (x >= N/2) {
                        *start3 = *first;
                        start3 += 1;
                        count +=1;
                    }
                }
            }

}
void swapCircle(int *start, int*start1, int*start2, int*start3, int*start4, int N){
    int count = 0;
    for (int k = 1; k<=N/2; k++) {
        for (int *first = start + count, *end = first + N-1, x = 0; first <= end; first++, x++) {

            if (x < N/2) {
                *first = *start4;
                start4 += 1;
                count +=1;
            }
            if (x >= N/2) {
                *first = *start1;
                start1 += 1;
                count +=1;
            }
        }
    }
    for (int k = 1; k<=N/2; k++) {
        for (int *first = start + count, *end = first + N-1, x = 0; first <= end; first++, x++) {

            if (x < N/2) {
                *first = *start3;
                start3 += 1;
                count +=1;
            }
            if (x >= N/2) {
                *first = *start2;
                start2 += 1;
                count +=1;
            }
        }
    }

}

void swapDiagonal(int *start, int*start1, int*start2, int*start3, int*start4, int N){
    int count = 0;
    for (int k = 1; k<=N/2; k++) {
        for (int *first = start + count, *end = first + N-1, x = 0; first <= end; first++, x++) {

            if (x < N/2) {
                *first = *start3;
                start3 += 1;
                count +=1;
            }
            if (x >= N/2) {
                *first = *start4;
                start4 += 1;
                count +=1;
            }
        }
    }
    for (int k = 1; k<=N/2; k++) {
        for (int *first = start + count, *end = first + N-1, x = 0; first <= end; first++, x++) {

            if (x < N/2) {
                *first = *start2;
                start2 += 1;
                count +=1;
            }
            if (x >= N/2) {
                *first = *start1;
                start1 += 1;
                count +=1;
            }
        }
    }

}
void swapVertical(int *start, int*start1, int*start2, int*start3, int*start4, int N){
    int count = 0;
    for (int k = 1; k<=N/2; k++) {
        for (int *first = start + count, *end = first + N-1, x = 0; first <= end; first++, x++) {

            if (x < N/2) {
                *first = *start4;
                start4 += 1;
                count +=1;
            }
            if (x >= N/2) {
                *first = *start3;
                start3 += 1;
                count +=1;
            }
        }
    }
    for (int k = 1; k<=N/2; k++) {
        for (int *first = start + count, *end = first + N-1, x = 0; first <= end; first++, x++) {

            if (x < N/2) {
                *first = *start1;
                start1 += 1;
                count +=1;
            }
            if (x >= N/2) {
                *first = *start2;
                start2 += 1;
                count +=1;
            }
        }
    }

}

void swapHorizontal(int *start, int*start1, int*start2, int*start3, int*start4, int N){
    int count = 0;
    for (int k = 1; k<=N/2; k++) {
        for (int *first = start + count, *end = first + N-1, x = 0; first <= end; first++, x++) {

            if (x < N/2) {
                *first = *start2;
                start2 += 1;
                count +=1;
            }
            if (x >= N/2) {
                *first = *start1;
                start1 += 1;
                count +=1;
            }
        }
    }
    for (int k = 1; k<=N/2; k++) {
        for (int *first = start + count, *end = first + N-1, x = 0; first <= end; first++, x++) {

            if (x < N/2) {
                *first = *start3;
                start3 += 1;
                count +=1;
            }
            if (x >= N/2) {
                *first = *start4;
                start4 += 1;
                count +=1;
            }
        }
    }

}

void arr_sort(int *arr, int N){

    for (int *first = arr + 1,  *last = first + N*N-1; first <= last; first++){
        for (int *parr = first;parr > arr;parr-- ){
            if (*parr < *(parr - 1)) {
                swap(*parr,*(parr - 1));
            }
        }
    }
}
void userOperation(int *start, int N, int userChoice, int userValue){
    switch(userChoice){
        case 1:
            for (int *first = start, *last = first + ((N * N) - 1), i = 0; first <= last; first++, i++) {
                *first = *first * userValue;
            }
            break;

        case 2:
            for (int *first = start, *last = first + ((N * N) - 1), i = 0; first <= last; first++, i++) {
                *first = *first / userValue;

            }
            break;

        case 3:
            for (int *first = start, *last = first + ((N * N) - 1), i = 0; first <= last; first++, i++) {
                *first = *first + userValue;

            }
            break;

        case 4:
            for (int *first = start, *last = first + ((N * N) - 1), i = 0; first <= last; first++, i++) {
                *first = *first - userValue;

            }
            break;


    }


}
//ИДЗ: Заполнить матрицу случайными числами, проверить, является ли она магическим квадратом, вывести промежуточные этапы.
void magicSquare(int N) {
    srand(time(0));
    int arr[N][N];
//    Магический квадрат для проверки работы алгоритма
//    int arr[3][3] = {3,4,2,
//                     2,3,4,
//                     4,2,3};
    int sum[N + N + 2];
    int *psum = sum;
    int countSummed = 0;
    for (int *first = sum, *last = first + (N + N + 1), i = 0; first <= last; first++, i++) {
        *first = 0;
    }

    int *start = &arr[0][0];

    for (int *first = start, *last = first + ((N * N) - 1), i = 0; first <= last; first++, i++) {
        *first = randInt(1,100);
    }

    printMatrix(start, N);

    int count = 0;

    for (int k = 1; k <= N; k++) {

        for (int *first = start + count, *end = first + N - 1; first <= end; first++) {

            *psum = *psum + *first;
            count += 1;
        }
        cout << "\nSum of " << k << " line: " << *psum;
        if ((count >= N * 2) && (*psum != *(psum-1))){
            cout << "\nNOT MAGIC\n";
            return;

        }
        psum += 1;
    }
    cout << "\n-----------------------------------\n";
    for (int k = 1; k <= N; k++) {
        for (int *first = start + (k - 1), *end = first + (N * N - N); first <= end; first += N) {

            *psum = *psum + *first;
            count += 1;
        }
        cout << "\nSum of " << k << " column: " << *psum;
        if ((count >= N * 2) && (*psum != *(psum-1))){
            cout << "\nNOT MAGIC\n";
            return;

        }

        psum += 1;
    }
    cout << "\n-----------------------------------\n";
    for (int k = 1; k <= N; k++) {
        int *first = start + (k - 1) * N + k - 1;

        *psum = *psum + *first;
        count += 1;
    }
    cout << "\nSum of main diagonal: " << *psum;

    cout << "\n-----------------------------------\n";
    if ((count >= N * 2) && (*psum != *(psum-1))){
        cout << "\nNOT MAGIC\n";
        return;

    }

    psum += 1;
    for (int k = 1; k <= N; k++) {
        int *first = start + (N - 1) * k;

        *psum = *psum + *first;
        count += 1;
    }
    if ((count >= N * 2) && (*psum != *(psum-1))){
        cout << "\nNOT MAGIC\n";
        return;

    }
    cout << "\nSum of main diagonal: " << *psum;


    cout << "\n-----------------------------------\n";


    for (int i = 0; i < N + N + 2; i++) {
        for (int j = 0; j< N + N + 2; j++) {
            if (sum[i] != sum[j]) {
                cout << "\nNOT MAGIC\n";
                return;
            }
        }
    }
    cout << "\nMAGIC\n";

}



int main3(){
    srand(time(0));

    int mainLoop;

    cout << "'1' - Start the program\n'0' - End the program\n";
    cin >> mainLoop;

    while(mainLoop) {

        int choiceIdz;
        cout << "'1' - Start the IDZ\n'0' - Go to the main program\n";
        cin >> choiceIdz;
        while(choiceIdz) {

            int sizeIdz;
            cout << "Enter size of the matrix:\n";
            cin >> sizeIdz;
            getchar();
            system("cls");
            magicSquare(sizeIdz);
            cout << "\n'1' - Repeat task '0' - Go to the main program:\n";
            cin >> choiceIdz;
        }


        int N;
        getchar();
        system("cls");
        cout << "Enter size of the matrix:\n";
        cin >> N;
        cout <<"\nPress any key to start the task 1.\n";
        getchar();
        system("cls");
        int arr[N][N];

        int array1[N / 2][N / 2];
        int array2[N / 2][N / 2];
        int array3[N / 2][N / 2];
        int array4[N / 2][N / 2];
        int *start = &arr[0][0];

        int *start1 = &array1[0][0];

        int *start2 = &array2[0][0];

        int *start3 = &array3[0][0];

        int *start4 = &array4[0][0];

        spiralFill(start, N);
        snakeFill(start, N);
        setCursorPosition(0, N * 2);
        cout << "Press any key to continue:\n";
        cin.get();
        getchar();
        system("cls");
        printMatrix(start, N);
        cout << "----------------\n";

        cout << "\na) Circle swap\n";

        arrsForSwap(start, start1, start2, start3, start4, N);
        swapCircle(start, start1, start2, start3, start4, N);
        printMatrix(start, N);

        Sleep(500);
        cout << "\nb) Diagonal swap\n";


        arrsForSwap(start, start1, start2, start3, start4, N);
        swapDiagonal(start, start1, start2, start3, start4, N);
        printMatrix(start, N);

        Sleep(500);
        cout << "\nc) Vertical swap\n";


        arrsForSwap(start, start1, start2, start3, start4, N);
        swapVertical(start, start1, start2, start3, start4, N);
        printMatrix(start, N);

        Sleep(500);
        cout << "\nd) Horizontal swap\n";


        arrsForSwap(start, start1, start2, start3, start4, N);
        swapHorizontal(start, start1, start2, start3, start4, N);
        printMatrix(start, N);
        Sleep(1000);
        cout << "\n-------------------------------------\nArray after sort:\n";


        arr_sort(start, N);
        printMatrix(start, N);


        int userChoiceOper, userValue, userChoice;
        cout << "\n'1' - Start next task '0' - Go to next task:\n";
        cin >> userChoice;


        while (userChoice) {
            getchar();
            system("cls");
            printMatrix(start, N);
            cout << "\nchoose the operation:\n";
            cout << "1 - '*'\n2 - '/'\n3 - '+'\n4 - '-'\n";
            cin >> userChoiceOper;
            cout << "Enter an integer value:\n";
            cin >> userValue;
            userOperation(start, N, userChoiceOper, userValue);
            printMatrix(start, N);
            cout << "\n'1' - Repeat task '0' - End the program :c :\n";
            cin >> userChoice;

        }
        cout << "\n'1' - Repeat program '0' - End the program :c :\n";
        cin >> mainLoop;

    }

}

