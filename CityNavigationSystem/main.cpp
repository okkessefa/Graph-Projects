/*
Tekirdağ ──70── Edirne
   |              |
 120             230
   |              |
Çanakkale ──320── Istanbul ──450── Ankara ──880── Erzurum
                        |            |             |
                      150          235           420
                        |            |            |
                     Bursa ──330── Eskişehir     Samsun
                        |            |
                     330            180
                        |            |
                     Izmir ──340── Konya ──340── Mersin          Hatay
                                    |           ---                |
                                   150      ---                   190
                                    |   ---                        |
                                 Adana ──────────────────180── Gaziantep

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
    int distance;
    Node* next;
    Node(const std::string& val, int dist) : cityName(val), distance(dist), next(nullptr) {}
};


class CityNavigation 
{
private:
    // -------------------------------------------
    // 🔧 1. Initialization and Global Structures
    // -------------------------------------------
    // - Adjacency list (Graph List)
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adjacencyList;
    
    // std::unordered_map<std::string, std::vector<CityNode>> graph;

public:
    CityNavigation() {}
    
    // -------------------------------------------
    // 🏗️ 2. Add Cities (No Coordinates Needed)
    // -------------------------------------------
    // - Input a city name
    // - Add to cityList (if not duplicate)
    // - Initialize its adjacency list entry
    void  AddCity(const std::string& city)
    {
        if(adjacencyList.find(city) == adjacencyList.end()){
            adjacencyList[city] = {};
        }
    }
    
    
    // -------------------------------------------
    // 🔗 3. Add Roads Diestance (Graph Edges)
    // -------------------------------------------
    // - Input two city names and diestance
    // - Add bidirectional edge in the adjacency list:
    void  InsertEdge(const std::string& from, const std::string& to, int distance) 
    {
        adjacencyList[from].push_back({to, distance});

    }
    void  AddBidirectionalRoad(const std::string& city1 , const std::string& city2 , int distance)
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
    std::cout<<"<-----------------------Road Map Connection---------------------->"<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    std::cout<<"Tekirdağ ──70── Edirne                                           "<<std::endl;
    std::cout<<"   |              |                                              "<<std::endl;
    std::cout<<" 120             230                                             "<<std::endl;
    std::cout<<"   |              |                                              "<<std::endl;
    std::cout<<"Çanakkale ──320── Istanbul ──450── Ankara ──880── Erzurum        "<<std::endl;
    std::cout<<"                     |            |                 |            "<<std::endl;
    std::cout<<"                    150          235              420            "<<std::endl;
    std::cout<<"                     |            |                |             "<<std::endl;
    std::cout<<"                   Bursa ──330── Eskişehir       Samsun          "<<std::endl;
    std::cout<<"                     |            |                              "<<std::endl;
    std::cout<<"                     330            180                          "<<std::endl;
    std::cout<<"                      |            |                             "<<std::endl;
    std::cout<<"                    Izmir ──340── Konya ──340── Mersin    Hatay  "<<std::endl;
    std::cout<<"                                    |           ---          |   "<<std::endl;
    std::cout<<"                                   150      -90-            190  "<<std::endl;
    std::cout<<"                                    |   ---                  |   "<<std::endl;
    std::cout<<"                                 Adana ─────────180── Gaziantep  "<<std::endl;
    std::cout<<"#################################################################"<<std::endl;
    }
      // ✅ Display the full graph as an adjacency list
    void DisplayGraph() const {
        for (const auto& pair : adjacencyList) 
        {
            std::cout << pair.first << " -> ";
            for(const auto& neighbour : pair.second) 
            {
                std::cout << "(" << neighbour.first << ", " << neighbour.second << " km) ";
            }
            std::cout << "\n";
        }
    }

    // -------------------------------------------
    // 🛣️ 7. BFS Traversal
    // -------------------------------------------
    // - Ask for source and destination city
    // - Use queue, visited set, and parent map
    // - Reconstruct path from destination to source
    // - Print path with arrows (→)
    //    queue
    //    Stack
        
    // Function: BFS(start, target)
    void BFS(const std::string& start, const std::string& target){
        // - Find shortest path from start to target using Breadth-First Search
        // - Print path and total distance

        // Declare:
        // - parent map to track the previous city for each visited city
        std::unordered_map<std::string , std::string> parent;
        // - distance map to accumulate distance from start
        std::unordered_map<std::string, int> Totaldistance;
        // - visited map to mark which cities have been visited
        std::unordered_map<std::string, bool> visited;
        // - queue for BFS traversal
        std::queue<std::string> q;

        // Push start city into the queue
        q.push(start);
        // Mark start as visited
        visited[start] = true;
        // Set total distance of start to 0
        Totaldistance[start] = 0;

        // Initialize a flag called found = false
        bool found = false;

        // While queue is not empty:
        while(!q.empty()){
            //     - Take the front element (current city) and pop it
            std::string current = q.front(); q.pop();
            //     - If current == target:
            if(current == target){
                found  = true;
                break;
                //         - Set found = true
                //         - Break the loop
            }
            //     - For each neighbor of current city:
            for(const auto& neighbour : adjacencyList[current]){
                //         - Extract neighbor city and road distance
                std::string nextCity = neighbour.first;
                int roaddistance = neighbour.second;

                //         - If neighbor is not visited:
                if(!visited[nextCity]){
                    //             - Mark neighbor as visited
                    visited[nextCity] = true;
                    //             - Set parent[neighbor] = current
                    parent[nextCity] = current;
                    //             - Set totalDistance[neighbor] = totalDistance[current] + edge distance
                    Totaldistance[nextCity] = Totaldistance[current] + roaddistance;
                    //             - Push neighbor to queue
                    q.push(nextCity);
                }
            }
            
        }
        // If not found:
        if(!found){
            //     - Print: No path found from start to target
            std::cout<<"This road map is not from"<< start<< " to " << target << std::endl;
            //     - Return
            return;
        }
            
        // Reconstruct path from target to start using parent map:
        // - Create a vector called path
        std::vector<std::string> path;
        // - While at != start:
        for(std::string at = target; at != start; at = parent[at])
        {
            //     - Push at into path
            path.push_back(at);
        }
        // - Push start into path
        path.push_back(start);
        // - Reverse path to get start → target
        std::reverse(path.begin(), path.end());
            
        std::cout<<"The shortest way from"<< start << " to "<< target << "is that:"<<std::endl;
        for(size_t i = 0; i < path.size() ; i++){
            // Print path with arrows (→)
            std::cout<<path[i];
            if(i < path.size() - 1) std::cout<<" -> ";
            // Print total distance from totalDistance[target]
        }
        std::cout<<"Total distance is "<< Totaldistance[target]<< "km." << std::endl;
    }





        //Create traversal search loop :
        //    start with begin ti search until finfing the target when you find the target return roadmap
        //    use recursion then when find the way add it linked list        
        
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
    
    g.AddBidirectionalRoad("Tekirdag", "Edirne", 70); 
    g.AddBidirectionalRoad("Tekirdag", "Canakkale", 120);
    g.AddBidirectionalRoad("Canakkale", "Istanbul", 320);
    g.AddBidirectionalRoad("Istanbul", "Edirne", 230);
    g.AddBidirectionalRoad("Istanbul", "Ankara", 450);
    g.AddBidirectionalRoad("Bursa","Istanbul",  150);
    g.AddBidirectionalRoad("Ankara", "Erzurum", 880);
    g.AddBidirectionalRoad("Erzurum", "Samsun", 420);
    g.AddBidirectionalRoad("Ankara", "Eskisehir", 235);
    g.AddBidirectionalRoad("Bursa", "Eskisehir", 330);
    g.AddBidirectionalRoad("Konya", "Eskisehir", 180);
    g.AddBidirectionalRoad("Bursa", "Izmir", 330);
    g.AddBidirectionalRoad("Izmir", "Konya", 340);
    g.AddBidirectionalRoad("Konya", "Mersin", 340);
    g.AddBidirectionalRoad("Konya", "Adana", 150);
    g.AddBidirectionalRoad("Adana", "Gaziantep", 180);
    g.AddBidirectionalRoad("Mersin", "Adana", 90);


    

    
    //             ...   
    // -------------------------------------------
    // 🎛️ 5. User Interaction Menu
    // -------------------------------------------
    // - while (true):
    int command;
    while(true)
    {
        std::cout<<"<------------------MENU------------------>"<<std::endl;
        std::cout<<"Press 1 to view all cities and connections"<<std::endl;
        std::cout<<"Press 2 to Add city and road"<<std::endl;
        std::cout<<"Press 3 to finding path"<<std::endl;
        std::cout<<"Press 4 to quit from program"<<std::endl;
        std::cout<<"<--------------------------------------->"<<std::endl;

        std::cout<<"Please enter an option: ";
        std::cin>>command;
        
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<<"Invalid value, Please enter a number between 1-4"<<std::endl;
            continue;
        }
        std::cin.ignore();
        switch(command)
        {
            //     1. View all cities and connections
            case 1:
            {
                std::cout<<"<--------------------------------------->"<<std::endl;
                g.DisplayRoadMap();
                std::cout<<"<--------------------------------------->"<<std::endl;
                std::cout<<"<#######################################>"<<std::endl;
                std::cout<<"<--------------------------------------->"<<std::endl;
                g.DisplayGraph();
                std::cout<<"<--------------------------------------->"<<std::endl;

                break;
            }
            //     2. Add city and road
            case 2:
            {
                std::string place1; 
                std::string place2;
                int waydistance;
                std::cout<< "Please enter a city name and distance to add new road"<<std::endl;
                std::cout<<"City name 1: ";
                std::cin.ignore();
                getline(std::cin, place1);
                std::cout<<"City name 2: ";
                std::cin.ignore();
                getline(std::cin, place2);
                std::cout<<"Road distance: ";
                std::cin>>waydistance;
                g.AddBidirectionalRoad(place1, place2, waydistance);
                std::cin.ignore();
                break;
            }
            //     3. Find path (BFS)
            case 3:
            {
                std::string city_start; 
                std::string city_target;
                std::cin.ignore();
                std::cout<< "Please enter a starting city name target city name"<<std::endl;

                std::cout<<"City name 1: ";
                getline(std::cin, city_start);

                std::cout<<"City name 2: ";
                getline(std::cin, city_target);

                g.BFS(city_start, city_target);
                break;
            }
                //     4. Exit
            case 4:
            {
                std::cout<<"Goodbye..."<<std::endl;
                return 0;
            }
            default:
            {
                std::cout<<"Invalid value"<<std::endl;
                break;
            }
        }
    }
    return 0;
}