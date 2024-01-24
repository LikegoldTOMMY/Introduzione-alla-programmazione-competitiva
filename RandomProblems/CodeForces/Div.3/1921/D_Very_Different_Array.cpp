/*
Autore: Tommaso Ulian
Data: 19/01/2024
Problema: Codeforces 1921 D
Rating: 1100
Tags: Data structures, Greedy, Sortings, Two pointers
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;


void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n),b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(), b.end());
    ll d = 0;
    int l2 = 0, r2 = m-1;
    int l1 = 0, r1 = n-1;
    while(l1 <= r1){
        int w = abs(a[l1]-b[r2]);
        int e = abs(a[r1] - b[l2]);
        int m = max(w,e);
        if(m == w){
            l1++; r2--;
        }
        else if(m == e){
            r1--; l2++;
        }
        d += m;
    }
    cout << d << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
