#include<stdio.h>
#include<algorithm>
using namespace std;
int inp[100007];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        k=k-1;
        int inp_max=0;
        for(int i=0;i<n;i++){
            scanf("%d",inp+i);
            inp_max=max(inp_max,inp[i]);
        }
        if(k==0){
            printf("%d\n",inp_max);
            continue;
        }
        int left=0;
        int right=inp_max;
        sort(inp,inp+n);
        while(left<=right){
            int mid=(left+right)/2;
            long long count=0;
            int first=upper_bound(inp,inp+n,mid)-inp;
            for(;first<n;first++){
                count+=(inp[first]-mid+k-1)/k;
            }
            if(count>mid){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        printf("%d\n",left);
    }
    return 0;
}
