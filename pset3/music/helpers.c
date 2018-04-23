// Helper functions for music

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "helpers.h"

int x; // Numerator variable
int y; // Denominator variable

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    x = atoi(&fraction[0]);
    y = atoi(&fraction[2]);
    printf("x = %i and y = %i", x, y);

    switch (y)
    {
        case 8 :
            break;
        case 4 :
            x = x * 2;
            break;
        case 2 :
            x = x * 4;
            break;
    }
     return x; // Return number of eighths
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char noteVal = note[0];
    char accidental = ' ';
    int octave;
    int acc;
    int freq;

    if (strlen(note) == 3)
    {
        accidental = note[1];
        octave = atoi(&note[2]);
    }
    else
    {
        octave = atoi(&note[1]);
    }
    printf("Note is %s, note value is %c, accidental is %c, octave is %i\n", note, noteVal, accidental, octave);

    switch (accidental)
    {
        case # :
            acc = round(440 * 2 * (2 * (1/12)); // A4 added with the accidental
            break;
        case b :
            acc = round(440 / 2 * (2 * (1/12)); // A4 added with the accidental
            break;
    }

    freq =

    return freq; // implement the math of accidentals, then octaves, then note
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (!s) // If there is no string...
    {
        return true;
    }

    return false;
}