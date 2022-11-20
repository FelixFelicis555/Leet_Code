class Solution {
public:
    int calculate(string s) {
       int n=s.size(),res=0,sign=1;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                int num=s[i]-'0';
                while(i+1<n && isdigit(s[i+1]))
                {
                    num=num*10+(s[++i]-'0');
                }
                res+=sign*num;
            }
            else if(s[i]=='+')
                sign=1;
            else if(s[i]=='-')
                sign=-1;
            else if(s[i]=='(')
            {
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                res*=st.top();
                st.pop();
                res+=st.top();
                st.pop();
                
            }
        }
        return res; 
    }
};