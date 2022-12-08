class Solution {
public:
     struct Node{
        Node* arr[2];
        int val;
    };
    
    Node* root=new Node();
    
    void insert(int n){
        Node* temp=root;
        for(int i=31;i>=0;i--){
            bool bitVal=n & (1<<i);
            if(temp->arr[bitVal]==NULL){
               Node* newNode = new Node();
               temp->arr[bitVal]=newNode; 
            }
            temp=temp->arr[bitVal];
        }
        temp->val=n;
    }
    
    int findMaxXor(int n){
        Node* temp=root;
        for(int i=31;i>=0;i--){
            bool bitVal=n & (1<<i);
            if(temp->arr[!bitVal]!=NULL)
                temp=temp->arr[!bitVal]; 
            else if(temp->arr[bitVal]!=NULL)
                temp=temp->arr[bitVal];
            else
                return INT_MIN;
        }
        return n^temp->val;
    }
    int findMaximumXOR(vector<int>& nums) {
        Node* temp=root;
        int maxXor=INT_MIN;
        int n=nums.size();
        if(n<2)
            return 0;
        insert(nums[0]);
        for(int i=1;i<n;i++){
            maxXor=max(maxXor, findMaxXor(nums[i]));
            insert(nums[i]);
        }
        return maxXor;
    }
};