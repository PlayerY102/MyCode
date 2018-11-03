#include<stdio.h>
#include<algorithm>
using namespace std;
int inp[20];
int dp[20];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",inp+i);
    }
    dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(inp[i]<=inp[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
            else{
                dp[i]=max(dp[i],1);
            }
        }
    }
    printf("%d",dp[n]);
    return 0;
}
