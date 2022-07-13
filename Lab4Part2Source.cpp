
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

int power(int);



int main(void) {

	int num = 0, paddednum = 0;
	int a, b, fs, endNum;
	char filename[100], outfile[100];
	FILE * infile, * outputfile;
	float * time, * sin, * amp, * freq;

	printf("What is the Sampling frequency?  \n");
	scanf("%i", &fs);


	printf("File name: ");
	scanf("%s", filename);
	infile = fopen(filename, "r");

	if (infile == NULL) {
		printf("File does not exist\n");
		exit(EXIT_FAILURE);
	}

	while ((fscanf(infile, "%f %f", &a, &b)) != EOF) {
		num++;
	}
	printf("n for signal is %i\n", num);
	rewind(infile);

	paddednum = power(num);
	endNum = (paddednum / 2.0) - 1;


	time = (float*)calloc(sizeof(float), paddednum);
	sin = (float*)calloc(sizeof(float), paddednum);
	amp = (float*)calloc(sizeof(float), endNum +1);
	freq = (float*)calloc(sizeof(float), endNum +1);

	for (int i = 0; i < paddednum; i++) {
		fscanf(infile, "%f %f", &time[i], &sin[i]);
	}


	fft(sin, paddednum, 1);


	int i = 2;
	amp[0] = sin[0] / num;
	amp[endNum] = sin[1] / num;
	for (int k = 1; k < endNum; k++) {
		amp[k] = (sqrt(pow(sin[i], 2.0) + pow(sin[i + 1], 2.0)) * (2.0 / num));
		//amp[k] = (sqrt(pow(sin[i], 2.0) + pow(sin[i + 1], 2.0)) * 1.0);
		i = i + 2;
	}


	freq[0] = 0;
	freq[endNum] = fs / 2.0;

	for (int k = 1; k < endNum; k++) {
		freq[k] = (float)k * ((float)fs /paddednum);
	}


	printf("Outfile name:  ");
	scanf("%s", outfile);
	outputfile = fopen(outfile, "w");

	if (outfile == NULL) {
		printf("File could not be made.\n");
		exit(EXIT_FAILURE);
	}


	for (int i = 0; i <= endNum; i++) {
		fprintf(outputfile, "%f\t%f\n", freq[i], amp[i]);
	}





	fclose(infile);
	fclose(outputfile);


	/*

	int a, b, n1=0, n2=0, n3=0;
	FILE* infile200, * infile400, * infile600, *outfile200, *outfile400, *outfile600;
	float *time200, *sin200, *time400, *sin400, *time600, *sin600, *amp200, *freq200, *amp400, *freq400, *amp600, *freq600;
	//float time200[1024], sin200[1024], time400[2048], sin400[2048], time600[4096], sin600[4096];
	infile200 = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab4p2\\CompAppsLab4p2\\sin200.txt", "r");
	infile400 = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab4p2\\CompAppsLab4p2\\sin400.txt", "r");
	infile600 = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab4p2\\CompAppsLab4p2\\sin600.txt", "r");
	outfile200 = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab4p2\\CompAppsLab4p2\\freq200.txt", "w");
	outfile400 = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab4p2\\CompAppsLab4p2\\freq400.txt", "w");
	outfile600 = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab4p2\\CompAppsLab4p2\\freq600.txt", "w");
	


	//finding the number of data points
	while ((fscanf(infile200, "%f %f", &a, &b)) != EOF) {
		n1++;
	}
	printf("n for 200 is %i\n", n1);

	while ((fscanf(infile400, "%f %f", &a, &b)) != EOF) {
		n2++;
	}
	printf("n for 400 is %i\n", n2);

	while ((fscanf(infile600, "%f %f", &a, &b)) != EOF) {
		n3++;
	}
	printf("n for 600 is %i\n", n3);
	rewind(infile200);
	rewind(infile400);
	rewind(infile600);

	int number1;
	for (int i = 0; i < n1; ++i) {
		int power1 = pow(2, i);
		if (power1 >= n1) {
			number1 = power1;
			printf("number of pow2 for 200 is %i\n", number1);
			break;
		}
	}

	int number2;
	for (int i = 0; i < n2; ++i) {
		int power2 = pow(2, i);
		if (power2 >= n2) {
			number2 = power2;
			printf("number of pow2 for 400 is %i\n", number2);
			break;
		}

	}

	int number3;
	for (int i = 0; i < n3; ++i) {
		int power3 = pow(2, i);
		if (power3 >= n3) {
			number3 = power3;
			printf("number of pow2 for 600 is %i\n", number3);
			break;
		}

	}
	
	time200 = (float*)calloc(sizeof(float), number1);
	sin200 = (float*)calloc(sizeof(float), number1);
	amp200 = (float*)calloc(sizeof(float), number1);
	freq200 = (float*)calloc(sizeof(float), number1);
	time400 = (float*)calloc(sizeof(float), number2);
	sin400 = (float*)calloc(sizeof(float), number2);
	amp400 = (float*)calloc(sizeof(float), number1);
	freq400 = (float*)calloc(sizeof(float), number1);
	time600 = (float*)calloc(sizeof(float), number3);
	sin600 = (float*)calloc(sizeof(float), number3);
	amp600 = (float*)calloc(sizeof(float), number3);
	freq600 = (float*)calloc(sizeof(float), number3);


	// assigning values from the files to the arrays
	
	for (int i = 0; i < number1; i++) {
		fscanf(infile200, "%f %f", &time200[i], &sin200[i]);
	}
	for (int i = 0; i < number2; i++) {
		fscanf(infile400, "%f %f", &time400[i], &sin400[i]);
	}

	for (int i = 0; i < number3; i++) {
		fscanf(infile600, "%f %f", &time600[i], &sin600[i]);
	}

	printf("%f\n", sin200[0]);
	printf("%f\n", sin200[1]);
	printf("%f\n\n", sin200[number1-1]);
	

	fft(sin200, number1, 1);
	fft(sin400, number2, 1);
	fft(sin600, number3, 1);

	printf("%f\n", sin200[0]);
	printf("%f\n", sin200[1]);
	printf("%f\n", sin200[2]);


	// finding frequency content for the 200 fs sin function 
	int i = 2;
	amp200[0] = sin200[0] / 800.0;
	amp200[(number1 / 2)-1] = sin200[1] / 800.0;
	for (int k = 1; k < (number1/2)-1; k++) {
		amp200[k] = (sqrt(pow(sin200[i], 2.0) + pow(sin200[i + 1], 2.0)) * (2.0/800.0));
		i = i+2;
	}		


	freq200[0] = 0;
	freq200[(number1 / 2)-1] = 200/2;
	for (int k = 1; k < (number1/2)-1; k++) {
		freq200[k] = (float)k * (200.0/(float)number1);
	}

	for (int i = 0; i < number1/2; i++) {
		fprintf(outfile200, "%f\t%f\n", freq200[i], amp200[i]);
	}

	// finding frequency content for the 400 fs sin function 
	
	i = 2;
	amp400[0] = sin400[0] / 1600.0;
	amp400[(number2 / 2) - 1] = sin400[1] / 1600.0;
	for (int k = 1; k < (number2 / 2) - 1; k++) {
		amp400[k] = (sqrt(pow(sin400[i], 2.0) + pow(sin400[i + 1], 2.0)) * (2.0 / 1600.0));
		i = i+2;
	}


	freq400[0] = 0;
	freq400[(number2 / 2) - 1] = 400.0 / 2;
	for (int k = 1; k < (number2 / 2) - 1; k++) {
		freq400[k] = (float)k * (400.0 / (float)number2);
	}

	for (int i = 0; i < number2/2; i++) {
		fprintf(outfile400, "%f\t%f\n", freq400[i], amp400[i]);
	}
	
	// finding frequency content for the 600 fs sin function 
	
	i = 2;
	amp600[0] = sin600[0] / 2400.0;
	amp600[(number3 / 2) - 1] = sin600[1] / 2400.0;
	for (int k = 1; k < (number3 / 2) - 1; k++) {
		amp600[k] = (sqrt(pow(sin600[i], 2.0) + pow(sin600[i + 1], 2.0)) * (2.0 / 2400.0));
		i = i + 2;
	}


	freq600[0] = 0;
	freq600[(number3 / 2) - 1] = 600.0 / 2;
	for (int k = 1; k < (number3 / 2) - 1; k++) {
		freq600[k] = (float)k * (600.0 / (float)number3);
	}

	for (int i = 0; i < number3 / 2; i++) {
		fprintf(outfile600, "%f\t%f\n", freq600[i], amp600[i]);
	}
	

	free(time200);
	free(sin200);
	free(amp200);
	free(freq200);
	free(time400);
	free(sin400);
	free(amp400);
	free(freq400);
	free(time600);
	free(sin600);
	free(amp600);
	free(freq600);

	
	*/

}



int power(int num) {
	int number1;
	for (int i = 0; i < num; ++i) {
		int power1 = pow(2, i);
		if (power1 >= num) {
			number1 = power1;
			printf("The new padded number for the signal is %i\n", number1);
			return number1;
			break;
		}
	}
	
}



