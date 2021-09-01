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
int ans = 10;

void rec(string &s, int a, int b, int i, int l, int r) {
    // cout << s << ' ' << a << ' ' << b << ' ' << i << ' ' << a+l << ' ' << b+r << '\n';
    if(i >= s.length()) return;
    else if(a > b + r || b > a + l) {
        ans = min(i, ans);
        return;
    }
    
    if(s[i] == '?') {
        s[i] = '1';
        // cout << "test1 at " << i << ' ' << s << '\n';
        rec(s, a, b, i, l, r);
        s[i] = '0';
        // cout << "test0 at " << i << ' ' << s << '\n';
        rec(s, a, b, i, l, r);
        s[i] = '?';
    }
    else {
        if(i % 2 == 0) {
            l--;
            if(s[i] == '1') a++;
        }
        else {
            r--;
            if(s[i] == '1') b++;
        }
        rec(s, a, b, i+1, l, r);
    }
}

void solve()
{
    string s;
    cin >> s;
    ans = 10;
    rec(s, 0, 0, 0, 5, 5);
    cout << ans;
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
