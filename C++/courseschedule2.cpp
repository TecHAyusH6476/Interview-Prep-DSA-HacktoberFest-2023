#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);
    vector<int> result;

    // Create a graph representation with prerequisites
    for (auto& prereq : prerequisites) {
        int course = prereq[0];
        int prerequisite = prereq[1];
        graph[prerequisite].push_back(course);
        inDegree[course]++;
    }

    // Create a queue for topological sorting
    queue<int> q;

    // Add courses with no prerequisites to the queue
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int course = q.front();
        q.pop();
        result.push_back(course);

        for (int neighbor : graph[course]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (result.size() == numCourses) {
        return result;
    } else {
        return {}; 
    }
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    vector<int> order = findOrder(numCourses, prerequisites);

    if (!order.empty()) {
        cout << "Course order to finish all courses: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    } else {
        cout << "It is impossible to finish all courses due to prerequisites." << endl;
    }

    return 0;
}
