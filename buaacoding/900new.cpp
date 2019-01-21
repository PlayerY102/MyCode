#include<stdio.h>
#include<algorithm>
#include<string.h>
#define max_size 207
using namespace std;
int inp[max_size][max_size];
int dp[2][max_size][max_size];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&inp[i][j]);
            }
        }
        int cur=0;
        for(int i=1;i<=n;i++){
            cur=cur^1;
            for(int j=1;j<=m;j++){
                for(int x=1;x<=n;x++){
                    int y=i+j-x;
                    dp[cur][j][x]=max(max(dp[cur^1][j][x-1],dp[cur][j-1][x]),max(dp[cur][j-1][x-1],dp[cur^1][j][x]));
                    if(i==x){
                        dp[cur][j][x]+=inp[i][j];
                    }
                    else{
                        dp[cur][j][x]+=inp[i][j]+inp[x][y];
                    }
                }
            }
        }
        printf("%d\n",dp[cur][m][n]);
    }
    return 0;
}