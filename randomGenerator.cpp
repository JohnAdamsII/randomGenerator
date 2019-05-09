#include <iostream>  // cout
#include <vector>    // vector
#include <ctime>     // time
#include <cstdlib>   // rand,srand
#include <unistd.h>  // usleep
#include <time.h>    //clock for execution time

//! ANSI color LUT macro defintions
#include "colors.h"

//! constants
static const unsigned int UPPER_BOUND = 1;
static const unsigned int LOWER_BOUND = 0;
static const unsigned int NUM_VECS = 1000000;
static const unsigned int LEN_VECS = 100;
static const unsigned int SLEEP_TIME = 100000;

//* need to split into 4 threads of 25 and use mutithreading

using namespace std;

//! function declarations
vector<unsigned int> getRandomVec(unsigned int randVecLen, unsigned int randNumUpperBound, unsigned int randNumLowerBound);
int randNumGenerator(unsigned int upper, unsigned int lower) { return rand()% (upper + 1 - lower) + lower; }

int main()
{
    clock_t tStart = clock(); //* Start Timer

    vector<unsigned int> randomNums;
    srand(time(NULL));

    cout << KGRN; //* set color

    for (unsigned int i = 0; i < NUM_VECS; i++)
    {
        randomNums = getRandomVec(LEN_VECS,UPPER_BOUND,LOWER_BOUND);
        for (auto i: randomNums)
            cout << i;
       
        // usleep(SLEEP_TIME); //! Sleep to slow down printing
        cout << '\n';  
    }

    cout << RST; //* reset color
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC); //* print execution time
    return 0;
}

vector<unsigned int> getRandomVec(unsigned int randVecLen, unsigned int randNumUpperBound, unsigned int randNumLowerBound)
{
    vector<unsigned int> randomNums;
    int randNum;

    for (unsigned int i = 0; i < randVecLen; i++) 
    {
        randNum = randNumGenerator(randNumUpperBound,randNumLowerBound);
        randomNums.emplace_back(randNum);
    }

    return randomNums; 
}

//! run $ /usr/bin/time ./randGem      to get execution time on UNIX





