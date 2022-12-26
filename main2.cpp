#include <iostream>
#include <chrono>
#include <algorithm>
#include <ctime>
using namespace std;
using namespace chrono;


//Сортировки
const int arrSize = 100;
void bubbleSort(int array[]) {
    for (int i = 0; i < arrSize - 1; i++)
        for (int j = 0; j < arrSize - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}

void shakerSort(int array[]){
    for (int i = 0; i<arrSize-1; i++) {
        for (int j = i; j < arrSize - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
        for (int j = arrSize - 1 - i; j < 0 + i; j++) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
            }
        }
    }
}
void combSort(int array[]){
    double S = arrSize - 1, k = 1.247;
    int count = 0;
    while (S >= 1) {
        for (int i = 0; i + S < arrSize; i++) {
            if (array[i] > array[int(i + S)]) swap(array[i], array[int(i + S)]);
        }
        S /= k;
    }
    for (int j = 0; j < arrSize-1; j++) {

        if (array[j] > array[j + 1]) {
            swap(array[j], array[j + 1]);
        }
    }

}

void insertSort(int array[]){
    for (int i = 1; i < arrSize; i++) {
        for (int j = i; (j > 0) && (array[j-1] > array[j]); j--) {
                  swap(array[j-1], array[j]);
            }
        }
    }

void quickSort(int array[], int left, int right){
    int referenceElement;
    int leftLimit = left;
    int rightLimit = right;
    referenceElement = array[(left + right)/2];
    while(leftLimit < rightLimit){
        while(array[leftLimit] < referenceElement){
            leftLimit++;
        }
        while(array[rightLimit] >= referenceElement){
            rightLimit--;
        }
        if (leftLimit<=rightLimit){
            swap(array[leftLimit],array[rightLimit]);
            leftLimit++;
            rightLimit--;
        }
    }
    if(left < rightLimit){
        quickSort(array, left, rightLimit);

    if(leftLimit < right){
        quickSort(array, leftLimit, right);
    }
    }

}

void printArray(int arr[])
{
    int i;
    for (i = 0; i < 100; i++){
        cout << arr[i]<< ' ';
    }
}

