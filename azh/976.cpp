#include<stdio.h>
#include<algorithm>
#include<queue>
#define max_size 500007
using namespace std;
struct plane{
    int index;
    int cost;
    bool operator< (const plane& b) const{
        return cost<b.cost;
    }
};

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        priority_queue<plane> Q;
        long long result=0;
        for(int i=1;i<=n+k;i++){
            if(i<=n){
                plane temp;
                scanf("%d",&temp.cost);
                temp.index=i;
                Q.push(temp);
            }
            if(i>=k+1){
                plane temp=Q.top();
                Q.pop();
                result+=(long long)(i-temp.index)*temp.cost;
            }
        }
        printf("%lld\n",result);
    }
    return 0;
}
