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

int cnt[26];

void solve()
{
    string s; cin >> s;
    mem0(cnt);
    int mxVowel = 0, mxCons = 0; char vowelMx = 'x', consMx = 'x';
    for(char &c : s) {
        cnt[c - 'A']++;
        bool isVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
        if(isVowel && cnt[c - 'A'] > mxVowel) {
            mxVowel = cnt[c - 'A'];
            vowelMx = c;
        }
        else if(!isVowel && cnt[c - 'A'] > mxCons) {
            mxCons = cnt[c - 'A'];
            consMx = c;
        }
    }
    int s1 = 0, s2 = 0;
    for(char &c : s) {
        bool isVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
        if(c == vowelMx);
        else if(isVowel && c != vowelMx) s1 += 2;
        else s1++;
    }
    for(char &c : s) {
        bool isVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
        if(c == consMx);
        else if(!isVowel && c != consMx) s2 += 2;
        else s2++;
    }
    cout << min(s1, s2);
}
 
main(){
    fast
    // #ifndef ONLINE_JUDGE
    // freopen("consistency_chapter_1_input.txt", "r", stdin);
    // freopen("a1out.txt", "w", stdout);
    // #endif

    int t;
    cin >> t;
    loop(i,1,t+1){
        cout << "Case #" << i << ": ";
        solve();
        newline
    }
}
