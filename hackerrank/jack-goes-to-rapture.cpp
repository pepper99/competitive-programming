#include<bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
 
#define ff                first 
#define ss                second 
#define ll               long long 
#define vi                vector<int>
#define ld                long double
#define pii               pair<int,int>
#define vpii              vector<pair<int,int>>
#define pb                push_back
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define setbits(x)        __builtin_popcountll(x)
#define custom            pair<int,pair<int,int> >
#define sz(x)             ((int)(x).size())
#define all(x)            (x).begin(), (x).end()
#define deb(x)            { cout<< #x << " is " << x << '\n'; }
#define newline           { cout << '\n'; }
#define loop(x, a, b)     for(int x = a; x < b; ++x)
#define loopB(x, a, b)    for(int x = a; x >= b; --x)
#define arrset(a, n, c)   loop(i, 0, n) a[i] = c;

pii direction[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
#define mod 1000000007

int pow(int x,int y, int p){
    int res = 1;x = x % p;
    while (y > 0) {
        if (y & 1)
        res = (res * x) % p;
        y = y >> 1; x = (x * x) % p;
    }
    return res%p;
}

int modinverse(int n,int p){
    return pow(n,p-2,p);
}

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b % a, a);
}
/*--------------------------------------------------------------------------------------------------------------------------*/

#define pll pair<long, long>

void solve()
{
    ll n, m; cin >> n >> m;
    ll f, t, w;
    vector<vector<pll>> g(n+1);
    loop(i, 0, m) {
        cin >> f >> t >> w;
        g[f].push_back({t, w});
        g[t].push_back({f, w});
    }
    vector<ll> d(n+1, -1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pll p;
    pq.push({0, 1});
    while(!pq.empty()) {
        p = pq.top();
        pq.pop();
        if(d[p.ss] != -1 && p.ff > d[p.ss]) continue;
        d[p.ss] = p.first;
        // cout << p.ss << ' ' << d[p.ss] << '\n';

        f = p.ss;
        for(pll &pt : g[p.ss]) {
            t = pt.ff; w = pt.ss;

            if(d[f] != -1 && (d[t] == -1 || d[t] > d[f] + max(0ll, w - d[f]))) {
                d[t] = d[f] + max(0ll, w - d[f]);
                pq.push({d[t], t});
            }
        }
    }
    // loop(i, 1, n+1) deb(d[i]);
    if(d[n] == -1) cout << "NO PATH EXISTS";
    else cout << d[n];
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
