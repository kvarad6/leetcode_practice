// Custom comparator using function pointer
#include <iostream>
#include<vector>
#include <bits/stdc++.h> 
using namespace std; 

bool customComparator(int a, int b){
    if(a>b){
        return true;
    }else{
        return false;
    }
    // return a>b;
}

int main() {
    vector<int> arr;
    for(int i=0;i<5;i++){
        arr.push_back(i);
    }
    sort(arr.begin(), arr.end(), customComparator);
    
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" "; //4 3 2 1 0 
    }

    return 0;
}
