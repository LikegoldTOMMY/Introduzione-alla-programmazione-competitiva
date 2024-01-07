/*
Autore: Tommaso Ulian
Data: 07/01/2024
Problema: CodeForces 1909 A
Rating: 800
Tags: Math, Implementation
*/

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

/*
Utilizzando solamente tre pulsanti partendo dall'origine possiamo muoverci solamente verso l'alto sulla
Y o in basso e ovunque sulla X, oppure solamente a destra o a sinistra e ovunque sulla Y.
Quindi semplicemente contiamo quanti dei punti hanno Y positiva, e quanti hanno X positiva, contiamo inoltre
gli zeri separatemante perchè sono neutri in questo caso.
Se troviamo che tutti i punti hanno Y positiva (o zero) allora possiamo raggiungerli, stesso discorso
vale se hanno Y negativa.
Se non lo hanno allora devono avere tutti X positiva (o zero), oppure tutti X negativa.
*/

void solve(){
    int n; cin >> n;
    int xp = 0, xz = 0;
    int yp = 0, yz = 0;
    
    for (int  i = 0; i < n; i++)
    {
        int x,y; cin >> x >> y;
        if(x > 0)xp++;
        if(x == 0)xz++;
        if(y > 0)yp++;
        if(y == 0)yz++;
    }
    if(xp+xz == n || xp == 0)cout << "YES" << endl;
    else if(yp+yz == n || yp == 0)cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
