class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        if(k>=2):
            return "".join(sorted(s))
        n=len(s)
        best=s
        for i in range(1,n):
            cur=s[i:]+s[:i]
            best=min(cur,best)
        return best