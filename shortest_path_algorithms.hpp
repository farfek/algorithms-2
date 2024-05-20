#ifndef SHORTEST_PATH_ALGORITHMS_HPP_
#define SHORTEST_PATH_ALGORITHMS_HPP_

#include "graphs/graph.hpp"

#include <map>
#include <utility>
#include <vector>
#include <queue>
#include <cstdint>

using ShortestPathResult = std::map<int, std::pair<int, std::vector<int>>>;

void dijkstra(Graph& graph, int sourceIndex, ShortestPathResult& result);
bool bellmanFord(Graph& graph, int sourceIndex, ShortestPathResult& result);

#endif /* SHORTEST_PATH_ALGORITHMS_HPP_ */
