class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        //initially lets consider smallest and biggest from the first array
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();
        int maxDistance = INT_MIN;
        //now trasverse the 2d array from second one
        for(int i=1; i<arrays.size();i++){
            //started by considering smallest of the first array and biggest of the current one, compairing and updating maxDistance
            maxDistance = max(abs(arrays[i].back()-smallest), maxDistance);

            //started by considering biggest of the first array and the smallest of the current one, compairing and updating maxDistance
            maxDistance = max(abs(biggest-arrays[i][0]), maxDistance);

            //update the smallest 
            smallest = min(smallest, arrays[i][0]);

            //update the biggest
            biggest = max(biggest, arrays[i].back());
        }
        return maxDistance;
    }
};
