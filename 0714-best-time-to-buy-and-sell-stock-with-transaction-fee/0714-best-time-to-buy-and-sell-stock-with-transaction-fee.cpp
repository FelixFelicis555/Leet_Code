class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len=prices.size();
        int buy=0;
       int sell=-prices[0];
        for(int i=1;i<len;i++)
        {
            buy=max(buy,sell+prices[i]-fee);
            sell=max(sell,buy-prices[i]);
        }
        return buy;
    }
};