class Solution {
public:
    void flood(vector<vector<int>>&image,int sr,int sc,int color,int newColor)
    {
        if (sr < 0 || sc < 0 ||  sr >= image.size() || sc >= image[0].size() || image[sr][sc] != color) {
            return;
        }
        image[sr][sc]=newColor;
        int tr=sr-1;
        int br=sr+1;
        int lc=sc-1;
        int rc=sc+1;
        flood(image,tr,sc,color,newColor);
        flood(image,br,sc,color,newColor);
        flood(image,sr,lc,color,newColor);
        flood(image,sr,rc,color,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        flood(image,sr,sc,image[sr][sc],color);
        return image;
    }
};