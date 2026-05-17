#include<bits/stdc++.h>
using namespace std;

//x,y=position
// g = steps travelled
// h = remaining distance
// path = moves taken
// f() = total cost (g+h)
struct Node {
    int x, y;
    int g, h;
    string path;
    int f() {
        return g + h;
    }
};

//custom operator, for sorting according to f() value in priority queue
struct Compare {
    bool operator()(Node a, Node b) {
        return a.f() > b.f();
    }
};

int main() {
    int n = 5;
    // 0 = open , 1=obstacle
    vector<vector<int>> grid = {
        {0,0,0,0,0},
        {1,1,1,1,0},
        {0,0,0,1,0},
        {0,1,1,0,0},
        {0,0,0,0,0}
    };

    int sx = 0, sy = 0; // start
    int dx = 4, dy = 4; // goal

    priority_queue<Node, vector<Node>, Compare> pq;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // Start node
    // h(n) = |x-xgoal| + |y-ygoal| (Manhattan distance)
    pq.push({sx, sy, 0,abs(sx - dx) + abs(sy - dy),""});

    // Directions
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // U D L R

    string move = "UDLR"; // used for printing path
    while(!pq.empty()) {
        Node curr = pq.top();
        pq.pop();
        int x = curr.x;
        int y = curr.y;
        if(visited[x][y]) continue;

        visited[x][y] = true;
        // Destination reached
        if(x == dx && y == dy) {
            cout << "Path Found\n";
            cout << "Cost = " << curr.g << endl;
            cout << "Moves = " << curr.path << endl;
            return 0;
        }

        // Explore neighbors
        for(int i = 0; i < 4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            // Valid cell
            if(nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if(grid[nx][ny] == 0 && !visited[nx][ny]) {
                    int newg = curr.g + 1; // steps taken till now
                    int newh = abs(nx - dx) + abs(ny - dy); // heuristic
                    pq.push({
                        nx,
                        ny,
                        newg,
                        newh,
                        curr.path + move[i]
                    });
                }
            }
        }
    }
    cout << "No Path Found";
    return 0;
}