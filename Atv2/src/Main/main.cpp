#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../Graph/graph.hpp"
#include "../Algorithms/dijkstra.hpp"

int main() {
    int vertices;
    std::vector<int> arrayToEdges;
    std::vector<int*> adjMatrix;

    std::string line;
    std::ifstream file;
    file.open("../Instances/dij10.txt");
    if (file.is_open()) {
        // Gets the size of the graph to build a Adjacency Matrix.
        std::getline(file, line);
        vertices = std::stoi(line);

        // Reads the file, which contains the top half of the Adjacency Matrix.
        std::string delimiter = " ";
        while(std::getline(file, line)) {
            auto start = 0U;
            auto end = line.find(delimiter);
            int dist;
            while (end != std::string::npos) {
                dist = std::stoi(line.substr(start, end - start));
                arrayToEdges.push_back(dist);
                start = end + delimiter.length();
                end = line.find(delimiter, start);
            }
            dist = std::stoi(line.substr(start, end - start));
            arrayToEdges.push_back(dist);
        }
        file.close();
    }
    else
        std::cout << "ERROR: Unable to open file" << std::endl;

    // Creates the Adjacency Matrix.
    int* array;
    for (int i = 0; i < vertices; i++) {
        array = new int[vertices];
        adjMatrix.push_back(array);
    }
    int k = 0;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (j > i) {
                adjMatrix[i][j] = arrayToEdges[k];
                adjMatrix[j][i] = arrayToEdges[k];
                k++;
            }
            else if (j == i)
                adjMatrix[i][j] = 0;
        }
    }
    std::vector<Edge*> edgeArray = Edge::createEdgeArray(adjMatrix, vertices);

    Graph* graph = new Graph(vertices, edgeArray, adjMatrix);

    Dijkstra dijkstra;
    dijkstra.dijkstraAdjMatrix(graph, 0);

    delete[] array;
    delete graph;
    return 0;
}
