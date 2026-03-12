#include<iostream>
using namespace std;
// function to countDigits
int countDig(int n) {
    if(n<10)
    {
        return 1;
    }
    else {
        int count= countDig( n/10) ;
            return count+1;
        
    }

}
int main() {
    cout<<countDig(564);
}