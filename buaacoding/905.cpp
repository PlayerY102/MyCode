#include <stdio.h>
#include <algorithm>
#define max_size 1000007
using namespace std;
int weight[101];
int dp[max_size];

int main()
{
    int n;
    for (int i = 1; i <= 100; i++)
    {
        weight[i] = i * i * i;
    }
    n=1000000;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (unsigned)-1 >> 1;
        for (int j = 1; j <= 100; j++)
        {
            if (weight[j] > i)
            {
                break;
            }
            dp[i] = min(dp[i - weight[j]] + 1, dp[i]);
        }
    }
    while (scanf("%d", &n) != EOF)
    {

        if (dp[n] == n)
        {
            printf("Oh NO!\n");
        }
        else
        {
            printf("%d\n", dp[n]);
        }
    }
    return 0;
}
