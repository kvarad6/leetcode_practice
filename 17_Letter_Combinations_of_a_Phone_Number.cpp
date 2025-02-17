class Solution {
    void solve( vector<string> &ans, string output, int index, string digits, string mapping[]){
        //base case
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        
        int number = digits[index] - '0';
        string value = mapping[number];
        //recursive call for the chars associated with the numbers
        for(int i=0;i<value.length(); i++){
            output.push_back(value[i]);
            solve(ans, output, index+1, digits, mapping);
            //backtrack
            //removing char from output after every recursive call to reach to the empty state
            output.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
      vector<string> ans;
      string output = "";
      int index = 0;
      if(digits.length()==0){
          return ans;
      }
      //creating array to map number to corresponding chars
      string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      solve(ans, output, index, digits, mapping);
      return ans;
    }
};
