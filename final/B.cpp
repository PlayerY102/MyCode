#include<stdio.h>
#include<algorithm>
using namespace std;
int inp[100007];
int dp[100007];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",inp+i);
        }
        if(n==1){
            printf("%d\n",inp[n]);
            continue;
        }
        dp[1]=inp[1];
        for(int i=2;i<=n-1;i++){
            dp[i]=max(dp[i-1],dp[i-2]+inp[i]);
        }
        int temp1=dp[n-1];
        inp[1]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+inp[i]);
        }
        printf("%d\n",max(temp1,dp[n]));
    }
    return 0;
}
