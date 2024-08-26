class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reversedGraph(n);
        vector<int> outDegree(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                reversedGraph[j].push_back(i);
            }
            outDegree[i] = graph[i].size();
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (outDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (int neighbor : reversedGraph[node]) {
                --outDegree[neighbor];
                if (outDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};