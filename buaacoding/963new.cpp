#include<stdio.h>
#include<string.h>
#include<algorithm>
#define max_size 100007
using namespace std;
int dp[max_size];
int weight[102];
int value[102];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        int w_sum=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&value[i],&weight[i]);
            w_sum+=weight[i];
        }
        for(int i=0;i<n;i++){
            for(int j=w_sum;j>=weight[i];j--){
                dp[j]=min(dp[j],dp[j-weight[i]]+value[i]);
            }
        }
        for(int i=w_sum;i>=0;i--){
            if(dp[i]<=m){
                printf("%d\n",i);
                break;
            }
            if(i==0){
                printf("0\n",i);
            }
        }
    }
    return 0;
}