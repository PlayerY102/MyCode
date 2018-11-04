#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        long long temp=0;
        long long dp=0;
        long long now;
        for(int i=1;i<=n;i++){
            scanf("%lld",&now);
            dp=max(now,dp+now);
            if(dp>temp){
                temp=dp;
            }
        }
        printf("%lld\n",temp);
    }
    return 0;
}
