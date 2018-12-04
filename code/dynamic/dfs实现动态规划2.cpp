#include<stdio.h>
#include<algorithm>
#define max_size 100000
using namespace std;
int left[max_size];
int right[max_size];
int ans;
int dfs(int x){
    if(x==0){
        return 0;
    }
    int l=dfs(left[x]);
    int r=dfs(right[x]);
    ans=max(ans,l+r+1);
    return max(l,r)+1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",left+i,right+i);
    }
    dfs(1);
    printf("%d\n",ans-1);
    return 0;
}
