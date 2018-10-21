#include <stdio.h>
#include <algorithm>
using namespace std;
#define max_size 1000007
int arr[max_size];
void quicks(int l,int r,int dep){
    static int count=0;
    if(dep==2){
        count++;
        if(count==2){
            for(int i=l;i<=r;i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
        }
    }
    int i=l;
    int j=r;
    int mid=arr[(l+r+1)/2];
    while(i<=j){
        while(arr[i]<mid){
            i++;
        }
        while(arr[j]>mid){
            j--;
        }
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;j--;
        }
    }
    if(l<j)quicks(l,i-1,dep+1);
    if(i<r)quicks(i,r,dep+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    quicks(0,n-1,0);
    return 0;
}
