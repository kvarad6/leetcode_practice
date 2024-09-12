//----------- Approach 1 ----------//
//Using unordered_set
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        //transverse the allowed string and in the set
        for(int i=0;i<allowed.size();i++){
            st.insert(allowed[i]);
        }

        int count = 0;
        
        //transverse the words array
        for(int i=0;i<words.size();i++){
            //update the flag each time you start with the new string
            bool status = true;
            for(int j=0;j<words[i].size();j++){
                if(st.find(words[i][j])==st.end()){
                    status=false;
                    break;
                }
            }
            if(status==true){
                count++;
            }
        }
        return count;
    }
};

//----------- Approach 2 ----------//
// Pending : Using bit manupulation
