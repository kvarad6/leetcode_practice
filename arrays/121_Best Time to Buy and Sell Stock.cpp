//Solution 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for(int i=1;i<n;i++){
            int diff = prices[i] - minPrice;
            maxProfit = max(maxProfit, diff);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};

//Solution 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxProfit = 0;
       int minPrice = INT_MAX;
       int n = prices.size();
       for(int i=0;i<n;i++){
           if(minPrice>prices[i]){
               minPrice = prices[i];
           }
           if(maxProfit < prices[i]-minPrice){
               maxProfit = prices[i] - minPrice;
           }
       }
       return maxProfit;
    }
};

