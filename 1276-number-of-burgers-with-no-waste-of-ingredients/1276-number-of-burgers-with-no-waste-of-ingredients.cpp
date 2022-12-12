class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int total=cheeseSlices;
        int l=0,r=total;
        while(l<=r){
            int mid=l+(r-l)/2;
            int curr=mid*4+(total-mid)*2;
            if(curr==tomatoSlices)
                return {mid,total-mid};
            else if(curr<tomatoSlices)
                l=mid+1;
            else
                r=mid-1;
        }
        return {};
    }
};