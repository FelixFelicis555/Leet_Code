class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
       vector<int>n1(nums1),n2(nums2);
        long long res=0,sum=0;
        vector<int>id(n1.size());
        iota(begin(id),end(id),0);
        sort(begin(id),end(id),[&](int i,int j){
            return n1[i]>n1[j];
        });
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      for (int i : id) {
        sum += n1[i];
        pq.push({ n2[i], n1[i] });
        if (pq.size() >= k) {
            res = max(res, pq.top().first * sum);
            sum -= pq.top().second;
            pq.pop();
        }
    }
    return res;
    }
};