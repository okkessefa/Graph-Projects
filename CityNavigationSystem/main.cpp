/*
          Tekirdağ ──  Edirne
             |           |
       Çanakkale ── Istanbul ── Ankara ── Erzurum
                         |        |         |
                       Bursa   Eskişehir   Samsun
                         |        |
                      Izmir ─── Konya ─── Mersin ─── Hatay
                                  |                    |
                                Adana              Gaziantep

*/


#include <iostream>           // For input/output
#include <vector>             // For storing adjacency lists and paths
#include <unordered_map>      // For graph representation (Graph List)
#include <queue>              // For BFS traversal
#include <string>             // For city names (std::string)
#include <algorithm>          // For std::find, std::reverse (used in BFS path reconstruction)

// | Header            | Required?    | Purpose                                                                  |
// | ----------------- | -----------  | ------------------------------------------------------------------------ |
// | `<iostream>`      | ✅           | `cin`, `cout`, and user interaction                                      |
// | `<vector>`        | ✅           | Storing neighbor lists and traversal paths                               |
// | `<unordered_map>` | ✅           | Efficient graph representation (`unordered_map<string, vector<string>>`) |
// | `<queue>`         | ✅           | BFS traversal                                                            |
// | `<string>`        | ✅           | Handling city names as `std::string`                                     |
// | `<algorithm>`     | ✅           | `std::find()`, `std::reverse()` used in BFS path reconstruction          |


// -------------------------------------------
// 🔧 1. Initialization and Global Structures
// -------------------------------------------
// - List of cities
// vector<string> cityList;

// - Adjacency list (Graph List)
// unordered_map<string, vector<string>> graph;

// -------------------------------------------
// 🏗️ 2. Add Cities (No Coordinates Needed)
// -------------------------------------------
// - Input a city name
// - Add to cityList (if not duplicate)
// - Initialize its adjacency list entry

// -------------------------------------------
// 🔗 3. Add Roads (Graph Edges)
// -------------------------------------------
// - Input two city names
// - Add bidirectional edge in the adjacency list:
//     graph[city1].push_back(city2);
//     graph[city2].push_back(city1);

// -------------------------------------------
// 📄 4. Display Adjacency List (City Connections)
// -------------------------------------------
// - Loop through graph and print neighbors of each city

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

int main() {
    // TODO: Pre-fill sample cities and roads if desired
    // TODO: Start the user interaction menu loop
    return 0;
}