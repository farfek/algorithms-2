#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>
#include <structures/element.hpp>

class Graph{

  public:   
  
    virtual void insertVertex(Vertex* v) = 0;
    virtual void insertEdge(Vertex* v1, Vertex* v2, int weight) = 0;
    virtual void removeVertex(Vertex* v) = 0;
    virtual void removeEdge(Edge* edge) = 0;
    virtual void replace(Vertex* v, std::string label) = 0;
    virtual void replace(Edge* edge, int weight) = 0; 
    virtual std::vector<Edge*> incidentEdges(Vertex* v) = 0;
    virtual std::vector<Edge*> edges() = 0;
    virtual std::vector<Vertex*> vertices() = 0;
    virtual std::vector<Vertex*> endVertices(Edge* edge) = 0;
    virtual Vertex* opposite(Vertex* v, Edge* egde) = 0;
    virtual bool areAdjacent(Vertex* v1, Vertex* v2) = 0;
    virtual void visualise() = 0;
    virtual void visualiseFile() = 0;
    virtual Vertex* get_starting_vertex() = 0;
    
};

#endif /* GRAPH_HPP_ */
