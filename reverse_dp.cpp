#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;
#define max_inp 107
int inp[max_inp];
int outp[max_inp];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", inp + i);
        }
        memset(outp, 0, sizeof(outp));
        int total = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            outp[i] = max(outp[i + 1], total - outp[i + 1] + inp[i]);
            total += inp[i];
        }
        printf("%d\n", outp[0]);
    }
    return 0;
}
