class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s1=to_string(low);
        string s2=to_string(high);
        int n1=s1.size();
        int n2=s2.size();
        for(int i=n1;i<=n2;i++)
        {
            for(int j=1;j<=10-i;j++)
            {
                int x=0;
                for(int k=j;k<=j-1+i;k++ )
                {
                    x=x*10+k;
                }  
                if(x>=low && x<=high)
                {
                    ans.push_back(x);
                }    
            }    
        } 
        return ans;
    }
};