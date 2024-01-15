/*
Autore: Tommaso Ulian
Data: 14/01/2024
Problema: Codeforces 1914 D
Rating: 1200
Tags: Brute force, dp, Greedy, Implementation, Sortings
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
 
void solve(){
    int n;
    cin >> n;
    vector<pair<ll,int>> a;
    vector<pair<ll,int>> b;
    vector<pair<ll,int>> c;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        a.push_back({x,i});
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        b.push_back({x,i});
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        c.push_back({x,i});
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());
    ll m = -1;
    for(int i = 0; i < 3 && i < n; i++){
        for(int j = 0; j < 3 && i < n; j++){
            for(int k = 0; k < 3 && i < n; k++){
                if(a[i].second != b[j].second && b[j].second != c[k].second && a[i].second != c[k].second)m = max(m, a[i].first+b[j].first+c[k].first);
            }
        }
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