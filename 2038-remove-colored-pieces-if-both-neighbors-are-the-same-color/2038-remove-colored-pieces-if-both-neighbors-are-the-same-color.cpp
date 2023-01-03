class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        int a=0,b=0;
        for(int i=1;i+1<colors.size();i++)
        {
            if((colors[i-1]==colors[i]) && (colors[i]==colors[i+1]))
            {
                if(colors[i]=='A')
                    a+=1;
                else
                    b+=1;
            }    
        }
        return a>b;
    }
};