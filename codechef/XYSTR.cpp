#include <iostream>
using namespace std;

int dp[100000];

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 1; i < s.length(); i++) {
        if(s[i-1] != 'z' && s[i-1] != s[i]) {
            ans++;
            s[i-1] = s[i] = 'z';
        }
    }
    cout << ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout << '\n';
    }
}
