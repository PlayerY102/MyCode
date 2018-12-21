#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        priority_queue<int> inp;
        for(int i=0;i<n;i++){
            int temp;
            scanf("%d",&temp);
            inp.push(temp);
        }
        k=k-1;
        int time=0;
        while(inp.top()-time>0){
            int temp=inp.top();
            inp.pop();
            temp-=k;
            inp.push(temp);
            time++;
        }
        printf("%d\n",time);
    }
}