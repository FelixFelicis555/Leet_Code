//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        vector<int>ans;
        if(R==0)
        return ans;
        vector<vector<bool>>seen(R,vector<bool>(C,false));
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        int x=0,y=0,di=0;
        for(int i=0;i<R*C;i++)
        {
            ans.push_back(a[x][y]);
            seen[x][y]=true;
            int newX=x+dr[di];
            int newY=y+dc[di];
            if(newX>=0 && newX<R && newY>=0 && newY<C && !seen[newX][newY])
            {
                x=newX;
                y=newY;
            }
            else
            {
                di=(di+1)%4;
                x+=dr[di];
                y+=dc[di];
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends