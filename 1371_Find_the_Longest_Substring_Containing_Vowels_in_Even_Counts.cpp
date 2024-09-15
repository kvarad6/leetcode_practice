//----------- Approach 1 -----------//
//-> creating an array of vowels -> [0,0,0,0,0] -> indexes represent in the order a,e,i,o,u
class Solution {
public:
    int findTheLongestSubstring(string s) {
        //creating a map to store the pattern and freq of the same
        unordered_map<string, int> mpp;

        //declaring an array to store the state of the vowels
        vector<int> state(5, 0);  //a,e,i,o,u

        //current state in string format, to store it in the map
        string currentState = "00000";

        mpp[currentState] = -1;

        int result = 0;

        //transversing the string s
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                state[0] = (state[0]+1)%2;  //just need to deal with even/odd 
            }else if(s[i]=='e'){
                state[1] = (state[1]+1)%2;
            }else if(s[i]=='i'){
                state[2] = (state[2]+1)%2;
            }else if(s[i]=='o'){
                state[3] = (state[3]+1)%2;
            }else if(s[i]=='u'){
                state[4] = (state[4]+1)%2;
            }

            currentState = "";
            //updating current state
            for(int j=0;j<5;j++){
                currentState += to_string(state[j]);
            }

            //check if currentState is already seen/ covered, update the result, if not, store in the map
            if(mpp.find(currentState)!=mpp.end()){
                result = max(result, i-mpp[currentState]);
            }else{
                mpp[currentState] = i;
            }
        }
        return result;
    }
};

//----------- Approach 2 -----------//
//Using XOR instead of (state+1)%2 as, if we XOR the same number even no. of times, result would be '0', and XOR the same number odd number of times, result would be '1'
//so, instead of state[0] = (state[0]+1)%2 -> state[0] = state[0]^1
//-> creating an array of vowels -> [0,0,0,0,0] -> indexes represent in the order a,e,i,o,u
class Solution {
public:
    int findTheLongestSubstring(string s) {
        //creating a map to store the pattern and freq of the same
        unordered_map<string, int> mpp;

        //declaring an array to store the state of the vowels
        vector<int> state(5, 0);  //a,e,i,o,u

        //current state in string format, to store it in the map
        string currentState = "00000";

        mpp[currentState] = -1;

        int result = 0;

        //transversing the string s
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                state[0] = state[0]^1;  //just need to deal with even/odd 
            }else if(s[i]=='e'){
                state[1] = state[1]^1;
            }else if(s[i]=='i'){
                state[2] = state[2]^1;
            }else if(s[i]=='o'){
                state[3] = state[3]^1;
            }else if(s[i]=='u'){
                state[4] = state[4]^1;
            }

            currentState = "";
            //updating current state
            for(int j=0;j<5;j++){
                currentState += to_string(state[j]);
            }

            //check if currentState is already seen/ covered, update the result, if not, store in the map
            if(mpp.find(currentState)!=mpp.end()){
                result = max(result, i-mpp[currentState]);
            }else{
                mpp[currentState] = i;
            }
        }
        return result;
    }
};

//---------- Appraoch 3 -----------//
//Using bitmask
//TC: O(n)
//SC: O(1)

class Solution {
public:
    int findTheLongestSubstring(string s) {
        //creating a map to store the pattern and freq of the same
        unordered_map<int, int> mpp;

        int mask = 0; //00000

        mpp[mask] = -1;

        int result = 0;

        //transversing the string s
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                mask = mask^(1<<0);  //just need to deal with even/odd 
            }else if(s[i]=='e'){
                mask = mask^(1<<1);
            }else if(s[i]=='i'){
                mask = mask^(1<<2);
            }else if(s[i]=='o'){
                mask = mask^(1<<3);
            }else if(s[i]=='u'){
                mask = mask^(1<<4);
            }


            //check if currentState is already seen/ covered, update the result, if not, store in the map
            if(mpp.find(mask)!=mpp.end()){
                result = max(result, i-mpp[mask]);
            }else{
                mpp[mask] = i;
            }
        }
        return result;
    }
};

