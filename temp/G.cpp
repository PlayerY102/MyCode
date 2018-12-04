#include<stdio.h>
#include<algorithm>
#include<vector>
#define max_size 10007
using namespace std;
vector<int>points[max_size];
int visit[max_size];
int match[max_size];
bool dfs(int x){
    for(int i=0;i<points[x].size();i++){
        int to=points[x][i];
        if(!visit[to]){
            visit[to]=1;
            if(match[to]==0||dfs(match[to])){
                match[to]=x;
                return true;
            }
        }
    }
    return false;
}
int maxmatch(int n,int m){
    for(int i=0;i<=m;i++){
        match[i]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            visit[j]=0;
        }
        if(dfs(i)){
            ans++;
        }
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            points[i].clear();
        }
        for(int i=1;i<=n;i++){
            int to;
            scanf("%d",&to);
            if(to==0){
                continue;
            }
            points[i].push_back(to);
        }
        for(int i=1;i<=n;i++){
            int from;
            scanf("%d",&from);
            if(from==0){
                continue;
            }
            points[from].push_back(i);
        }
        printf("%d\n",n-maxmatch(n,n));
    }
    return 0;
}
