#include<bits/stdc++.h>
using namespace std;

main()
{
    int t, n, s, m;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n + 1, 0);
        for(int i = 0; i < n; i++) {
            cin >> s;
            v[s]++;
        }
        for(int s = 2; s <= n*2; s++){
            m = 0;
            for(int i = 1; i < s - i; i++){
                if(s - i > n) continue;
                m += min(v[i], v[s-i]);
            }
            if(s % 2 == 0) m += v[s/2] / 2;
            v[0] = max(v[0], m);
        }
        cout << v[0] << endl;
    }

}
