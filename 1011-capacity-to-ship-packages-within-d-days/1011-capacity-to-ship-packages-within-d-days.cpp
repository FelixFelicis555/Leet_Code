class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<high)
        {
            int d=1;
            int wt=0;
            int mid=(low+high)/2;
            for(auto w:weights)
            {
                if(wt+w>mid)
                {
                    d+=1;
                    wt=0;
                }
                wt+=w;
            }
            if(d<=days)
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};