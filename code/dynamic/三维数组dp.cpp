#include<stdio.h>
#include<memory.h>
#include<algorithm>
#define max_size 207
#define mod 1000007
long long ans[max_size][max_size][2];
using namespace std;
int main()
{
    int n,m,x,y;
    while(scanf("%d %d %d %d",&n,&m,&x,&y)!=EOF){
        memset(ans,0,sizeof(ans));
        ans[0][0][0]=1;
        ans[0][0][1]=1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int z=max(0,i-x);z<i;z++){
                    ans[i][j][0]=(ans[i][j][0]+ans[z][j][1])%mod;
                }
                for(int z=max(0,j-y);z<j;z++){
                    ans[i][j][1]=(ans[i][j][1]+ans[i][z][0])%mod;
                }
            }
        }
        printf("%lld\n",(ans[n][m][0]+ans[n][m][1])%mod);
    }
    return 0;
}
