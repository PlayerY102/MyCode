#include <iostream>
#include <algorithm>
#include <malloc.h>
using namespace std;
int a[500007];
int dp[500007];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i] = (unsigned)-1 >> 1;
    }
    int pos = 0;
    dp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > dp[pos])
            dp[++pos] = a[i];
        else
            dp[lower_bound(dp, dp + pos + 1, a[i]) - dp] = a[i];
    }
    cout << pos + 1 << endl;
}
