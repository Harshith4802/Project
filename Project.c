#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"


int  main(void) //main function begins
{

//assuming the value of lambda
double lambda = sqrt(2);
saveVal("lambda.dat",lambda);

//Variables
double s = (5*lambda)/14;
double t = (19*lambda)/21;

//Matrix A
double **A = createMat(3,1);
A[0][0] =12*s;
A[1][0] =lambda + 6*s;
A[2][0] =(-lambda/6) - s;
saveMat(A,"A.dat",3,1);

//Matrix B
double **B = createMat(3,1);
B[0][0] =6*t;
B[1][0] =-4*lambda + 6*t;
B[2][0] =2*lambda + t;
saveMat(B,"B.dat",3,1);

//Matrix AB
double **AB = linalg_sub(A,B,3,1);
saveMat(AB,"AB.dat",3,1);

//direction vector of line-1
double **d1 = createMat(3,1);
d1[0][0] =12;
d1[1][0] =6;
d1[2][0] =-1;
saveMat(d1,"d1.dat",3,1);

//direction vector of line-1
double **d2 = createMat(3,1);
d2[0][0] =6;
d2[1][0] =6;
d2[2][0] =1;
saveMat(d2,"d2.dat",3,1);

//verifying if AB is perpendicular to the lines


double **q1 = matmul(transpose(AB,3,1),d1,1,3,1);
printf("AB^T x d1 = ");
print(q1,1,1);


double **q2 = matmul(transpose(AB,3,1),d2,1,3,1);
printf("AB^T x d2 = ");
print(q2,1,1);

//checking the value of |AB|
double q = linalg_norm(AB,3);
printf("%lf\n",q);



return 0;
}
