#include "graphs/shortest_path_algorithms.hpp"

void dijkstra(Graph& graph, int sourceIndex, ShortestPathResult& result){

    result.clear();

    Vertex* start_vertex = graph.get_starting_vertex();
    Vertex* current_vertex = start_vertex;

    std::priority_queue<std::pair<int, Vertex*>, std::vector<std::pair<int, Vertex*>>, std::greater<std::pair<int, Vertex*>>> queue;    

    std::map<Vertex*, int> path_map;
    std::map<Vertex*, std::vector<Vertex*>> vertex_map;

    for(auto obj : graph.vertices()){
    
        vertex_map.emplace(obj, std::vector<Vertex*>{start_vertex});
        path_map.emplace(obj, INT32_MAX);
        
    }

    queue.push(std::make_pair(0, start_vertex));

    path_map.at(start_vertex) = 0;

    while(!queue.empty()){

        for(auto& edge : graph.incidentEdges(current_vertex)){

            Vertex* next_v = graph.opposite(current_vertex, edge);

            if(next_v->index == current_vertex->index) continue;
                            
            int new_distance = path_map.at(current_vertex) + edge->weight;

            if(new_distance < path_map.at(next_v)){
            
                path_map.at(next_v) = new_distance;
                queue.push(std::make_pair(edge->weight, next_v));
                vertex_map.at(next_v) = vertex_map[current_vertex];
                vertex_map[next_v].push_back(next_v);
                
            }
            
        }
        
        current_vertex = queue.top().second;
        queue.pop();
        
    }    

   for(auto v_obj : path_map){
   
        std::vector<int> path;
        
        for(auto obj : vertex_map.at(v_obj.first))
            path.push_back(obj->index);

        result.emplace(v_obj.first->index, 
        std::make_pair(path_map.at(v_obj.first), path));
            
   }
        
}

bool bellmanFord(Graph& graph, int sourceIndex, ShortestPathResult& result){

    result.clear();

    Vertex* start_vertex = graph.get_starting_vertex();

    std::map<Vertex*, int> path_map;

    std::map<Vertex*, std::vector<Vertex*>> vertex_map;

    for(auto obj : graph.vertices()){
    
        path_map[obj] = INT16_MAX;
        vertex_map[obj] = {start_vertex};
        
    }

    path_map.at(start_vertex) = 0;    

    for(int i = 0; i < graph.vertices().size() - 1; i++){
        
        for(auto& edge : graph.edges()){
            Vertex* v1 = edge->v1;
            Vertex* v2 = edge->v2;
            int weight = edge->weight;

            int new_distance = path_map[v1] + weight;

            if(new_distance < path_map[v2]){
            
                path_map.at(v2) = new_distance;
                vertex_map[v2] = vertex_map[v1];
                vertex_map[v2].push_back(v2);

            }

        }

    }


   for(auto v_obj : path_map){
   
        std::vector<int> path;
        
        for(auto obj : vertex_map.at(v_obj.first)) path.push_back(obj->index);
            
        result.emplace(v_obj.first->index, 
        std::make_pair(path_map.at(v_obj.first), path));
        
   }


    for(auto& edge : graph.edges()){
    
        Vertex* v1 = edge->v1;
        Vertex* v2 = edge->v2;
        int weight = edge->weight;
        
        int new_distance = path_map[v1] + weight;
        
        if(new_distance < path_map.at(v2)){
            std::cout << "negative cycle" << std::endl;
            return false;
            
        }

    }

    return true;
    
}
