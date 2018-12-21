#include<stdio.h>
#include<algorithm>
#define max_size 10007
using namespace std;
int inp1[max_size];
int inp2[max_size];
int dp[max_size][max_size];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",inp1+i);
        }
        for(int j=0;j<m;j++){
            scanf("%d",inp2+j);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(inp1[i]==inp2[j]){
                    dp[i][j]=1;
                        for(int a=0;a<j;a++){
                        if(inp2[a]<inp2[i]){
                            for(int b=0;b<j;b++){
                                dp[i][j]=max(dp[i][j],dp[a][b]+1);
                            }
                        }
                    }
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
