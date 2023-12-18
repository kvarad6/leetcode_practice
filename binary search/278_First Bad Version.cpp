// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //Using Binary Search..
        
        int firstBadElement = 1;
        int low = 0;
        int high = n;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isBadVersion(mid)==true){
                high = mid - 1;
                firstBadElement = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return firstBadElement;
       
    }
};
