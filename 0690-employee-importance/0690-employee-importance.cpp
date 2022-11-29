/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
       queue<Employee*>q;
        unordered_map<int,Employee*>m;
        int ans=0;
        for(auto i:employees)
            m[i->id]=i;
        q.push(m[id]);
        while(!q.empty())
        {
            Employee* e=q.front();
            q.pop();
            ans+=e->importance;
            for(int s:e->subordinates)
                q.push(m[s]);
            
        }
        return ans;
    }
};