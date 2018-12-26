#include<stdio.h>
#include<algorithm>
#define max_size 1007
using namespace std;
long long inp[max_size];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",inp+i);
        }
        sort(inp,inp+n);
        long long miss=1;
        int add=0;
        int index=0;
        while(miss<=m){
            long long minfa;
            if(index>=n){
                minfa=(unsigned long long)-1>>1;
            }
            else{
                minfa=inp[index];
            }
            if(minfa>miss){
                add++;
                miss=2*miss;
            }
            else{
                index++;
                miss+=minfa;
            }
        }
        printf("%d\n",add);
    }
    return 0;
}
