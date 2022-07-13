

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



void filter(float [], int, float []);
void firstDer(float [], int, float []);
void secondDer(float [], int, float []);
void scaledSum(float[], float[], int, float[]);


int main(void)
{
	// declare the variables 
	// time and amp hold the values from the file, nAmp holds the scaled ecg
	// filtout, D1, D2 and scaledout hold the outputs of each of these functions 
	int i = 0;
	float *time, *amp, *nAmp;
	float *filtout, *D1, *D2, *scaledOut;
	int n=0;
	char in_file[100];
	
	
	
	FILE *inputfile, *outfile, * outfile1;
	float a, b;

	//file declared and open in read mode
	//inputfile = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab3\\CompAppsLab3\\sinus22.txt", "r");
	outfile = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab3\\CompAppsLab3\\sinusout.txt", "w");
	outfile1 = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab3\\CompAppsLab3\\SinusOutEvents.txt", "w");

	// prompting user for data file
	printf("Enter input file name:");
	scanf("%s", in_file);
	inputfile = fopen(in_file, "r");

	// checking if file exits and exit if it doesn't
	if (inputfile == NULL) {
		printf("file does not exist.\n");
			exit(EXIT_FAILURE);
	}
	
	//finding the number of data points
	while ((fscanf(inputfile, "%f %f", &a, &b)) != EOF) {
		n++;
	}

	// setting dynamic memory allocation 
	time = (float*)calloc(sizeof(float), n);
	amp = (float*)calloc(sizeof(float), n);
	filtout = (float*)calloc(sizeof(float), n);
	D1 = (float*)calloc(sizeof(float), n);
	D2 = (float*)calloc(sizeof(float), n);
	nAmp = (float*)calloc(sizeof(float), n);
	scaledOut = (float*)calloc(sizeof(float), n);

	rewind(inputfile);

	// assigning values from the files to the arrays
	for (i = 0; i < n; i++) {
		fscanf(inputfile, "%f %f", &time[i], &amp[i]);
	}

	fclose(inputfile);

	// divide all the amplitudes by 250 
	for (i = 0; i < n; i++) {
		nAmp[i] = (amp[i]) / 250;
	}


	// calling each arithmatic function 
	filter(nAmp, n, filtout);
	firstDer(filtout, n, D1);
	secondDer(filtout, n, D2);
	scaledSum(D1, D2, n, scaledOut);

	// print out all the arrays to a txt file 
	for (i = 0; i < n; i++) {
		fprintf(outfile, "%f\t%f\t%f\t%f\t%f\t%f\n", time[i], amp[i], filtout[i], D1[i], D2[i], scaledOut[i]);
	}


	// algorithm to find the number of events in the data 
	int eventcount = 0, ptsabovethresh;
	float blank = 25, eventnum[1000], eventtime[1000], ecgAmp[1000];
	i = 0;
	while (i < n) {
		if (scaledOut[i] >= 1 ){
			ptsabovethresh = 0;
			for (int j = i; j< i + 8 && j<n; j++) {
				if (scaledOut[j] >= 1) {
					ptsabovethresh = ptsabovethresh + 1;
				}
				if (ptsabovethresh >= 6) {
					eventcount = eventcount + 1;
					eventnum[eventcount - 1] = eventcount;
					eventtime[eventcount - 1] = time[i];
					ecgAmp[eventcount - 1] = amp[i];
					i = i + blank;
					break;
				}
			}
			i++;
		}
		else
			i++;
	}

	// calculating the average heart rate 
	float avgHR;
	avgHR = eventnum[12] / (eventtime[12] / 60.0);

	// calculating the selectivity and positive predictability
	float se, pp;
	se = eventnum[12] / eventnum[12] + 0;
	pp = eventnum[12] / eventnum[12] + 0;

	// print out all the arrays to a txt file 
	for (i = 0; i < 13; i++) {
		fprintf(outfile1, "%f\t%f seconds\t%f mV\n", eventnum[i], eventtime[i], ecgAmp[i]);
	}
	fprintf(outfile1, "\nThe average heart Rate is %f", avgHR);



	// print out all the arrays
	printf("Event Number\tTime\t\t\tAmplitude\n");
	for (i = 0; i < 13; i++) {
		printf("%f\t%f seconds\t%f mV\n", eventnum[i], eventtime[i], ecgAmp[i]);
	}
	printf("\nThe average heart Rate is %f.\n", avgHR);
	printf("The selectivity of the event detection algorithm is %f.\n", se);
	printf("The positive predictability of the event detection algorithm is %f.\n", pp);


	// free all the pointers that are dynamic 
	free(time);
	free(amp);
	free(filtout);
	free(D1);
	free(D2);
	free(nAmp);

}

//filtering fuction 
void filter(float data[], int n, float out[]) {
	int i;
	for (i = 2; i < n - 2; i++) {
		out[i] = ((data[i] + (2*data[i - 1]) +data[i-2])) / 4.0;

	}

}

// function to calculate the first derivative of an array of values 
void firstDer(float data[], int n, float out[]) {
	int i;
	for (i = 2; i < n-2; i++) {
		out[i] = fabs(data[i + 1] - data[i - 1]);
		
	}

}

// function to caculate the second derivative of an array of values
void secondDer(float data[], int n, float out[]) {
	int i, x= 0;
	for (i = 2; i < n-2; i++) {
		out[i] = fabs(data[i + 2] - 2*data[i] + data[i - 2]); 

	}
	
}

// function of the scaled sum of the first and second derivatives 
void scaledSum(float fd[], float sd[], int n, float scaledout[]) {
	int i;
	for (i = 0; i < n-1; i++) {
		scaledout[i] = 1.3 * fd[i] + 1.1 * sd[i];
	}

}



