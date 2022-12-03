class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
         int t[n][6][16]; 
       memset(t,0,sizeof(t));
        
       for(int i=0;i<6;i++)
           t[0][i][1]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<6;j++){
                for(int k=0;k<6;k++){
                    if(k==j)
                        continue;
                    for(int m=1;m<=rollMax[k];m++){
                        t[i][j][1]=(t[i][j][1]+t[i-1][k][m])%1000000007;
                    }
                   
                    
                }
                 for(int m=2;m<=rollMax[j];m++){
                        t[i][j][m]=(t[i-1][j][m-1])%1000000007;
                    }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<6;i++){
            for(int j=1;j<=rollMax[i];j++){
                ans=(ans+t[n-1][i][j])%1000000007;
            }
        }
        return ans;
    }
};