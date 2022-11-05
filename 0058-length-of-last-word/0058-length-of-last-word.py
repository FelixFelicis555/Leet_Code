class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        l=list(s.split())
        res=l[-1]
        return len(res)