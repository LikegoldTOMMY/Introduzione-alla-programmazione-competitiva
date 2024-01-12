/*
Autore: Tommaso Ulian
Data: 12/01/2024
Problema: Codeforces 1898 A
Rating: 800
Tags: Brute force, Implementation, Strings
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;


void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int a = 0;
    int b = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A')a++;
        else b++;
    }
    if(b == k){
        cout << 0 << endl;
        return;
    }
    if(b > k){
        cout << 1 << endl;
        int i = 0, r = 0;
        while(r < b-k){
            if(s[i] == 'B')r++;
            i++;
        }
        cout << i << " A" << endl;
    }
    else{
        cout << 1 << endl;
        int i = 0, r = 0;
        while(r < k-b){
            if(s[i] == 'A')r++;
            i++;
        }
        cout << i << " B" << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
