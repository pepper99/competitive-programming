#include<bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
 
#define ff                first 
#define ss                second 
#define int               long long 
#define vi                vector<int>
#define ld                long float
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

void solve()
{
    int W, H; cin >> W >> H;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h; cin >> w >> h;

    int ow = x2 - x1;
    int oh = y2 - y1;
    
    if(w + ow <= W || h + oh <= H) {
        if(W - x2 >= w || x1 >= w || H - y2 >= h || y1 >= h) {
            cout << 0;
            return;
        }
        float a = INFINITY;
        if(oh + h <= H) {
            if(y1 < h && y2 + (h - y1) <= H) a = min(a, (float) h - y1);
            if(y2 + h > H && y2 - (h + y2 - H) >= 0) a = min(a, (float) h + y2 - H);
        }
        if(ow + w <= W) {
            if(x1 < w && x2 + (w - x1) <= W) {
                a = min(a, (float) w - x1);
            }
            if(x2 + w > W && x2 - (w + x2 - W) >= 0) {
                a = min(a, (float) w + x2 - W);
            }
        }
        cout << setprecision(9) << a;
        return;
    }
    cout << -1;
}
 
main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
        newline
    }
}
