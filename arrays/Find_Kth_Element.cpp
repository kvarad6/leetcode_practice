#include <bits/stdc++.h> 

//---------- Approach 1 ---------------//
//Using Extra Space 

int findKthElement(vector<int> &arr1, vector<int> &arr2, int k){
    vector<int> ans;
    for(int i=0;i<arr1.size();i++){
        ans.push_back(arr1[i]);
    }

    for(int j=0;j<arr2.size();j++){
        ans.push_back(arr2[j]);
    }

    sort(ans.begin(), ans.end());

    return ans[k-1];
}

//------------- Approach 2 ----------------//
//Without using extra space

int findKthElement(vector<int> &arr1, vector<int> &arr2, int k){

    int m = arr1.size();
    int n = arr2.size();
    for(int i=0;i<n;i++){
        arr1.push_back(arr2[i]);
    }
    sort(arr1.begin(), arr1.end());
    return arr1[k-1];
}
