// User function Template for C++

class Solution {
  public:
    long long countKdivPairs(int A[], int n, int K) {
        int freqArray[K] = {0};
        for(int i=0;i<n;i++){
            freqArray[A[i]%K]++;
        }
        
        long long count = 0;
        
        //transverse the freq array
        for(int i=0;i<=K/2;i++){
            if(i==0 || i==K-i){
                count += (long long) freqArray[i] * (freqArray[i]-1)/2;
            }else{
                count += (long long) freqArray[i] * freqArray[K-i];
            }
        }
        return count;
    }
};
