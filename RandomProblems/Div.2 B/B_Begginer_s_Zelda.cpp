/*
Autore: Tommaso Ulian
Data: 05/01/2024
Problema: Codeforces 1905B
Rating: 1100
Tags: Greedy, Trees
*/

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

/*
Definiamo un operazione ottimale come quella che comprime più
vertici, è facile notare come questa operazione parte sempre da una
foglia dell'albero ed arriva ad un altra. 
Notiamo quindi che in un operazione ottimale rimuoviamo due foglie 
è quindi solamente necessario contare il numero di foglie dell'albero +1 
 e dividerlo per due arrotondando per difetto.
Aggiungiamo uno perchè nella penultima operazione se il numero di foglie è 
dispari creiamo un ulteriore foglia. 
*/

void solve(){
    int n; cin >> n;
    vector<int> v(n,0);
    n--;
    while(n--){
        int a,b; cin >> a >> b;
        v[a-1]++;
        v[b-1]++;
    }
    int count = 1;
    for(auto x: v){
        if(x == 1)count++;
    }
    cout << floor(count/2) << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();

	
    return 0;
}
