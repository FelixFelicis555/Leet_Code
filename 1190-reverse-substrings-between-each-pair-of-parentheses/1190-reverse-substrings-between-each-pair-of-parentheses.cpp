class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        queue<char> q;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || isalpha(s[i]))
                st.push(s[i]);
            else{
                while(!st.empty() && st.top()!='('){
                    q.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!q.empty()){
                    st.push(q.front());
                    q.pop();
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};