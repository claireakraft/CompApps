/*
name: Claire Kraft
class: Computer Applications
section: 401
TA: Tianling Niu
*/


#pragma warning (disable: 4996)
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include "fftfiltera.h"


int main(void) {

	////part one of week 1
	
	//// initializing variables
	//int N = 512, Filter, fs;
	//static float impulse[512], time[512];
	//char fileout[200]; //store output file name
	//FILE* output; //output file pointer
	//impulse[0] = 1.0;
	
	//// have the user enter the sampling frequency 
	//printf("What is the Sampling frequency? \n");
	//scanf("%i", &fs);


	//// ask the user if they want to use the lowpass or high-pass filter
	//printf("Enter 1 for lowpass and 2 for highpass: ");
	//scanf("%i", &Filter);
	//

	//if (Filter == 1) {
	//		lowpass(impulse, N);
	//}
	//else if (Filter == 2) {
	//	highpass(impulse, N);
	//}
	//else {
	//	printf("Wrong Enter\n");
	//	exit(EXIT_FAILURE);
	//}

	//// create an array with time using the sampling frequency 
	//for (int i = 0; i < (N / 2); i++) {
	//	time[i] = i * (1.0 / fs);
	//}

	//// ask user for the name of output file to print the data onto and make sure the program can make the file
	//printf("Outfile name:  ");
	//scanf("%s", fileout);
	//output = fopen(fileout, "w");

	//if (fileout == NULL) {
	//	printf("File could not be made.\n");
	//	exit(EXIT_FAILURE);
	//}

	//// print the data onto the said file
	//for (int i = 0; i < N/2; i++) {
	//	fprintf(output, "%f\t%f\n", time[i], impulse[i]);
	//}

	//fclose(output);

	// coment out all lines below this line to run part 1 and comment all lines above this line to run part 2

	// part2

	// initializing variables
	int num = 0;
	int a, b, fs, filter;
	char filename[100], outfile[100];
	FILE* infile, * outputfile;
	float *time, * Impulse;


	// prompt user for file name and opwn file if it exits
	printf("File name: ");
	scanf("%s", filename);
	infile = fopen(filename, "r");

	if (infile == NULL) {
		printf("File does not exist\n");
		exit(EXIT_FAILURE);
	}

	// find the number of data points in the file 
	while ((fscanf(infile, "%f %f", &a, &b)) != EOF) {
		num++;
	}
	printf("n for signal is %i\n", num);
	rewind(infile);


	// dynamically allocate arrays 
	time = (float*)calloc(sizeof(float), num);
	Impulse = (float*)calloc(sizeof(float), num);
	
	// scan in all the data from the file into the arrays 
	for (int i = 0; i < num; i++) {
		fscanf(infile, "%f %f", &time[i], &Impulse[i]);
	}


	// ask the user if they want to use the lowpass or high-pass filter
	printf("Enter 1 for lowpass and 2 for highpass: ");
	scanf("%i", &filter);
	if (filter == 1) {
		lowpass(Impulse, num);
	}
	else if (filter == 2) {
		highpass(Impulse, num);
	}
	else {
		printf("Error you stupid idiot\n");
		exit(EXIT_FAILURE);
	}
	

	// ask user for the name of output file to print the data onto and make sure the program can make the file
	printf("Outfile name:  ");
	scanf("%s", outfile);
	outputfile = fopen(outfile, "w");

	if (outfile == NULL) {
		printf("File could not be made.\n");
		exit(EXIT_FAILURE);
	}


	// print the data to said output file 
	for (int i = 0; i < num; i++) {
		fprintf(outputfile, "%f\t%f\n", time[i], Impulse[i]);
	}


	fclose(infile);
	fclose(outputfile);




}





