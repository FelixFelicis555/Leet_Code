class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int>hm;
        int n=emails.size();
        for(int i=0;i<n;i++)
        {
            int pos=emails[i].find('@');
            string id=emails[i].substr(0,pos);
            string domain=emails[i].substr(pos);
            if(id.find('+')!=string::npos)
            {
                pos=id.find('+');
                id=id.substr(0,pos);
            }
            id.erase(remove(id.begin(),id.end(),'.'),id.end());
            string email=id+domain;
            hm[email]++;
        }
        return hm.size();
        
    }
};