GNU Scientific Library, Release 2.4
14.19 Balancing
The process of balancing a matrix applies similarity transformations to make the rows and columns have comparable
norms. This is useful, for example, to reduce roundoff errors in the solution of eigenvalue problems. Balancing a
matrix A consists of replacing A with a similar matrix
A′ = D−1AD
where D is a diagonal matrix whose entries are powers of the floating point radix.
int gsl_linalg_balance_matrix(gsl_matrix * A, gsl_vector * D)
This function replaces the matrix A with its balanced counterpart and stores the diagonal elements of the simi-
larity transformation into the vector D.
14.20 Examples
The following program solves the linear system Ax = b. The system to be solved is,




0.18 0.60 0.57 0.96
0.41 0.24 0.99 0.58
0.14 0.30 0.97 0.66
0.51 0.13 0.19 0.85








x0
x1
x2
x3



 =




1.0
2.0
3.0
4.0




and the solution is found using LU decomposition of the matrix A.
#include <stdio.h>
#include <gsl/gsl_linalg.h>
int
main (void)
{
double a_data[] = { -1, 2, 1,
1, -3, -2, 
3, -1, -1};
double b_data[] = { -1,-1, 4 };
gsl_matrix_view m
= gsl_matrix_view_array (a_data, 4, 4);
gsl_vector_view b
= gsl_vector_view_array (b_data, 4);
gsl_vector *x = gsl_vector_alloc (4);
int s;
gsl_permutation * p = gsl_permutation_alloc (4);
gsl_linalg_LU_decomp (&m.matrix, p, &s);
gsl_linalg_LU_solve (&m.matrix, p, &b.vector, x);
printf ("x = \n");
gsl_vector_fprintf (stdout, x, "%g");