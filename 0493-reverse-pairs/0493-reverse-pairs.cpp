class Solution {
public:
    
    int merge(vector<int>&nums,int low,int mid,int high)
    {
        int inv_count=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++) // Fixing one element in left-subarray
        {
            while(j<=high && nums[i]> 2LL *nums[j]) // Checking condition
            {
                j++;
            }
             inv_count+=(j-(mid+1));    // These no of pairs possible for that element
        }
        
        // During merge-operation ,we will sort the entire array
        
        vector<int>t;
        int left=low,right=mid+1;
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
                t.push_back(nums[left++]);
            else
                t.push_back(nums[right++]);
        }
        // copy remaining elements into temp vector if there are any in either left-subarray or right subarray
        while(left<=mid)
        {
            t.push_back(nums[left++]);
        }
        while(right<=high)
        {
            t.push_back(nums[right++]);
        }
        
        // copy_back merged elements into original array
        for(int i=low;i<=high;i++)
        {
            nums[i]=t[i-low];
        }
        return inv_count;
    }
    int mergeSort(vector<int>&nums,int low,int high)
    {
        if(low>=high) // Base-case
            return 0;
        int mid=(low+high)/2;  // Divide array into two halves
        int inv=mergeSort(nums,low,mid); // left-subarray
        inv+=mergeSort(nums,mid+1,high); // right-subarray
        inv+=merge(nums,low,mid,high);    // merge-step
        return inv;
    }
    int reversePairs(vector<int>& nums) {
       return mergeSort(nums,0,nums.size()-1); 
    }
};