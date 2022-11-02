class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n=bank.size();
        unordered_set<string>s;
        for(int i=0;i<n;i++)
            s.insert(bank[i]);
        if(s.find(end)==s.end())
            return -1;
        vector<char>avail={'A','C','G','T'};
        unordered_set<string>vis;
        int ans=0;
        queue<string>q;
        q.push(start);
        vis.insert(start);
        while(!q.empty())
        {
            int k=q.size();
            while(k--)
            {
                string cur=q.front();
                q.pop();
                if(cur==end)
                    return ans;
                for(int i=0;i<8;i++)
                {
                    char ch=cur[i];
                    for(int j=0;j<4;j++)
                    {
                        cur[i]=avail[j];
                        if(s.find(cur)!=s.end())
                        {
                            if(vis.find(cur)==vis.end())
                            {
                                q.push(cur);
                                vis.insert(cur);
                            }
                        }
                    }
                    cur[i]=ch;
                        
                }
    
            }
            ans++;
            
        }
        return -1;
        
    }
};