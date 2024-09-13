//------------ Approach 1 ----------//
//For each string in the words array, create a seperate set
//To store all the sets in a vector
//can directly compare two sets (set1 == set2) and update the pair count 
class Solution {
public:
    int similarPairs(vector<string>& words) {
        //initialising vector of sets
        vector<set<char>> finalSet;

        //for each string, creating a new set, inserting chars in it and finally, inserting the set into the vector of sets
        for(int i=0;i<words.size();i++){
            set<char> tempSet;
            for(int j=0;j<words[i].size();j++){
                tempSet.insert(words[i][j]);
            }
            finalSet.push_back(tempSet);
        }

        int pairCount = 0;
        //comparing the sets and updating the pair count
        for(int i=0;i<finalSet.size();i++){
            for(int j=i+1;j<finalSet.size();j++){
                if(finalSet[i]==finalSet[j]){
                    pairCount++;
                }
            }
        }
        return pairCount;
    }
};

//---------- Approach 2 ----------//
/*
-> Using bitmask 
-> (c - 'a') converts the character to a number (0 for 'a', 1 for 'b', etc.)
-> (1 << (c - 'a')) shifts 1 to the left by this number of positions. This creates a number with only one bit set, corresponding to the current letter.
-> We use the bitwise OR operation (|=) to set this bit in our mask.
*/

class Solution {
public:
    int similarPairs(vector<string>& words) {
        //initialising a vector to store the bitmask of each word
        vector<int> bitmask;

        //calculating the bitmask and storing in the bitmask vector
        for(int i=0;i<words.size();i++){
            int mask = 0;
            for(int j=0;j<words[i].size();j++){
                char c = words[i][j];
                mask |= (1<<c-'a');
            }
            bitmask.push_back(mask);
        }

        int count = 0;
        //compairing bitmasks of each word and updating count
        for(int i=0;i<bitmask.size();i++){
            for(int j=i+1; j<bitmask.size();j++){
                if(bitmask[i]==bitmask[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
