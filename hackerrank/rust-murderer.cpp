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

void solve()
{
    int n, m; cin >> n >> m;
    vector<unordered_set<int>> g(n+1);
    int f, t;
    loop(i, 0, m) {
        cin >> f >> t;
        g[f].insert(t);
        g[t].insert(f);
    }
    list<int> go;
    loop(i, 1, n+1) go.push_back(i);
    cin >> f;
    vi d(n+1, -1);
    queue<pii> q;
    q.push({f, 0});
    pii p;
    while(!q.empty()) {
        p = q.front();
        q.pop();
        if(d[p.ff] != -1) continue;
        d[p.ff] = p.ss;
        for(auto it = go.begin(); it != go.end();) {
            if(d[*it] == -1 && p.ff != *it && g[p.ff].find(*it) == g[p.ff].end()) {
                q.push({*it, p.ss + 1});
                it = go.erase(it);
                continue;
            }
            it++;
        }
    }
    loop(i, 1, n+1) if(f != i) cout << d[i] << ' ';
}
 
int main(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);    
    #endif

    int t;
    cin >> t;
    while(t--){
        solve();
        newline
    }
}
