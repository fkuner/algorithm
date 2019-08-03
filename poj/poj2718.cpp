#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 10000001
using namespace std;
int a[11];
int T, n;
void solve();
int main()
{
    char c;
    cin >> T;
    getchar();
    while (T--)
    {
        n = 0;
        memset(a, 0, sizeof(a));
        while ((c = getchar()) != '\n')
        {
            if (c != ' ')
                a[n++] = c - '0';
        }
        if (n == 1)
            cout << a[0]<<endl;
        else if (n == 2)
            cout << abs(a[1] - a[0])<<endl;
        else
            solve();
    }
    return 1;
}
void solve()
{
    while (a[0] == 0)
        next_permutation(a, a + n);
    int ans = INF;
    int mid = (n + 1) / 2;
    do
    {
        if (a[mid])
        {
            int x = a[0];
            int y = a[mid];
            for (int i = 1; i < mid; i++)
                x = x * 10 + a[i];
            for (int i = mid + 1; i < n; i++)
                y = y * 10 + a[i];
            if (ans > abs(x - y))
                ans = abs(x - y);
        }
    } while (next_permutation(a, a + n));
    cout << ans << endl;
}