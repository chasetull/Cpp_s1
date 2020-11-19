#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <list>
#include <stack>

using namespace std;

void Graph::createEdge(string v1, string v2, int num){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    av.weight = num;
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    av2.weight = num;
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::insertVertex(string n){
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

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    // cout<<"here"<<vertices.size()<<endl;
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<endl;
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout<<" --> "<< vertices[i]->adj[j].v->name << " ("<<vertices[i]->adj[j].weight << ")";// << endl;
        }
        cout<<endl;
    }
}



void Graph::traverseWithDijkstra(string start){
    vertex *startv;
    vertex *endv;

    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        vertices[i]->visited = false;
        if (vertices[i]->name == start)
        {
            startv = vertices[i];
        }
        if (i == vertices.size() -1)
        {
            endv = vertices[i];
        }
    }

    cout << "start: " << startv->name << ", end: " << endv->name << endl;

}



void depthFirstTraversalHelper(vertex* svtx)//vertex *svtx)
{
    if (svtx->visited == false)
    {
        cout << svtx->name << " -> ";
    }
    svtx->visited = true;
    //vertex *

    //list<vertex>::iterator i;

    for (adjVertex vx : svtx->adj)  //i = svtx->adj.begin(); i != svtx->adj.end(); i++
    {
        if (vx.v->visited == false)
        {
            depthFirstTraversalHelper(vx.v);
        }
    }

}






void Graph::depthFirstTraversal(string sourceVertex)
{
    //vector<bool> 
    //vector<bool> visited(vertices, false);
    stack<string> stackS;
    stackS.push(sourceVertex);
    vertex *srcV;


    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        vertices[i]->visited = false;

        for (adjVertex advx : vertices[i]->adj)
        {
            advx.v->visited = false;
        }
    }

    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        depthFirstTraversalHelper(vertices[i]);
        //cout << endl;
    }
    cout << "DONE"<< endl;

    

}
/*

    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        vertices[i]->visited = false;
        
    }

    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->name == sourceVertex)
        {
            srcV = vertices[i];
        }
    }

    while (!stackS.empty())
    {
        sourceVertex = stackS.top();
        stackS.pop();

        for(unsigned int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i]->name == sourceVertex)
            {
                srcV = vertices[i];
            }
        }

        if (srcV->visited == false)
        {
            cout << srcV->name << " -> ";
            srcV->visited = true;
        }

        for (adjVertex avx : srcV->adj)
        {
            if (avx.v->visited == false)
            {
                avx.v->visited = true;
                stackS.push(avx.v->name);
            }
        }
        //cout << "Done" << endl;
    }
*/




int minDistPathHelper(vertex *vtex, int curTotal)
{
    int returnCount = 0;
    int curSmallest = 0;
    vector<int> intList;
    //adjVertex *curr;

    if (vtex->visited == false)
    {
        for (adjVertex advtex : vtex->adj)
        {
            intList.push_back(advtex.weight);
            //cout << "ad " << advtex.v->name << endl;

        }

        int sm = intList[0];
        for (int i=0; i<intList.size(); i++)
        {
            curSmallest = intList[i];

            if (curSmallest < sm)
            {
                sm = curSmallest;
                returnCount = sm;
            }

        }
        
    }

    return returnCount;
}




void Graph::minDistPath(string source, string destination) {
    int totalWeight = 0;
    vertex *strt;
    vertex *endr;
    //adjVertex *advx;

    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        vertices[i]->visited = false;
        
        for (adjVertex advx : vertices[i]->adj)
        {
            advx.v->visited = false;
        }

        if (vertices[i]->name == source)
        {
            strt = vertices[i];
        }
        if (vertices[i]->name == destination)
        {
            endr = vertices[i];
        }
    }

    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        int addW = minDistPathHelper(vertices[i], totalWeight);
        totalWeight += addW;
    }

    cout << "Min dist: " << totalWeight << endl;
}
