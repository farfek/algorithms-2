#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <sstream>

class Vertex{

    public:
    
        std::string label;
        int index;
        
        Vertex(int index){
        
            this->index = index;
            std::stringstream ss;
            ss << index;
            this->label = ss.str();
 
        }
        
};

class Edge{

    public:
    
        Vertex* v1;
        Vertex* v2;
        int weight;

        Edge(Vertex* v1, Vertex* v2, int weight){
        
            this->v1 = v1;
            this->v2 = v2;
            this->weight = weight;
            
        }
        
};

#endif
