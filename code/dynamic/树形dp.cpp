#include<stdio.h>
#include<vector>
#include<algorithm>
#define max_size 6007
using namespace std;
int dp[max_size][2];
int visit[max_size];
vector<int>sub[max_size];
int find_root(int n){
    for(int i=0;i<=n;i++){
        visit[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0,size=sub[i].size();j<size;j++){
            visit[sub[i][j]]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            return i;
        }
    }
    return 0;
}
void dfs(int root){
    if(root<=0){
        return;
    }
    for(int i=0,size=sub[root].size();i<size;i++){
        int next=sub[root][i];
        dfs(next);
        dp[root][0]+=max(dp[next][0],dp[next][1]);
        dp[root][1]+=dp[next][0];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&dp[i][1]);
    }
    int l,k;
    while(scanf("%d %d",&l,&k)!=EOF){
        if(l==0 && k==0){
            break;
        }
        sub[k].push_back(l);
    }
    int root=find_root(n);
    dfs(root);
    printf("%d\n",max(dp[root][0],dp[root][1]));
    // system("pause");
    return 0;
}
