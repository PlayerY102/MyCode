#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define max_size 57
using namespace std;
int inp[max_size][max_size];
int dp[max_size][max_size][max_size][max_size];
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&inp[i][j]);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int x=1;x<=m;x++){
                for(int y=1;y<=n;y++){
                    dp[i][j][x][y]=max(max(dp[i-1][j][x-1][y],dp[i][j-1][x][y-1]),max(dp[i-1][j][x][y-1],dp[i][j-1][x-1][y]));
                    if(i==x&&j==y){
                        dp[i][j][x][y]+=inp[i][j];
                    }
                    else{
                        dp[i][j][x][y]+=inp[i][j]+inp[x][y];
                    }
                }
            }
        }
    }
    printf("%d\n",dp[m][n][m][n]);
    system("pause");
    return 0;
}
