//Umar Draz - ITM036 - Morning
#include<iostream>
using namespace std;

void printChar(char ch, int n) {
    if (n == 0)
        return;

    // print n characters in one line
    for(int i = 0; i < n; i++) {
        cout << ch;
    }
    cout << endl;

    // recursive call
    printChar(ch, n - 1);
}

int main() {
    int num;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    cout << "Enter a number: ";
    cin >> num;

    printChar(ch, num);
}