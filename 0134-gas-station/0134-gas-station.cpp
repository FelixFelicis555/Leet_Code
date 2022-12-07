class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int n=gas.size();
        int total_fuel=0,total_cost=0;
        int current=0,start=0;
        for(int i=0;i<n;i++)
        {
            total_fuel+=gas[i];
            total_cost+=cost[i];
        }
        if(total_fuel<total_cost)
            return -1;
        for(int i=0;i<n;i++)
        {
            current+=(gas[i]-cost[i]);
            if(current<0)
            {
                start=i+1;
                current=0;
            }
        }
        return start;
    }
};