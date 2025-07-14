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
    std::string cityName;
    int weight;
    Node* next;
    Node(const std::string& val, int weight) : cityName(val), weight(weight), next(nullptr) {}
    // CityNode(std::string data, int weight, Node* next)
    // {
    //     this->data = data;
    //     this->age = age;
    //     this->gpa = gpa;
    // }
};
class CityNavigation
{
private:
    // -------------------------------------------
    // 🔧 1. Initialization and Global Structures
    // -------------------------------------------
    // - Adjacency list (Graph List)
    std::unordered_map<std::string, Node*> adjacencyList;
    // std::unordered_map<std::string, std::vector<CityNode>> graph;
public:
    CityNavigation() {}
    // -------------------------------------------
    // 🏗️ 2. Add Cities (No Coordinates Needed)
    // -------------------------------------------
    // - Input a city name
    // - Add to cityList (if not duplicate)
    // - Initialize its adjacency list entry
    void AddCity(const std::string& city)
    {
        if(adjacencyList.find(city) == adjacencyList.end()){
            adjacencyList[city] = nullptr;
        }
    }
    
    
    // -------------------------------------------
    // 🔗 3. Add Roads Diestance (Graph Edges)
    // -------------------------------------------
    // - Input two city names and diestance
    // - Add bidirectional edge in the adjacency list:
    void InsertEdge(const std::string& from, const std::string& to, int distance) 
    {
        Node* newNode = new Node(to, distance);
        if(adjacencyList[from] == nullptr)
        {
            adjacencyList[from] = newNode;
        } 
        else
        {
            Node* current = adjacencyList[from];
            while(current->next != nullptr)
            {
                current = current->next; 
            }
            current->next = newNode;
        }

    }
    void AddBidirectionalRoad(const std::string& city1 , const std::string& city2 , int distance)
    {
        AddCity(city1);
        AddCity(city2);
        InsertEdge(city1, city2, distance);
        InsertEdge(city2, city1, distance);
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
      // ✅ Display the full graph as an adjacency list
    void DisplayGraph() const {
        for (const auto& pair : adjacencyList) {
            std::cout << pair.first << " -> ";
            Node* current = pair.second;
            while (current != nullptr) {
                std::cout << "(" << current->cityName << ", " << current->weight << " km) ";
                current = current->next;
            }
            std::cout << "\n";
        }
    }


    
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
    
    ~CityNavigation() {
        for (auto& [city, head] : adjacencyList) {
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

};


int main() {
    // TODO: Pre-fill sample cities and roads if desired
    // TODO: Start the user interaction menu loop
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
    
    
    CityNavigation g;
    
    g.AddBidirectionalRoad("Tekirdag", "Edirne", 70);
    g.AddBidirectionalRoad("Tekirdag", "Canakkale", 120);
    g.AddBidirectionalRoad("Canakkale", "Istanbul", 320);
    g.AddBidirectionalRoad("Istanbul", "Ankara", 450);
    g.AddBidirectionalRoad("Istanbul", "Bursa", 150);
    g.AddBidirectionalRoad("Ankara", "Erzurum", 880);
    g.AddBidirectionalRoad("Ankara", "Eskisehir", 235);
    g.AddBidirectionalRoad("Erzurum", "Samsun", 420);
    g.AddBidirectionalRoad("Bursa", "Eskisehir", 330);
    g.AddBidirectionalRoad("Bursa", "Izmir", 330);
    g.AddBidirectionalRoad("Izmir", "Konya", 340);
    g.AddBidirectionalRoad("Konya", "Mersin", 340);
    g.AddBidirectionalRoad("Mersin", "Hatay", 200);
    g.AddBidirectionalRoad("Konya", "Adana", 150);
    g.AddBidirectionalRoad("Adana", "Gaziantep", 180);
    
    //             ...   
    
    // Display Options
    g.DisplayGraph();
    g.DisplayRoadMap();
    
    //int command;
    //do{
    //    //The menu goes here
    //}while(command !=6);
    return 0;
}