#include <iostream>  // cout
#include <vector>    // vector
#include <ctime>     // time
#include <cstdlib>   // rand,srand
#include <unistd.h>  // usleep

//! for mutitheading in the future!
/* #include <future>
    #include <ctime> */

//! color macro defintions
#include "colors.h"

#define UPPER_BOUND 1
#define LOWER_BOUND 0
#define NUM_VECS 100
#define LEN_VECS 72
#define SLEEP_TIME 100000

using namespace std;
vector<int> getRandomVec(int vecLen);
int randNumGenerator(int upper, int lower) { return rand()% (upper + 1 - lower) + lower; }

int main()
{
    vector<int> randomNums;
    srand(time(NULL));

    cout << KGRN; //* set color

    for (int i = 0; i < NUM_VECS; i++)
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

vector<int> getRandomVec(int vecLen)
{
    vector<int> randomNums;
    int randNum;

    for (int i = 0; i < vecLen; i++) 
    {
        randNum = randNumGenerator(UPPER_BOUND,LOWER_BOUND);
        randomNums.push_back(randNum);
    }

    return randomNums; 
}




