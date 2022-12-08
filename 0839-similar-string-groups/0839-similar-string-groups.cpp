class Solution {
public:
    int par[305];
    int size[305];
    int c;
    
    int find(int u){
      if(u == par[u])
        return u;
    
      else
        return par[u]=find(par[u]);
    }

    void combine (int u, int v){
      u = find(u);
      v = find(v);
     
      if(u == v)
        return;
    
      else{   
        c--;
        if(size[u] > size[v]){
            par[v] = u;
            size[u] += size[v];
          }
        
        else{
            par[u] = v;
            size[v] += size[u];
          }
    
      }
    
    }
    

    bool similar(string s, string t){
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                c++;
                if(c>2)
                  return false;
            }
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        c=n;
        for(int i=0;i<n;i++){
            par[i]=i;
            size[i]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(similar(strs[i],strs[j]))
                {
                    combine(i,j);
                }
            }
        }
        return c;
    }
};