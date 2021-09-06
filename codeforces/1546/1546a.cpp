#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n], b[n], d[n];
    vector<int> pos, neg;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int P = 0, N = 0;
    for(int i = 0 ; i < n ; i++) {
        cin >> b[i];
        d[i] = a[i] - b[i];
        if(d[i] > 0) {
            P += d[i];
            pos.push_back(i);
        }
        else if(d[i] < 0) {
            N -= d[i];
            neg.push_back(i);
        }
    }
    if(P != N) {
        cout << "-1\n";
        return;
    }
    cout << P << '\n';
    for(int i = 0, j = 0; P > 0; P--) {
        cout << pos[i] + 1 << ' ' << neg[j] + 1 << '\n';
        d[pos[i]]--; d[neg[j]]++;
        if(d[pos[i]] == 0) i++;
        if(d[neg[j]] == 0) j++;
    }
}

main()
{
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}