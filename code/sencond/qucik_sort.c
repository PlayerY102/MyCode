#include<stdio.h>
#define max_size 1000007
int inp[max_size];
int quicks(int l,int r){
    int i=l;int j=r;
    if(i>j){
        return i;
    }
    int mid=inp[(i+j+1)/2];
    while(i<=j){
        while(inp[i]<mid&&i<=j){
            i++;
        }
        while(inp[j]>mid&&j>=i){
            j--;
        }
        if(i<=j){
            int temp=inp[i];
            inp[i]=inp[j];
            inp[j]=temp;
            i++;
            j--;
        }
    }
    return i;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",inp+i);
    }
    int i=quicks(0,n-1);
    int j=quicks(0,i-1);
    for(int z=j;z<i;z++){
        printf("%d ",inp[z]);
    }
    return 0;
}
