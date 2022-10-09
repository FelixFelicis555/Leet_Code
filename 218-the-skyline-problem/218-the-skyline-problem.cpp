class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
       vector<vector<int>>ans;
        
        int n=buildings.size();
        priority_queue<pair<int,int>>pq;
        int i=0;
        while(i<n || !pq.empty())
        {
            int currx;
            if(pq.empty())
            {
                currx=buildings[i][0];
            }  
            else
            {
                currx=pq.top().second;
            }
            if(i>=n || buildings[i][0]>currx)
            {
                while(!pq.empty() && pq.top().second<=currx)
                {
                    pq.pop();
                }    
            }
            else
            {
                currx=buildings[i][0];
                while(i<n && buildings[i][0]==currx)
                {
                    pq.push({buildings[i][2],buildings[i][1]});
                    i++;
                }
            }
            int currh;
            if(pq.empty())
                currh=0;
            else
                currh=pq.top().first;
            if(ans.empty() || ans.back()[1]!=currh)
            {
                ans.push_back({currx,currh});
            }
        } 
        return ans;
        
    }
};