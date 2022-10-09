class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
      int prev=0;
        int n=pref.size();
     for(int i=0;i<n;i++)
      {
         pref[i]^=prev;
         prev^=pref[i];
      }
        return pref;
    }
};