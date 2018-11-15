#include<stdio.h>
#include<algorithm>
using namespace std;
int inp[10007];
int judge(int n,int mid){
    int len=inp[0];
    int temp=1;
    for(int i=0;i<n;i++){
        if (inp[i]-len>=mid){
            temp++;
            len=inp[i];
        }
    }
    return temp;
}
int main()
{
    int n,c;
    while(scanf("%d %d",&n,&c)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",inp+i);
        }
        sort(inp,inp+n);
        int left=0;
        int right=inp[n-1];
        while(left<=right){
            int mid=(left+right)/2;
            if(judge(n,mid)<c){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        printf("%d\n",left-1);
    }
    return 0;
}
