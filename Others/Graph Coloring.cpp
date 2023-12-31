#include <iostream>
#include <array>
#include <vector>

/**
 * @namespace
 * @brief Backtracking algorithms
 */
namespace backtracking {
    /** A utility function to print solution
     * @tparam V number of vertices in the graph
     * @param color array of colors assigned to the nodes
     */
    template <size_t V>
    void printSolution(const std::array <int, V>& color) {
        std::cout << "Following are the assigned colors\n";
        for (auto &col : color) {
            std::cout << col;
        }
        std::cout << "\n";
    }

    /** A utility function to check if the current color assignment is safe for
     * vertex v
     * @tparam V number of vertices in the graph
     * @param v index of graph vertex to check
     * @param graph matrix of graph nonnectivity
     * @param color vector of colors assigned to the graph nodes/vertices
     * @param c color value to check for the node `v`
     * @returns `true` if the color is safe to be assigned to the node
     * @returns `false` if the color is not safe to be assigned to the node
     */
    template <size_t V>
    bool isSafe(int v, const std::array<std::array <int, V>, V>& graph, const std::array <int, V>& color, int c) {
        for (int i = 0; i < V; i++) {
            if (graph[v][i] && c == color[i]) {
                return false;
            }
        }
        return true;
    }

    /** A recursive utility function to solve m coloring problem
     * @tparam V number of vertices in the graph
     * @param graph matrix of graph nonnectivity
     * @param m number of colors
     * @param [in,out] color description // used in,out to notify in documentation
     * that this parameter gets modified by the function
     * @param v index of graph vertex to check
     */
    template <size_t V>
    void graphColoring(const std::array<std::array <int, V>, V>& graph, int m, std::array <int, V> color, int v) {
        // base case:
        // If all vertices are assigned a color then return true
        if (v == V) {
            backtracking::printSolution<V>(color);
            return;
        }

        // Consider this vertex v and try different colors
        for (int c = 1; c <= m; c++) {
            // Check if assignment of color c to v is fine
            if (backtracking::isSafe<V>(v, graph, color, c)) {
                color[v] = c;

                // recur to assign colors to rest of the vertices
                backtracking::graphColoring<V>(graph, m, color, v + 1);

                // If assigning color c doesn't lead to a solution then remove it
                color[v] = 0;
            }
        }
    }
}  // namespace backtracking

/**
 * Main function
 */
int main() {
    // Create following graph and test whether it is 3 colorable
    // (3)---(2)
    // |   / |
    // |  /  |
    // | /   |
    // (0)---(1)

    const int V = 4;  // number of vertices in the graph
    std::array <std::array <int, V>, V> graph = {
        std::array <int, V>({0, 1, 1, 1}),
        std::array <int, V>({1, 0, 1, 0}),
        std::array <int, V>({1, 1, 0, 1}),
        std::array <int, V>({1, 0, 1, 0})
    };

    int m = 3;  // Number of colors
    std::array <int, V> color{};

    backtracking::graphColoring<V>(graph, m, color, 0);
    return 0;
}
