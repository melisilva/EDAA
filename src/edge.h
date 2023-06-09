#ifndef EDGE_H
#define EDGE_H

#include <string>
#include <functional>
#include "flight.h"

using namespace std;

class Node;


class Edge
{
    Node *source;
    Node *dest;
    Flight data;

public:
    Edge(Node *source, Node *dest, Flight data);
    Node *getSource();
    Node *getDest();
    Flight *getData();

    string toString();
    string toCSV();

    // function<bool (Edge*)>getEdgeFilter(double (*f)(Flight*), double min, double max);

    static EdgeFilter getEdgeFilter();
    // static EdgeFilter getEdgeFilter(string dataAttributeName, double min, double max);
    static EdgeFilter getEdgeFilter(function<double (Flight*)> f, double min, double max);
    static EdgeFilter getEdgeFilter(function<int (Flight*)> f, int min, int max);
    static EdgeFilter getEdgeFilter(function<string (Flight*)> f, string comparison);

    static function<double(Edge*, double&)> getEdgeWeighter(string dataAttributeName);
    static function<double(Edge*, double&)> getDoubleEdgeWeighter(function<double (Flight*)> f);
    static function<double(Edge*, double&)> getIntEdgeWeighter(function<int (Flight*f)> f);
};
#endif
