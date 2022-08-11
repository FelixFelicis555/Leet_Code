class Solution {
public:
    vector<int>adj[1001];
    int vis[10001];
    static bool cmp(string a,string b){
        int x=a.size();
        int y=b.size();
        if(x!=y)
            return a.size()<b.size();
        return a<b;
    }
    int dfs(int i){
        if(vis[i])
            return 0;
        vis[i]=1;
        int c=1;
        for(auto x: adj[i]){
            if(!vis[x])
            {
                c=max(c,dfs(x)+1);
            }    
        }
        return c;
    }
    bool isPossible(string a,string b){
        int ind=-1;
        int n=b.size();
        for(int j=0;j<n;j++){
            if(a[j]!=b[j])
            {
                ind=j;
                break;
            }    
        }
        if(ind==n-1){
            if(n>1){
                return true;
            }
            else
                return false;
        }
        for(int j=ind+1;j<n;j++)
        {
            if(a[j-1]!=b[j])
                return false;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        for(int i=0;i<n;i++){
            string a=words[i];
            int v=a.size();
            for(int j=i+1;j<n;j++){
                string b=words[j];
                int w=b.size();
                if(w!=v+1){
                    continue;
                }
                if(isPossible(a,b)){
                    adj[i].push_back(j);
                }
            }
        }
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            ans=max(ans,dfs(i));
        } 
        return ans;
    }
};