#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <limits>
#include "graph.h"

Graph::Node* Graph::nodeById(long node_id)
{
    auto it = std::find_if(nodes.begin(), nodes.end(), [node_id](const Node& n){
        return n.id == node_id;
    });

    return (it != nodes.end())? &(*it): nullptr;
}

void Graph::dijsktra(long src_id, std::vector<long>& costv, std::vector<long>& pathv)
{
    std::unordered_set<long> vertex_set;

    costv.resize(nodes.size());
    pathv.resize(nodes.size());
    for(const auto& n: nodes)
    {
        costv[n.id] = std::numeric_limits<int>::max();
        pathv[n.id] = -1;

        vertex_set.insert(n.id);
    }

    costv[src_id] = 0;

    while(!vertex_set.empty())
    {
        auto it = vertex_set.begin();
        long min_id = *it;
        it++;
        while(it != vertex_set.end())
        {
            long node_id = *it ++;
            if(costv[min_id] > costv[node_id])
                min_id = node_id;
        }

        vertex_set.erase(min_id);

        Node* u = nodeById(min_id);

        for(const auto& edge: u->edges)
        {
            const Node* v = edge.node;
            int alt = costv[u->id] + edge.weight;
            if(alt < costv[v->id])
            {
                
                costv[v->id] = alt;
                pathv[v->id] = u->id;
            }
        }

    }
}

void Graph::print() const
{
    for(const auto& n: nodes)
    {
        std::cout<< n.label << '\n';

        for(const auto& t: n.edges)
        {
            std::cout<< t.node->label << ", " << t.weight << '\n';
        }
    }
}

void Graph::genDotOutPut() const
{
    std::cout << "graph {\n";

    for(const auto& n: nodes)
    {
        for(const auto &t: n.edges)
        {
            std::cout<< "   "
                    <<n.label << " -- " << t.node->label
                    <<" [ label= \"" << t.node->label << "\""
                    << ", weight= \"" << t.weight << "\" ] ;\n";
        }
    }
    std::cout<< "}\n";
}

void Graph::floyd(int grafo[][V])
{
    int dist[V][V];  
  
    for (int i = 0; i < V; i++)  
        for (int j = 0; j < V; j++)  
            dist[i][j] = grafo[i][j];  
  

    for (int k = 0; k < V; k++)  
    {  
        for (int i = 0; i < V; i++)  
        {  
            for (int j = 0; j < V; j++)  
            {  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }   
    printFloyd(dist);  
}

void Graph::printFloyd(int floyd [][V])
{
    std::cout<<"\nShortest path (Floyd) \n"; 
    std::cout<<"  A\tB\tC\tD\tE\n"; 
    for (int i = 0; i < V; i++)  
    {  
        switch(i)
        {
            case 0: std::cout<<"A ";
            break;
            case 1: std::cout<<"B ";
            break;
            case 2: std::cout<<"C ";
            break;
            case 3: std::cout<<"D ";
            break;
            case 4: std::cout<<"E ";
            break;
        }
        for (int j = 0; j < V; j++)  
        {  
            if (floyd[i][j] == INF)  
                std::cout<<"INF"<<"\t";  
            else
                std::cout<<floyd[i][j]<<"\t";  
        }  
        std::cout<<std::endl;  
    }  
}