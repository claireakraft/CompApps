

/* This program determines the sum of three floating point numbers*/

#pragma warning (disable: 4996) 
// preprocessor statements
#include <stdio.h> 
#include <stdlib.h> 


int main(void)
{
    //declaration statements
    float sum, product, mean, a, b, c;

    //output statement
    printf("Enter the values of a, b, and c \n");

    //input statement
    scanf(" % f % f % f", &a, &b, &c);

    //arithmatic statements
    sum = a + b + c;
    product = a * b * c;
    mean = (a + b + c) / 3.0;

    //output statements
    printf("Sum = a + b + c = % 3.4f \n", sum);
    printf("Product = (a * b * c) = % 3.3f \n", product);
    printf("Mean = (a + b + c) / 3 = % 3.3f \n", mean);

    //i/o statement
    system("pause");

    //output statement
    return 0;
}

