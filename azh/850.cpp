#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    while(N--){
        int n;
        double p;
        scanf("%d%lf",&n,&p);
        double pre=0;
        double now;
        for(int i=1;i<n;i++){
            double pro=(double)i*(n-i);
            pro=pro/((double)n*(n-1)/2.0);
            pro=pro*p;
            now=pre+1.0/pro;
            pre=now;
        }
        printf("%.3lf\n",now);
    }
    return 0;
}
