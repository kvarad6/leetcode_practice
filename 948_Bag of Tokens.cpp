class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //sort the tokens
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int ans = 0;
        int i = 0;
        int j = tokens.size()-1;

        while(i<=j){
            //if power is more than tokens, can use to gain 1 score
            if(tokens[i]<=power){
                score += 1;
                //update final score (ans)
                if(ans<=score){
                    ans = score;
                }
                //update power after gaining score
                power -= tokens[i];
                i++;
            }
            //else if you do not have much power, spend score to get highest token and update power
            else if(score>0){
                power += tokens[j];
                //reduce score by 1
                score -= 1;
                j--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
