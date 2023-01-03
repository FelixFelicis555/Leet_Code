class Solution {
public:
    int getDis(vector<int>&a,vector<int>&b)
    {
        int dx=a[0]-b[0];
        int dy=a[1]-b[1];
        return dx*dx +dy*dy;
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
    
        map<int,int>m;
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                int d=getDis(points[i],points[j]);
            
                    m[d]+=1;
            
            }       
        for(auto [key,val]:m)
        {
            res+=val*(val-1);
        }
        m.clear();
        
        }
        return res;
    }
};