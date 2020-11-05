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
    vertex *vStart = NULL;
    for (unsigned i=0; i<vertices.size(); i++)
    {
        if (vertices[i]->name == sourceVertex)
        {
            vStart = vertices[i];
        }
    }

    vStart->visited = true;
    vStart->distance = 0;
    queue<vertex*> q;
    q.push(vStart);

    cout << "Starting vertex (root): " << vStart->name << "-> ";
    while(!q.empty())
    {
        vertex *curr = q.front();
        q.pop();
        for (unsigned i=0; i<curr->adj.size(); i++)
        {
            if (!(curr->adj[i].v)->visited)
            {
                (curr->adj[i].v)->distance = curr->distance + 1;
                (curr->adj[i].v)->visited = true;
                cout << curr->adj[i].v->name << "(" << curr->adj[i].v->distance << ")" << " ";
                q.push(curr->adj[i].v);
            }
        }
        curr->visited = true;
    }
}

void DFS(vertex* startr)
{
    if (startr->visited == false)
    {
        startr->visited = true;
        for (unsigned i=0; i<startr->adj.size(); i++)
        {
            DFS(startr->adj[i].v);
        }
    }
}

int Graph::getConnectedBuildings()
{
    int count = 0;

    for (int i=0; i<vertices.size(); i++)
    {
        if (vertices[i]->visited == false)
        {
            DFS(vertices[i]);
            count++;
        }
    }

    return count;
}