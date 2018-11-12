#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[100007];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int pos=0;
        for(int i=1;i<=n;i++){
            int temp;
            scanf("%d",&temp);
            if(temp>dp[pos]){
                dp[++pos]=temp;
            }
            else{
                dp[lower_bound(dp+1,dp+pos+1,temp)-dp]=temp;
            }
        }
        printf("%d\n",pos);
    }
    return 0;
}
