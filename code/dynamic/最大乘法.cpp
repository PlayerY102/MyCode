#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char inp[20];
long long dp[20][20];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",inp);
        int len=strlen(inp);
        dp[0][0]=inp[0]-'0';
        for(int i=1;i<len;i++){
            dp[i][0]=dp[i-1][0]*10+inp[i]-'0';
        }
        for(int num=1;num<=n;num++){
            for(int i=num;i<len;i++){
                dp[i][num]=0;
                for(int j=0;j<i;j++){
                    long long next=0;
                    for(int temp=j+1;temp<=i;temp++){
                        next=next*10+inp[temp]-'0';
                    }
                    dp[i][num]=max(dp[i][num],dp[j][num-1]*next);
                }
            }
        }
        printf("%lld\n",dp[len-1][n]);
    }
    return 0;
}
