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

void solve()
{
    int n, x; cin >> n;
    int a[n];
    string s;
    vector<pll> v(n+1);
    loop(i,0,n) cin >> a[i];
    cin >> s;
    loop(i,0,n) {
        if(s[i] == 'R') v[i+1] = {max(1ll,a[i]), n};
        else if(s[i] == 'B') v[i+1] = {1, min(a[i],n)};
    }
    sort(v.begin()+1,v.end());
    loop(i,1,n+1) {
        if(v[i].ff <= v[i].ss && v[i].ff <= i && i <= v[i].ss) continue;
        else {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}
 
INT main(){
    fast

    int t;
    cin >> t;
    while(t--){
        solve();
        newline
    }
}
