class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
 
        for(char c: s){
            //finding ascii value -> converting that ascii value to string -> appending it in num string
            num+= to_string(c-'a'+1);
        }
        int sum = 0;
        for(int i=0;i<k;i++){
        sum=0;
        for(char digit: num){
            //to convert char to int | ASCII of the digit - ASCII of 0 (48)
            sum+= digit-'0';
        }
        num = to_string(sum);
        }
    
    return sum;
    }
};
