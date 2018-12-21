#include<stdio.h>
#include<algorithm>
#define max_size 10007
using namespace std;

int inp[max_size];
short int dp[max_size][max_size];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",inp+i);
        }
        sort(inp,inp+n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                dp[i][j]=2;
            }
        }
        int ans=2;
        for(int j=1;j<n-1;j++){
            int i=j-1;
            int k=j+1;
            while(i>=0&&k<=n-1){
                if(inp[j]-inp[i]>inp[k]-inp[j]){
                    k++;
                }
                else if(inp[j]-inp[i]<inp[k]-inp[j]){
                    i--;
                }
                else{
                    dp[j][k]=dp[i][j]+1;
                    ans=max(ans,(int)dp[j][k]);
                    i--;
                    k++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
