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
        int v_sum=0;
        int w_sum=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&weight[i],&value[i]);
            v_sum+=value[i];
            w_sum+=weight[i];
        }
        dp[v_sum]=w_sum;
        for(int i=0;i<n;i++){
            for(int j=value[i];j<=v_sum;j++){
                dp[j-value[i]]=min(dp[j-value[i]],dp[j]-weight[i]);
            }
        }
        for(int i=v_sum;i>=0;i--){
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