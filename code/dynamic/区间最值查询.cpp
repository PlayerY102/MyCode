#include<stdio.h>
#include<algorithm>
#define M 25
#define max_size 1007
using namespace std;
int inp[max_size];
int log[max_size];
int dp[max_size][M];
int findlog(int n){
    if(n<=1){
        return 0;
    }
    if(!log[n]){
        log[n]=findlog(n/2)+1;
    }
    return log[n];
}
int rmq(int n){
    for(int i=1;i<=n;i++){
        dp[i][0]=inp[i];
    }
    for(int j=1;j<=findlog(n);j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",inp+i);
        }
        rmq(n);
        while(m--){
            int l,r;
            scanf("%d %d",&l,&r);
            int len=findlog(r-l+1);
            int outp=max(dp[l][len],dp[r+1-(1<<len)][len]);
            printf("%d\n",outp);
        }
    }
    return 0;
}
