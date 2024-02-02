# Breadth First Search 
>Appunti basati su questo [pdf](https://moodle2.units.it/pluginfile.php/438805/mod_resource/content/1/Lecture_16_handout.pdf) riguardante i grafi e le lezioni in preparazione alle gare regionali dell'università LUISS

****

## Teoria
La ***Breadth First Search*** (Ricerca in ampiezza), chiamata più comunemente ***BFS***, è un algortmo di ricerca per i grafi che permette di verificare se da nodo di partenza è possibile arrivare ad un altro nodo del grafo.  
Per esempio possiamo verificare se un grafo è bipartito, ovvero se è suddivisibile in 2 sottoinsiemi di punti tali che ogni punto di un insieme è collegato solo a punti appartenenti all'altro.

Questo esempio lo tratteremo in seguito, dopo aver visto come funziona questo algoritmo.

Utilizziamo come esempio il seguente albero:  
<img src="https://github.com/LikegoldTOMMY/Introduzione-alla-programmazione-competitiva/blob/main/Useful%20Files/Graph.png?raw=true)" width="340" height="260">

Esso può essere descritto come una lista di adiacenza, costruita come una mappa di set in cui la chiave della mappa è il nodo padre e il set corrispondente è l'insieme dei figli.
Detto ciò possiamo inizializzare la lista come:


    map<int, set<int>> graph;


Ora possiamo iterare per inserire il grafo nella lista. In input deve essere fornito un numero *n* che rappresenta il numero degli archi e successivamente altri *2n* numeri, che rappresentano rispettivamente il nodo di partenta e il nodo di arrivo.

    int n;
    cin>>n;
    while(n--){
        int x, y;
        cin>>x>>y;
        graph[x].insert(y);
    }

Questa iterazione salva solo i grafi orientati. Nel caso volessimo salvare un grafo non orientato l'iterazione diventerebbe:

    int n;
    cin>>n;
    while(n--){
        int x, y;
        cin>>x>>y;
        graph[x].insert(y);
        graph[y].insert(x);
    }


***

## Complessità
L'algoritmo è utilizzabile sia su grafi orientati, sia su quelli non orientati e il peso degli archi non influenza la BFS ma viene gestito dall'[Algoritmo di Dijkstra](https://github.com/LikegoldTOMMY/Introduzione-alla-programmazione-competitiva/blob/main/13.%20Dijkstra/Dijkstra.md) e dall'Algoritmo di Bellman-Ford.

**Dato un grafo G = (*V*, *E*),** in cui *V* è l'insieme dei nodi e *E* è l'insieme degli archi, la complessità dell'algoritmo è:
> ***O( |V| + |E| )***
