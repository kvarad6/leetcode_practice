//----------- Approach 1 -----------//
//bruite force | two pointers
//TC: O(N^2) | TLE
class Solution {
public:
    int maxArea(vector<int>& height) {
        int currentArea=0, maxArea=0; 
        int currentWidth=0, currentHeight=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1; j<height.size();j++){
                currentWidth = j-i;
                currentHeight = min(height[i], height[j]);
                currentArea = currentHeight * currentWidth;
                maxArea = max(maxArea, currentArea);
            }
        }
    return maxArea;
    }
};

//----------- Approach 2 -----------//
//optimised appraoch | two pointer | greedy
//one pointer to the left and one to the right of the array
//Moving the pointer that points to the lower line.
//TC: O(N)
//SC: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int currentArea=0, maxArea=0;
        int currentWidth=0, currentHeight=0;

        while(i<=j){
            currentWidth = j-i;
            currentHeight = min(height[i], height[j]);
            currentArea = currentHeight * currentWidth;
            maxArea = max(maxArea, currentArea);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxArea;
    }
};
