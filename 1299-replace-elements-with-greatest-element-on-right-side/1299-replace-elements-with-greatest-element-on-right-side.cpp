class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxFromRight=-1;
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            int temp=maxFromRight;
            if(arr[i]>maxFromRight)
            {
                maxFromRight=arr[i];
            }
            arr[i]=temp;
        }
        return arr;
    }
};