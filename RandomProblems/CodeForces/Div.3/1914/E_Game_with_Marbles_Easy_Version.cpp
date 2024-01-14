/*
Autore: Tommaso Ulian
Data: 14/01/2024
Problema: Codeforces 1914 E1-E2
Rating: 1400
Tags: Games, Greedy, Sortings
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

bool customSort(const pair<int, int>& a, const pair<int, int>& b) {
    int absDiffA = a.first + a.second;
    int absDiffB = b.first + b.second;
    return absDiffA > absDiffB;
}

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++)cin >> v[i].first;
    for (int i = 0; i < n; i++){
        cin  >> v[i].second;
    }
    sort(v.begin(), v.end(), customSort);
    ll score = 0;
    for(int i = 0; i < n; i++){
        if(i & 1){
            score -= (v[i].second-1);
        }
        else{
            score += (v[i].first-1);
        }
    }
    
    cout << score << endl ;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
