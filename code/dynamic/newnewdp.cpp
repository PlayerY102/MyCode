#include<stdio.h>
#include<memory.h>
#define max_size 50007
#define mod 1000007
int dp[max_size][350];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int outp=0;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<350;i++){
            for(int j=0;j<=n;j++){
                if(j-i>=0){
                    dp[j][i]=(dp[j-i][i-1]+dp[j-i][i])%mod;
                }
            }
            outp=(outp+dp[n][i])%mod;
        }
        printf("%d\n",outp);
    }
    return 0;
}
