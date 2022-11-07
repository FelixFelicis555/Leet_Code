class Solution {
public:
    vector<int>p;
    bool canEat(int h,int k)
    {
      long long int res=0;
        for(auto a:p)
        {
            res+=((a/k)+((a%k==0)?0 :1));
        }
     return res<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int n=piles.size();
        for(auto x:piles)
            p.push_back(x);
        int low=1,high=1e9;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(canEat(h,mid))
            {
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return low;
    }
};