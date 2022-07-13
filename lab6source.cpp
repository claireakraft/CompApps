
/*
name: Claire Kraft
class: Computer Applications
section: 401
TA: Tianling Niu
*/

#pragma warning (disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float ke, h, S, I, R, alpha, beta; // global variables

float slope1(float, float);
float slope2(float, float);
float slope3(float);


int main(void)
{
	float t0 = 0, tf, h, c0, k1, k2, k3, k4, q1, q2, q3, q4, p1, p2, p3, p4;
	int N;
	char sim_file[100];
	FILE* out_file;
	float* out_time, * out_S, *out_I, *out_R;

	// have the user input the following parameters

	printf("Enter the values of the rate constant alpha \n");
	scanf("%f", &alpha);

	printf("Enter the values of the rate constant beta \n");
	scanf("%f", &beta);

	printf("Enter value of S at t = 0 \n");
	scanf("%f", &S);

	printf("Enter value of I at t = 0 \n");
	scanf("%f", &I);

	printf("Enter value of R at t = 0 \n");
	scanf("%f", &R);

	printf("Enter the final time for solution \n");
	scanf("%f", &tf);

	printf("Enter the solution step size h \n");
	scanf("%f", &h);

	N = (int)(tf / h); // number of points

	// prompt the user for the output file name

	printf("Enter file name to store solution \n");
	scanf("%s", sim_file);

	
	out_file = fopen(sim_file, "w");

	// dynamically allocate memory to arrays
	out_S = (float*)calloc(sizeof(float), N);
	out_I = (float*)calloc(sizeof(float), N);
	out_R = (float*)calloc(sizeof(float), N);
	out_time = (float*)calloc(sizeof(float), N);

	// set initial values for each array
	out_S[0] = S;
	out_I[0] = I;
	out_R[0] = R;
	out_time[0] = 0;

	// print initial values to output file
	fprintf(out_file, "%f \t %f \t %f \t %f\n", out_time[0], out_S[0], out_I[0], out_R[0]);


	// for loop for the Runge-kutta method 
	// k is for the Susceptable 
	// q is for the infected 
	// p is for the recovered

	for (int i = 0; i < N; ++i)
	{
		out_time[i + 1] = (i + 1) * h;

		k1 = h * slope1(out_S[i], out_I[i]);
		q1 = h * slope2(out_S[i], out_I[i]);
		p1 = h * slope3(out_I[i]);

		k2 = h * slope1(out_S[i] + (k1/2.0), out_I[i] + (q1/2.0));
		q2 = h * slope2(out_S[i] + (k1 / 2.0), out_I[i] + (q1 / 2.0));
		p2 = h * slope3(out_I[i] + (q1 / 2.0));

		k3 = h * slope1(out_S[i] + (k2 / 2.0), out_I[i] + (q2 / 2.0));
		q3 = h * slope2(out_S[i] + (k2 / 2.0), out_I[i] + (q2 / 2.0));
		p3 = h * slope3(out_I[i] + (q2 / 2.0));

		k4 = h * slope1(out_S[i] + (k3 / 2.0), out_I[i] + (q3 / 2.0));
		q4 = h * slope2(out_S[i] + (k3 / 2.0), out_I[i] + (q3 / 2.0));
		p4 = h * slope3(out_I[i] + (q3 / 2.0));


		out_S[i + 1] = out_S[i] + (1.0 / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
		out_I[i + 1] = out_I[i] + (1.0 / 6) * (q1 + 2 * q2 + 2 * q3 + q4);
		out_R[i + 1] = out_R[i] + (1.0 / 6) * (p1 + 2 * p2 + 2 * p3 + p4);
		fprintf(out_file, "%f \t %f \t %f \t %f \t \n", out_time[i + 1], out_S[i + 1], out_I[i + 1], out_R[i + 1]);
	}
	return 0;
}

// slope for the Susceptable 
float slope1(float S, float I)
{
	float out;
	out = -alpha * S * I;
	return out;
}


// slope for the infected
float slope2(float S, float I)
{
	float out;
	out = (alpha * S * I) - (beta *I);
	return out;
}

// slope for the recovered
float slope3(float I)
{
	float out;
	out = beta * I;
	return out;
}
