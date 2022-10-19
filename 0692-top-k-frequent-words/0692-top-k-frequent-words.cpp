class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
         map<string,int>m;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            if(m.find(words[i])==m.end())
                m[words[i]]=1;
            else
                m[words[i]]+=1;
        }
        priority_queue<int>pq;
        for(auto it=m.begin();it!=m.end();it++)
        {
            pq.push(it->second);
        }
        vector<string>res;
        while(k>0)
        {
            for(auto it=m.begin();it!=m.end();it++)
            {
                if(pq.top()==it->second)
                {
                    res.push_back(it->first);
                    m.erase(it);
                    break;
                }
            }
            pq.pop();
            k--;
        }
        return res;
    }
};