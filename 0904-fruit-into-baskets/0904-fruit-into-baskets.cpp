class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int n=fruits.size();
        unordered_map<int,int>m;
        int j=0;
        int i=0;
        for( i=0;i<n;i++)
        {
            m[fruits[i]]++;
            if(m.size()>2)
            {
               m[fruits[j]]--;
                if(m[fruits[j]]==0)
                    m.erase(fruits[j]);
                j++;
            }
            
        }
        return (i-j);
    }
};