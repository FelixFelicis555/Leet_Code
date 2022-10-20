val = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
rom = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
class Solution:
    def intToRoman(self, num: int) -> str:
        ans = ""
        for i in range(13):
            while num >= val[i]:
                ans += rom[i]
                num -= val[i]
        return ans
        