class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        for(int i=0;i<intervals.size();i++){

    //------------ case 1: -----------------------//
            //if the end of current element of intervals is less than start of newIntervals, then its not overlapping with current intervals, just add it to result.
            if(intervals[i][1]<newInterval[0]){
                result.push_back(intervals[i]);
            }

    //------------ case 2: ------------------------//
            //if the start of current interval is greater than end of newIntervals, directly insert newIntervals in the result..

            else if(intervals[i][0] > newInterval[1]){
                result.push_back(newInterval);

                //to push the remaining elements of intervals in result...
                newInterval = intervals[i];
            }

    //------------ case 3: -------------------------//
            //overlapping case..
            //if end of current intervals element is greate than start of newIntervals, or start of current intervals element less than or equal to end of newIntervals then overlapping present..
            else if(intervals[i][1]>=newInterval[0] || intervals[i][0]<=newInterval[1]){
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }

        }
        result.push_back(newInterval);
        return result;
    }
};
