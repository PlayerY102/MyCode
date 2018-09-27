#include<stdio.h>
void move(char from,char to){
    printf("%c to %c\n",from,to);
}
void hanoi(int n,char from,char to,char blank){
    if(n<=1){
        move(from,to);
    }
    else{
        hanoi(n-1,from,blank,to);
        hanoi(1,from,to,blank);
        hanoi(n-1,blank,to,from);
    }
}
int main()
{
    int temp;
    while(scanf("%d",&temp)!=EOF){
        hanoi(temp,'A','C','B');
        printf("\n");
    }
    return 0;
}
