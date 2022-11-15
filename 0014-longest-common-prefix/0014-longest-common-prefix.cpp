class Solution {
public:
    class Trie{
        public:
        Trie *child[26]; // child pointers
        bool isEnd;
        int count;
        Trie(){
            for(int i=0;i<26;i++)
            {
                child[i]=NULL;
            }    
                isEnd=false;
                count=0;
            
        }
    };
    Trie* root=new Trie();
    void insert(string s)
    {
      Trie*cur=root;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i]-'a';
            if(cur->child[ch]==NULL)
            {
                cur->child[ch]=new Trie();
            }
            cur=cur->child[ch];
            cur->count++;
        }
        cur->isEnd=true;
        
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1)
            return strs[0];
        int c=0;
        for(int i=0;i<n;i++)
        {
            string s=strs[i];
            int v=s.size();
            if(v!=0)
                insert(s);
        }
        string ref=strs[0];
        int sz=ref.size();
        Trie*temp=root;
        string ans;
        for(int i=0;i<sz;i++){
            char ch=ref[i]-'a';
            if(temp->child[ch]!=NULL && temp->child[ch]->count==n)
                ans.push_back(ref[i]);
            else break;
            temp=temp->child[ch];
        }
        return ans;
    }
    
};