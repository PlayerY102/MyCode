#include<stdio.h>
#include<algorithm>
#define maxsize 100007
using namespace std;
struct fish{
    int t;
    int d;
    double value;
};
struct fish fishs[maxsize];
bool cmp(struct fish a,struct fish b){
    return a.value>b.value;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&fishs[i].t,&fishs[i].d);
        fishs[i].value=(double)fishs[i].d/(double)fishs[i].t;
    }
    sort(fishs,fishs+n,cmp);
    long long ti=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=fishs[i].d*ti;
        ti+=fishs[i].t;
    }
    printf("%lld\n",ans);
    // system("pause");
    return 0;
}
