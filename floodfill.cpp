class Solution {
public:
    void helper(vector<vector<int>>& image, int r, int c, int x, int y, int oldColor, int newColor, vector<vector<bool> > &visited) {
        if (x > -1 && x < r && y > -1 && y < c && !visited[x][y] && image[x][y] == oldColor) {
            visited[x][y] = true;
            image[x][y] = newColor;
            helper(image,r,c,x+1,y,oldColor,newColor,visited);
            helper(image,r,c,x-1,y,oldColor,newColor,visited);
            helper(image,r,c,x,y+1,oldColor,newColor,visited);
            helper(image,r,c,x,y-1,oldColor,newColor,visited);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int r = image.size(), c = image[0].size();
        vector<vector<bool> > visited(r,vector<bool>(c,false));
        helper(image,r,c,sr,sc,image[sr][sc],newColor,visited);
        return image;    
    }
};
