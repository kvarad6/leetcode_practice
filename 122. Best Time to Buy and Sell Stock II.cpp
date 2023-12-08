class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        int totalProfit = 0;

        for(int i=0;i<prices.size();i++){
            if(minPrice>prices[i]){
                minPrice = prices[i];
            }

            if(maxProfit<prices[i]-minPrice){
                maxProfit = prices[i]-minPrice;
                totalProfit += maxProfit;
                maxProfit = 0;
                minPrice = prices[i];
            }
        }
        return totalProfit;
    }
};
