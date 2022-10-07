class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int ind=-1;
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr[mid]>x)
            {
                r=mid-1;
            } 
            else
            {
                ind=mid;
                l=mid+1;
            }    
        }
         l=max(ind-k,0);
          r=min(ind+k,n-1);
        while(r-l>=k)
        {
            if(abs(arr[l]-x)<=abs(arr[r]-x))
            {
                r--;
            } 
            else
                l++;
        } 
        vector<int>res;
        for(int i=l;i<=r;i++)
        {
          res.push_back(arr[i]);  
        }
        return res;
    }
};