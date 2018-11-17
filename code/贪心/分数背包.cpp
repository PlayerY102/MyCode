#include<stdio.h>
#include<algorithm>
using namespace std;
struct iron{
    int w;
    int v;
    double perv;
};
bool cmp(struct iron a,struct iron b){
    if(a.perv>b.perv){
        return true;
    }
    return false;
}
struct iron inp[10007];
int main()
{
    int g,k,n;
    while(scanf("%d %d %d",&g,&k,&n)!=EOF){
        double dp=0;
        int total=0;
        for(int i=0;i<k;i++){
            scanf("%d %d",&inp[i].w,&inp[i].v);
            inp[i].perv=(double)inp[i].v/(double)inp[i].w;
        }
        sort(inp,inp+k,cmp);
        int index=0;
        while(total<g){
            if(index>=k){
                break;
            }
            int left=g-total;
            if(inp[index].w<=left){
                dp+=inp[index].v;
                total+=inp[index].w;
            }
            else{
                dp+=inp[index].perv*left;
                total+=left;
            }
            index++;
        }
        if(dp>=n){
            printf("Yuri is the master!\n");
        }
        else{
           printf("%.3lf\n",(double)n-dp); 
        }
        
    }
    return 0;
}
