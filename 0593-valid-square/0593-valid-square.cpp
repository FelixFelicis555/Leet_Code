class Solution {
public:
    long long int dist(vector<int>&p1,vector<int>&p2)
    {
        return pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2);
    }
    bool check(vector<int>&p1,vector<int>&p2,vector<int>&p3,vector<int>&p4)
    {
        return dist(p1,p2)>0 && dist(p1,p2)==dist(p2,p3) && dist(p2,p3)==dist(p3,p4) && dist(p3,p4)==dist(p4,p1) && dist(p1,p3)>0 && dist(p1,p3)==dist(p2,p4);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
       return check(p1,p2,p3,p4) || check(p1,p3,p2,p4) || check(p1,p2,p4,p3);  
    }
};