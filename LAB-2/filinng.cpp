# include<iostream>
# include<fstream>
# include<string>
using namespace std;
int main(){
    cout<<"Filling the file with data..."<<endl;
    ofstream out("data.txt");
    if(out.is_open()){
        out<<"This is the first line."<<endl;
        out<<"This is the second line."<<endl;
}