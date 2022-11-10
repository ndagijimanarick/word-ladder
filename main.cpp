
#include <iostream>
#include "time.h"
#include <fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    string word1, word2;
    cout << "Please enter the string of the same length" << endl;
    cout << "Word 1: ";
    cin >> word1;
    while (word1.length() != 4) {
        cerr << "\nERROR: Please enter only four letter words\n";
        cout << "Word 1: ";
        cin >> word1;
    }
    cout << "OK well obeyed" << endl;
    cout << endl << "Word 2: ";
    cin >> word2;
    while (word2.length() != 4) {
        cerr << "\nERROR: Please enter only four letter words\n";
        cout << "Word 2: ";
        cin >> word2;
    }
    cout << "OK well obeyed" << endl;
    for (int i = 0; i < word1.length(); i++) {
        word1[i] = word1[i] & 0xDF;
        word2[i] = word2[i] & 0xDF;
    }
    cout << word1 << endl << word2 << endl;
    ifstream inFile;
    inFile.open("EnglishWords.dat");
    if (inFile.fail()) {
        cerr << "ERROR: Unable to open file" << endl;
        exit(1);
    }
    string word;
    bool word1Found = false;
    bool word2Found = false;

    while (!inFile.eof() && (word1Found != true || word2Found != true)) {
        inFile >> word;
        if (word1 == word) word1Found = true;
        if (word2 == word) word2Found = true;
    }
    inFile.close();

    if (word1Found == true && word2Found == true) {
        cout << endl << "Both words are found in the dictionary" << endl;
    }

    return 0;
}
