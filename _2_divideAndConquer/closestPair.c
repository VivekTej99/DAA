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

void swap(struct k p[], int i, int j) {
    struct k temp = p[i];
    p[i] = p[j];
    p[j] = temp;
} 

void quickSort(struct k p[], int st, int end, int key) {
    /* Base case here */
    if(st < end) {

        int pivotI = st;
        int pivotE = (key == 0 ? p[pivotI].x : p[pivotI].y);
        int i=st+1,j=end;
        int ele;
        while(i<j) {
            while(i<j) {
                ele = (key == 0 ? p[i].x : p[i].y);
                if(ele > pivotE) {
                    break;
                }
                if(i>= j) {
                    break;
                }
                i++;
            }
            while(i<j) {
                ele = (key == 0 ? p[j].x : p[j].y);
                if(ele < pivotE) {
                    break;
                }
                if(i>= j) {
                    break;
                }
                j--;
            }
            if(i<j) {
                swap(p, i,j);
            }
        }
        // printf("\nSorted pivot index: %d", pivotI);
        swap(p, j, pivotI);
        quickSort(p,st,j-1,key);
        quickSort(p,j+1,end,key);
        
    }

    
    
}

void sortPoints(int n,struct k p[], int key) {
    /* Quick Sort algorithm based on key*/

    quickSort(p, 0,n-1, key);
}

float bruteForce(int m,int n, struct k points[]) {
    float min = 99999;
    int p1=-1,p2=-1;
    for(int i=m; i<n-1;i++) {
        for(int j=i+1; j<n;j++) {
            float dis = calculateDistance(points[i], points[j]);
            if(dis < min) {
                min = dis;
                p1=i;
                p2=j;
            }
        }
    }
    return min;
}

int csp(int n, struct k p[],int i , int j) {
    /* Base case goes here  */

    if(j-i <= 3) {
        /* Brutforce approach */
        int dis = (int)bruteForce(i,j+1,p);
        return dis;
    }

    int mid = i+j/2;
    int dl = csp(n, p, i, mid-1);
    int dr = csp(n, p, mid+1, j);
    int d = dl < dr ? dl: dr;
    struct k strip[n];
    int l=0,m=0;
    for(l=0;l<=j;l++) {
        if(p[l].x - p[mid].x > 0 && p[l].x - p[mid].x < d) {
            strip[m++] = p[l];

        }
        else if(p[l].x - p[mid].x < 0 && (p[l].x - p[mid].x)*-1 < d) {
            strip[m++] = p[l];
        }
    }
    /* Sort strip array based on y coordinates */
    sortPoints(m,strip,1);

    int minD=9999;
    for(int s = 0; s<m-1;s++) {
        for (int r=s+1; r<m; r++) {
            if(strip[r].y - strip[s].y < d) {
                minD = calculateDistance(strip[r], strip[s]);
            }else {
                break;
            }
        }
    }
    if(minD < d) {
        d= minD;
    }
    return d;
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

    struct k output[2];

    /* Sort the Array based on x coordinates */
    sortPoints(n,points,0);
    
    /* for(int i=0;i<n;i++) {
        printf("\n (x, y): (%f, %f)", points[i].x, points[i].y);
    } */

    int d = csp(n,points,0,n-1);
    printf("\nThe minimum distance is: %d.\n",d);

    


}