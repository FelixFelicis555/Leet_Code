class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int l=0;
        int n=citations.size();
        int h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(citations[mid]==(n-mid))
                return citations[mid];
            else if(citations[mid]>(n-mid))
                h=mid-1;
            else
                l=mid+1;
        }
        return n-l;
    }
};