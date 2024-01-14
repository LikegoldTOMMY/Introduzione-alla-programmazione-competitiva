/*
Autore: Tommaso Ulian
Data: 14/01/2024
Problema: Codeforces 1914 B
Rating: 800
Tags: Constructive algorithms, Math
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
 
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = n-k; i <= n; i++){
        v.push_back(i);
    }
    for(int i = n-k-1; i > 0; i--){
        v.push_back(i);
    }
    for(int a: v){
        cout << a << " ";
    }
    cout << endl;
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
 
	
    return 0;
}