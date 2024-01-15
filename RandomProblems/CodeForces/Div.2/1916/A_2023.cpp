/*
Autore: Tommaso Ulian
Data: 08/01/2024
Problema: CodeForces 1916 A
Rating: 800
Tags: Constructive algorithms, Implementation, Math, Number theory
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

/*
Se la moltiplicazione dei numeri forniti è un divisore di 2023 allora
la risposta è YES e si può rispondere con 2023/mult seguito da tanti 1 
quanti sono necessari per raggiungere K.
*/

void solve(){
    int n,k; cin >> n >> k;
    ll mult = 1;
    while(n--){
        int x; cin >> x;
        mult *= x;
    }
    if(2023 % mult == 0){
        cout << "YES" << endl;
        for(int i = 1; i < k; i++){
            cout << 1 << " ";
        }
        cout << 2023/mult << endl;
    }
    else{
        cout << "NO" << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();

	
    return 0;
}
