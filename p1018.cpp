#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char inp[107];
long long dp[107][107];
long long trans(int st,int ed){
    long long temp=0;
    for(int i=st;i<=ed;i++){
        temp=temp*10+inp[i]-'0';
    }
    return temp;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",inp);
    for(int i=0;i<n;i++){
        dp[i][0]=trans(0,i);
    }
    for(int num=1;num<=k;num++){
        for(int i=num;i<n;i++){
            for(int st=num-1;st<i;st++){
                dp[i][num]=max(dp[i][num],dp[st][num-1]*trans(st+1,i));
            }
        }
    }
    printf("%lld\n",dp[n-1][k]);
    system("pause");
    return 0;
}
