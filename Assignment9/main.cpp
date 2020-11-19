#include "Graph.hpp"
#include <string>

using namespace std;

int main()
{
    Graph g;

    g.insertVertex("A");
    g.insertVertex("B");
    g.insertVertex("C");
    g.insertVertex("D");
    g.insertVertex("E");
    g.insertVertex("F");
    g.insertVertex("G"); 

    g.createEdge("A", "B", 1);
    g.createEdge("A", "C", 3);
    g.createEdge("B", "C", 1);
    g.createEdge("B", "D", 2);
    g.createEdge("B", "E", 4);
    g.createEdge("B", "G", 3);
    g.createEdge("D", "F", 4);
    g.createEdge("E", "F", 5);

    int inp = -1;
    bool done = false;

    //switch vars
    string srcv;
    string start;
    string fin;

    while (!done)
    {
        cout << "+++  CHOSE OPTION  +++" << endl;
        cout << "1) Display graph" << endl;
        cout << "2) DFT" << endl;
        cout << "3) Dijkstra traverse" << endl; 
        cout << "4) Min dist" << endl; 
        cout << "0) gtfo" << endl; 
        cin >> inp;


        switch (inp)
        {
        case 0:
            /* quit */
            done = true;
            cout << "Exiting..." << endl;
            break;
        case 1:
            /* FULL GRAPH */
            cout << "FULL GRAPH" << endl;
            g.displayEdges();
            break;
        case 2:
            /* dft */
            srcv = "A";
            g.depthFirstTraversal(srcv);
            break;
        case 3:
            /* Dijkstra */
            cout << "Enter source vtx: " << endl;
            cin >> srcv;
            g.traverseWithDijkstra(srcv);
            break;
        case 4:
            /* Min dist */
            start = "A";
            fin = "F";
            
            g.minDistPath(start, fin);
            break;
        
        default:
            break;
        }
    }

    



    return 0;
}