#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;
#define max_size 10007
int dp[max_size][107];
int dfs(int x,int y){
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    if(y>=10){
        dp[x][y]=dfs(x-1,y-9)+60;
    }
    else{
        dp[x][y]=max(dfs(x-1,y+1)+17,dfs(x-1,y+5));
    }
    return dp[x][y];
}
int half(int m,int s,int t){
    int left=0;
    int right=t;
    int mid=(left+right)/2;
    while(left<=right){
        if(dfs(mid,m)>=s){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
        mid=(right+left)/2;
    }
    return left;
}
int main()
{
    int m,s,t;
    while(scanf("%d %d %d",&m,&s,&t)!=EOF){
        memset(dp,-1,sizeof(dp));
        memset(dp[0],0,sizeof(dp[0]));
        int longest=dfs(t,m);
        if(longest>=s){
            printf("Yes\n");
            printf("%d\n",half(m,s,t));
        }
        else{
            printf("No\n");
            printf("%d\n",longest);
        }
    }
    return 0;
}
