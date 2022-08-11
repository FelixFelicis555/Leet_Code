class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>pq;
        for(auto &x:stones)
            pq.push(x);
        while(pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a!=b)
            {
                int x=abs(a-b);
                pq.push(x);
            } 
            
        } 
        int v=0;
        if(!pq.empty())
        {
            v=pq.top();
        } 
        return v;
    }
};