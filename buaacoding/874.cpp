#include<stdio.h>
#include<algorithm>
#define max_size 1007
using namespace std;
int from[max_size];
int to[max_size];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",from+i,to+i);
            if(from[i]%2==0){
                from[i]--;
            }
            if(to[i]%2==0){
                to[i]--;
            }
        }
    }
    return 0;
}
