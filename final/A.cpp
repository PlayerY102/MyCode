#include<stdio.h>
#include<algorithm>
using namespace std;
int inp[10000];
int outp[10000];
int n,m;
bool judge(int mid){
    int les=0;
    int les_count=0;
    for(int i=0;i<=m;i++){
        if(inp[i]>mid){
            return false;
        }
        if(les_count+inp[i]>mid){
            les++;
            les_count=inp[i];
        }
        else{
            les_count+=inp[i];
        }
    }
    les++;
    if(les>n){
        return false;
    }
    return true;
}
void show(int mid){
    int les_count=0;
    for(int i=0;i<=m;i++){
        if(les_count+inp[i]>mid){
            printf("%d ",les_count);
            les_count=inp[i];
        }
        else{
            les_count+=inp[i];
        }
    }
    printf("%d \n",les_count);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<=m;i++){
            scanf("%d",inp+i);
        }
        int left=0;
        int right=inp[m-1];
        int mid=(left+right)/2;
        while(left<=right){
            if(judge(mid)){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
            mid=(left+right)/2;
        }
        printf("%d\n",left);
        show(left);
    }
    return 0;
}
