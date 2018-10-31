#include<stdio.h>
#include<memory.h>
#define mod 1000007
int dp[10007][1007];
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i&&j<=m;j++){
                dp[i][j]=(dp[i-1][j-1]+dp[i-j][j])%mod;
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}

