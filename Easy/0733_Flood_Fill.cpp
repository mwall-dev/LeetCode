class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int start_color = image[sr][sc];
        if (image[sr][sc] != newColor) {
            helper_fill(image, sr, sc, start_color, newColor);
        }

        return image;
    }
    
    void helper_fill(vector<vector<int>>& image, int row, int col, int match_color, int new_color) {
        if(row >= image.size() || row < 0 || col >= image[0].size() || col < 0) return;
        
        if(image[row][col] == match_color) {
            image[row][col] = new_color;
            helper_fill(image, row+1, col, match_color, new_color);
            helper_fill(image, row-1, col, match_color, new_color);            
            helper_fill(image, row, col+1, match_color, new_color);
            helper_fill(image, row, col-1, match_color, new_color);
        } 
    }
};
