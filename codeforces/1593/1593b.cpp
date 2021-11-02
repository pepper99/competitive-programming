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
    string s; cin >> s;
    int i = s.length()-1;
    int ans1 = 0, ans2 = 0;

    string sub = s.substr(s.length()-2,2);
    if(sub == "25" || sub == "00" || sub == "50" || sub == "75") {
        cout << 0;
        return;
    }
    while(i >= 0 && s[i] != '5') {
        ans1++;
        i--;
    }
    i--;
    while(i >= 0 && s[i] != '2' && s[i] != '7') {
        ans1++;
        i--;
    }
    if(i < 0) ans1 = LONG_LONG_MAX;
    i = s.length()-1;
    while(i >= 0 && s[i] != '0') {
        ans2++;
        i--;
    }
    i--;
    while(i >= 0 && s[i] != '0' && s[i] != '5') {
        ans2++;
        i--;
    }
    if(i < 0) ans2 = LONG_LONG_MAX;
    cout << min(ans1,ans2);
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
