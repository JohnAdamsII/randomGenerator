#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <thread>

//! ANSI color LUT macro defintions
#include "colors.h"

//! constants
static const unsigned int UPPER_BOUND = 1;
static const unsigned int LOWER_BOUND = 0;
static const unsigned int NUM_VECS = 1'000'000;
static const unsigned int LEN_VECS = 100;
static const unsigned int SLEEP_TIME = 100'000;

//* need to split into 4 threads of 25 and use mutithreading

using namespace std;

//! function declarations
vector<unsigned int> getRandomVec(unsigned int randVecLen, unsigned int randNumUpperBound, unsigned int randNumLowerBound);
int randNumGenerator(unsigned int upper, unsigned int lower) { return rand()% (upper + 1 - lower) + lower; }

int main()
{
    clock_t tStart = clock();

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

    cout << "Generated " << NUM_VECS << " random vectors of length " << LEN_VECS << " in: ";
    printf("%.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    int numThreads = std::thread::hardware_concurrency();
    cout << "Concurrent threads supported: " << numThreads << endl;
    
    return 0;
}

vector<unsigned int> getRandomVec(unsigned int randVecLen, unsigned int randNumUpperBound, unsigned int randNumLowerBound)
{
    vector<unsigned int> randomNums;
    unsigned int randNum;

    for (unsigned int i = 0; i < randVecLen; i++) 
    {
        randNum = randNumGenerator(randNumUpperBound,randNumLowerBound);
        randomNums.emplace_back(randNum);
    }

    return randomNums; 
}

//! run $ /usr/bin/time ./randGem      to get execution time on UNIX





