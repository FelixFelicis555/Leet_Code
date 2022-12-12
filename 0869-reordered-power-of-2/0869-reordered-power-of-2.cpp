class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int N=n;
        string s=to_string(N);
        sort(s.begin(),s.end());
        do{
            if(s[0]!='0'){
                int k=stoi(s);
            if(k>0 && (k&(k-1))==0)
                return true;
            }
            
        }
        while(next_permutation(s.begin(), s.end()));
        return false;  
    }
};