#pragma warning (disable: 4996)

#include <stdlib.h>; 


#include <stdio.h>;
#include <math.h>;

float main(void)

{
    int alpha; 
    float Gamma;
    float Beta;

    // compute result

    alpha = 40 + 36 - pow(100,2);

    Beta = 40 * 36;

    Gamma = 12.0;

    // Display results

    printf("alpha = %i\n", alpha);
    printf("Beta = %f\n", Beta);
    printf("Gamma = %f\n", Gamma);

    system("pause");

    return Gamma;

}