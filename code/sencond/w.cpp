#include<stdio.h>
#include<algorithm>
#include<string.h>
#define max_size 1007
char inp[max_size];
int ifis(char* l,char* r){
    int flag=0;
    int count=0;
    int com_count=0;
    for(char* i=l;i<=r;i++){
        if(*i=='('){
            count++;
        }
        else if(*i==')'){
            count--;
        }
        if(count<0){
            return 1;
        }
        if(count==0){
            flag=ifis(l+1,i-1);
            if(flag){
                return 1;
            }
            l=i+1;
            com_count++;
        }
    }
    if(count!=0||com_count>2){
        return 1;
    }
    if(flag){
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",inp);
        if(ifis(inp,inp+strlen(inp)-1)){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
    return 0;
}
