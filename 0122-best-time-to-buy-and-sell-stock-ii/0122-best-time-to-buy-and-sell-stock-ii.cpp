class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // selling price - purchasedPrice < 0 drop purchasePrice = sellingPrice
        // selling price - purchasedPrice > 0 calculate maxProfit (maxProfit < currProfit) maxProfit -> update
        // 
        int bestBuy = prices[0];
        int maxProfit = 0;
        int currProfit = 0;

        for(int i = 1; i < prices.size(); i++){
            int profit = prices[i] - bestBuy;
            if(profit < currProfit){
                bestBuy = prices[i];
                maxProfit += currProfit;
                currProfit = 0;
            }else{
                currProfit = profit;
            }
        }
        return maxProfit + currProfit;
    }
};