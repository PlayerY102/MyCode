#include<stdio.h>
#include<algorithm>
#define max_size 1007
using namespace std;
long long dp[max_size][max_size];
int flag[max_size][max_size];
int n,m;
void init(int x,int y){
    flag[x][y]=-1;
    flag[x-1][y-2]=-1;
    flag[x-1][y+2]=-1;
    flag[x-2][y-1]=-1;
    flag[x-2][y+1]=-1;
    flag[x+1][y-2]=-1;
    flag[x+1][y+2]=-1;
    flag[x+2][y-1]=-1;
    flag[x+2][y+1]=-1;
    
}
int main()
{
    scanf("%d%d",&n,&m);
    n+=2;
    m+=2;
    int temp_x,temp_y;
    scanf("%d%d",&temp_x,&temp_y);
    temp_x+=2;
    temp_y+=2;
    init(temp_x,temp_y);
    dp[2][2]=1;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp[i][j]+=dp[i-1][j]+dp[i][j-1];
            if(flag[i][j]){
                dp[i][j]=0;
            }
        }
    }
    printf("%lld\n",dp[n][m]);
    system("pause");
    return 0;
}
