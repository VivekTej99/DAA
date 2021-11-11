// TravelSaleMan: Find the travel path of tavelling all the cities with minimun cost.
#include<stdio.h>


int min=9999;
void swap(int cities[] , int i, int j) {
    int temp = cities[i];
    cities[i] = cities[j];
    cities[j] = temp;
}


void tsp(int n, int binaryCities[], int costArray[][n], int st, int end, int output[]) {

    if(st == end) {
        int cost =0;
        int i=0;
        for(i=0; i<n-1;i++) {
            cost = cost + costArray[binaryCities[i]][binaryCities[i+1]];
        }
        cost = cost + costArray[binaryCities[i]][binaryCities[0]];

        if(cost < min) {
            min=cost;
            for(int j=0; j<n;j++) {
                output[j] = binaryCities[j];
            }
        }
    }
    for (int l = st; l < end; l++)
    {
        swap(binaryCities, st, l);
        tsp(n , binaryCities, costArray, st+1, end, output);
        swap(binaryCities,st, l);

    }
    

}





int main() {
    int n;
    printf("\nEnter the no. of cities: ");
    scanf("%d", &n);
    printf("\nEnter the cities string: ");
    char cities[n];
    scanf("%s", cities);
    int transformedCities[n];
    for (int i=0;i<n;i++) {
        transformedCities[i]=i;
    }
    int costArray[n][n];
    printf("\n**** Enter the cost between cities****\n");
    for (int m=0;m<n;m++) {
        for(int k=0;k<n;k++) {
            if(m!=k) {
                printf("\nEnter the cost between cities %c --> %c : ", cities[m], cities[k]);
                scanf("%d", &costArray[m][k]);
            }
        }
    }
    int output[n];
    tsp(n, transformedCities, costArray, 0,n,output);

    printf("\n*****output*****\n");
    printf("\nMin cost: %d", min);
    printf("\nPath: ");
    for (int i=0; i<n;i++) {
        printf("%c",cities[output[i]]);
    }
    printf("\n");

}