//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    
    void find(vector<int>&ans,int A,int B,int length,int num)
    {
       if(length-1==0)
       {
           if(A<=num && num<=B)
           ans.push_back(num);
           return;
       }
       int last_digit=num%10;
       if(last_digit==0)
       find(ans,A,B,length-1,num*10+1);
       else if(last_digit==9)
       find(ans,A,B,length-1,num*10+8);
       else
       {
           find(ans,A,B,length-1,num*10+last_digit+1);
           find(ans,A,B,length-1,num*10+last_digit-1);
       }
    }
    
    int steppingNumbers(int n, int m)
    {
        // Code Here
        int res=0;
        int temp,l1=0,l2=0;
        vector<int>ans;
        temp=n;
        while(temp>0)
        {
            temp=temp/10;
            l1+=1;
        }
        if(l1==0)
        ans.push_back(0);
        temp=m;
        while(temp>0)
        {
            temp=temp/10;
            l2+=1;
        }
        for(int i=l1;i<=l2;i++)
        {
            for(int j=1;j<10;j++)
            {
                if(i!=0)
                find(ans,n,m,i,j);
            }
        }
        res=ans.size();
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends