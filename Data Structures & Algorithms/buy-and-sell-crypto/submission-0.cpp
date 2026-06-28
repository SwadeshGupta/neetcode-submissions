class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minprice=prices[0];
        int maxprofit=0;
        for(int i=0;i<n;i++){
            maxprofit=max(maxprofit,prices[i]-minprice);
            minprice=min(minprice,prices[i]);
        }
        return maxprofit;
    }
};
