//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int>ans;
		int n=N;
		for(int k=0;k<n;k++)
		{
		    int r=0,c=k;
		    while(c>=0)
		    {
		      ans.push_back(A[r][c]);
		      r++;
		      c--;
		    }
		}
		for(int j=1;j<n;j++)
		{
		    int c=n-1,r=j;
		    while(r<n)
		    {
		        ans.push_back(A[r][c]);
		        r++;
		        c--;
		    }
		}
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends