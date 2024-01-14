/*
Autore: Tommaso Ulian
Data: 14/01/2024
Problema: Codeforces 1914 C
Rating: 1100
Tags: Greedy, Math
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
 
void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> a;
    vector<ll> b;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
    ll m = 0;
    ll sum = 0;
    ll mb = 0;
    for(int i = 0; i < n && i < k; i++){
        sum += a[i];
        mb = max( mb, b[i]);
        m = max(m , sum + (k-i-1)*mb);
    }
    cout << m << endl;
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
 
	
    return 0;
}
