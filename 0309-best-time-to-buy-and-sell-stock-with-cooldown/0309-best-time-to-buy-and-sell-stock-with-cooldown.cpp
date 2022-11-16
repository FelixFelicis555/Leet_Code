class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1)
            return 0;
        int buy=-prices[0];
        int sell=0;
        int cooldown=0;
        for(int i=1;i<n;i++)
        {
            int prev_buy=buy,prev_sell=sell,prev_cooldown=cooldown;
            buy=max(prev_buy,prev_cooldown-prices[i]);
            sell=max(prev_sell,prices[i]+prev_buy);
            cooldown=max(prev_cooldown,prev_sell);
        }
        return max(sell,cooldown);
    }
};