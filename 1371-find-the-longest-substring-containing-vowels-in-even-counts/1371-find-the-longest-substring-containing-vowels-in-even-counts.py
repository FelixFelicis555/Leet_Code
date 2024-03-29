class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        m={'a':1,'e':2,'i':4,'o':8,'u':16}
        seen={0:-1}
        res=cur=0
        for i in range(len(s)):
            if s[i] in m:
                cur^=m.get(s[i])
            if cur in seen:
                res=max(res,i-seen.get(cur))
            else:
                seen[cur]=i
        return res        
        