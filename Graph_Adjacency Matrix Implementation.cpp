// Adjacency Matrix Implementation

#include <iostream>
using namespace std;

int vectArray[20][20];
int count = 0;

//To display Adjacency Matrix
int displayMatrix(int v){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<vectArray[i][j];
        }
        cout<<endl;
    }
}

//Undirected Graph. So we can go from u to v and v to u.
//Mark the position as 1, considered as visited path
int add_edge(int u, int v){
    vectArray[u][v] = 1;
    vectArray[v][u] = 1;
}

int main() {
   int v = 6;    //there are 6 vertices in the graph
   add_edge(0, 4);
   add_edge(0, 3);
   add_edge(1, 2);
   add_edge(1, 4);
   add_edge(1, 5);
   add_edge(2, 3);
   add_edge(2, 5);
   add_edge(5, 3);
   add_edge(5, 4);
   displayMatrix(v);
}
