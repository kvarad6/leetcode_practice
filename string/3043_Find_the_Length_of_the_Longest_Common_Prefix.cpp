//----------- Approach 1 -----------//
/*
-> Bruite force 
-> Find each and every pair, their common prefix, find the length and maintain the longest length
-> The problem is indeed about finding the longest common prefix starting from the leftmost character, not just any common substring.
-> TLE | As constraints are much larger
    1 <= arr1.length, arr2.length <= 5 * 104
    1 <= arr1[i], arr2[i] <= 108
*/
class Solution {
public:
    int longestSubstrLength = 0;
    void findSubstr(string str1, string str2){
        int currentSubstrLength = 0;
        int i=0, j=0;
        while(i<str1.size() && j<str2.size()){
            if(str1[i]==str2[j]){
                currentSubstrLength++;
                i++;
                j++;
            }else{
                // longestSubstrLength = max(longestSubstrLength, currentSubstrLength);
                // i++;
                // //restarting from start of second string
                // j=0;
                // //resetting current substring length
                // currentSubstrLength = 0;

                //Skipping above logic as we need only those substring that starts from the leftmost character
                break;
            }
        }
        //final check
        longestSubstrLength = max(longestSubstrLength, currentSubstrLength);
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        //accessing each of the integers present in arr1 and arr2
        for(int i=0;i<arr1.size();i++){
            for(int j=0;j<arr2.size();j++){
                findSubstr(to_string(arr1[i]), to_string(arr2[j]));
            }
        }
        return longestSubstrLength;
    }
};


//---------- Approach 2 ----------//
/*
-> Optimised Approach
-> Using hashset
-> Put all the possible prefixes of each element in arr1 into a HashSet.
-> For all the possible prefixes of each element in arr2, check if it exists in the HashSet.
TC: O((m+n)*k^2) | m -> arr1 length, n -> arr2 length, k -> avg size of digit
SC: O(m*k^2) | m -> arr1 size, k -> maximum number of digits in any number in either array
*/
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        //initialising a hashset
        unordered_set<string> st;

        //inserting all the possible substring for each element in arr1 in the hashset
        for(int i=0;i<arr1.size();i++){
            string num = to_string(arr1[i]);
            //checking and inserting non-empty prefixes (starting from length=1).
            for(int j=1;j<=num.size();j++){
                st.insert(num.substr(0, j));
            }
        }

        //check for all the possible substring for each element in arr2, if its already present in the hashset or not
        //if already present, find length and maintain the longest one
        int currentSubstrLength = 0;
        int maxSubstrLength = 0;

        for(int i=0;i<arr2.size();i++){
            string num = to_string(arr2[i]);
            //checking and inserting non-empty prefixes (starting from length=1).
            for(int j=1;j<=num.size();j++){
                if(st.count(num.substr(0, j))!=0){
                    currentSubstrLength = j;
                    maxSubstrLength = max(maxSubstrLength, currentSubstrLength);
                }else{
                    break;
                }
            }
        }
        return maxSubstrLength;
    }
};
