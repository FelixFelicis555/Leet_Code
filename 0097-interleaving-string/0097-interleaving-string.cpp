class Solution {
public:
    int n,m,sz;
    bool isInterleave(string s1, string s2, string s3) {
         n=s1.size();
        m=s2.size();
        sz=s3.size();
        if(n+m!=sz)
            return false;
    
        int i=0,j=0;
        queue<pair<int,int>>q; // s1 index,s2 index
        q.push({0,0});
        int vis[n+1][m+1];
        memset(vis,false,sizeof(vis));
        vis[0][0]=true;
        int ind=0; // This is pointing to string s3
        while(!q.empty())
        {
            int k=q.size();
            bool check=false;
            while(k--)
            {
                int in1=q.front().first;
                int in2=q.front().second;
                q.pop();
                if(ind==sz && in1>=n && in2>=m )
                    return true;
                if(s3[ind]==s1[in1] && !vis[in1+1][in2])
                {
                    check=true;
                    q.push({in1+1,in2});
                    vis[in1+1][in2]=true;
                }
                if(s3[ind]==s2[in2] && !vis[in1][in2+1])
                {
                    check=true;
                    q.push({in1,in2+1});
                    vis[in1][in2+1]=true;
                }
            }
            ind++;
            if(!check)
                return false;
        }
        return true;
    }
};