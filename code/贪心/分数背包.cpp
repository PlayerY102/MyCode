#include <stdio.h>
#include <algorithm>
#define maxsize 100007
using namespace std;
double dp[maxsize];
struct liq{
    int c;
    int l;
    double per;
};
struct liq inp[maxsize];
bool cmp(struct liq a,struct liq b){
    return a.per>b.per;
}
int main()
{
    int m,k,s;
    while(scanf("%d %d %d",&m,&k,&s)!=EOF){
        for(int i=0;i<=s;i++){
            dp[i]=0;
        }
        for(int i=0;i<m;i++){
            scanf("%d %d",&inp[i].c,&inp[i].l);
            inp[i].per=(double)inp[i].l/(double)inp[i].c;
        }
        while(k--){
            int w,r;
            scanf("%d %d",&w,&r);
            for(int i=s;i>=w;i--){
                dp[i]=max(dp[i],dp[i-w]+r);
            }
        }
        sort(inp,inp+m,cmp);
        int total=s;
        while(total>0&&dp[total]==dp[total-1]){
            total--;
        }
        int index=0;
        double ans=dp[s];
        while(index<m && total+inp[index].c<=s){
            total+=inp[index].c;
            ans+=inp[index].l;
            index++;
        }
        if(index<m){
            ans+=(s-total)*inp[index].per;
        }
        printf("%.1lf\n",ans);
    }
    return 0;
}
