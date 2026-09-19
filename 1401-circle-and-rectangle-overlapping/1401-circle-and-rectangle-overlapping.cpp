class Solution {
public:
    bool checkOverlap(int r, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x,y;
        int dis=1e8;
        for(int i=x1;i<=x2;i++){
            int z=abs(i-xCenter);
            if(z<dis){
                dis=z;
                x=i;
            }
        }
        dis=1e8;
         for(int i=y1;i<=y2;i++){
            int z=abs(i-yCenter);
            if(z<dis){
                dis=z;
                y=i;
            }
        }
        x=abs(xCenter-x);
        y=abs(yCenter-y);
        if(x*x+y*y<=r*r)return true;
        return false;
    }
};