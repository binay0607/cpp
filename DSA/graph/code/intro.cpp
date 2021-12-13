so graph are basically set of indices with a set of edges connecting them, may be all of them or non.
vertices--> nodes of a graph
edges --> path connecting any two vertices
adjacent vertices --> two vertices having a edge connecting them
degree--> number of edges passing through a vertice
connected graph--> there should be a path to traverse all the nodes
connected components --> each independent connect graph present in a graph (there can be vertices not connecting with any other vertices , all of them are independent connected components of that graph)
complete graph--> every vertices is connecting with every other vertices


NOTES :
1) min number of edges=  0
2) min number of edges in a connected graph= n-1
3) min number of edges in a complete graph= n(n-1)/2


IMPLEMENTATION :
1) edge list :
    we store a array containing all the edges and another array containing all the pair of vertices having a edge

2) adjacency list:
     here we have a array of vertices and all vertices have another array link to containing vertices which have a edge connected with this vertices
3) adjacency matrix:
    if there are n nodes we make a n*n matrix (most probably of type bool) and mark it according to if they have a edge or not


VARIATION IN GRAPH:
    1) Directed Graph:
        here unlike normal graph there can be edges which are one way only 
        what we need to do here is- when we know there is a edge from i to j instead of doing edges[i][j]=1 and edges[j][i]=1, we only do edges[i][j]=1
    
    2) Weighted Graph:
        here the edges can have some weight attached to them
        the simplest way of assigning the weight to the edge is- we store edges[i][j]= (its weight) instead of 1

