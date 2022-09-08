class Solution {
public:
    int ret;
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int maxcount = 0;// To keep track of maximum frequency till noq
        vector<int> a(26,0);
        // Size of substring can be computed by using i-j+1
        // Instead of replacing,we would have reduce the frequency of char by one
       // One pointer is to iterate over the length of the string
       // Other pointer is to point to upper_bound of sub-array
       // We can always approach in reverse fashion,instead of performing atmost k    operations,we can make use of it negation property what we do if that doesn't happen
       
        while (i < s.size()) {
            a[s[i]-'A']++;
            maxcount = max(maxcount, a[s[i]-'A']);
            
            while (j <= i && i -j +1 -maxcount > k) {
                a[s[j]-'A']--;
                j++;
            
            }
            ret = max(ret, i - j +1);
            i++;
        }
        return ret;
    }
};