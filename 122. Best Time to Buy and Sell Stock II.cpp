class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //using normal approach | minPrice, maxProfit, totalProfit
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

        //using peak-valley concept
        //buy at valley, sell at peak

        int i=0, profit=0, buy, sell;
        while(i < prices.size()-1){
            //if curent price of stock is less than next one, buy...
            while(i < prices.size()-1 && prices[i] >= prices[i+1]){
                i++;
            }
            buy = prices[i];

            //if current price of stock is more than next one, sell..
            while(i < prices.size()-1 && prices[i] < prices[i+1]){
                i++;
            }
            sell = prices[i];
            profit += sell - buy;
        }
        return profit;

    }
};
