
class Solution {
public:
    string reverseWords(string s) {
        //----------------- Approach 1 ----------------//
        //Using stringstream
        //steps:
        //1. seperate all the words from given string using stringstream and store them in vector
        //2. reverse the vector
        //3. store the words in a new string one by one.

        vector<string> vec;
        string word;

        stringstream str(s);

        // storing separated words in vector
        while (str >> word) 
            vec.push_back(word);
        
        reverse(vec.begin(), vec.end());
        string res;

        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<endl;
            res += vec[i];
            //adding space after the word except for the last word
            if(i!=vec.size()-1){
                res += " ";
            }
        }
        return res;
    }
};
