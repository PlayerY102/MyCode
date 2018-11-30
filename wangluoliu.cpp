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
int inp[507];
int lis[507];
int flag[507];
int my_lis(int st,int ed){
    memset(lis,0,sizeof(lis));
    int pos=0;
    for(int i=st;i<=ed;i++){
        int now=inp[i];
        if(now>lis[pos]){
            lis[++pos]=now;
        }
        else{
            int*p=lower_bound(lis+1,lis+pos+1,now);
            *p=now;
        }
    }
    return pos;
}
int my_lis2(int con,int st,int ed){
    memset(lis,0,sizeof(lis));
    int pos=0;
    lis[++pos]=con;
    for(int i=st;i<=ed;i++){
        int now=inp[i];
        if(now>lis[pos]){
            lis[++pos]=now;
        }
        else{
            int*p=lower_bound(lis+1,lis+pos+1,now);
            if(p!=lis+1){   
                *p=now;
            }
        }
    }
    return pos;
}
vector<int>set[maxN];
int edge_now=0;
void build(int from,int to,int w){
    points[from].push_back(edge_now);
    points[to].push_back(edge_now^1);
    edge_to[edge_now]=to;
    edge_w[edge_now]=w;
    edge_to[edge_now^1]=from;
    edge_w[edge_now^1]=0;
    edge_now+=2;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",inp+i);
    }
    int LIS_num=my_lis(0,n-1);
    printf("%d\n",LIS_num);
    for(int i=0;i<n;i++){
        flag[i]=my_lis2(inp[i],i+1,n-1);
    }
    for(int i=0;i<n;i++){
        set[flag[i]].push_back(i);
    }
    s=n;
    t=n+1;
    for(int i=0;i<set[LIS_num].size();i++){
        build(s,set[LIS_num][i],1);
    }
    for(int i=0;i<set[1].size();i++){
        build(set[1][i],t,1);
    }
    for(int z=LIS_num;z>=2;z--){
        for(int i=0;i<set[z].size();i++){
            for(int j=0;j<set[z-1].size();j++){
                int from=set[z][i];
                int to=set[z-1][j];
                if(from<to){
                    if(inp[from]<inp[to]){
                        build(from,to,1);
                    }
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     printf("%d ",flag[i]);
    // }
    // printf("\n");
    // for(int i=0;i<=n+1;i++){
    //     for(int j=0;j<points[i].size();j++){
    //         printf("%d ",points[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d\n",dinic());
    for(int i=0;i<=n+1;i++){
        points[i].clear();
    }
    memset(edge_w,0,sizeof(edge_w));
    memset(edge_to,0,sizeof(edge_to));
    for(int i=0;i<set[LIS_num].size();i++){
        build(s,set[LIS_num][i],1);
    }
    for(int i=0;i<set[1].size();i++){
        build(set[1][i],t,1);
    }
    for(int z=LIS_num;z>=2;z--){
        for(int i=0;i<set[z].size();i++){
            for(int j=0;j<set[z-1].size();j++){
                int from=set[z][i];
                int to=set[z-1][j];
                if(from<to){
                    if(inp[from]<inp[to]){
                        build(from,to,1);
                    }
                }
            }
        }
    }
    for(int i=0;i<points[0].size();i++){
        int edge=points[0][i];
        edge_w[edge^1]=(unsigned)-1>>1;
    }
    for(int i=0;i<points[n-1].size();i++){
        int edge=points[n-1][i];
        edge_w[edge]=(unsigned)-1>>1;
    }
    printf("%d\n",dinic());
    system("pause");
    return 0;

}
