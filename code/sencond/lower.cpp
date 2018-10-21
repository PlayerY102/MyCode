#include <stdio.h>
#include <algorithm>
#define max_size 1000007
long long inp[max_size];
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%lld",inp+i);
        }
        int nth;
        scanf("%d",&nth);
        sort(inp,inp+n);
        int len=unique(inp,inp+n)-inp;
        int out=lower_bound(inp,inp+len,nth)-inp;
        printf("%d\n",len-out);
    }
    return 0;
}
