class Solution {
public:
    bool wordPattern(string p, string s) {
       unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        string temp="";
        int idx=0, n=s.size();
        for(int i=0; i<=n; i++)
        {
            if(s[i]==' ' || i==n)
            {
                if(idx<p.size() && (p2s.find(p[idx]) != p2s.end() || s2p.find(temp) != s2p.end()))
                {
                    if(p2s[p[idx]]!=temp || s2p[temp]!=p[idx]) return false;
                }

                else
                {
                    p2s[p[idx]] = temp;
                    s2p[temp] = p[idx];
                }
                temp="";
                idx++; 
            }
            else
                temp += s[i];
        }

        return idx==p.size(); 
    }
};