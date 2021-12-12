#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

typedef int INT;
typedef long long ll;
#define int ll

#define ff                first 
#define ss                second 
#define vi                vector<INT>
#define vll               vector<ll>
#define ld                long double
#define pii               pair<INT,INT>
#define pll               pair<ll,ll>
#define pb                push_back
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define setbits(x)        __builtin_popcount(x)
#define setbitsll(x)      __builtin_popcountll(x)
#define sz(x)             ((INT)(x).size())
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

bool dfs(int x, vector<map<int,bool>> &g, vector<bool> &visited, bool &alltwo) {
    visited[x] = true;
    if(g[x].size() > 2) return false;
    else if(g[x].size() != 2) alltwo = false;
    for(auto &k : g[x]) {
        if(!visited[k.ff]) {
            if(!dfs(k.ff,g,visited,alltwo)) return false;
        }
    }
    return true;
}

void solve()
{
    int n,m; cin >> n >> m;
    vector<map<int,bool>> g(n);
    vector<bool> visited(n);
    loop(i,0,m) {
        int a, b; cin >> a >> b; a--; b--;
        if(a == b) continue;
        g[a][b] = true;
        g[b][a] = true;
    }
    loop(i,0,n) {
        if(!visited[i]) {
            bool alltwo = true;
            bool chk = dfs(i,g,visited,alltwo);
            if(!chk || alltwo) {
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";
}
 
INT main(){
    fast
    solve();
}
