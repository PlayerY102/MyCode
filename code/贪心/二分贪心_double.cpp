#include<stdio.h>
#include<algorithm>
using namespace std;
int inp[100000];
int judge(int n,int m,double mid){
    double pos=inp[0]+mid;
    m--;
    int index=1;
    while(m>=0){
        if(index>=n){
            return 1;
        }
        double ri=pos+mid;
        if(inp[index]>ri){
            pos=inp[index]+mid;
            m--;
        }
        index++;
    }
    return 0;
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++){
        scanf("%d",inp+i);
    }
    sort(inp,inp+n);
    double left=0.0;
    double right=inp[n-1];
    while(right-left>0.01){
        double mid=(left+right)/2;
        if(judge(n,m,mid)){
            right=mid;
        }
        else{
            left=mid;
        }
    }
    printf("%.1lf\n",left);
    return 0;
}
