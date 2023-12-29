class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //----------- Approach 1 ---------------//
        //bruite force
        //TC: O(N^2)
        //SC: O(N)

        vector<vector<int>> ans;

        int length = intervals.size();
        if(length<=1){
            return intervals;
        }
        //need to sort the array, as in the case of:
        //[[1,4],[0,4]] logic fails
        sort(intervals.begin(),intervals.end());

        for(int i=0;i<length;i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            for(int j=i+1;j<length;j++){
                int c = intervals[j][0];
                int d = intervals[j][1];
                if(b>=c){
                    b = max(b,d);
                    i=j;
                }
            }
            ans.push_back({a,b});
        }
        return ans;

        //------------- Approach 2 ---------------//
        //optimised approach
        //TC: O(NlogN) | N-> for loop | logn -> sorting
        //SC: O(N)

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

            //result.back()-> referes to the last pair in result vector [[i,j]]
            //result.back()[1] -> referes to the jth element of last pair

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
