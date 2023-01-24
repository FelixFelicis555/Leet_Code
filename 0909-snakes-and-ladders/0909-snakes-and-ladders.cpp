class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int ans=0;
        queue<int>q{{1}};
        vector<bool>vis(1+n*n);
        vector<int>arr(1+n*n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                arr[(n-i-1)*n +(n-i & 1 ? j+1 :n -j)]=board[i][j];
        }
        while(!q.empty())
        {
            ans++;
            for(int sz=q.size();sz>0;sz--)
            {
                int curr=q.front();
                q.pop();
                for(int next=curr+1;next<=min(curr+6,n*n);next++)
                {
                    int dest=arr[next]>0?arr[next]:next;
                    if(dest==n*n)
                        return ans;
                    if(vis[dest])
                        continue;
                    q.push(dest);
                    vis[dest]=true;
                }
            }
        }
        return -1;
    }
};