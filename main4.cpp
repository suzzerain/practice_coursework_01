#include <iostream>
#include <string>
#include <chrono>
#include <fstream>


using namespace std;

void getString(string &str){
    cout << "\nChoose type of getting string:\n1 - Keyboard\n2 - From file\n";
    int userChoice;
    cin >> userChoice;
    if(userChoice==1) {
        cout << "\nEnter your string\n";

        cin.clear();
        while(cin.get() != '\n');
        getline(cin, str);
    }
    if(userChoice==2){

        ifstream File;
        File.open("C:\\Users\\vvlad\\CLionProjects\\practice_4\\text.txt");
        if(File.is_open()) {
            string str1;
            while (!File.eof()) {
                getline(File, str1);
                str+=str1;

            }
        }
            else{
                cout<<"File couldn't be opened...";
                return;
            }
            File.close();
        }
    }


void cleaningStr(string str, string &cleanStr){
    bool flagSpace;
    bool flagComma = true;
    for (int i = 0; i < str.length(); i++){
        if (str[i]==' ' && flagSpace == false){
            continue;
        }
        if (str[i]==' ' && flagSpace == true){
            cleanStr+=' ';
            flagSpace = false;
        }


        if (str[i] == '.' && str[i + 1] == '.' && str[i + 2] == '.') {
            i += 2;
            cleanStr += "...";
            continue;
        } else if (str[i] == '.') {
            cleanStr += '.';
            break;
        }

        if (str[i]==',' && flagComma == false){
            continue;
        }
        if (str[i]==',' && flagComma == true){
            cleanStr += ',';
            flagComma = false;
        }
        //ASCII A-65 Z-90;a-97 z-122;
        if (flagSpace == true && (str[i]>=65 && str[i]<=90)){
            cleanStr += str[i] + 32;
        }
        else if(str[i] != ' ' && str[i] != ','){
            cleanStr += str[i];
            flagSpace = true;
            flagComma = true;

        }
    }
    cout << cleanStr << '\n';
}


void reversingStr(string cleanStr){
    //Вывести на экран слова последовательности в обратном порядке.

    string reversedStr;
    char words[50][11];
    int i,j,k;
    for (i = 0, j = 0,k = 0; i < cleanStr.length(); i++) {
        if (i==cleanStr.length()-1){
            words[j][k+1] = '\0';
        }
        if (cleanStr[i] == ' ') {
            words[j][k] = '\0';
            j += 1;
            k = 0;
        } else {
            words[j][k] = cleanStr[i];
            k += 1;
        }
    }
    cout<< "\n-----------------\n";
    cout<< "\nReversed string:\n";

    int  lenWords = j;
    for (;j>=0; j--){
        cout << words[j] << ' ';
    }
    cout << '\n';

    cout<< "\n-----------------\n";
    cout<< "\nString after upping every first symbol of word:\n";


//        Вывести на экран ту же последовательность, заменив во всех словах первую букву соответствующей прописной буквой.
    for (int j = lenWords;j >=0; j--) {
        //ASCII A-65 Z-90;a-97 z-122;
        if (words[j][0]>=97 && words[j][0]<=122){
            words[j][0]-=32;
        }
    }
    for (int j = lenWords;j >=0; j--) {
        cout << words[j] << ' ';
    }
    cout<< "\n-----------------\n";

}

void linearSearching(string cleanStr, string strForSearch){
    cout<< "\n-----------------\n";
    cout<< "\nLinear searching:\n";

    int countCheck;
    bool flagCheck = false;
    int searchLen = strForSearch.length();
    cout <<'\n'<<cleanStr;
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    for (int i = 0; i<cleanStr.length() - searchLen; i++){
        countCheck = 0;
        if (cleanStr[i]==strForSearch[0]){
            countCheck = 1;
            for(int j =1; j<searchLen; j++){
                if (cleanStr[i+j]==strForSearch[j]){
                    countCheck+=1;
                }
                else{
                    break;
                }
                if(countCheck==searchLen){
                    flagCheck = true;
                    cout <<"\nString located on " <<i << "position\n"; //i-j+3
                }

            }
        }
    }
    if (flagCheck==false){
        cout <<"\nString wasn't found";
    }
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout <<"\nElapsed time of linear searching: "<<end-start<<" ns\n";

}

