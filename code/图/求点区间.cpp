struct point{
    int x,y;
};
int quad(point a){
    if(a.x==0&&a.y==0){
        return 0;
    }
    else if(a.x>0&&a.y>=0){
        return 1;
    }
    else if(a.x<=0&&a.y>0){
        return 2;
    }
    else if(a.x<0&&a.y<=0){
        return 3;
    }
    else{
        return 4;
    }
}