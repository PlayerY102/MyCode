#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define max_size 107
using namespace std;
int inp[max_size][max_size];
int dp[max_size][max_size][max_size][max_size];
int main()
{
    int n;
    scanf("%d",&n);
    int x,y,w;
    scanf("%d%d%d",&x,&y,&w);
    while(!(x==0&&y==0&&w==0)){
        inp[x][y]=w;
        scanf("%d%d%d",&x,&y,&w);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int x=1;x<=n;x++){
                for(int y=1;y<=n;y++){
                    dp[i][j][x][y]=max(max(dp[i-1][j][x-1][y],dp[i][j-1][x][y-1]),max(dp[i-1][j][x][y-1],dp[i][j-1][x-1][y]))+inp[i][j]+inp[x][y];
                    if(i==x&&j==y){
                        dp[i][j][x][y]-=inp[x][y];
                    }
                }
            }
        }
    }
    printf("%d\n",dp[n][n][n][n]);
    system("pause");
    return 0;
}
