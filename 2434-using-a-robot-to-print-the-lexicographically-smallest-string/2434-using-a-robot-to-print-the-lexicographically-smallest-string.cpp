class Solution {
public:
    string robotWithString(string s) {
       string p,t;
      multiset<char>ms(begin(s),end(s));
        for(auto ch:s)
        {
            t+=ch;
            ms.erase(ms.find(ch));
            while(!t.empty() && t.back()<=*(begin(ms)))
            {
                p+=t.back();
                t.pop_back();
            }
        }
        return p+string(rbegin(t),rend(t));
    }
};