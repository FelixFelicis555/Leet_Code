class Solution {
public:
    
    /*
    Approach-1: Sorting 
    
     sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];
        
        Approach-2 : Heap
        
        O(nlogn)
        
        Whenever there's need to use sorting,we can try to use heap
        
        Optimal solution: MIn-heap
        TC-O(nlogk)
        SC-O(k)
        
        Whenever we see kth largest,max,the optimal solution is to think of using min-heap
        
        We store only k-elements always
        In min-heap ,top-most element will be min-value
        
        
    
    */
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++)
        {
            if(pq.size()<k)
                pq.push(nums[i]);
            else
            {
                if(pq.top()<nums[i])
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
};