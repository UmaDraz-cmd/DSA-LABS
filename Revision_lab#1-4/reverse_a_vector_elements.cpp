#include<iostream>
#include<vector>
using namespace std;
    // vector<int> reverseVector(vector<int> &vec)  {
    //     vector<int> vec2(vec.size());
    //     for(int i=vec.size()-1; i>=0; i--) {
    //         vec2[vec.size()-1-i] = vec[i];
    //     }
    //     return vec2;
    // }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int k=0;
        vector<int> temp(nums1.size());
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                if(nums1[i]== nums2[j]) {
                    temp[k]= nums1[i];
                    k++;
                }
            }
        }
        return temp;
        
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
    int size1;
    cout << "Enter the size of the vector: ";       
    cin >> size1;
    vector<int> vec1(size1);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < size1; i++) {
        cin >> vec1[i];  
    }
    vector<int> reversedVec = intersection(vec,vec1);       
    cout << "The reversed vector is: ";
    for (int i = 0; i < reversedVec.size(); i++) {
        cout << reversedVec[i] << " ";
    }
    cout << endl;
    return 0;
}   