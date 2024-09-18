//----------- Approach 1 -----------//
/*
-> Need to implement custom sort as the builtin sort functionality will not provide us with the expected answer
-> Taking two integers/ strings at a time, concatinating them, consider the concatination result which will be the larger among other.
-> Then moving to the next string
-> Need to add our own comparator in the inbuilt sorting method | sort(arr.begin(), arr.end(), customComparator)
-> Comparator can be created using 3 methods
    1. Function Pointer
    2. Functors
    3. Lambda
-> Here, to implement the comparator, used lamda function
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //initialising a string array
        vector<string> arr;

        //trasverse nums array -> convert each number into string -> add in the arr
        for(int i=0;i<nums.size();i++){
            arr.push_back(to_string(nums[i]));
        }
        //creating a custom comparator using lambda function for sorting purpose
        auto customComparator = [](string &s1, string &s2){
            if(s1+s2 > s2+s1){
                return true;
            }else{
                return false;
            }
        };
        //sort the string array (arr)
        sort(arr.begin(), arr.end(), customComparator);

        //handling the case where only 0s' present in the array
        if(stoi(arr[0])==0){
            return "0";
        }
        //combine all the strings of the sorted array
        string result = "";
        for(int i=0;i<arr.size();i++){
            result += arr[i];
        }
        return result;
    }
};
