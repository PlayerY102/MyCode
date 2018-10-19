#include<stdio.h>
#include<stdlib.h>
#define max_size 1007
struct edge{
    int v1,v2;
    int len;
};
struct city{
    int t;
    int c;
    int value;
};
int father[max_size];
struct edge edge[max_size];
struct city city[max_size];
int find_fa(int n){
    if(father[n]!=n){
        father[n]=find_fa(father[n]);
    }
    return father[n];
}
void create(int a,int b,int c,int i){
    edge[i].v1=a;
    edge[i].v2=b;
    edge[i].len=c;
}
void put_value(int t,int c,int i){
    city[i].t=t;
    city[i].c=c;
    city[i].value=-1;
}
int st[max_size];
int st_top=0;
int st_bot=0;
int comp(const void*a,const void*b){
    int x=*(int *)a;
    int y=*(int *)b;
    return city[x].c-city[y].c;
}
void find_min(int x,int y,int m){
    if(x==y){
        return;
    }
    for(int i=0;i<m;i++){
        struct edge* temp=edge+i;
        if(temp->v1!=x&&temp->v2!=x){
            continue;
        }
        if(temp->len>city[x].t){
            continue;
        }
        int to=(x==temp->v1?temp->v2:temp->v1);
        int fx=find_fa(x);
        int fto=find_fa(to);
        if(fx==fto){
            continue;
        }
        father[fto]=fx;
        city[to].value=(city[x].value+city[x].c);
        st[st_bot++]=to;
    }
    if(st_top==st_bot){
        return;
    }
    qsort(st+st_top,st_bot-st_top,sizeof(int),comp);
    find_min(st[st_top++],y,m);
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        int x,y;
        scanf("%d %d",&x,&y);
        for(int i=1;i<=n;i++){
            father[i]=i;
        }
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            create(a,b,c,i);
        }
        for(int i=1;i<=n;i++){
            int t,c;
            scanf("%d %d",&t,&c);
            put_value(t,c,i);
        }
        city[x].value=0;
        find_min(x,y,m);
        printf("%d\n",city[y].value);
    }
    return 0;
}
