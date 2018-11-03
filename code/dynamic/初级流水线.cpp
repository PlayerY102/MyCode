#include <stdio.h>
#include <algorithm>
#include <memory.h>
#define max_size 507
using namespace std;
int p[max_size][max_size];
int t[max_size][max_size];
int value[max_size][max_size];
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &(p[i][j]));
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &(t[i][j]));
            }
        }
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                value[i][j]=(unsigned)-1>>1;
            }
        }
        for(int i=1;i<=n;i++){
            value[i][1]=p[i][1];
        }
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                //value[i][j]=(unsigned)-1>>1;
                for (int z = 1; z <= n; z++)
                {
                    value[i][j]=min(value[i][j],value[z][j-1]+t[z][i]+p[i][j]);
                }
            }
        }
        int temp = ((unsigned)-1) >> 1;
        for (int z = 1; z <= n; z++)
        {
            temp = min(temp, value[z][m]);
        }
        printf("%d\n", temp);
    }
    return 0;
}
