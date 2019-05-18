#include <iostream>
#include <string>

//! ANSI color LUT macro defintions
#include "colors.h"

using namespace std;

//! constants
static const char *argv0;

//! function declarations
void printRandomVec(long unsigned int randVecLen, long int randNumUpperBound, long int randNumLowerBound);
long int randNumGenerator(long int upper, long int lower) { return rand()% (upper + 1 - lower) + lower; }

void usage(FILE *f, int err) 
{
    fprintf(f,
            "USAGE: %s NUM_VECS LEN_VECS MIN MAX\n\n"
            "Generates random vectors and prints them to stdout.\n",
            argv0);
    exit(err);
}


int main(int argc, const char *argv[])
{
    argv0 = argv[0];

    clock_t tStart = clock();
    srand(time(NULL)); // seed for RNG

    if (argv[1] == "--help" || argv[1] == "-h")
        usage(stdout, 0);

    if (argc != 5)
        usage(stderr, 1);

    int argIndex;
    try {
            for (argIndex = 1; argIndex < argc; argIndex++)
                int temp(stoi(argv[argIndex])) ;
        } 
    catch (invalid_argument &e) 
    {
        fprintf(stderr, "Could not parse %s as an integer\n", argv[argIndex]);
        exit(1);
    }

    static const long int NUM_VECS = stoi(argv[1]);
    static const long int LEN_VECS = stoi(argv[2]);
    static const long int LOWER_BOUND = stoi(argv[3]);
    static const long int UPPER_BOUND = stoi(argv[4]);

    if (NUM_VECS < 0 || LEN_VECS < 0)
    {
        cout << "NUM_VECS and LEN_VECS must be non-negative\n";
        usage(stderr, 1);
    }

    if (LOWER_BOUND > UPPER_BOUND)
    {
        cout << "MIN cannot be greater than max\n";
        usage(stderr, 1);
    }

    cout << KGRN; //* set color
    
    for (long int i = 0; i < NUM_VECS; i++)
    {
        printRandomVec(LEN_VECS,UPPER_BOUND,LOWER_BOUND);
        cout << '\n';  
    }

    cout << RST; //* reset color

    cout << "\nGenerated " << NUM_VECS << " random vectors of length " << LEN_VECS << " in: ";
    printf("%.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}


void printRandomVec(long unsigned int randVecLen, long int randNumUpperBound, long int randNumLowerBound)
{
    for (long unsigned int i = 0; i < randVecLen; i++) 
        cout << randNumGenerator(randNumUpperBound,randNumLowerBound);
}