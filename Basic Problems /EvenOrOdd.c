//Write a Program to check whether a number is Odd or Even

#include <stdio.h>
int main() {
    int n;
    printf("Enter The Number : ");
    scanf("%d",&n);
    if(n%2==0){
        printf("This Number is Even");
    }else{
        printf("The Number is odd");
    }
    return 0;
}

/*
SAMPLE OUTPUT
Enter The Number : 8
This Number is Even
*/
