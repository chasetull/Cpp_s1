#include "Graph.hpp"
#include <string>

using namespace std;

int main()
{
    Graph graph;
    graph.addVertex("ATLS");
    graph.addVertex("EC");
    graph.addVertex("AERO");

    graph.addEdge("ATLS", "EC");
    graph.addEdge("AERO", "EC");

    graph.displayEdges();

    int cb = graph.getConnectedBuildings();
    cout << cb << " connected buildings." << endl;

    //graph.breadthFirstTraverse("AEO");
    graph.breadthFirstTraverse("ATLS");


    return 0;
}