#include<stdio.h>
#include<algorithm>
#define max_size 507
using namespace std;
int inp[max_size][max_size];
int dp[max_size][max_size];
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
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+inp[i][j];
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
