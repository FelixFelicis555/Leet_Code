class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int c=0;
        int rem=0;
        int r=0;
        int ans=0;
        int p_max=-1;
        for(int i=0;i<customers.size()|| (rem);i++)
        {
            r++;
            rem+=i<customers.size()?customers[i]:0;
            if(rem<4)
            {
                c+=rem;
                rem=0;
            }
            else
            {
                c+=4;
                rem-=4;
            }
            int p=c*boardingCost-r*runningCost;
            if(p>p_max)
            {
                p_max=p;
                ans=r;
            }
        }
        
        return p_max<=0?-1:ans;
    }
};