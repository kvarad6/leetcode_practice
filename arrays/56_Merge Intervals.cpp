
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> result;

        //base case
        if(intervals.size()<=1){
            return intervals;
        }

        //sort the intervals..
        sort(intervals.begin(), intervals.end());

        //putting first element of intervals into result
        result.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){

            //if the current end of the result element is less than start of current element of intervals, then, end of interval element becomes new end of result element...
            //i.e if intervals are overlapping..

            if(result.back()[1]>=intervals[i][0]){
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }
            //if intervals are not overlapping...
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
