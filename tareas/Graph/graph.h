#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <string>

#define INF 99999
#define V 5

class Graph
{
    public:

    class Node;

    class Edge
    {
    public:
        Edge(const Node *node, int weight)
        : node(node), weight(weight)
        {}
        
        const Node *node;
        int weight;
    };

    class Node
    {
        public:
        Node(long id, const std::string& lbl)
        :id(id), label(lbl)
        {}

        void addEdge(const Node* node, int weight)
        {
            edges.emplace_back(node, weight);
        }

        std::vector<Edge> edges;
        std::string label;
        long id;
    };

    void print() const;

    Graph()
    {}
    void addNode(long id, const std::string& lbl)
    { nodes.emplace_back(id, lbl);}

    void dijsktra(long src_id, std::vector<long>& costv, std::vector<long>& pathv);
    void floyd(int grafo[][V]);
    void printFloyd(int floyd [][V]);

    Node* nodeById(long node_id);
    
    public:

    void genDotOutPut() const;
    std::vector<Node> nodes;

};

#endif