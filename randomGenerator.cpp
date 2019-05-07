#include <iostream>  // cout
#include <vector>    // vector
#include <ctime>     // time
#include <cstdlib>   // rand,srand
#include <unistd.h>  // usleep

//! ANSI color LUT macro defintions
#include "colors.h"

//! constants
static const unsigned int UPPER_BOUND = 1;
static const unsigned int LOWER_BOUND = 0;
static const unsigned int NUM_VECS = 100;
static const unsigned int LEN_VECS = 72;
static const unsigned int SLEEP_TIME = 100000;

//* need to get terminal width and generator current length vector based off of this

using namespace std;

//! function declarations
vector<unsigned int> getRandomVec(unsigned int vecLen);
int randNumGenerator(int upper, int lower) { return rand()% (upper + 1 - lower) + lower; }

int main()
{
    vector<unsigned int> randomNums;
    srand(time(NULL));

    cout << KGRN; //* set color

    for (unsigned int i = 0; i < NUM_VECS; i++)
    {
        randomNums = getRandomVec(LEN_VECS);
        for (auto i: randomNums)
            cout << i << ' ';
       
        usleep(SLEEP_TIME);
        cout << '\n';  
    }

    cout << RST; //* reset color
    return 0;
}

vector<unsigned int> getRandomVec(unsigned int vecLen)
{
    vector<unsigned int> randomNums;
    int randNum;

    for (unsigned int i = 0; i < vecLen; i++) 
    {
        randNum = randNumGenerator(UPPER_BOUND,LOWER_BOUND);
        randomNums.emplace_back(randNum);
    }

    return randomNums; 
}




