#include<stdio.h>


int main() {
    char mString[100], sString[100];
    int l1,l2;
    printf("\nEnter the main string: ");
    scanf("%s",mString);
    printf("\nEnter the sub string to search: ");
    scanf("%s",sString);
    printf("\nEnter the lengths of string, substring: "); 
    scanf("%d%d",&l1,&l2);
    
    for (int i = 0; i < l1-l2+1; i++)
    {
        int c=0;
        for (int j = i; j < i+l2; j++)
        {
            if(mString[j] == sString[j-i]){
                c++;
            }else{
                break;
            }
        }
        
        if(c==l2){
            printf("\nFound at %d.\n", i);
        }
        
    }
    


}