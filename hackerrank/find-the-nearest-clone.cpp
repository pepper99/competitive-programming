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

void solve()
{
    int n, m, c, b;
    cin >> n >> m;
    vector<vi> g(n+1);
    vi color(n+1);
    vector<bool> visited(n+1);
    loop(i, 0, m) {
        cin >> c >> b;
        g[c].push_back(b);
        g[b].push_back(c);
    }
    loop(i, 1, n+1) cin >> color[i];
    cin >> c;
    int s = -1;
    loop(i, 1, n+1) {
        if(color[i] == c) {
            s = i;
            break;
        }
    }
    if(s == -1) {
        cout << -1;
        return;
    }
    int ans = INT_MAX;
    queue<pii> q;
    q.push({s, 0});
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        visited[p.first] = true;
        int dist = p.second;
        if(color[p.first] == c && dist > 0) {
            ans = min(dist, ans);
            dist = 0;
        }
        for(int &x : g[p.first]) {
            if(!visited[x]) q.push({x, dist + 1});
        }
    }
    cout << (ans == INT_MAX ? -1 : ans);
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
