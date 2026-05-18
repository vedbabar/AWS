#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void coronaSpread(vector<vector<int>>& graph, int start, int n) {

    vector<bool> infected(n, false);

    queue<int> q;

    infected[start] = true;
    q.push(start);

    cout << "Corona Spread Order:\n";

    while(!q.empty()) {

        int person = q.front();
        q.pop();

        cout << "Person " << person << " infected\n";

        for(int neighbor : graph[person]) {

            if(!infected[neighbor]) {

                infected[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {

    int n = 6;

    vector<vector<int>> graph(n);

    // Connections between people
    graph[0] = {1,2};
    graph[1] = {0,3,4};
    graph[2] = {0,5};
    graph[3] = {1};
    graph[4] = {1};
    graph[5] = {2};

    coronaSpread(graph, 1, n);

    return 0;
}
