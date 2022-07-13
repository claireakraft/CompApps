
/* 
name: Claire Kraft
class: Computer Apllication 
section: 401
TA: Tianling Niu
*/


#pragma warning (disable: 4996)
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
// header creater with the mean, varience, and skewness function 
// #include "meanvarskew.h"


float fmean(float[], int);
float fvarience(float[], int, float);
float fskewness(float[], int, float, float); 


int main(void)
{
	// i is used as a counter for the loops, data1 and data2 are used to store the data from the file 
	// m holds the mean, var holds the varience, and skewn holds the skewness 
	int i;
	static float data1[270], data2[270];
	static float m1, var1, skewn1, m2, var2, skewn2;
	static int n;

	FILE *inputfile, *outfile;

	// file declared and open in read mode
	inputfile = fopen("C:\\Users\\13096\\source\\repos\\Lab2\\Lab2\\Age_sys_P.txt", "r");
	// file declared and open in write mode
	outfile = fopen("C:\\Users\\13096\\source\\repos\\Lab2\\Lab2\\Age_sys_P_out.txt", "w");

	// prompting the user for the amont of data points to be analyzed
	printf("Enter the number of data points in the file:\n");
		scanf("%i", &n);

	
	// assigning values from the files to the arrays
	for (i = 0; i < n;i++) {
		fscanf(inputfile, "%f", &data1[i]);
		fscanf(inputfile, "%f", &data2[i]);
	}
	fclose(inputfile);


	// call functions for ages
	m1 = fmean(data1, n);
	var1 = fvarience(data1, n, m1);
	skewn1 = fskewness(data1, n, m1, var1);

	// print values for ages to text document 
	fprintf(outfile, "the mean age from the file is %3.2f years\n", m1);
	fprintf(outfile, "the varience of ages from the file is %3.2f years\n", var1);
	fprintf(outfile, "the skewness of ages from the file is %3.2f years \n", skewn1);

	// print out values for ages 
	printf("the mean of age from the file is %3.2f years \n", m1);
	printf("the varience of ages from the file is %3.2f years\n", var1);
	printf("the skewness of ages from the file is %3.2f years\n\n", skewn1);

	// call functions for systolic pressure
	m2 = fmean(data2, n);
	var2 = fvarience(data2, n, m2);
	skewn2 = fskewness(data2, n, m2, var2);

	//print out values for systolic pressure to text document 
	fprintf(outfile, "the mean systolic pressure from the file is %3.2f mmHg \n", m2);
	fprintf(outfile, "the varience of systolic pressures the data from the file is %3.2f mmHg\n", var2);
	fprintf(outfile, "the skewness of systolic pressures from the file is %3.2f mmHg \n", skewn2);

	// print out values for systolic pressure
	printf("the mean systolic pressure from the file is %3.2f mmHg \n", m2);
	printf("the varience of systolic pressures from the file is %3.2f mmHg\n", var2);
	printf("the skewness of systolic pressures from the file is %3.2f mmHg\n", skewn2);

	fclose(outfile);

	return 0;


}


// function to find the mean of the data 

float fmean(float data[], int n) {
	float count = 0;
	float mean = 0;
	for (int i = 0; i < n; i++) {
		count = count + data[i];
	}
	mean = count / n;
	return mean;

}
// function to find the varience of the data 
float fvarience(float data[], int n, float m) {
	float count = 0;
	float v, x = 0;
	for (int i = 0; i < n;i++) {
		x = pow((data[i] - m), 2.0);
		count = count + x;
	}
	v = count / (n - 1);
	return v;

}
// function to find the skewness of the data 
float fskewness(float data[], int n, float m, float v) {
	float count = 0;
	float s, x = 0;
	for (int i = 0; i < n; i++) {
		x = pow((data[i] - m), 3.0);
		count = count + x;
	}

	s = (count * (1.00 / ((float)n - 1.00))) / (pow(v, (1.50)));
	return s;


}



