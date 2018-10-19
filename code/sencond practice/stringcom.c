#include<stdio.h>
#include<string.h>
#define max_size 200007
char a[max_size];
char b[max_size];
int com(char* a, char* b,int size){
    int len=size/2;
    if(size%2==0){
        return (com(a,b,len)&&com(a+len,b+len,len))||(com(a,b+len,len)&& com(a+len,b,len));
    }
    else{
        for(int i=0;i<size;i++){
            if(a[i]!=b[i]){
                return 0;
            }
        }
        return 1;
    }
}
int main()
{
    while(scanf("%s",a)!=EOF){
        scanf("%s",b);
        if(com(a,b,strlen(a))){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
