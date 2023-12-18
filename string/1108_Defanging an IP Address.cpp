class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(int i=0;i<address.length();i++){
            if(address[i]=='.'){
                ans += "[.]";
            }
            else{
                ans += address[i];
            }
        }
        return ans;
    }
};

//Note: The main difference between ' ' (single quotes) and " " (double quotes) is that C++ treats everything in between " " (double quotes) as a string irrespective of the number of characters. Whereas ' ' (single quotes) are used to represent a character which has length always equal to one.
