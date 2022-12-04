class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(begin(skill),end(skill));
        int ts=skill.front()+skill.back();
        long long res=0;
        for(int i=0,j=skill.size()-1;i<j;i++,j--)
        {
            if(skill[i]+skill[j]!=ts)
                return -1;
            res+=1LL*skill[i]*skill[j];
        }
        return res;
    }
};