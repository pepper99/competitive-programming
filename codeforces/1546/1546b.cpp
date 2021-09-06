#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    n = (n << 1) - 1;
    vector<char> a(m, 0);
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[j] ^= s[j];
        }
    }
    for(int i = 0; i < m; i++) cout << a[i];
    cout << '\n';
}

main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}