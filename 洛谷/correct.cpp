#include<stdio.h>
#include<algorithm>
#define max_size 1007
using namespace std;
struct enemy{
    int attack;
    int live;
    double per;
    bool operator<(enemy &b){
        return per<b.per;
    }
};
enemy inp[max_size];
int main()
{
    int n,HP;
    while(scanf("%d%d",&n,&HP)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",&inp[i].attack,&inp[i].live);
            inp[i].per=(double)inp[i].live/inp[i].attack;
        }
        sort(inp,inp+n);
        int last_time=0;
        for(int i=0;i<n;i++){
            HP-=inp[i].attack*(inp[i].live+last_time);
            last_time+=inp[i].live;
            if(HP<0){
                break;
            }
        }   
        if(HP>0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
