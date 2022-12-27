class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>rem;
        int n=rocks.size();
        for(int i=0;i<n;i++)
        {
            rem.push_back(capacity[i]-rocks[i]);
        }
        sort(begin(rem),end(rem));
        int full_bags=0;
        for(int i=0;i<n;i++)
        {
            if(additionalRocks>=rem[i])
            {
                full_bags++;
                additionalRocks-=rem[i];
            }
            else
                break;
        }
        return full_bags;
    }
};