void searchBoyerMoore(string cleanStr, string strForSearch){
    cout<< "\n-----------------\n";
    cout <<"\nAlgorithm Boyer-Moore searching\n";
    cout <<'\n'<<cleanStr;

    //Алгоритм Бойера - Мура
    int searchLen = strForSearch.length();
    int arr[searchLen];
    //заполнение массива отступов
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    for (int i = searchLen-1; i>=0; i--){
        for (int j =i-1; j>=0; j--){
            if (strForSearch[j]==strForSearch[i]){
                arr[j] = arr[i];
            }
            else{
                arr[j] = searchLen-j-1;
            }
        }

    }
    bool flagMoore = false;
    for(int i = searchLen-2; i>=0;i--){
        if (strForSearch[i]==strForSearch[searchLen-1]){
            flagMoore = true;
            arr[searchLen-1] = arr[i];
            break;
        }
    }
    if (flagMoore==false) {arr[searchLen-1] =searchLen;}
    cout << '\n' << searchLen<< '\n';

//Поиск подстроки в строке.
    int countMoore;
    bool flagBoyel = false, flagFind;
    for (int i = searchLen-1; i<cleanStr.length();){
        countMoore=1;
        if (cleanStr[i]==strForSearch[searchLen-1]){
            for(int j = i;j>(i-searchLen);j--){
                if (cleanStr[j]==strForSearch[searchLen-1-(i-j)]) {
                    countMoore+=1;
                }
                else{
                    flagFind=false;
                    for(int l=0; l<searchLen;l++){
                        if (cleanStr[i]==strForSearch[l]){
                            flagFind=true;
                            i+=arr[l];
                            break;
                        }
                    }
                    if(flagFind==false){
                        i+=searchLen;
                    }
                    break;
                }
            }
            if(countMoore==searchLen+1){
                flagBoyel = true;
                cout <<"\nString located on " <<i-searchLen+1<< "position\n";
                i+=searchLen;
            }
        }
        else {
            flagFind=false;
            for(int l=0; l<searchLen;l++){
                if (cleanStr[i]==strForSearch[l]){
                    flagFind=true;
                    i+=arr[l];
                    break;
                }
            }
            if(flagFind==false){
                i+=searchLen;
            }
        }
    }
    if (flagBoyel==false){
        cout <<"\nString wasn't found";
    }
    auto  end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout <<"\nElapsed time of Boyer-Moore searching: "<<end-start<<" ns\n";

}

int main4() {
    string str;
    getString(str);
    int loopFind;
    cout <<"\nYour string:\n";
    cout << str;
    cout<< "\n-----------------\n";
    cout<< "\nString after cleaning:\n";
    string cleanStr;
    string strForSearch;
    cleaningStr(str,cleanStr);
    //Вывести на экран слова последовательности в обратном порядке.
    //Вывести на экран ту же последовательность, заменив во всех словах первую букву соответствующей прописной буквой.
    reversingStr(cleanStr);
    //Линейный поиск подстроки в строке
    cout << "\n'1' - Start finding substring in string \n'0'- End the program\n";
    cin >> loopFind;
    while(loopFind) {
        cout << "\nEnter substring for searching:\n";
        cin >> strForSearch;
        cin.get();
        linearSearching(cleanStr, strForSearch);
        //Поиск по алгоритму Бойера-Мура
        searchBoyerMoore(cleanStr, strForSearch);
//        cin.get();
        cout << "\n'1' - Restart finding substring in string \n'0'- End the program\n";
        cin >> loopFind;
    }


    return 0;
}