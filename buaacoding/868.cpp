#include<stdio.h>
#include<algorithm>
#define max_size 100007
using namespace std;
int n,p;
int A[max_size];
int B[max_size];
bool judge(double mid){
    double total=p*mid;
    for(int i=0;i<n;i++){
        double need=(double)A[i]*mid-B[i];
        if(need>0){
            total-=need;
        }
        if(total<0){
            break;
        }
    }
    return total>=0;
}
int main()
{
    while(scanf("%d%d",&n,&p)!=EOF){
        long long sum=0;
        for(int i=0;i<n;i++){
            scanf("%d %d",A+i,B+i);
            sum+=A[i];
        }
        if(sum<=p){
            printf("Great Robot!\n");
            continue;
        }
        double left=0;
        double right=1e12;
        while(right-left>0.00001){
            double mid=(left+right)/2;
            if(judge(mid)){
                left=mid;
            }
            else{
                right=mid;
            }
        }
        printf("%.3lf\n",left);
    }
    return 0;
}
