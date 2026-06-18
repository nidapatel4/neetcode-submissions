class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minPrice=prices[0];
        for(int j=1;j<prices.size();j++){
            if(prices[j-1]<minPrice){
                minPrice=prices[j-1];
            }
            int profit=prices[j]-minPrice;
            maxProfit=max(maxProfit,profit);
        }
        return maxProfit;
    }
};
