/*
Autore: Tommaso Ulian
Data: 04/01/2024
Problema: Codeforces 1891 B
Rating: 1100
Tags: Brute Force, Math, Sortings
*/

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

int bigTwo(int x){
    int position = 0;
    while ((x & 1) == 0 && x > 0) {
        x >>= 1;  
        ++position;
    }
    return position;
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> v;
    while(n--){
        int x; cin >> x; 
        v.push_back(x);
    }
    vector<int> qs(31,0);
    int m = 33;
    while(q--){
        int x; cin >> x;
        if(x < m){
            for(int i = x; i < 31; i++){
                qs[i] += 1 << x-1;
            }
            m = x;
        }
    }
    for(int i = 0; i< v.size(); i++){
       cout << v[i] + qs[bigTwo(v[i])] << " ";
    }
    cout << endl;
}
int main(){

    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
