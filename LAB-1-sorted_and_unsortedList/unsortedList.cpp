#include "unsortedList.h"
#include <iostream>
using namespace std;
unsortedList::unsortedList(int size)
{
    if (size <= 0)
    {
        arr = nullptr;
        maxSize = 0;
    }
    else
    {
        maxSize = size;
        arr = new int[maxSize];
    }

    currSize = 0;
}
unsortedList::~unsortedList()
{
    if (arr != nullptr)
    {
        delete[] arr;
    }
}
bool unsortedList::isEmpty() const
{
    if (currSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool unsortedList::isFull() const
{
    if (currSize == maxSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void unsortedList::display() const
{
    if (currSize == 0)
    {
        return;
    }
    for (int i = 0; i < currSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool unsortedList::insert(int val)
{
    if (currSize == maxSize)
    {
        return false;
    }
    else
    {
        arr[currSize] = val;
        currSize++;
        return true;
    }
}
          //TASK#2 
bool unsortedList:: removeMax(int &maxVal) {
    int i=0;
    arr[0]= maxVal;  //here maxVal is supposed to have default val zero 
    while(i<currSize) { 
        if(arr[i]>maxVal) {
            maxVal= arr[i];
            arr[i]= arr[currSize-1];
            return true;
        }

    }
    
        return false; //if list is empty
    
}
void unsortedList::  reverse() {
    int i=0,J=currSize-1;
    while(i<J) {
        arr[i]= arr[J-1];
        arr[J-1]= arr[i];
        i++;
        J--;
    }

}
void unsortedList:: combineList(const unsortedList & list2) {
   
    int newSize = maxSize + list2.maxSize;
    int* newArr = new int[newSize];
    int start1 = 0,start2 = 0,total = 0;
    while(start1<currSize && start2<list2.currSize){
        if(arr[start1]<list2.arr[start2]){
            newArr[total] = arr[start1];
            start1++;
        }
        else{
            newArr[total] = arr[start2];
            start2++;
        }
        total++;
    }
    while(start1<currSize){
        newArr[total] = arr[start1];
        start1++;
        total++;
    }
    
    while(start2<list2.currSize){
        newArr[total] = list2.arr[start2];
        total++;
        start2++;
    }
    currSize = currSize + list2.currSize;
    delete [] arr;
    arr = newArr;


        
}
            //TASK#4 
// int replaceVal(int oldVal, int newVal) {
//     int count=0,i=0;
//     while(i<currSize) {
//         if(arr[i]==newVal) {
//             arr[i]=newVal;
//             count++;
//         }

//     }
//     return count;
// }
// bool removeLastoccurence(int val) {
//     int last_occurence=0,i=0;
//     while(i<currSize) {
//         if(arr[i]==newVal) {
//             last_occurence=newVal;
            
//         }
//         return true;

//     }
//     return false;

// }


bool unsortedList::remove1(int index, int &val)
{
    if (index < 0 || index >= currSize)
    {
        return false;
    }
    else
    {
        val = arr[index];
        arr[index] = arr[currSize - 1];
        currSize--;
        return true;
    }
}
bool unsortedList::remove2(int index, int &val)
{
    if (index < 0 || index >= currSize)
    {
        return false;
    }
    else
    {
        val = arr[index];
        for (int i = index; i < currSize - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        currSize--;
        return true;
    }
}
unsortedList::unsortedList(unsortedList &rhs)
{
    maxSize = rhs.maxSize;
    arr = new int[maxSize];
    currSize = 0;
    for (int i = 0; i < rhs.currSize; i++)
    {
        arr[i] = rhs.arr[i];
        currSize++;
    }
}
unsortedList &unsortedList::operator=(unsortedList &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    if (arr != nullptr)
    {
        delete[] arr;
    }
    maxSize = rhs.maxSize;
    arr = new int[maxSize];
    currSize = 0;
    for (int i = 0; i < rhs.currSize; i++)
    {
        arr[i] = rhs.arr[i];
        currSize++;
    }
    return *this;
}
bool unsortedList::operator==(unsortedList &rhs)const
{
    if (currSize != rhs.currSize)
    {
        return false;
    }
    for (int i = 0; i < currSize; i++)
    {
        if (arr[i] != rhs.arr[i])
        {
            return false;
        }
    }
    return true;
}
int unsortedList::removeAll1(int val)
{
    int total = 0;
    for (int i = 0; i < currSize; i++)
    {
        if (arr[i] == val)
        {
            arr[i] = arr[currSize - 1];
            total++;
            currSize--;
            if (arr[i] == val)
            {
                i--;
            }
        }
    }
    return total;
}
int unsortedList::removeAll2(int val)
{
    int total = 0;
    for (int i = 0; i < currSize; i++)
    {
        if (arr[i] == val)
        {
            total++;
            for (int j = i; j < currSize - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            currSize--;
            if (arr[i] == val)
            {
                i--;
            }
        }
    }
    return total;
}
int unsortedList::removeAll3(int val)
{
    int total = 0;
    int *newArr = new int[maxSize];
    for (int i = 0; i < currSize; i++)
    {
        if (arr[i] == val)
        {
            total++;
        }
        else
        {
            newArr[i - total] = arr[i];
        }
    }
    currSize = currSize - total;
    delete[] arr;
    arr = newArr;
    return total;
}
int unsortedList::removeAll4(int val)
{
    int count = 0;
    int i = 0, j = 0;
    while (i < currSize)
    {
        if (arr[i] != val)
        {
            arr[j] = arr[i];
            i++;
            j++;
        }
        else
        {
            count++;
            i++;
        }
    }
    currSize -= count;
    return count;
}
bool unsortedList::search(int value) {
    for (int i = 0; i < currSize; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}
