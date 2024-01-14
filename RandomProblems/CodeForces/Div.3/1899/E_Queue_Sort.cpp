/*
Autore: Tommaso Ulian
Data: 14/01/2024
Problema: Codeforces 1899 E
Rating: 1300
Tags: Greedy, Implementation, Sortings
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
 
void solve(){
    int n; cin >> n;
    vector<int>  v;
    int m = INFINITY;
    int mp = -1;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
        if(x < m){
            m = x; mp = i;
        }
    }
    
    for(int i = mp+1; i < n; i++){
        if(v[i] < v[i-1]){
            cout << -1 << endl;
            return;
        }
    }
    cout << mp << endl;
    
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
 
	
    return 0;
}
