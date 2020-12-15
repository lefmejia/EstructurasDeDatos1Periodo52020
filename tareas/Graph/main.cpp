#include <iostream>
#include "graph.h"
#include <bits/stdc++.h> 

using namespace std;
#define INF 99999
#define V 5

int main()
{
    Graph g;


    g.addNode(0,"A");
    g.addNode(1,"B");
    g.addNode(2,"C");
    g.addNode(3,"D");
    g.addNode(4,"E");

    Graph::Node *pna = g.nodeById(0);
    Graph::Node *pnb = g.nodeById(1);
    Graph::Node *pnc = g.nodeById(2);
    Graph::Node *pnd = g.nodeById(3);
    Graph::Node *pne = g.nodeById(4);

    

    pna->addEdge(pnb, 100);
    pna->addEdge(pnc, 10);
    pna->addEdge(pnd, 5);

    pnb->addEdge(pna, 100);
    pnb->addEdge(pnc, 20);
    pnb->addEdge(pne, 100);

    pnc->addEdge(pna, 10);
    pnc->addEdge(pnb, 20);
    pnc->addEdge(pne, 20);

    pnd->addEdge(pna, 5);
    pnd->addEdge(pne, 20);

    pne->addEdge(pnb, 100);
    pne->addEdge(pnc, 20);
    pne->addEdge(pnd, 20);

    g.genDotOutPut();

    std::vector<long> costv;
    std::vector<long> pathv;

    g.dijsktra(0, costv, pathv);

    for(long cost : costv)
    {
        std::cout << "Min cost: " << cost << '\n';
    }

    for(long p: pathv)
    {
        if(p< 0) continue;
        Graph::Node* n = g.nodeById(p);
        std::cout << "Path: "<< n->label << '\n';
    }

    //      A   B   C   D   E
    //  A   0   100 10  5   inf
    //  B   100 0   20  inf 100
    //  C   10  20  0   inf 20
    //  D   5   inf inf 0   20
    //  E   inf 100 20  20 0

    int grafo[V][V] = {{0, 100, 10, 5, INF},
                     {100, 0, 20, INF, 100},
                     {10, 20, 0, INF, 20},
                     {5, INF, INF, 0, 20},
                     {INF, 100, 20, 20, 0}};

    // int grafo[V][V] = {{0, 100, 10, 5, INF},
    //                  {INF, 0, 20, INF, 100},
    //                  {INF, INF, 0, INF, 20},
    //                  {INF, INF, INF, 0, 20},
    //                  {INF, INF, INF, INF, 0}};

    g.floyd(grafo);
}