#include<stdio.h>
#include<algorithm>
#define max_size 1007
using namespace std;
int attack[max_size];
int live[max_size];
long long live_sum[max_size];
long long attack_sum[max_size];
long long dp[max_size][max_size];
int main()
{
    int n,HP;
    while(scanf("%d%d",&n,&HP)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d%d",attack+i,live+i);
            attack_sum[i]=attack_sum[i-1]+attack[i];
            live_sum[i]=live_sum[i-1]+live[i];
        }
        for(int i=1;i<=n;i++){
            dp[i][i]=(long long)attack[i]*live[i];
        }
        for(int gap=1;gap<n;gap++){
            for(int i=1;i<=n-gap;i++){
                int j=i+gap;
                long long temp=(unsigned long long)-1>>1;
                for(int k=i;k<j;k++){
                    temp=min(temp,dp[i][k]+(live_sum[k]-live_sum[i-1])*(attack_sum[j]-attack_sum[k])+dp[k+1][j]);
                    temp=min(temp,dp[i][k]+(attack_sum[k]-attack_sum[i-1])*(live_sum[j]-live_sum[k])+dp[k+1][j]);
                }
                dp[i][j]=temp;
            }
        }
        if(dp[1][n]>=HP){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}
