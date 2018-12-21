#include<stdio.h>
#include<algorithm>
#define max_size 10007
using namespace std;
int inp1[max_size];
int inp2[max_size];
short int dp[max_size];
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
        for(int j=0;j<=m;j++){
                dp[j]=0;
        }
        for(int i=1;i<=n;i++){
            short int temp=0;
            for(int j=1;j<=m;j++){
                if(inp1[i]==inp2[j]){
                    dp[j]=temp+1;
                }
                else if(inp1[i]>inp2[j]){
                    temp=max(temp,dp[j]);
                } 
            }
        }
        short int ans=0;
        for(int j=1;j<=m;j++){
            ans=max(ans,dp[j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
