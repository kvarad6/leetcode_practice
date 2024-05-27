//------------ Approach 1 -------------//
//Sorting + Greedy
//Imp: We have given x range of ballons (Xstart, Xend), y coordinates are unknown.
/*
Step 1 : 
    -> Sort the ballons to see which ones are overlapping.
    -> Sort them using end points
Step 2:
    -> Check for the arrows needed
    -> If Xend of the first ballon > Xstart of second ballon
        -> If yes, continue
        -> if no, update endPointer with Xend of the current ballon, increment arrow varibale by 1.
*/

//TC: O(nlogn)
//SC: O(1)

bool compare(vector<int> &pointA, vector<int> &pointB){
        return pointA[1]<pointB[1];
    }

class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        
        //edge cases
        if(points.size()==0){
            return 0;
        }

        //sort the points matrix | by Xend of every ballon range
        sort(points.begin(), points.end(), compare);

        int prevBallonEnd = points[0][1];
        int arrowsRequired = 1;

        for(int i=1;i<points.size();i++){
            int currentXstart = points[i][0];
            int currentXend = points[i][1];

            if(currentXstart > prevBallonEnd){
                arrowsRequired++;
                prevBallonEnd = currentXend;
            }
        }
        return arrowsRequired;
    }
};
