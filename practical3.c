#include <stdio.h>
#include <math.h>
int main(void){
/* 1. Set values of a and b*/
double a = 0.0,b = M_PI/3.0; 

/* 2. Get the first part of the sum*/
double first_sum = 0.0;
first_sum += tan(a) + tan(b);

/* 3. Create a loop that generates 11 equidistant points between a and b */
int N = 12;
double h = (b -a) / N ;/* Width of each interval*/
for (int i = 1; i < N; i ++){
    double xi = a + i * h;
    printf("x%d = %.6f\n",i, xi);
}

/* 4. Change the loop so that 2tan(xi) is added for each of the points*/
double area = 0.0;
for (int i = 1; i< N; i ++){
    double xi = a + i * h;
    area += 2 * tan(xi);
}

/* 5. Add the end points sum and multiply by (b-a)/N */
area += first_sum;
area *= ((b-a)/(2*N));

/* 6. Compare against log(2)*/
double exact_area = log(2);
printf("The difference with the exact area is %.8f\n", fabs(exact_area - area));
}