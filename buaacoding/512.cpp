#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int swit[17][17];
int dp[17][2];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int current=0;
        memset(swit,0,sizeof(swit));
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=m;j++){
            current=current^1;
            for(int i=1;i<=n;i++){
                int temp;
                scanf("%d",&temp);
                dp[i][current]=(unsigned)-1>>1;
                for(int x=1;x<=n;x++){
                    dp[i][current]=min(dp[i][current],dp[x][current^1]+swit[x][i]);
                }
                dp[i][current]+=temp;
            }
            if(j<m){
                for(int x=1;x<=n;x++){
                    for(int y=1;y<=n;y++){
                        scanf("%d",&swit[x][y]);
                    }
                }
            }
            
        }
        int ans=(unsigned)-1>>1;
        for(int i=1;i<=n;i++){
            ans=min(ans,dp[i][current]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
