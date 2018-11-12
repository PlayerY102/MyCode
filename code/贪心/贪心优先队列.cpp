#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            int temp;
            scanf("%d",&temp);
            pq.push(temp);
        }
        int k;
        scanf("%d",&k);
        int time=0;
        while(time<pq.top()){
            int temp=pq.top();
            pq.pop();
            temp-=k-1;
            pq.push(temp);
            time++;
        }
        printf("%d\n",time);
    }
}