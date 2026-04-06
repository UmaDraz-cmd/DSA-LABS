#include "sortedList.h"
#include <iostream>
using namespace std;
sortedList::sortedList(int size)
{
    if (size <= 0)
    {
        arr = nullptr;
        maxSize = 0;
    }
    else
    {
        arr = new int[size];
        maxSize = size;
    }
    currSize = 0;
}
sortedList::~sortedList()
{
    if (arr != nullptr)
    {
        delete[] arr;
        arr= nullptr;
    }
}
bool sortedList::insert(int val)
{
    if (currSize == maxSize)
    {
        return false;
    }
    else
    {
        int i = currSize - 1;
        while (i >= 0 && arr[i] > val)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = val;
        currSize++;
        return true;
    }
}
bool sortedList::isEmpty() const
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
bool sortedList::isFull() const
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
 //TASK#1
bool sortedList::replace(int idx, int newVal) {
    int i=0;
    if(idx<0 || idx>maxSize) {
        return false;

    }
    else {
        while(i<currSize){
            if(i==idx) {
                arr[i]= newVal;


                return true;


            }
            return false;
            i++;
        }
    }

}
  //TASK#3
  bool sortedList::binarySearch(int val)  //binarySearch member function
{
    int start = 0, end = currSize - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == val)
        {
            return true;
        } 
        else if (arr[mid] < val)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

int sortedList:: removeAll(int val) { //removeAll traversing once and not using any extra arr
    int i=0,count=0,j=currSize-1;
    while(i<currSize) {
        if(arr[i]==val) {
            arr[i]= arr[j+1];
        }
    }

}

void sortedList::display() const
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
bool sortedList::remove2(int index, int &val)
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
sortedList::sortedList(const sortedList &rhs)
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
sortedList &sortedList::operator=(const sortedList &rhs)
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
bool sortedList::operator==(const sortedList &rhs)
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
int sortedList::removeAll2(int val)
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
            i--;
        }
    }
    return total;
}
int sortedList::removeAll3(int val)
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
bool sortedList::search(int key)
{
    int i = 0;
    while (i < currSize)
    {
        if (arr[i] == key)
        {
            return true;
        }
        i++;
    }
    return false;
}

void sortedList::merge(const sortedList &list2)
{
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
