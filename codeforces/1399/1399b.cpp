#include<bits/stdc++.h>
using namespace std;

main()
{
    int t, d, n, m;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n], b[n], minA = -1, minB = -1;
        unsigned long long int m = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(minA == -1 || minA > a[i]) minA = a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            if(minB == -1 || minB > b[i]) minB = b[i];
        }

        for(int i = 0; i < n; i++) {
            if(minA < a[i]) {
                d = a[i] - minA;
                m += d;
                b[i] = (b[i] - d < minB ? minB : b[i] - d);
            }
        }
        for(int i = 0; i < n; i++) {
            if(minB < b[i]) {
                m += b[i] - minB;
            }
        }
        cout << m << endl;
    }

}
