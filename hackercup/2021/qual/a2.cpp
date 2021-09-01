#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

#define ff                first 
#define ss                second 
#define ll                long long 
#define vi                vector<int>
#define vl                vector<ll>
#define ld                long double
#define pii               pair<int,int>
#define pll               pair<ll,ll>
#define pb                push_back
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define setbits(x)        __builtin_popcount(x)
#define setbitsll(x)      __builtin_popcountll(x)
#define custom            pair<int,pair<int,int> >
#define sz(x)             ((int)(x).size())
#define all(x)            (x).begin(), (x).end()
#define deb(x)            { cout<< #x << " is " << x << '\n'; }
#define newline           { cout << '\n'; }
#define loop(x, a, b)     for(int x = a; x < b; ++x)
#define loopB(x, a, b)    for(int x = a; x >= b; --x)
#define arrset(a, n, c)   loop(i, 0, n) a[i] = c;
#define fast              {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

pii direction[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
pii directionEx[8] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
#define mod 1000000007

int pow(int x, int y, int p){
    int res = 1;x = x % p;
    while (y > 0) {
        if (y & 1)
        res = (res * x) % p;
        y = y >> 1; x = (x * x) % p;
    }
    return res%p;
}

int modinverse(int n, int p){
    return pow(n,p-2,p);
}

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b % a, a);
}
/*--------------------------------------------------------------------------------------------------------------------------*/

int cnt[26];

void solve()
{
    string s; cin >> s;
    int K; cin >> K;
    vector<vi> g(26);
    loop(i, 0, 26) {
        g[i].resize(26, -1);
        g[i][i] = 0;
    }
    string x;
    loop(i, 0, K) {
        cin >> x;
        g[x[0] - 'A'][x[1] - 'A'] = 1;
    }
    loop(k, 0, 26) loop(i, 0, 26) loop(j, 0, 26) {
        if(g[i][k] != -1 && g[k][j] != -1 && (g[i][j] == -1 || g[i][j] > g[i][k] + g[k][j])) g[i][j] = g[i][k] + g[k][j];
    }
    mem0(cnt);
    for(char &c : s) {
        cnt[c - 'A']++;
    }
    vector<pair<int, char>> charHist;
    loop(i,0,26) {
        charHist.push_back({cnt[i], 'A' + i});
    }
    sort(all(charHist));
    int ans = -1;
    for(int i = 25; i >= 0; i--) {
        int count = 0;
        loop(j, 0, s.length()) {
            if(g[s[j] - 'A'][charHist[i].ss - 'A'] == -1) {
                count = -1;
                break;
            }
            count += g[s[j] - 'A'][charHist[i].ss - 'A'];
        }
        if(count != -1 && (ans == -1 || ans > count)) ans = count;
    }
    cout << ans;
}
 
main(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("a1ina2.txt", "r", stdin);
    // freopen("a1ina2out.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    loop(i,1,t+1){
        cout << "Case #" << i << ": ";
        solve();
        newline
    }
}
