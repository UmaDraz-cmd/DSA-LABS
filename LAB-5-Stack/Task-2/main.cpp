#include "freq.cpp"
#include "insertion_sort.cpp"
#include <fstream>
#include <iostream>
using namespace std;

void calculateFrequencies(const char *filename, LetterInfo *freqArray);
void insertionSort(LetterInfo *freqArray);
void displayFrequencies(LetterInfo *freqArray);

int main()
{
    LetterInfo freqArray[26];
    for (int i = 0; i < 26; i++)
    {
        freqArray[i].letter = 'a' + i;
        freqArray[i].freq = 0;
    }

    char filename[100];
    cout << "Enter input file name: ";
    cin >> filename;

    calculateFrequencies(filename, freqArray);
    insertionSort(freqArray);
    displayFrequencies(freqArray);

    return 0;
}