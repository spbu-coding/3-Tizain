#include <stdio.h>
#include <math.h>
#include <string.h>


double dbl_count() {
	double change_val = 2.0002, x1, x2, length, prev_change_val;
	printf("Calculation using double\n");
	do
	{  	x1 = 20002 - 10000 * (change_val + 2.0001) / 2;
		x2 = 2 - x1;
		length = sqrt((x1 - 1) * (x1 - 1) + (x2 - 1) * (x2 - 1));
		printf("x1 = %.15f  x2 = %.15f  length = %.15f\n", x1, x2, length);
		if (change_val == prev_change_val) {
			change_val = -1;
			break;
		}
		prev_change_val = change_val;
		change_val = (change_val + 2.0001) / 2;
	} 	while(length > 0.000001);  	

	return change_val;
}

float flt_count() {
	float change_val = 2.0002, x1, x2, length, prev_change_val;
	printf("Calculation using float\n");
	do
	{  	x1 = 20002 - 10000 * (change_val + (float)2.0001) / 2;
		x2 = 2 - x1;
		length = sqrt((x1 - 1) * (x1 - 1) + (x2 - 1) * (x2 - 1));
		printf("x1 = %.7f  x2 = %.7f  length = %.7f\n", x1, x2, length);
		if (change_val == prev_change_val) {
			change_val = -1;
			break;
		}
		prev_change_val = change_val;
		change_val = (change_val + 2.0001) / 2;
	} 	while(length > 0.000001);  	

	return change_val;
}


int main() {

	float flt_method = flt_count();
	double dbl_method = dbl_count();

	if (flt_method == -1) 
		printf("\nThe float type is not enough to work with such accurate values\n");
	else 
		printf("\nRequired value (float method): %.7f\n", flt_method);

	if (dbl_method == -1) 
		printf("\nThe double type is not enough to work with such accurate values\n\n");
	else 
		printf("\nRequired value (double method): %.15f\n\n", dbl_method);

    return 0;
}


