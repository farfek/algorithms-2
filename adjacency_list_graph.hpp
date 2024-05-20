#ifndef ADJACENCY_LIST_GRAPH_HPP_
#define ADJACENCY_LIST_GRAPH_HPP_

#include <memory>

#include "graphs/graph.hpp"
#include <structures/file.hpp>
#include <unordered_map>
#include <list>

class AdjacencyListGraph : public Graph{

  private:
  
    Vertex* starting_vertex;
    int starting_vertex_index;
    int size;

    std::unordered_map<Vertex*, std::list<Edge*>> v_map;
    std::vector<Vertex*> v_vector;
    std::vector<Edge*> e_vector;

  public:
    
    static std::unique_ptr<Graph> createGraph(std::istream& is);
    void insertVertex(Vertex* v) override;
    void insertEdge(Vertex* v1, Vertex* v2, int weight) override;
    void removeVertex(Vertex* v) override;
    void removeEdge(Edge* edge) override;
    void replace(Vertex* v, std::string label) override;
    void replace(Edge* edge, int weight) override; 
    std::vector<Edge*> incidentEdges(Vertex* v) override;
    std::vector<Edge*> edges() override;
    std::vector<Vertex*> vertices() override;
    std::vector<Vertex*> endVertices(Edge* edge) override;
    Vertex* opposite(Vertex* v, Edge* egde) override;
    bool areAdjacent(Vertex* v1, Vertex* v2) override;
    void visualise() override;
    void visualiseFile() override;
    Vertex* get_starting_vertex() override;
    
};

#endif /* ADJACENCY_LIST_GRAPH_HPP_ */
