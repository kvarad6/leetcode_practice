//optimised technique
// sort the array -> fix one number -> two pointers to find target-selected number 
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // sort the array
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<arr.size();i++){
            int newTarget = target - arr[i];
            int startPointer = i+1;
            int endPointer = arr.size()-1;
            while(startPointer<endPointer){
                int currentSum = arr[startPointer] + arr[endPointer];
                if(newTarget==currentSum){
                    return true;
                }else if (currentSum<newTarget){
                    startPointer++;
                }else{
                    endPointer--;
                }
            }
        }
        return false;
    }
};     
