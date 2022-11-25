class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        int m=left,n=right;
       for(int bit=30;bit>=0;bit--)
       {
           if((m & (1<<bit))!=(n & (1<<bit)))
               break;
           else
           {
               ans|=(m &(1<<bit));
           }
       }
        return ans;
    }
};