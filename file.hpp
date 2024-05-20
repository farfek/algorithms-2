#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <structures/element.hpp>

class FileReader{

    private:
    
        std::vector<std::string> data;

    public:
    
        FileReader();
        
        FileReader(std::istream& is){
        
            std::string output;
            
            while(std::getline(is, output)) data.push_back(output);
            
        }

        std::vector<std::string> get_lines(){
            return data;
        }

        int get_size(){
            return data.size();
        }
        
        std::vector<int> parse(std::string line){
        
            std::vector<int> values;
            int value;

            std::istringstream stream(line);
            
            while(stream >> value) values.push_back(value);
                
            return values;

        }

        int get_graph_size(){
            return parse(data.front())[0];
        }

        int get_edges_count(){
            return parse(data.front())[1];
        }

        int get_starting_vertex(){
            return parse(data.back())[0];
        }

};

class FileWriter{

    public:
    
        FileWriter(){
        
            srand(time(NULL));
            
        }

        void write(int size, int density){
        
            if(density > 100) return;
                
            std::stringstream buffer;


            int max_edges = size * (size - 1) / 2;
            float_t perc = (float_t) density / 100;
            int edge_per_v = (size - 1) * perc;

            std::vector<Edge*> e_vector;
            buffer << size << " " << edge_per_v * size << "\n";
            
            for(int vertex = 0; vertex < size; vertex++){
            
                std::vector<int> used_verteces;

                for(int edge = 0; edge < edge_per_v; edge++){

                    while(true){

                        int temp = random(0, size);

                        if(!contains(used_verteces, temp)){
                        
                            if(vertex != temp){
                            
                                used_verteces.push_back(temp);
                                break;
                        
                            }
                            
                        }
                        
                    }
                    
                }

                for(auto obj : used_verteces){                
                    buffer << vertex << " " << obj << " " << random(1, 4096) << "\n";
                }
                
            }


            buffer << random(0, size) << "\n";

            std::remove("graph.txt");
            std::ofstream file;
            file.open("graph.txt");

            if(file){
            
                file << buffer.str();
                file.close();
                
            }
            
        }

        bool contains(std::vector<int> v, int number_to_check){

            if(v.empty()) return false;

            for(auto obj : v){
            
                if(obj == number_to_check){
                
                    return true;
                    
                }
                
            }

            return false;
            
        }

        int random(int low, int high){
        
            return rand() % high + low;
            
        }

        std::string get_file_name(){
        
            return "graph.txt";
            
        }
        
};

#endif

