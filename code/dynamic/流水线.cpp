#include<stdio.h>
#include<algorithm>
#define max_size 507
using namespace std;
int p[max_size][max_size];
int f[max_size][max_size];
int value[max_size][max_size];
int find(int n,int m){
    for(int i=1;i<=n;i++){
        value[i][1]=p[i][1];
    }
    for(int j=2;j<=m;j++){
        for(int i=1;i<=n;i++){
            value[i][j]=(unsigned)-1>>1;
            for(int z=1;z<=n;z++){
                value[i][j]=min(value[i][j],value[z][j-1]+f[z][i]+p[i][j]);
            }
        }
    }
    int temp=unsigned(-1)>>1;
    for(int z=1;z<=n;z++){
        temp=min(temp,value[z][m]);
    }
    return temp;
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&(p[i][j]));
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&(f[i][j]));
            }
        }
        printf("%d\n",find(n,m));
    }
    return 0;
}
