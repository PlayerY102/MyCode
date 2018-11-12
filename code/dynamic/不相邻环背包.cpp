#include<stdio.h>
#include<algorithm>
using namespace std;
int v[100007];
int max_value(int left,int right){
    int last_two=0,last_one=0;
    for(int i=left;i<=right;i++){
        int temp=last_one;
        last_one=max(last_one,last_two+v[i]);
        last_two=temp;
    }
    return last_one;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==1){
            int temp;
            scanf("%d",&temp);
            printf("%d\n",temp);
            continue;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",v+i);
        }
        printf("%d\n",max(max_value(1,n-1),max_value(2,n)));
    }
    return 0;
}
