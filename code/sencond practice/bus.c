#include<stdio.h>
#define max_size 107
int nex[max_size];
int main()
{
    int k,m;
   while(scanf("%d %d",&k,&m)!=EOF){
    for( int i=0;i<k;i++){
        nex[i]=i;
    }
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        while(nex[a]!=a){
            a=nex[a];
        }
        while(nex[b]!=b){
            b=nex[b];
        }
        int min=a<b?a:b;
        nex[a]=min;
        nex[b]=min;
    }
    for(int i=0;i<k;i++){
        int temp=nex[i];
        while(temp!=nex[temp]){
            temp=nex[temp];
        }
        nex[i]=temp;
    }
    int flag=0;
    for(int i=0;i<k;i++){
        
       if(nex[i]!=0){
           flag=1;
           break;
       }
    }
    
    if(flag){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
    }
    return 0;
}