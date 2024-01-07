/*
Autore: Tommaso Ulian
Data: 07/01/2024
Problema: AtCoder Code Festival 2016 qual B B
Rating: 319
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

void solve(){
    int n, a ,b; cin >> n >> a >> b;
    string s; cin >> s;
    int total = 0, over = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            if(total < a+b){
                cout << "Yes" << endl;
                total++; 
            }
            else cout << "No" << endl;
        }
        else if(s[i] == 'b'){
            if(total < a+b && over < b){
                cout << "Yes" << endl;
                total++; 
                over++;
            }
            else cout << "No" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
