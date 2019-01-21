#include<stdio.h>
#include<string.h>
#include<algorithm>
#define max_size 1007
using namespace std;
char inp[max_size];
int dp[max_size][max_size];
int main()
{
    scanf("%s",inp);
    int n=strlen(inp);
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    for(int gap=1;gap<=n-1;gap++){
        for(int i=0;i+gap<n;i++){
            int j=i+gap;
            if(inp[i]==inp[j]){
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    printf("%d\n",n-dp[0][n-1]);
    system("pause");
    return 0;
}
