#include<stdio.h>
#include<algorithm>
#define max_size 10007
using namespace std;
int inp1[max_size];
int inp2[max_size];
short int dp[2][max_size];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",inp1+i);
        }
        for(int j=1;j<=m;j++){
            scanf("%d",inp2+j);
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=0;
            }
        }
        int cur=0;
        for(int i=1;i<=n;i++){
            short int temp=0;
            cur=cur^1;
            for(int j=1;j<=m;j++){
                if(inp1[i]==inp2[j]){
                    dp[cur][j]=temp+1;
                }
                else{
                    dp[cur][j]=dp[cur^1][j];
                    if(inp1[i]>inp2[j]){
                        temp=max(temp,dp[cur^1][j]);
                    }
                } 
            }
        }
        short int ans=0;
        for(int j=1;j<=m;j++){
            ans=max(ans,dp[cur][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
