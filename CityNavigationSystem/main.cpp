/*
Tekirdağ ──70── Edirne
   |              |
 120             230
   |              |
Çanakkale ──320── Istanbul ──450── Ankara ──880── Erzurum
                        |            |             |
                      150          235           420
                        |            |
                     Bursa ──330── Eskişehir     Samsun
                        |
                     330
                        |
                     Izmir ──340── Konya ──340── Mersin ──200── Hatay
                                   |                         |
                                 150                     190
                                   |                         |
                                 Adana ───────────────180── Gaziantep

*/


#include <iostream>           // For input/output
#include <vector>             // For storing adjacency lists and paths
#include <unordered_map>      // For graph representation (Graph List)
#include <queue>              // For BFS traversal
#include <stack>              // For rotation check list
#include <string>             // For city names (std::string)
#include <algorithm>          // For std::find, std::reverse (used in BFS path reconstruction)

// | Header            | Required?    | Purpose                                                                  |
// | ----------------- | -----------  | ------------------------------------------------------------------------ |
// | `<iostream>`      | ✅           | `cin`, `cout`, and user interaction                                      |
// | `<vector>`        | ✅           | Storing neighbor lists and traversal paths                               |
// | `<unordered_map>` | ✅           | Efficient graph representation (`unordered_map<string, vector<string>>`) |
// | `<queue>`         | ✅           | BFS traversal                                                            |
// | `<stack>`         | ✅           | Check List                                                            |
// | `<string>`        | ✅           | Handling city names as `std::string`                                     |
// | `<algorithm>`     | ✅           | `std::find()`, `std::reverse()` used in BFS path reconstruction          |

//All futures can be used as class attributes
struct Node {
    std::string data;
    int weight;
    Node* next;
    Node(std::string val, int weight) : data(val), weight(weight), next(nullptr) {}
};

class CityNavigation
    {
private:
    // -------------------------------------------
    // 🔧 1. Initialization and Global Structures
    // -------------------------------------------
    // - List of cities
    std::vector<std::string> cityList;
    // - Adjacency list (Graph List)
    std::unordered_map<std::string, std::vector<Node>> graph;
public:
    // -------------------------------------------
    // 🏗️ 2. Add Cities (No Coordinates Needed)
    // -------------------------------------------
    // - Input a city name
    // - Add to cityList (if not duplicate)
    // - Initialize its adjacency list entry
    void AddCity(const std::string& city)
    {
        if(graph.find(city) == graph.end()){
            cityList.push_back(city);
        }
        graph[city] = {};
    }

    // -------------------------------------------
    // 🔗 3. Add Roads Diestance (Graph Edges)
    // -------------------------------------------
    // - Input two city names and diestance
    // - Add bidirectional edge in the adjacency list:
    void EstablishRoad(const std::string from , const std::string to , int distance, bool  bidirectional = true)
    {
        graph[from].emplace_back(to , distance);
        if(bidirectional){
            graph[to].emplace_back(from, distance);
        }
    }

    // -------------------------------------------
    // 📄 4. Display Adjacency List (City Connections)
    // -------------------------------------------
    // - Loop through graph and print neighbors of each city
    void DisplayRoadMap(){
    std::cout<<"<-------------------Road Map Connection-------------------->"<<std::endl;
    std::cout<<"############################################################"<<std::endl;
    std::cout<<"#       Tekirdağ ──  Edirne                                #"<<std::endl;
    std::cout<<"#          |           |                                   #"<<std::endl;
    std::cout<<"#    Çanakkale ── Istanbul ── Ankara ── Erzurum            #"<<std::endl;
    std::cout<<"#                      |        |         |                #"<<std::endl;
    std::cout<<"#                    Bursa   Eskişehir   Samsun            #"<<std::endl;
    std::cout<<"#                      |        |                          #"<<std::endl;
    std::cout<<"#                   Izmir ─── Konya ─── Mersin ─── Hatay   #"<<std::endl;
    std::cout<<"#                               |                    |     #"<<std::endl;
    std::cout<<"#                             Adana              Gaziantep #"<<std::endl;
    std::cout<<"############################################################"<<std::endl;
    }



    // -------------------------------------------
    // 🎛️ 5. User Interaction Menu
    // -------------------------------------------
    // - while (true):
    //     1. View all cities and connections
    //     2. Add city
    //     3. Add road
    //     4. Find path (DFS)
    //     5. Find path (BFS)
    //     6. Exit

    // -------------------------------------------
    // 🧭 6. DFS Traversal
    // -------------------------------------------
    // - Ask for source and destination city
    // - Use recursive DFS
    // - Track visited nodes
    // - If path exists, print using arrows (→)

    // -------------------------------------------
    // 🛣️ 7. BFS Traversal
    // -------------------------------------------
    // - Ask for source and destination city
    // - Use queue, visited set, and parent map
    // - Reconstruct path from destination to source
    // - Print path with arrows (→)

    // -------------------------------------------
    // 🛑 8. Exit Program
    // -------------------------------------------
    // - Exit loop on user command
    // - Optional: print goodbye message
};

int main() {
    // TODO: Pre-fill sample cities and roads if desired
    // TODO: Start the user interaction menu loop
    CityNavigation g;

    g.AddCity("Istanbul");
    g.AddCity("Ankara");
    g.AddCity("Izmir");

    // Add connections
    g.EstablishRoad("Istanbul", "Ankara", 450);
    g.EstablishRoad("Istanbul", "Izmir", 480);
    g.EstablishRoad("Ankara", "Izmir", 520);

    // Display
    g.DisplayRoadMap();
    return 0;
}