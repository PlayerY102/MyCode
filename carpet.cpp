#include<stdio.h>
#include<stdlib.h>
#define max_size 100007
struct carpet{
    int a;
    int b;
    int x_len;
    int y_len;
};
struct carpet carpets[max_size];
int match(int x,int y,int i){
    int x_min=carpets[i].a;
    int x_max=carpets[i].a+carpets[i].x_len;
    int y_min=carpets[i].b;
    int y_max=carpets[i].b+carpets[i].y_len;
    if(x>=x_min&&x<=x_max&&y>=y_min&&y<=y_max){
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&carpets[i].a,&carpets[i].b,&carpets[i].x_len,&carpets[i].y_len);
    }
    int x,y;
    scanf("%d%d",&x,&y);
    int ans=-1;
    for(int i=n;i>=1;i--){
        if(match(x,y,i)){
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);
    // system("pause");
    return 0;
}
