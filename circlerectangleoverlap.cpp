class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int closest_x = x_center, closest_y = y_center;
        int x_diff, y_diff;
        float dist_from_center;
        if (x1 > x_center)
            closest_x = x1;
        else if (x2 < x_center)
            closest_x = x2;
        if (y1 > y_center)
            closest_y = y1;
        else if (y2 < y_center)
            closest_y = y2;
        
        x_diff = closest_x - x_center;
        y_diff = closest_y - y_center;
        
        dist_from_center = sqrt((x_diff*x_diff)+(y_diff*y_diff));
        
        return dist_from_center <= radius;
    }
};
