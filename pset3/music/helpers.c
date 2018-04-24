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
    // printf("x = %i and y = %i", x, y);

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
    double freqVar = 440.0; // Starting frequency of A4
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
    // printf("Note is %s, note value is %c, accidental is %c, octave is %i\n", note, noteVal, accidental, octave);

    switch (accidental)
    {
        case '#' :
            freqVar = freqVar * pow(2.0, 1.0 / 12.0); // A4 added with the accidental
            break;
        case 'b' :
            freqVar = freqVar / pow(2.0, 1.0 / 12.0); // A4 added with the accidental
            break;
        default :
            // freqVar = 440;
            break;

    }
    switch (octave)
    {
        case 1 :
            freqVar = freqVar / 8.0;
            break;
        case 2 :
            freqVar = round(freqVar / 4.0);
            break;
        case 3 :
            freqVar = freqVar / 2.0;
            break;
        case 4 :
            break;
        case 5 :
            freqVar = freqVar * 2.0;
            break;
        case 6 :
            freqVar = freqVar * 4.0;
            break;
        case 7 :
            freqVar = freqVar * 8.0;
            break;
        case 8 :
            freqVar = freqVar * 16.0;
            break;
    }

    switch (noteVal)
    {
        case 'C' :
            freqVar = freqVar / pow(2.0, 9.0 / 12.0);
            break;
        case 'D' :
            freqVar = freqVar / pow(2.0, 7.0 / 12.0);
            break;
        case 'E' :
            freqVar = freqVar / pow(2.0, 5.0 / 12.0);
            break;
        case 'F' :
            freqVar = freqVar / pow(2.0, 4.0 / 12.0);
            break;
        case 'G' :
            freqVar = freqVar / pow(2.0, 2.0 / 12.0);
            break;
        case 'A' :
            break;
        case 'B' :
            freqVar = freqVar * pow(2.0, 2.0 / 12.0);
            break;
    }

    freq = round(freqVar);

    return freq; // implement the math of accidentals, then octaves, then note
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0) // If there is no string...
    {
        return true;
    }

    return false;
}