# Breadth First Search 
>Appunti basati su questo [pdf](https://moodle2.units.it/pluginfile.php/438805/mod_resource/content/1/Lecture_16_handout.pdf) riguardante i grafi e le lezioni in preparazione alle gare regionali dell'università LUISS

****

## Teoria
La ***Breadth First Search*** (Ricerca in ampiezza), chiamata più comunemente ***BFS***, è un algortmo di ricerca per i grafi che permette di verificare se da nodo di partenza è possibile arrivare ad un altro nodo del grafo.  
Per esempio possiamo verificare se un grafo è bipartito, ovvero se è suddivisibile in 2 sottoinsiemi di punti tali che ogni punto di un insieme è collegato solo a punti appartenenti all'altro.

Questo esempio lo tratteremo in seguito, dopo aver visto come funziona questo algoritmo.

Utilizziamo come esempio il seguente albero:  
<img src="https://github.com/LikegoldTOMMY/Introduzione-alla-programmazione-competitiva/blob/main/Useful%20Files/Graph.png?raw=true)" width="340" height="260">


***

## Complessità
L'algoritmo è utilizzabile sia su grafi orientati, sia su quelli non orientati e il peso degli archi non influenza la BFS. Esso viene impiegato nell'[Algoritmo di Dijkstra](https://github.com/LikegoldTOMMY/Introduzione-alla-programmazione-competitiva/blob/main/13.%20Dijkstra/Dijkstra.md)

**Dato un grafo G = (*V*, *E*),** in cui *V* è l'insieme dei nodi e *E* è l'insieme degli archi, la complessità dell'algoritmo è:
> ***O( |V| + |E| )***