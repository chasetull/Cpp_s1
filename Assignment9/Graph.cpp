#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void Graph::createEdge(string v1, string v2, int num){

}

void Graph::insertVertex(string n){

}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    // cout<<"here"<<vertices.size()<<endl;
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<endl;
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout<<" --> "<< vertices[i]->adj[j].v->name << " "<<vertices[i]->adj[j].weight<<endl;
        }
        cout<<endl;
    }
}



void Graph::traverseWithDijkstra(string start){

}



void Graph::depthFirstTraversal(string sourceVertex)
{


}

void Graph::minDistPath(string source, string destination) {

}
