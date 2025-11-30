#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 6;
void buildGraph(vector<int> adjList[], int adjMatrix[N][N]) {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            adjMatrix[i][j]=0;
    vector<pair<int,int>> edges = {{1,4},{2,4},{2,5},{3,5},{4,5}};

    for(auto e : edges){
        int u = e.first;
        int v = e.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
}
void BFS(int start, vector<int> adjList[]){
    vector<bool> visited(N,false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting at " << start << ": ";
    while(!q.empty()){
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int v: adjList[u]){
            if(!visited[v]){
                visited[v]=true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void DFSUtil(int u, vector<int> adjList[], vector<bool> &visited){
    visited[u] = true;
    cout << u << " ";
    for(int v : adjList[u]){
        if(!visited[v])
            DFSUtil(v, adjList, visited);
    }
}

void DFS(int start, vector<int> adjList[]){
    vector<bool> visited(N,false);
    cout << "DFS Traversal starting at " << start << ": ";
    DFSUtil(start, adjList, visited);
    cout << endl;
}

int main(){
    vector<int> adjList[N];
    int adjMatrix[N][N];
    buildGraph(adjList, adjMatrix);
    cout << "Adjacency List:" << endl;
    for(int i=1;i<N;i++){
        cout << i << ": ";
        for(int v: adjList[i])
            cout << v << " ";
        cout << endl;
    }
    cout << "\nAdjacency Matrix:" << endl;
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
    BFS(1, adjList);
    DFS(1, adjList);

    return 0;
}
