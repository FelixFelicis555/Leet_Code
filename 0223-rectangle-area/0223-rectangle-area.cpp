class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
       int area1=abs(ax1-ax2)*abs(ay1-ay2);
        int area2=abs(bx1-bx2)*abs(by1-by2);
        int x_dis=min(ax2,bx2)-max(ax1,bx1);
        int y_dis=(min(ay2,by2)-max(ay1,by1));
        int area=0;
        if(x_dis>0 && y_dis>0)
        {
            area=x_dis*y_dis;
        }
        return (area1+area2-area); 
    }
};