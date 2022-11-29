class Solution {
public:
    bool isCyclic(vector<vector<int>>& graph, vector<int> &color, int i){
        color[i]=1;
        for(int j=0;j<graph[i].size();j++){
            if(color[graph[i][j]]==1)
                return true;
            if(color[graph[i][j]]==0 && isCyclic(graph, color, graph[i][j]))
                return true;
        }
        color[i]=2;
        return false;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        vector<int>color(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==2 || !isCyclic(graph,color,i))
                ans.push_back(i);
            
        }
        return ans;
    }
};