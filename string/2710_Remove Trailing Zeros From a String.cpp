class Solution {
public:
    string removeTrailingZeros(string num) {
        string ansString="";
        int lastIndex;
        int i;
        for(i=num.length()-1;i>0;i--){
            if(num[i]!='0'){
                lastIndex=i;
                break;
            }
        }
        for(int j=0;j<=lastIndex;j++){
            ansString += num[j];
        }
        //.substr can be used to perform above step.
        // ansString = num.substr(0, i+1);

        return ansString;
    }
};
