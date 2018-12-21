#include<stdio.h>
#include<algorithm>
#include<vector>
#define max_size 1007
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
int init(int n){
    for(int i=0;i<=n;i++){
        points[i].clear();
    }
}
int inp1[max_size];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        init(n);
        for(int i=1;i<=n;i++){
            scanf("%d",inp1+i);
        }
        for(int i=1;i<=m;i++){
            int temp;
            scanf("%d",&temp);
            for(int j=1;j<=n;j++){
                if(temp%inp1[j]==0){
                    points[j].push_back(i);
                }
            }
        }
        printf("%d\n",maxmatch(n,m));
    }
    return 0;
}
