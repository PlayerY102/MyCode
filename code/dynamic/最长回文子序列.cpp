#include<stdio.h>
#include<string.h>
#include<algorithm>
#define max_size 507
using namespace std;
int dp[max_size][max_size];
char inp[max_size];
int main()
{
    for(int i=0;i<max_size;i++){
        dp[i][i]=1;
    }
    while(scanf("%s",inp)!=EOF){
        int len=strlen(inp);
        for(int now_len=2;now_len<=len;now_len++){
            int gap=now_len-1;
            for(int i=0;i<len-gap;i++){
                int j=i+gap;
                if(inp[i]==inp[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        printf("%d\n",dp[0][len-1]);
    }
    return 0;
}
