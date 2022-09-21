class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int minp[k];
        int maxp[k];
        for(int i=0;i<k;i++)
        {
          minp[i]=INT_MAX;
          maxp[i]=0;
        } 
        for(int i=0;i<prices.size();i++)
        {
            for(int j=0;j<k;j++)
            {
                minp[j]=min(minp[j],prices[i]-(j>0? maxp[j-1]:0));
                maxp[j]=max(maxp[j],prices[i]-minp[j]);
            }    
        } 
        return maxp[k-1];
    }
};