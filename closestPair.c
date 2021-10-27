#include<stdio.h>
#include<math.h>

struct k{
    float x;
    float y;
};

float calculateDistance(struct k p1, struct k p2) {
    float xDis = (p2.x - p1.x)*(p2.x - p1.x);
    float yDis = (p2.y - p1.y)*(p2.y - p1.y);
    float res = sqrt((double)xDis+yDis);
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

    float min = 99999;
    int p1=-1,p2=-1;
    for(int i=0; i<n-1;i++) {
        for(int j=i+1; j<n;j++) {
            float dis = calculateDistance(points[i], points[j]);
            if(dis < min) {
                min = dis;
                p1=i;
                p2=j;
            }
        }
    }

    printf("\nThe closes pair are: (%.1f, %.1f) and (%.1f, %.1f)\n", points[p1].x,points[p1].y, points[p2].x, points[p2].y);
}