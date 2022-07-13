
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





int main(void) {

	// declaring the arrays to hold the different sin functions created
	int i;
	float sin1a[2500], sin2a[2500], sin3a[2500], sin4a[2500], timea[2500], outa[2500];
	float sin1b[2500], sin2b[2500], sin3b[2500], sin4b[2500], timeb[2500], outb[2500];
	float sin1c[2500], sin2c[2500], sin3c[2500], sin4c[2500], timec[2500], outc[2500];
	float sin1d[4800], sin2d[4800], sin3d[4800], sin4d[4800], timed[4800], outd[4800];

	// all the outfiles for the sin waves generated
	FILE* outfile200, * outfile400, * outfile600, * outfile600d;
	outfile200 = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab4p1\\CompAppsLab4p1\\sin200.txt", "w");
	outfile400 = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab4p1\\CompAppsLab4p1\\sin400.txt", "w");
	outfile600 = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab4p1\\CompAppsLab4p1\\sin600.txt", "w");
	outfile600d = fopen("C:\\Users\\13096\\source\\repos\\CompAppsLab4p1\\CompAppsLab4p1\\sin600d.txt", "w");


	// for loop for the 200 hz sampling frequency sum of sines
	for (i = 0; i < (int)(4 * 200); ++i)
	{
		float t = (float)i / 200.0;
		sin1a[i] = 1.0 * sin(2 * 3.14159 * 50 * t + 2);		//natural freq. 50hz
		sin2a[i] = 1.0 * sin(2 * 3.14159 * 100 * t + 2);	//natural freq. 100hz
		sin3a[i] = 1.0 * sin(2 * 3.14159 * 175 * t + 2);	//natural freq. 175hz
		sin4a[i] = 1.0 * sin(2 * 3.14159 * 200 * t + 2);	//natural freq. 200hz
		timea[i] = t;
		outa[i] = sin1a[i] + sin2a[i] + sin3a[i] + sin4a[i];
		fprintf(outfile200, "%f\t%f\n", timea[i], outa[i]);
	}

	// for loop for the 400 hz sampling frequency sum of sines
	for (i = 0; i < (int)(4 * 400); ++i)
	{
		float t = (float)i / 400.0;
		sin1b[i] = 1.0 * sin(2 * 3.14159 * 50 * t + 2);		//natural freq. 50hz
		sin2b[i] = 1.0 * sin(2 * 3.14159 * 100 * t + 2);	//natural freq. 100hz
		sin3b[i] = 1.0 * sin(2 * 3.14159 * 175 * t + 2);	//natural freq. 175hz
		sin4b[i] = 1.0 * sin(2 * 3.14159 * 200 * t + 2);	//natural freq. 200hz
		timeb[i] = t;
		outb[i] = sin1b[i] + sin2b[i] + sin3b[i] + sin4b[i];
		fprintf(outfile400, "%f\t%f\n", timeb[i], outb[i]);
	}

	// for loop for the 600 hz sampling frequency sum of sines
	for (i = 0; i < (int)(4 * 600); ++i)
	{
		float t = (float)i / 600.0;
		sin1c[i] = 1.0 * sin(2 * 3.14159 * 50 * t + 2);		//natural freq. 50hz
		sin2c[i] = 1.0 * sin(2 * 3.14159 * 100 * t + 2);	//natural freq. 100hz
		sin3c[i] = 1.0 * sin(2 * 3.14159 * 175 * t + 2);	//natural freq. 175hz
		sin4c[i] = 1.0 * sin(2 * 3.14159 * 200 * t + 2);	//natural freq. 200hz
		timec[i] = t;
		outc[i] = sin1c[i] + sin2c[i] + sin3c[i] + sin4c[i];
		fprintf(outfile600, "%f\t%f\n", timec[i], outc[i]);
	}


	// for loop for the 600 hz double duration sampling frequency sum of sines
	for (i = 0; i < (int)(8 * 600); ++i)
	{
		float t = (float)i / 600.0;
		sin1d[i] = 1.0 * sin(2 * 3.14159 * 50 * t + 2);		//natural freq. 50hz
		sin2d[i] = 1.0 * sin(2 * 3.14159 * 100 * t + 2);	//natural freq. 100hz
		sin3d[i] = 1.0 * sin(2 * 3.14159 * 175 * t + 2);	//natural freq. 175hz
		sin4d[i] = 1.0 * sin(2 * 3.14159 * 200 * t + 2);	//natural freq. 200hz
		timed[i] = t;
		outd[i] = sin1d[i] + sin2d[i] + sin3d[i] + sin4d[i];
		fprintf(outfile600d, "%f\t%f\n", timed[i], outd[i]);
	}
	printf("    200hz\t   400hz\t   600hz\t600hz double duration\n");
	printf("Time\tAmp.\tTime\tAmp.\tTime\tAmp.\tTime\tAmp.\n");



	for (i = 0; i < (int)(8 * 600); i++){
		printf("%5.3f\t%5.3f\t%5.3f\t%5.3f\t%5.3f\t%5.3f\t%5.3f\t%5.3f\n", timea[i], outa[i], timeb[i], outb[i], timec[i], outc[i], timed[i], outd[i]);
	}
}




