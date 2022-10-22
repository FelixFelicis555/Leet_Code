//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fillingBucket(int N) {
        // code here
        int MOD=1e8;
        int f[N+1];
        f[0]=f[1]=1;
        for(int i=2;i<=N;i++)
        f[i]=(f[i-1]+f[i-2])%MOD;
        return f[N];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends