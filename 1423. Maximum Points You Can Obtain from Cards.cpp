class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0;
        int rightSum = 0;
        int maxSum = 0;

        //First k elements in the window
        for(int i=0;i<=k-1;i++){
            leftSum = leftSum + cardPoints[i];
        }
        maxSum = leftSum;

        //removing from first k
        int rightIndex = cardPoints.size()-1;
        for(int i=k-1; i>=0; i--){
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[rightIndex];
            //Move right index backward
            rightIndex = rightIndex-1;

            maxSum = max(maxSum, leftSum+rightSum);
        }
        
        return maxSum;
    }
};
