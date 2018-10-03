#include<stdio.h>
int index;
int total;
int count;
void move(char from,char to){
    if(count==total){
        return;
    }
    printf("get game from board %c\n",from);
    if(from=='1'){
        if(index){
            index--;
        }
        else{
            printf("playing\n");
            count++;
        }
    }
    printf("put game to board %c\n",to);
    if(to=='1'){
        index++;
    }
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
    int n;
    while(scanf("%d",&n)!=EOF){
        index=0;
        total=n;
        count=0;
        if(n>=3){
            hanoi(n-2,'1','2','3');
            move('1','3');
            move('1','1');
        }
        else if(n==2){
            move('1','2');
            move('1','3');
        }
        else if(n==1){
            move('1','3');
        }
        printf("leave\n");
    }
    return 0;
}
