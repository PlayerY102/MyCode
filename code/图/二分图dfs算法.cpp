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
int init(int n){
    for(int i=0;i<=n;i++){
        points[i].clear();
    }
}