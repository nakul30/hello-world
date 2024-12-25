class Solution {
public:
     pair<int, int> farthestNode(const unordered_map<int, vector<int>>& tree, int start) {
        // If the tree is empty
        if (tree.empty()) {
            return {start, 0};
        }

        unordered_map<int, bool> visited;
        queue<pair<int, int>> q;  // pair of (node, distance)
        q.push({start, 0});
        visited[start] = true;

        pair<int, int> farthest = {start, 0};

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            farthest = {node, dist};

            for (int neighbor : tree.at(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, dist + 1});
                }
            }
        }

        return farthest;
    }

    int diameter(unordered_map<int,vector<int>> tree){
        // pelan farthet node kedia aa first valu 
        int node=farthestNode(tree,0).first ;
        int ans=farthestNode(tree,node).second;

        return ans;
    }
  
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> tree1, tree2;

        for (const auto& edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);  // Assuming it's an undirected tree
        }

        for (const auto& edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);  // Assuming it's an undirected tree
        }

        int dia1 = diameter(tree1);
        int dia2 = diameter(tree2);

        return max(max(dia1, dia2), (dia1 + 1) / 2 + (dia2 + 1) / 2 + 1);
    }
};
