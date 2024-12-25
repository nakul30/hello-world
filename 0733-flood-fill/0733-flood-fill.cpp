class Solution {
    bool issafe(const vector<vector<int>>& image, int row, int col, int originalColor) {
        return row >= 0 && row < image.size() && col >= 0 && col < image[0].size() && image[row][col] == originalColor;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
         int originalColor = image[sr][sc];
        queue<pair<int,int>>pendingnodes;
        image[sr][sc] = color;
        pendingnodes.push({sr,sc});
        while(!pendingnodes.empty()){
            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            pair<int,int> front=pendingnodes.front();
            pendingnodes.pop();
            int row=front.first;
            int col=front.second;
            for (const auto dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                if (issafe(image, newRow, newCol, originalColor)) {
                    image[newRow][newCol] = color;
                    pendingnodes.push({newRow, newCol});
                }
            }
        }
        return image;
    }
};