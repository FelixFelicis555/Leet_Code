class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       unordered_map<int,int>m;
       queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            if(m[v]==0)
            {
                m[v]++;
                for(int u:rooms[v])
                    q.push(u);
            }
        }
        return m.size()==rooms.size();
    }
};