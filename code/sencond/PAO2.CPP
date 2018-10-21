#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
struct cmp1{ 
    bool operator ()(int &a,int &b){ 
        return a>b;
    } 
}; 
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        priority_queue<int,vector<int>,cmp1>que1;
        for(int i=0;i<n;i++){
            int temp;
            scanf("%d",&temp);
            que1.push(temp);
        }
        long long outp=0;
        while(que1.size()>=3){
            int a1,a2,a3;
            a1=que1.top();que1.pop();
            a2=que1.top();que1.pop();
            a3=que1.top();que1.pop();
            outp+=a1+a2+a3;
            que1.push(a1+a2+a3);
        }
        printf("%lld\n",outp);
    }
    return 0;
}
