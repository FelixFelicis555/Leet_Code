class Solution {
public:
    int bestClosingTime(string customers) {
        int pen=count(begin(customers),end(customers),'Y');
        int min_pen=pen,j=-1;
        for(int i=0;i<customers.size();i++)
        {
            if(customers[i]=='Y')
                --pen;
            else
                ++pen;
            if(pen<min_pen)
            {
                min_pen=pen;
                j=i;
            }
        }
        return j+1;
    }
};