#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <chrono>

#include <catch2/catch.hpp>

#include <graphs/adjacency_matrix_graph.hpp>
#include <graphs/adjacency_list_graph.hpp>
#include <graphs/shortest_path_algorithms.hpp>

#define DATA_DIR "../sp_data/"

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

#define LOOP 100

std::vector<int> GRAPH_SIZES = {10, 50, 100, 250, 500};
std::vector<int> DENSITIES = {25, 50, 75, 100};

const std::filesystem::path dataDirectoryPath{DATA_DIR};

void time_test(){

    ShortestPathResult result, refResult;
    int sourceIndex = 5;
    
    for(auto density : DENSITIES){
    
        std::cout << std::endl << "=====================================" << std::endl;
        std::cout << "DENSITY: " << density << std::endl << std::endl;
        
        for(auto size : GRAPH_SIZES){
        
            std::cout << "CURRENT SIZE: " << size;
            TimeVar start;
            TimeVar end;

            int m_dijkstra_time = 0;
            int m_bellman_time = 0;
            int l_dijkstra_time = 0;
            int l_bellman_time = 0;

            for(int loop = 0; loop < LOOP; loop++){
            
                FileWriter writer = FileWriter();
                writer.write(size, density);
                std::fstream file(writer.get_file_name());
                                
                auto m_graph = AdjacencyMatrixGraph::createGraph(file);

                file.clear();
                file.seekg(0);

                auto l_graph = AdjacencyListGraph::createGraph(file);

                start = timeNow();
                dijkstra(*m_graph, sourceIndex, result);
                end = timeNow();
                m_dijkstra_time += duration(end - start);

                start = timeNow();
                dijkstra(*l_graph, sourceIndex, result);
                end = timeNow();
                l_dijkstra_time += duration(end - start);

                start = timeNow();
                bellmanFord(*m_graph, sourceIndex, result);
                end = timeNow();
                m_bellman_time += duration(end - start);

                start = timeNow();
                bellmanFord(*l_graph, sourceIndex, result);
                end = timeNow();
                l_bellman_time += duration(end - start);
                
            }

            std::cout << std::endl << std::endl;

            std::cout << "Matrix Djikstra:   " << m_dijkstra_time / LOOP << "us" << std::endl;
            std::cout << "Matrix Bellman:    " << m_bellman_time  / LOOP<< "us" << std::endl;
            std::cout << "List Djikstra:     " << l_dijkstra_time  / LOOP<< "us" << std::endl;
            std::cout << "List Bellman:      " << l_bellman_time  / LOOP << "us" << std::endl;
            std::cout << std::endl;
            
        }
        
    }
    
}

int main(int argc, char* argv[]){

    ShortestPathResult result, refResult;
    int sourceIndex = 0;

    //FileWriter writer = FileWriter();
    //std::fstream file(writer.get_file_name());
    
    

    time_test();
    return 0;
    
    std::fstream file("graph.txt");

    auto graph = AdjacencyListGraph::createGraph(file);
    //auto graph = AdjacencyMatrixGraph::createGraph(file);

	bellmann(*graph, 0, result);
	
	return 1;
    Vertex* v = graph.get()->vertices().at(1);
    Edge* e = graph.get()->edges().at(1);

    std::cout << "Vertex: " << v->index << std::endl;
    std::cout << "Edge: " << e->v1->index << ", " << e->v2->index <<std::endl;
    std::cout << "-------------------" << std::endl;
    graph.get()->visualise();
    std::cout << "-------------------" << std::endl;

	//graph.get()->
	
    graph.get()->visualise();
    graph.get()->visualiseFile();
    return 0;

	
    
}
