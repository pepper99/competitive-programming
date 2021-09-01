#include<bits/stdc++.h>
using namespace std;

main()
{
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        while(v.size() > 1){
            if(abs(*(v.end() - 1) - *(v.end() - 2)) <= 1) v.erase(v.end() - (*(v.end() - 1) <= *(v.end() - 2) ? 1 : 2));
            else break;
        }
        cout << (v.size() > 1 ? "NO" : "YES") << endl;
    }

}
