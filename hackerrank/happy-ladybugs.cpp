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
    int n; string s; cin >> n >> s;
    bool test = true;
    unordered_map<char, int> m;
    for(int i = 0; i < n; i++) {
        m[s[i]]++;
        if(s[i] != '_' && test) {
            int l = i > 0 ? i-1 : -1;
            int r = i + 1 < n ? i+1 : -1;
            bool b1 = false, b2 = false;
            if(l != -1) b1 = s[i] == s[l];
            if(r != -1) b2 = s[i] == s[r];
            if(!b1 && !b2) test = false;
        }
    }
    if(test) {
        cout << "YES";
        return;
    }
    else {
        bool hasOne = false, hasEmpty = false;
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->first != '_' && it->second == 1) hasOne = true;
            if(it->first == '_') hasEmpty = true;
        }
        if(hasOne || !hasEmpty) {
            cout << "NO";
            return;
        }
        cout << "YES";
        return;
    }
}
 
int main(){
    fast

    int t;
    cin >> t;
    while(t--){
        solve();
        newline
    }
}
