class Solution:
    def largestVariance(self, s: str) -> int:
        res=0
        chars=list(set(s))
        for i in range(len(chars)):
            for j in range(i+1,len(chars)):
                c1,c2=chars[i],chars[j]
                diff=0
                max_diff=min_diff=0
                last_c1_diff=last_c2_diff=0
                meet_c1=meet_c2=False
                for c in s:
                    if c==c1:
                        meet_c1=True
                        diff+=1
                        max_diff=max(last_c1_diff,max_diff)
                        last_c1_diff=diff
                    elif c==c2:
                        meet_c2=True
                        diff-=1
                        min_diff=min(last_c2_diff,min_diff)
                        last_c2_diff=diff
                    else:
                        continue
                    if meet_c1 and meet_c2:
                        res=max(res,max(diff-min_diff,max_diff-diff))
        return res                  