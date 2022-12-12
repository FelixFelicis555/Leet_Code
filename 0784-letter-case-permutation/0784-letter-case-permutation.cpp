class Solution {
public:
     void backtrack(int p, vector<string> &ans, string s, string &S){
        if(S.size()==s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=p;i<S.size();i++){
            if(isalpha(S[i])){
                s.push_back(tolower(S[i]));
                backtrack(i+1, ans, s, S);
                s.pop_back();
                s.push_back(toupper(S[i]));
                backtrack(i+1, ans, s, S);
                s.pop_back();
            }
            else{
                s.push_back(S[i]);
                backtrack(i+1, ans, s, S);
                s.pop_back();
            }
        }
    }
    vector<string> letterCasePermutation(string S) {
        string s="";
        vector<string> ans;
        backtrack(0, ans, s, S);
        return ans;
    }
};