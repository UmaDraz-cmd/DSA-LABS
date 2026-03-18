#include<iostream>
#include<vector>
using namespace std;
    vector<int> reverseVector(vector<int> &vec)  {
        vector<int> vec2(vec.size());
        for(int i=vec.size()-1; i>=0; i--) {
            vec2[vec.size()-1-i] = vec[i];
        }
        return vec2;
    }
int main() {
    int size;
    cout << "Enter the size of the vector: ";       
    cin >> size;
    vector<int> vec(size);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < size; i++) {
        cin >> vec[i];  
    }
    vector<int> reversedVec = reverseVector(vec);       
    cout << "The reversed vector is: ";
    for (int i = 0; i < reversedVec.size(); i++) {
        cout << reversedVec[i] << " ";
    }
    cout << endl;
    return 0;
}   