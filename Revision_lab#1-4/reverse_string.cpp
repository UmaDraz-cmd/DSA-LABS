#include<iostream>
using namespace std;
void reverseString(vector<char>& s) {
        int start=0, end= s.size()-1;
        while( start<end) {
            swap(s[start],s[end]);
            start++;
            end--;
        }
    
        
    }
int main() {
    bool isAlphanumeric(char ch) {
    if((ch>='0' && ch <='9') || (tolower(ch)>='a' && tolower(ch)<='z')) {
        return true;
    }
    return false;

}