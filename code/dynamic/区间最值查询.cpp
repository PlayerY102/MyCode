#include<stdio.h>
#include<algorithm>
#define M 40
#define max_size 200007
using namespace std;
int inp[max_size];
int mylog[max_size];
int dp[max_size][M];
int findmylog(int n){
    if(n<=1){
        return 0;
    }
    if(!mylog[n]){
        mylog[n]=findmylog(n/2)+1;
    }
    return mylog[n];
}
int rmq(int n){
    for(int i=1;i<=n;i++){
        dp[i][0]=inp[i];
    }
    for(int j=1;j<=findmylog(n);j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
}
int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",inp+i);
        }
        rmq(n);
        scanf("%d",&m);
        while(m--){
            int l,r;
            scanf("%d %d",&l,&r);
            int len=findmylog(r-l+1);
            int outp=max(dp[l][len],dp[r+1-(1<<len)][len]);
            printf("%d\n",outp);
        }
        break;
    }
    return 0;
}
