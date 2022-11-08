class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int vf=veganFriendly;
        int mp=maxPrice;
        int md=maxDistance;
        vector<vector<int>>R(restaurants);
        vector<pair<int,int>>v;
        for(auto a :R)
        {
            if(((vf==1 && a[2]==1)||(vf==0))&& a[3]<=mp && a[4]<=md)
            {
                v.push_back({a[1],a[0]});
            }
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<int>ans;
        for(auto a:v)
        {
            ans.push_back(a.second);
        }
        return ans;
    }
};