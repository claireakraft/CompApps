
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <"bloodpressure.h">

/*
float f_MAP(int s, int d) {
	float MAP;
	MAP = d + ((s - d) / 3);
	return MAP;
}

float f_PP(int s, int d) {
	float PP;
	PP = s - d;
	return PP;
}
*/
int main(void)
{

	int d;
	int s;
	float MAP;
	float PP;

	printf("Enter the systematic arterial and diastolic pressures below: \n ");

	scanf("%i", &s);
	scanf("%i", &d);

	MAP = f_MAP(s, d);
	PP = f_PP(s, d);


	printf("Systolic pressure is equal to %i mmHg \n", s);
	printf("Diastolic pressure is equal to %i mmHg \n", d);
	printf("MAP is equal to %f mmHg \n\n", MAP);

	printf("PP is equal to %f mmHg \n\n", PP);


	


	

}





