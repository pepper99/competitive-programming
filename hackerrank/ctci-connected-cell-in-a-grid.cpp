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
pii directionEx[8] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
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

int grid[10][10];
int n, m;
int ans = 0;

int dfs(int x, int y) {
    grid[x][y] = 0;
    int a = 1;
    loop(i, 0, 8) {
        int nx = x + directionEx[i].first;
        int ny = y + directionEx[i].second;
        if(0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny]) {
            a += dfs(nx, ny);
        }
    }
    return a;
}

void solve()
{
    cin >> n >> m;
    loop(i, 0, n) loop(j, 0, m) cin >> grid[i][j];
    loop(i, 0, n) loop(j, 0, m) {
        if(grid[i][j]) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
