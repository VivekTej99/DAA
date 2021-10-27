#include<stdio.h>

struct k{
    float x;
    float y;
};

struct line{
    float a;
    float b;
    float c;
};

struct line calculateLineEq(struct k p1, struct k p2) {
    struct line res;
    res.a = p2.y - p1.y;
    res.b = p1.x - p2.x;
    res.c = p1.x*p2.y - p1.y*p2.x;

    return res;

}


int main() {

    int n;
    printf("\nEnter the no. of points: ");
    scanf("%d", &n);
    struct k points[100];
    for(int i=0;i<n;i++) {
        printf("\nEnter coordinates of point-  %d.\n", i+1);
        printf("x: ");
        scanf("%f", &points[i].x);
        printf("y: ");
        scanf("%f", &points[i].y);
    }
    struct k convexHull[100];
    int resultIndex=0;
    for(int i=0; i<n-1;i++) {
        for(int j=i+1; j<n;j++) {
            struct line eq = calculateLineEq(points[i], points[j]);
            int lft=0,rgt=0;
            for (int k = 0; k < n; k++)
            {
                if(i!=k && j!=k) {
                    float lhs = (eq.a*points[k].x)+(eq.b*points[k].y);
                    float rhs = eq.c;
                    if(lhs < rhs) {
                        lft++;
                    }else if(lhs > rhs) {
                        rgt++;
                    }
                    if(lft>0 && rgt>0) {
                        break;
                    }
                }
            }
            if(lft>0 && rgt==0) {
                convexHull[resultIndex++] = points[i];
                convexHull[resultIndex++] = points[j];
            }else if(rgt>0 && lft==0) {
                convexHull[resultIndex++] = points[i];
                convexHull[resultIndex++] = points[j];
            }
            
        }
    }

    printf("\nThe established convex hull for the given points is: \n\n");
    for (int i = 0; i < resultIndex; i++)
    {
        printf("(%.1f, %.1f) --> ",convexHull[i].x, convexHull[i].y);
    }
    printf("\n");
    

}