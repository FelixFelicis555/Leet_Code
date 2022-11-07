class Solution {
public:
    bool check(vector<int>&bloomDay,int m,int k,int day )
{
    int bouq=0;
        int flowers=0;
        for(auto x:bloomDay)
        {
            if(day>=x)
                flowers++;
            else
                flowers=0;
            if(flowers==k)
            {
                bouq++;
                flowers=0;
            }
        }
        return bouq>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long res=m*1LL*k;
        if(res>n)
            return -1;
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        int left=*min_element(bloomDay.begin(),bloomDay.end());
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(check(bloomDay,m,k,mid))
            {
                right=mid;
            }
            else
                left=mid+1;
        }
        return left;
    }
};