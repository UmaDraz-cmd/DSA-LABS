#include<iostream>
using namespace std;
int countVowels(char* str, int length)
{
    if(length == 0)
        return 0;

    char ch = str[0];

    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
       ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        return 1 + countVowels(str + 1, length - 1);
    else
        return countVowels(str + 1, length - 1);
}
int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    int length = 0;
    while(str[length] != '\0')
        length++;

    int vowelCount = countVowels(str, length);
    cout << "The number of vowels in the string is: " << vowelCount << endl;
}