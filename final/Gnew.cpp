#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#define max_size 50007
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
struct point{
    int x;
    int y;
};
#define maxN 27
char inp[maxN][maxN];
int dist[maxN][maxN][maxN];
vector<point>out;
vector<point>single;
int n,m;
void mybfs(int i){
    memset(dist[i],0,sizeof(dist[i]));
    queue<point> Q;
    Q.push(out[i]);
    while(!Q.empty()){
        point pre=Q.front();
        Q.pop();
        point temp;
        temp.x=pre.x-1;
        temp.y=pre.y;
        if(temp.x>=0&&inp[temp.x][temp.y]=='.'&&dist[i][temp.x][temp.y]==0){
            dist[i][temp.x][temp.y]=dist[i][pre.x][pre.y]+1;
            Q.push(temp);
        }
        temp.x=pre.x+1;
        temp.y=pre.y;
        if(temp.x<n&&inp[temp.x][temp.y]=='.'&&dist[i][temp.x][temp.y]==0){
            dist[i][temp.x][temp.y]=dist[i][pre.x][pre.y]+1;
            Q.push(temp);
        }
        temp.x=pre.x;
        temp.y=pre.y+1;
        if(temp.y<m&&inp[temp.x][temp.y]=='.'&&dist[i][temp.x][temp.y]==0){
            dist[i][temp.x][temp.y]=dist[i][pre.x][pre.y]+1;
            Q.push(temp);
        }
        temp.x=pre.x;
        temp.y=pre.y-1;
        if(temp.y>=0&&inp[temp.x][temp.y]=='.'&&dist[i][temp.x][temp.y]==0){
            dist[i][temp.x][temp.y]=dist[i][pre.x][pre.y]+1;
            Q.push(temp);
        }
    }
}
bool judge(int mid){
    init(single.size());
    for(int i=0;i<single.size();i++){
        for(int j=0;j<out.size();j++){
            if(dist[j][single[i].x][single[i].y]==0){
                break;
            }
            for(int time=1;time<=mid;time++){
                if(dist[j][single[i].x][single[i].y]<=time){
                    points[i+1].push_back(j*mid+time);
                }
            }
        }
    }
    if(maxmatch(single.size(),out.size()*mid)==single.size()){
        return true;
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        out.clear();
        single.clear();
        memset(inp,0,sizeof(inp));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%s",inp[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(inp[i][j]=='E'){
                    point temp;
                    temp.x=i;
                    temp.y=j;
                    out.push_back(temp);
                }
                else if(inp[i][j]=='.'){
                    point temp;
                    temp.x=i;
                    temp.y=j;
                    single.push_back(temp);
                }
            }
        }
        for(int i=0;i<out.size();i++){
            mybfs(i);
        }
        int flag=0;
        for(int i=0;i<single.size();i++){
            flag=0;
            for(int j=0;j<out.size();j++){
                if(dist[j][single[i].x][single[i].y]){
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                break;
            }
        }
        if(flag==0){
            printf("Oh, poor single dog!\n");
            continue;
        }
        int left=0;
        int right=n*m;
        while(left<=right){
            int mid=(left+right)/2;
            if(judge(mid)){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        printf("%d\n",left);
    }
    return 0;
}
