#include<stdio.h>
#include<stdlib.h>
#define max_point 10007
#define max_edge 600007
struct edge{
    int v1,v2;
    int value;
};
int comp(const void* a,const void* b){
    int value_a=((struct edge*)a)->value;
    int value_b=((struct edge*)b)->value;
    return value_a-value_b;
}
int father[max_point];
struct edge edge[max_edge];
int find_fa(int n){
    if(n!=father[n]){
        father[n]=find_fa(father[n]);
    }
    return father[n];
}
void cre_edge(int a,int b,int c,int i){
     edge[i].v1=a;
     edge[i].v2=b;
     edge[i].value=c;
}
long long kruskal(int n,int m,int k){
    long long total=0;
    qsort(edge+1,m,sizeof(struct edge),comp);
    for(int i=1,count=0;i<=m&&count<n-2;i++){
        struct edge* temp=edge+i;
        if(temp->v1==k||temp->v2==k){
            continue;
        }
        int fa=find_fa(temp->v1);
        int fb=find_fa(temp->v2);
        if(fa!=fb){
            father[fb]=fa;
            total+=temp->value;
            count++;
        } 
    }
    return total;
}
int main()
{
    int n,m,k;
    int min=((unsigned)-1)>>1;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a==k||b==k){
            if(c<min){
                min=c;
            }
        }
        cre_edge(a,b,c,i);
    }
    long long outp=kruskal(n,m,k);
    outp=outp+min;
    printf("%lld\n",outp);
    return 0;
}
