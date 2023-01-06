class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs),end(costs));
        int count=0;
        int n=costs.size();
        for(int i=0;i<n;i++)
        {
            if(costs[i]<=coins)
            {
              count+=1;
                coins-=costs[i];
            }
        }
        return count;
    }
};