class Solution {
public:
    set<string> vis;
    queue<string> q;
    int openLock(vector<string>& deadends, string target) {
        for(int i=0;i<deadends.size();i++)
            vis.insert(deadends[i]);
        if(vis.find("0000")!=vis.end())
            return -1;
        string s="0000";
        q.push(s);
        int d=0;
        while(!q.empty()){
           int k=q.size();
           for(int j=0;j<k;j++){
                string curr=q.front();
                q.pop();
                if(curr==target)
                    return d;
                for(int i=0;i<4;i++){
                    char c=curr[i];
                    if(c!='9')
                        curr[i]=c+1;
                    else
                        curr[i]='0';
                    if(vis.find(curr)==vis.end()){
                        q.push(curr);
                        vis.insert(curr);
                    }
                    if(c!='0')
                        curr[i]=c-1;
                    else
                        curr[i]='9';
                    if(vis.find(curr)==vis.end()){
                        q.push(curr);
                        vis.insert(curr);
                    }
                    curr[i]=c;
               }
                 
            }
            d++;
            
        }
        return -1;
    }
};