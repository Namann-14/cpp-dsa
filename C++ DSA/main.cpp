#include <iostream>
using namespace std;

void solve(long long n)
{
    cout << n;
    if (n == 1)
    {
        return;
    }

    cout << " ";

    if (n % 2 == 0)
    {
        solve(n / 2);
    }
    else
    {
        solve((n * 3) + 1);
    }
}

int main()
{
    long long n;
    cin >> n;
    solve(n);
    return 0;
}