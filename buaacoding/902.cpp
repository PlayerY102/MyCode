#include<stdio.h>
#include<string.h>
#define mod 1000007
int dp[2][50007];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        int cur=0;
        int ans=0;
        for(int i=1;i<350;i++){
            cur=cur^1;
            for(int j=0;j<=n;j++){
                if(j-i>=0)
                    dp[cur][j]=(dp[cur][j-i]+dp[cur^1][j-i])%mod;
                else
                    dp[cur][j]=0;
            }
            ans=(ans+dp[cur][n])%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