int main2() {
// Task 1. Filling array random numbers from -99 to 99
    const int arrSize = 100;
    int arr[arrSize];
    int arrForSort[arrSize];
    int arrForIdz[arrSize];
    srand(time(0));
    int cycleMain;
    cout <<"Hello! '1' - Start the program '0' - Exit\n";
    while (!(cin >> cycleMain)) {
        cout << "error, expecting a num value\n";
        cin.clear();
        fflush(stdin);
    }
    while(cycleMain) {

        for (int i = 0; i < arrSize; i++) {
            arr[i] = -99 + (std::rand() % 199);


        }

        memcpy(arrForSort, arr, sizeof(arrForSort));
        cout << "Our array:\n";
        printArray(arr);
        cout << "\n---------------------------------";
        //Task 2. Sorting array:

        cout << "\nTask 2. Sorting array:\n'1' - Start task '0' - Go to next task:\n";
        int cycleSort;
        while (!(cin >> cycleSort)) {
            cout << "error, expecting a num value\n";
            cin.clear();
            fflush(stdin);
        }
        while (cycleSort) {
            cout << "\nChoice type of sorting\n'1'- Bubble Sort\n'2' - Shaker sort\n'3' - Comb sort\n'4' - Insert sort\n'5' - Quick sort\n";
            int userChoiceSort;
            while (!(cin >> userChoiceSort)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }
            if (userChoiceSort == 1) {
                cout << "---------------------------------";
                cout << "\nsorted array:\n";

                auto start = steady_clock::now();

                bubbleSort(arrForSort);
                auto end = steady_clock::now();
                auto result = duration_cast<nanoseconds>(end - start);
                printArray(arrForSort);
                cout << "\ntime " << result.count() << " ns";

            }
            if (userChoiceSort == 2) {
                cout << "---------------------------------";
                cout << "\nsorted array:\n";

                auto start = steady_clock::now();

                shakerSort(arrForSort);
                auto end = steady_clock::now();
                auto result = duration_cast<nanoseconds>(end - start);
                printArray(arrForSort);
                cout << "\ntime " << result.count() << " ns";
            }

            if (userChoiceSort == 3) {
                cout << "---------------------------------";
                cout << "\nsorted array:\n";

                auto start = steady_clock::now();

                combSort(arrForSort);
                auto end = steady_clock::now();
                auto result = duration_cast<nanoseconds>(end - start);
                printArray(arrForSort);
                cout << "\ntime " << result.count() << " ns";

            }
            if (userChoiceSort == 4) {
                cout << "---------------------------------";
                cout << "\nsorted array:\n";

                auto start = steady_clock::now();

                insertSort(arrForSort);
                auto end = steady_clock::now();
                auto result = duration_cast<nanoseconds>(end - start);
                printArray(arrForSort);
                cout << "\ntime " << result.count() << " ns";
            }
            if (userChoiceSort == 5) {
                cout << "---------------------------------";
                cout << "\nsorted array:\n";

                auto start = steady_clock::now();
                quickSort(arrForSort,0, arrSize-1);
                auto end = steady_clock::now();
                auto result = duration_cast<nanoseconds>(end - start);
                printArray(arrForSort);
                cout << "\ntime " << result.count() << " ns";
            }

            cout << "\n'1' - Repeat task '0' - Go to next task\n";
            while (!(cin >> cycleSort)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }
        }
        cout << "\nIndividual task. '1' - Start task '0' - Go to the next task\n";
        int cycleIdz;
        int inputIdz;
        while (!(cin >> cycleIdz)) {
            cout << "error, expecting a num value\n";
            cin.clear();
            fflush(stdin);
        }
        while(cycleIdz) {
            memcpy(arrForIdz, arrForSort, sizeof(arrForIdz));
            cout << "\n---------------------------------\n";
            cout << "Enter an integer value\n";
            while (!(cin >> inputIdz)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }
            for (int i = 0; i < arrSize; i += 2) {
                arrForIdz[i] -= inputIdz;
            }
            cout << "\nArray after substraction user value\n";
            printArray(arrForIdz);
            for (int i = 0; i < arrSize; i += 2) {
                arrForIdz[i] *= (rand() % 9 + 1);
            }
            cout << "\nArray after multiplication\n";
            printArray(arrForIdz);

            int countEven = 0, countUnEven = 0;

            for (int i = 0; i < arrSize; i += 2) {
                if (arrForIdz[i] % 2 == 0) {
                    countEven += 1;
                }
            }
            for (int i = 1; i < arrSize; i += 2) {
                if (arrForIdz[i] % 2 == 1) {
                    countUnEven += 1;
                }
            }
            cout << "\nCount of even elements on even position\n" << countEven;
            cout << "\nCount of un-even elements on un-even position\n" << countUnEven;
            cout << "\n'1' - Repeat task '0' - Go to next task\n";
            while (!(cin >> cycleIdz)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }
        }



        // Task 3. Searching max and min in array:
        cout << "\nTask 3. Searching max and min in array:";


        //Searching in unsorted array:
        cout << "\n---------------------------------";
        auto start = steady_clock::now();
        // что делать если размерность больше 100
        float maxx = -100;
        float minn = 100;
        for (int b = 0; b < arrSize; b++) {
            if (arr[b] > maxx) {
                maxx = arr[b];
            }
            if (arr[b] < minn) {
                minn = arr[b];
            }
        }
        auto end = steady_clock::now();
        auto result = duration_cast<nanoseconds>(end - start);
        cout << "\nmaximum:" << maxx << "\nminimum" << minn;
        cout << "\nElapsed time of searching max and min elements in unsorted array: " << result.count() << "ns";

        //Searching in sorted array:
        start = steady_clock::now();
        maxx = arrForSort[arrSize - 1];
        minn = arrForSort[0];
        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);
        cout << "\nmaximum:" << maxx << "\nminimum" << minn;
        cout << "\nElapsed time of searching max and min elements in sorted array: " << result.count() << "ns";
        cout << "\n---------------------------------";


        cout << "\nTask 4. Searching elements of array equal to the average of max and min";
        cout << "\n---------------------------------";

        //Task 4.1 Average of max and min:
        int average = (maxx + minn) / 2;
        cout << "\naverage value of max and min: " << average;
        cout << "\n---------------------------------";
        //Task 4.2 Search for array elements equal to the average:
        //In Unsorted array:
        cout << "\nIndexes of array elements equal to the average";
        start = steady_clock::now();

        int countAverage = 0;
        for (int i = 0; i < arrSize; i++) {
            if (arr[i] == average) {
                cout << "\n" << i;
                countAverage += 1;

            }
        }
        cout << "\ncount of equal elements:" << countAverage;
        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);
        cout << "\nElapsed time of searching equal elements to the average in unsorted array: " << result.count()
             << "ns";

        //In sorted array:

        countAverage = 0;
        start = steady_clock::now();
        for (int i = 0; i < arrSize; i++) {
            if (arrForSort[i] == average) {
                cout << "\n" << i;
                countAverage += 1;
            } else {
                if (arrForSort[i] > average) {
                    break;
                }
            }
        }
        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);
        cout << "\nElapsed time of searching equal elements to the average in sorted array: " << result.count() << "ns";
        cout << "\n---------------------------------";

        //Task 5 Find amount of elements which less than user input in sorted arra
        cout << "\nTask 5. Find amount of elements which less than user input in sorted array\n'1' - Start task '0' - Go to next task:\n";
        cout << "---------------------------------\n";

        int cycleFindLess;
        int userInputLess;
        while (!(cin >> cycleFindLess)) {
            cout << "error, expecting a num value\n";
            cin.clear();
            fflush(stdin);
        }

        while (cycleFindLess) {
            cout << "\nEnter an integer value:";
            while (!(cin >> userInputLess)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }
            int countLess = 0;
            for (int i = 0; i < arrSize; i++) {
                if (arrForSort[i] < userInputLess) {
                    countLess += 1;
                } else {
                    break;
                }
            }
            cout << "\nCount of elements less than " << userInputLess << ":";
            cout << "\n" << countLess;

            cout << "\n'1' - Repeat task '0' - Go to next task:\n";
            while (!(cin >> cycleFindLess)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }

        }
        //Task 6 Find amount of elements which more than user input in sorted array
        cout << "\n---------------------------------";
        cout << "\nTask 6. Find amount of elements which more than user input in sorted array\n'1' - Start task '0' - Go to next task:\n";
        cout << "---------------------------------\n";
        int userInputMore;
        int cycleFindMore;
        while (!(cin >> cycleFindMore)) {
            cout << "error, expecting a num value\n";
            cin.clear();
            fflush(stdin);
        }

        while (cycleFindMore) {
            cout << "\nEnter an integer value:";
            while (!(cin >> userInputMore)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }
            int countMore = 0;
            for (int i = 0; i < arrSize; i++) {
                if (arrForSort[i] > userInputMore) {
                    countMore += 1;
                }
            }
            cout << "\nCount of elements more than " << userInputMore << ":";
            cout << "\n" << countMore;

            cout << "\n'1' - Repeat task '0' - Go to next task:\n";
            while (!(cin >> cycleFindMore)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }

        }

        //Task 7. Find element in array:
        //7.1 linear searching
        cout << "\n---------------------------------";
        cout << "\nTask 7. Find Element in array\n'1' - Start task '0' - Go to next task:\n";
        cout << "---------------------------------\n";
        int userKey;
        int cycleFindKey;
        while (!(cin >> cycleFindKey)) {
            cout << "error, expecting a num value\n";
            cin.clear();
            fflush(stdin);
        }
        while (cycleFindKey) {
            cout << "\nEnter an integer value:";

            while (!(cin >> userKey)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }
            start = steady_clock::now();
            bool flag = 0;
            for (int i = 0; i < arrSize; i++) {
                if (arrForSort[i] == userKey) {
                    cout << "\nYour value is in the array!";
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                cout << "\nYour value isn't in the array!";
            }
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "\nElapsed time of linear searching: " << result.count() << "ns";

            cout << "\n---------------------------------";
            //7.2 Binary searching:
            int leftLimit = 0;
            int rightLimit = arrSize;
            int middleElement;
            flag = 0;

            start = steady_clock::now();

            while (leftLimit <= rightLimit) {
                middleElement = (leftLimit + rightLimit) / 2;
                if (userKey == arrForSort[middleElement]) {
                    flag = 1;
                    break;
                }
                if (userKey > arrForSort[middleElement]) {
                    leftLimit = middleElement + 1;
                }
                if (userKey < arrForSort[middleElement]) {
                    rightLimit = middleElement - 1;
                }
            }
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "\nElapsed time of binary searching: " << result.count() << "ns";
            if (flag) {
                cout << "\nYour value is in the array!\nIndex of element: " << middleElement;
            } else {
                cout << "\nYour value isn't in the array!";
            }
            cout << "\n'1' - Repeat task '0' - Go to next task:\n";
            while (!(cin >> cycleFindKey)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }
        }



        //Task 8. Swapping array elements:
        cout << "\n---------------------------------";
        cout << "\nTask 8. Swapping elements in array\n'1' - Start task '0' - Go to next task\n";
        cout << "---------------------------------\n";
        int cycleSwap;
        int inputFirstIndex, inputSecondIndex;
        while (!(cin >> cycleSwap)) {
            cout << "error, expecting a num value\n";
            cin.clear();
            fflush(stdin);
        }

        while (cycleSwap) {
            cout << "\nEnter first index from 0 to 99:";
            while (!(cin >> inputFirstIndex)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }
            cout << "\nEnter second index from 0 to 99:";
            while (!(cin >> inputSecondIndex)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);

            }
            cout << "\n---------------------------------";
            cout << "\narray before swap:\n";
            for (int i = 0; i < arrSize; i++) {
                if (i == inputFirstIndex || i == inputSecondIndex) {
                    cout << "<< " << arrForSort[i] << " << ";
                } else {
                    cout << arrForSort[i] << ' ';
                }
            }
            start = steady_clock::now();
            swap(arrForSort[inputFirstIndex], arrForSort[inputSecondIndex]);
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "\nElapsed time of swapping elements in sorted array: " << result.count() << "ns";


            cout << "\n---------------------------------";
            cout << "\narray after swap:\n";
            for (int i = 0; i < arrSize; i++) {
                if (i == inputFirstIndex || i == inputSecondIndex) {
                    cout << "<< " << arrForSort[i] << " << ";
                } else {
                    cout << arrForSort[i] << ' ';
                }
            }
            cout << "\n'1' - Repeat task '0' - Repeat/Finish the program:\n";
            while (!(cin >> cycleSwap)) {
                cout << "error, expecting a num value\n";
                cin.clear();
                fflush(stdin);
            }
        }
        cout << "\n'1' - Repeat the program '0' - Finish the program:\n";
        while (!(cin >> cycleMain)) {
            cout << "error, expecting a num value\n";
            cin.clear();
            fflush(stdin);
        }

    }
}
