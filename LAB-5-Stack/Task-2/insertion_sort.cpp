#include "letterinfo.h"

void insertionSort(LetterInfo *freqArray)
{
    for (int i = 1; i < 26; i++)
    {
        LetterInfo key = freqArray[i];
        int j = i - 1;
        while (j >= 0 && freqArray[j].freq < key.freq)
        {
            freqArray[j + 1] = freqArray[j]; 
            j--;
        }
        freqArray[j + 1] = key;
    }
}
