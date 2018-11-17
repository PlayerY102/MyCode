#include <stdio.h>
#include <algorithm>
using namespace std;
int inp[507];
int outp[507][2];
int judge(int n,int k,int mid){
    int count=0;
    int index=1;
    while(count<k){
        int temp=0;
        while(temp<mid){
            if(index>n){
                break;
            }
            temp+=inp[index++];
        }
        if(temp>mid){
            index--;
        }
        if(index>n){
            return 1;
        }
        count++;
    }
    return 0;
}
void show(int n,int k,int v){
    int index=n;
    int pre=index;
    int count=0;
    while(count<k){
        int temp=0;
        while(temp<v){
            if(index<1){
                break;
            }
            temp+=inp[index--];
        }
        if(temp>v){
            index++;
        }
        count++;
        outp[count][0]=index+1;
        outp[count][1]=pre;
        pre=index;
    }
}
int main()
{
    int m,k;
    int total=0;
    scanf("%d %d",&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d",inp+i);
        total+=inp[i];
    }
    int left=0;
    int right=total;
    while(left<=right){
        int mid=(left+right)/2;
        if(judge(m,k,mid)){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    show(m,k,left);
    for(int i=k;i>=1;i--){
        printf("%d %d\n",outp[i][0],outp[i][1]);
    }
    // system("pause");
    return 0;
}
