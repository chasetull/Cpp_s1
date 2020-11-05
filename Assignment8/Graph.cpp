#include "Graph.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void Graph::addEdge(string v1, string v2){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = n;
        vertices.push_back(v);
    }
}

void Graph::displayEdges()
{
    vertex *vDest;

    for (int i=0; i<vertices.size(); i++)
    {
        vDest = vertices[i];
        cout << vDest->name << " --> ";

        for (adjVertex vx : vDest->adj)
        {
            cout << vx.v->name << " ";
        }
        
        cout << endl;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex)
{
    vertex *srcVx = NULL;
    queue<string> vQueue;

    for (int i=0; i<vertices.size(); i++)
    {
        if (vertices[i]->name == sourceVertex)
        {
            srcVx = vertices[i];
        }
    }

    if (srcVx == NULL)
    {
        cout << "No source vertex" << endl;
        return;
    }
    else
    {
        srcVx->visited = true;
        vQueue.push(srcVx->name);

        for (int i=0; i<vertices.size(); i++)
        {
            if (vertices[i]->visited)
            {
                for (adjVertex vx : vertices[i]->adj)
                {
                    if (!vx.v->visited)
                    {
                        vQueue.push(vx.v->name);
                        vx.v->visited = true;
                    }
                }
            }
        }



    }
    while (!vQueue.empty())
    {
        cout << vQueue.front() << endl;
        vQueue.pop();
    }
}

int Graph::getConnectedBuildings()
{
    int count = 0;

    for (int i=0; i<vertices.size(); i++)
    {
        if (! vertices[i]->visited)
        {
            count++;
        }
    }

    return count;
}