#include<stdio.h>
#include<algorithm>
#define max_size 207
using namespace std;
int inp[max_size][max_size];
int dp[max_size][max_size][max_size];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&inp[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int x=1;x<=n;x++){
                    int y=i+j-x;
                    dp[i][j][x]=max(max(dp[i-1][j][x-1],dp[i][j-1][x]),max(dp[i][j-1][x-1],dp[i-1][j][x]));
                    if(i==x){
                        dp[i][j][x]+=inp[i][j];
                    }
                    else{
                        dp[i][j][x]+=inp[i][j]+inp[x][y];
                    }
                }
            }
        }
        printf("%d\n",dp[n][m][n]);
    }
    return 0;
}