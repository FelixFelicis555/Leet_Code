class Solution {
public:
    int numberOfSteps(int num) {
        int ans=0;
        while(num>0)
        {
            if(num%2==1)
            {
                num--;
                ans++;
            }
            else
            {
                num/=2;
                ans++;
            }    
        }
        return ans;
    }
};