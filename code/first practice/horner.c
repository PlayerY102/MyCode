#include<stdio.h>
long long change(int H){
    long long total=0;
    char temp=0;
    scanf("%c",&temp);
    while(temp!='\n'){
        if(temp>='0'&&temp<='9'){
            total=total*H+temp-'0';
        }
        scanf("%c",&temp);
    }
    return total;
}
int main()
{
    int n;
    scanf("%d",&n);
    int H;
    long long first,second;
    while(n--){
        scanf("%d",&H);
        first=change(H);
        scanf("%d",&H);
        second=change(H);
        printf("%lld\n",first+second);
    }
    return 0;
}
