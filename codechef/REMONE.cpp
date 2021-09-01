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
    ll n;
    cin >> n;
    ll a[n], b[n-1];
    loop(i,0,n) cin >> a[i];
    loop(i,0,n-1) cin >> b[i];

    sort(a, a+n); sort(b, b+n-1);

    ll ans = LONG_LONG_MAX;
    ll x1 = b[0] - a[0];
    bool onepass = true;
    ll j = 0;
    // printf("x1 = %lld\n", x1);
    if(x1 > 0ll) {
        for(ll i = 0; j < n-1; j++, i++) {
            if(b[j]-a[i] == x1) continue;
            else {
                if(onepass) {
                    onepass = false;
                    i++;
                }
                else break;
            }
        }
        if(j == n-1) ans = x1;
    }
    // printf("ans = %lld\n", ans);

    ll x2 = b[0] - a[1];
    onepass = true;
    j = 0;
    // printf("x2 = %lld\n", x2);
    if(x2 > 0) {
        for(ll i = 0; j < n-1; j++, i++) {
            if(b[j]-a[i] == x2) continue;
            else {
                if(onepass) {
                    onepass = false;
                    i++;
                }
                else break;
            }
        }
        if(j == n-1) ans = min(x2, ans);
    }
    // printf("test%lld", ans);
    cout << ans;
}
 
main(){
    fast

    int t;
    cin >> t;
    while(t--){
        solve();
        newline
    }
}
