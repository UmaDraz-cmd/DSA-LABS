#include<Iostream>
using namespace std;
bool prime_or_not(int n) {
    int count=0;
    for(int i=2; i<n/2; i++) {
        if(n%i==0) {
            count++;
        }
    }
    if(count>=1)
    return false;
    else
    return true;
}
int main() {
    cout<<"For Number is prime=1, For not prime=0: "<<prime_or_not(17)<<endl;
}