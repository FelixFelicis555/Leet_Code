class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
       unordered_set<string> s;
        vector<string>dict(dictionary);
        for(string &i: dict)
            s.insert(i);
        vector<string> v;
        string st="";
        sentence+=" ";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]!=' ')
                st+=sentence[i]; 
            else{
                v.push_back(st);
                st="";
            }  
        }
        string ans="";
        for(int i=0;i<v.size();i++){
            string pre="";
            for(int j=1;j<=v[i].size();j++){
                pre=v[i].substr(0,j);
                if(s.find(pre)!=s.end()){
                    break;
                }    
            }
            ans+=pre+" ";
        }
        return ans.substr(0,ans.size()-1); 
    }
};