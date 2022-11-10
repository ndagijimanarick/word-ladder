
#include <iostream>
#include "time.h"
#include <fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    string first1, second2;
    cout << "Please enter the string of the same length" << endl;
    cout << "first1: ";
    cin >> word1;
    while (first1.length() != 4) {
        cerr << "\nERROR: Please enter only four letter words\n";
        cout << "first1: ";
        cin >> first;
    }
    cout << "OK well obeyed" << endl;
    cout << endl << "second 2: ";
    cin >> second2;
    while (second2.length() != 4) {
        cerr << "\nERROR: Please enter only four letter words\n";
        cout << "second2: ";
        cin >> second2;
    }
    cout << "OK well obeyed" << endl;
    for (int i = 0; i < first1.length(); i++) {
        first1[i] = first[i] & 0xDF;
        second2[i] = second2[i] & 0xDF;
    }
    cout << first1 << endl << second2 << endl;
    ifstream inFile;
    inFile.open("EnglishWords.dat");
    if (inFile.fail()) {
        cerr << "ERROR: Unable to open file" << endl;
        exit(1);
    }
    string word;
    bool first1 Found = false;
    bool second2 Found = false;

    while (!inFile.eof() && (first1Found != true || second2Found != true)) {
        inFile >> word;
        if (first1 == word) first1Found = true;
        if (second2 == word) second2Found = true;
    }
    inFile.close();

    if (first1Found == true && second2Found == true) {
        cout << endl << "Both words are found in the dictionary" << endl;
    }

    return 0;
}
