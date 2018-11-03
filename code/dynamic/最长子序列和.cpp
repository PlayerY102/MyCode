#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int temp=0;
        int dp=0;
        int now;
        for(int i=1;i<=n;i++){
            scanf("%d",&now);
            dp=max(now,dp+now);
            if(dp>temp){
                temp=dp;
            }
        }
        printf("%d\n",temp);
    }
    return 0;
}
