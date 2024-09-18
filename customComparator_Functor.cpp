// Custom comparator using functor 
#include <iostream>
#include<vector>
#include <bits/stdc++.h> 
using namespace std; 

class CustomComparator{
    public:
         bool operator()(const int& a, const int& b) const {
             if(a>b){
                 return true;
             }else{
                 return false;
             }
    }
};

int main() {
    vector<int> arr;
    for(int i=0;i<5;i++){
        arr.push_back(i);
    }
    sort(arr.begin(), arr.end(), CustomComparator());
    
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" "; //4 3 2 1 0 
    }
    return 0;
}
