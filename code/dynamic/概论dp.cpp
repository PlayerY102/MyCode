#include<stdio.h>
#include<algorithm>
using namespace std;
#define max_size 107
double p[max_size][max_size];
double binomial[max_size][max_size];
void get_bio(){
    double temp=1;
    for(int i=1;i<max_size;i++){
        double c=1;
        temp*=2;
        binomial[i][0]=c/temp;
        for(int j=1;j<=i;j++){
            c=c*(i-j+1)/j;
            binomial[i][j]=c/temp;
        }
    }
}
void thr(int n,int m,int k){
    p[0][0]=1;
    for(int fl=0;fl<m;fl++){
        for(int num=0;num<=n;num++){
            int total_0=n-num;
            int left_1=num;
            if(k>total_0){
                left_1=n-k;
            }
            for(int i=0;i<=k;i++){
                p[fl+1][left_1+i]+=p[fl][num]*binomial[k][i];
            }
        }
    }
}
int main()
{
    get_bio();
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                p[i][j]=0;
            }
        }
        thr(n,m,k);
        double ans=0;
        for(int i=0;i<=n;i++){
            ans+=p[m][i]*i;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
