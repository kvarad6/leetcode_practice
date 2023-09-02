//Simple Method
class Solution {
public:
    string interpret(string command) {
        string ans;
        for(int i=0;i<command.length();i++){
            if(command[i]=='G'){
                ans += "G";
            }
            else if(command[i]=='(' && command[i+1] == ')'){
                ans += "o";
            }
            else if(command[i]=='(' && command[i+1] == 'a'){
                ans += "al";
            }
        }
        return ans;
    }
};

//Using Unordered Map

class Solution {
public:
    string interpret(string command) {
       unordered_map<string, string> mpp;
       mpp = {{"G", "G"}, {"()", "o"}, {"(al)", "al"}};

       string ans="";
       string temp="";
       for(int i=0; i<command.length();i++){
           temp += command[i];
           if(mpp.find(temp)!=mpp.end()){
               ans += mpp[temp];
               temp="";
           }
       }
       return ans;
    }
};
