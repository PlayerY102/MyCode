#include<stdio.h>
#include<algorithm>
#define max_size 27
using namespace std;
const double INF=1e9+7;
double p[max_size];
double q[max_size];
double sum[max_size][max_size];
double dp[max_size][max_size];
int root[max_size][max_size];
void init(int n){
    for(int i=1;i<=n;i++){
        for(int j=i-1;j<=n;j++){
            if(j==i-1){
                sum[i][j]=q[i-1];
                dp[i][j]=q[i-1];
            }
            else{
                sum[i][j]=sum[i][j-1]+p[j]+q[j];
            }
        }
    }
    sum[n+1][n]=q[n];
    dp[n+1][n]=q[n];
}
void obst(int n){
    for(int len=1;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            dp[i][j]=INF;
            for(int r=i;r<=j;r++){
                if(dp[i][j]>dp[i][r-1]+dp[r+1][j]+sum[i][j]){
                    dp[i][j]=dp[i][r-1]+dp[r+1][j]+sum[i][j];
                    root[i][j]=r;
                }
            }
        }
    }
}
void show(int l,int r){
    if(l>r){
        printf("{}");
        return;
    }
    printf("%d",root[l][r]);
    printf("{");
    show(l,root[l][r]-1);
    printf(",");
    show(root[l][r]+1,r);
    printf("}");
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%lf",p+i);
        }
        for(int i=0;i<=n;i++){
            scanf("%lf",q+i);
        }
        init(n);
        obst(n);
        show(1,n);
        printf("%.3lf\n",dp[1][n]);
    }
    return 0;
}
