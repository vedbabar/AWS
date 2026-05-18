#include <iostream>
#include <vector>

using namespace std;

void dfs(int folder, vector<vector<int>>& folders, vector<bool>& visited) {

    visited[folder] = true;

    cout << "Opening Folder " << folder << endl;

    for(int subfolder : folders[folder]) {

        if(!visited[subfolder]) {

            dfs(subfolder, folders, visited);
        }
    }
}

int main() {

    int n = 7;

    vector<vector<int>> folders(n);

    // Folder structure
    folders[0] = {1,2};
    folders[1] = {3,4};
    folders[2] = {5};
    folders[5] = {6};

    vector<bool> visited(n, false);

    cout << "Folder Traversal Using DFS:\n";

    dfs(0, folders, visited);

    return 0;
}
