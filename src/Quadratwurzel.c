/*
 ============================================================================
 Name        : Quadratwurzel.c
 Author      : Ursula Derichs
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Quadraturzel in C, Ansi89/90
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

double squareRoot (double value, int iterations, double eps)
{
    double iterNew, iter, diff;
    unsigned int numInteration = 0;
    // start iterations
    iter = value;
    do {
        // calculate next iteration
        iterNew = (iter + value / iter) / 2;

        // what is the difference to the last result?
        diff = iter - iterNew;

        // switch sign, if diff < 0
        if (diff < 0)
            diff = -diff;

        numInteration++;

        // store new iteration result
        iter = iterNew;
    } //while (!((diff < eps) || (numInteration == iterationen)));
    while ((diff >= eps) && (numInteration < iterations));

    return iterNew;
}

int main(void) {

    unsigned int maxIterations;
    double epsilon, value;

    // Read value
    printf("Geben Sie eine Zahl für die Berechnung der Quadratwurzel ein:\n");
    fflush(stdout);
    scanf("%lf", &value);
    fflush(stdin);

    // switch sign, if value < 0
    if (value < 0)
    {
        value = -value;
        printf ("Es wird die Quadratwurzel von %f berechent\n", value);
    }


    // read max. number of iterations
    printf("Geben Sie die maximale Anzahl an Iterationsschritten ein:\n");
    fflush(stdout);
    scanf("%u", &maxIterations);
    fflush(stdin);

    // read precision
    printf("Geben Sie die Grösse für Epsilon ein:\n");
    fflush(stdout);
    scanf("%lf", &epsilon);
    fflush(stdin);

    double sqroot = squareRoot (value, maxIterations, epsilon);

    printf("\nQuadratwurzel der value %f ist %f \n", value, sqroot);

    return EXIT_SUCCESS;
}