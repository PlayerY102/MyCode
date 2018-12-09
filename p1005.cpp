#include<bits/stdc++.h>
#define max_size 87
using namespace std;
struct int128
{
    long long hig;
    long long low;
};//定义int128
long long p=1e18;//作mod用
int128 max(int128 a,int128 b)
{
    if(a.hig>b.hig) return a;
    if(a.hig<b.hig) return b;//高位比较
    if(a.low>b.low) return a;
    if(a.low<b.low) return b;//低位比较
    return a;//相等时还要返回一个值
}
int128 operator + (int128 a,int128 b)//重载运算符
{
    int128 k;
    k.low=0,k.hig=0;
    k.low=a.low+b.low;
    k.hig=k.low/p+a.hig+b.hig;//防止溢出
    k.low%=p;
    return k;
}
int128 operator * (int128 a,int b)
{
    int128 k;
    k.low=0,k.hig=0;
    k.low=a.low*b;
    k.hig+=k.low/p+b*a.hig;//与上同理
    k.low%=p;
    return k;
}
int128 dp[max_size][max_size];
int128 inp[max_size][max_size];
int128 ans;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&inp[i][j].low);
        }
    }
    for(int num=1;num<=n;num++){
        for(int i=1;i<=m;i++){
            dp[i][i]=inp[num][i]*2;
        }
        for(int gap=1;gap<=m-1;gap++){
            for(int st=1;st+gap<=m;st++){
                dp[st][st+gap]=max(dp[st+1][st+gap]+inp[num][st],dp[st][st+gap-1]+inp[num][st+gap])*2;
            }
        }
        ans=ans+dp[1][m];
    }
    if(ans.hig==0){
        printf("%lld\n",ans.low);
    }
    else{
        printf("%lld%018lld\n",ans.hig,ans.low);
    }
    system("pause");
    return 0;
}
