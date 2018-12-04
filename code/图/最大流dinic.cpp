#include<stdio.h>
#include<algorithm>
#include<memory.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define maxN 10007
vector<int>points[maxN];
int edge_w[maxN*2];
int edge_to[maxN*2];
int s,t;
int point_depth[maxN];
bool bfs(){
    memset(point_depth,0,sizeof(point_depth));
    queue<int> Q;
    Q.push(s);
    point_depth[s]=1;
    while(!Q.empty()){
        int temp=Q.front();
        Q.pop();
        for(int i=0;i<points[temp].size();i++){
            int edge_num=points[temp][i];
            int next_point=edge_to[edge_num];
            if(edge_w[edge_num]>0&&point_depth[next_point]==0){
                Q.push(next_point);
                point_depth[next_point]=point_depth[temp]+1;
            }
        }
    }
    return point_depth[t]!=0;
}
int dfs(int u,int dist){
    if(u==t){
        return dist;
    }
    for(int i=0;i<points[u].size();i++){
        int edge_num=points[u][i];
        int next_point=edge_to[edge_num];
        if(point_depth[next_point]==point_depth[u]+1 && edge_w[edge_num]>0){
            int di=dfs(next_point,min(edge_w[edge_num],dist));
            if(di>0){
                edge_w[edge_num]-=di;
                edge_w[edge_num^1]+=di;
                return di;
            }
        }
    }
    return 0;
}
int dinic(){
    int ans=0;
    int INF=(unsigned)-1>>1;
    while(bfs()){
        while(int n=dfs(s,INF)){
            ans+=n;
        }
    }
    return ans;
}
int edge_now=0;
void insert_edge(int from,int to,int w){
    points[from].push_back(edge_now);
    points[to].push_back(edge_now^1);
    edge_to[edge_now]=to;
    edge_w[edge_now]=w;
    edge_to[edge_now^1]=from;
    edge_w[edge_now^1]=0;
    edge_now+=2;
}