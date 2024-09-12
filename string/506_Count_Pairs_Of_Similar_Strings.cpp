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
//Pending | Using bitmask 
