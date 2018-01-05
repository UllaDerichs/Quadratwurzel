/*
 ============================================================================
 Name        : Quadratwurzel.c
 Author      : Norbert Kellersohn
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Quadraturzel in C, Ansi89/90
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

double squareRoot (double zahl, int iterationen, double eps)
{
    double iterNeu, iterAlt, differenz;
    unsigned int anzahl = 0;
    // Iterationsanfang
    iterAlt = zahl;
    do {
        // Nächsten Iterationsschritt berechnen
        iterNeu = (iterAlt + zahl / iterAlt) / 2;

        // Differenz bestimmen
        differenz = iterAlt - iterNeu;

        // Wenn Differenz kleiner Null -> VZ umkehren
        if (differenz < 0)
            differenz = -differenz;

        // Anzahl erhöhen
        anzahl++;

        // Iterationsergebnis als letzten Wert speichern
        iterAlt = iterNeu;
    } //while (!((differenz < eps) || (anzahl == iterationen)));
    while ((differenz >= eps) && (anzahl < iterationen));
    //Solange, bis Differenz kleiner Epsilon oder Anzahl gleich max. Anzahl

    return iterNeu;
}

int main(void) {

    // Variablen-Deklaration

	unsigned int maxAnzahl;
	double epsilon, zahl;

    // Zahl einlesen
    printf("Geben Sie eine Zahl für die Berechnung der Quadratwurzel ein:\n");
    fflush(stdout);
    scanf("%lf", &zahl);
    fflush(stdin);

    // Wenn Zahl kleiner Null, dann Vorzeichen umkehren
    if (zahl < 0)
    {
        zahl = -zahl;
    	printf ("Es wird die Quadratwurzel von %f berechent\n", zahl);
    }


    // Max. Anzahl Iterationen einlesen
    printf("Geben Sie die maximale Anzahl an Iterationsschritten ein:\n");
    fflush(stdout);
    scanf("%u", &maxAnzahl);
    fflush(stdin);

    // Genauigkeit einlesen
    printf("Geben Sie die Grösse für Epsilon ein:\n");
    fflush(stdout);
    scanf("%lf", &epsilon);
    fflush(stdin);

    double wurzel = squareRoot (zahl, maxAnzahl, epsilon);

    // Quadratwurzel ausgeben
    printf("\nQuadratwurzel der Zahl %f ist %f \n", zahl, wurzel);

    return EXIT_SUCCESS;
}
