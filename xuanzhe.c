#include<stdio.h>
int fact(int a, int b){
    int temp=1;
    while(a>b){
        temp=temp*a;
        a--;
    }
    return temp;
}
int mh(int a,int b){
    int temp=fact(a,b)/fact(a-b,0);
    temp=temp%100007;
    return temp;
}
int count(int n){
    int temp=n;
    int total=0;
    while(temp>=0){
        int temp2=n-temp;
        if(temp2>temp+1){
            break;
        }
        else{
            total+=mh(temp+1,temp2);
        }
        total=total%100007;
        temp--;
    }
    return total;
}
int main()
{
    int n;
    int total=0;
    while(scanf("%d",&n)!=EOF){
        if(n>=0){
            total=count(n);
            printf("%d\n",total);
        }
    }
    return 0;
}
