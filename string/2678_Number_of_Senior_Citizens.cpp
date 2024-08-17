//----------- Appraoch 1 -------------//
//Bruite force approach
class Solution {
public:
    int countSeniors(vector<string>& details) {
        string age = "";
        int count = 0;
        for(int i=0;i<details.size();i++){
            for(int j=11; j<13;j++){
                age += details[i][j];
            }
            if(stoi(age)>60){
                count++;
            }
            age = "";
        }
        return count;
    }
};

//--------- Approach 2 ---------//
//pending
