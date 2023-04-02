#ifndef MULTIGRAPH_H
#define MULTIGRAPH_H

#include <vector>

using namespace std;
template <class T>
class Node;
template <class T>
class Edge;

template <class NodeT, class EdgeT>
class Multigraph
{
    vector<Node<NodeT> *> nodes;
    vector<Edge<EdgeT> *> edges;
    vector<Edge<EdgeT> *> dijkstraShortestPath(Node<NodeT> *source, Node<NodeT> *dest, bool (*edgeFilter)(Edge<EdgeT> *), double (*edgeWeight)(Edge<EdgeT> *));
    vector<Edge<EdgeT> *> dijkstraShortestPathEdgesByNode(Node<NodeT> *source, Node<NodeT> *dest, bool (*edgeFilter)(Edge<EdgeT> *), double (*edgeWeight)(Edge<EdgeT> *));
    vector<Edge<EdgeT> *> buildPath(Node<NodeT> *source, Node<NodeT> *dest);

public:
    Multigraph();
    bool createNode(NodeT data);
    bool createEdge(Node<NodeT> *source, Node<NodeT> *dest, EdgeT data);

    void *getNodes();
    void *getEdges();

    vector<vector<Edge<EdgeT>*>> getShortestPathDijkstra(
        vector<Node<NodeT>*> nodes,
        bool (*edgeFilter)(Edge<EdgeT>*) ,
        double (*edgeWeight)(Edge<EdgeT>*),
        vector<Edge<EdgeT> *> (*dijkstra)(Node<NodeT> *, Node<NodeT> *, bool (*)(Edge<EdgeT> *), double (*)(Edge<EdgeT> *)
 );
};
#endif