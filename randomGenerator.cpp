#include <iostream>  // cout
#include <vector>    // vector
#include <ctime>     // time
#include <cstdlib>   // rand,srand
#include <unistd.h>  // usleep

#include <future>
#include <ctime>

#define UPPER_BOUND 1
#define LOWER_BOUND 0
#define NUM_VECS 100
#define LEN_VECS 70
#define SLEEP_TIME 100000

using namespace std;
vector<int> getRandomVec(int vecLen);
int randNumGenerator(int upper, int lower) { return rand()% (upper + 1 - lower) + lower; }

int main()
{
    vector<int> randomNums;
    srand(time(NULL));

    for (int i = 0; i < NUM_VECS; i++)
    {
        randomNums = getRandomVec(LEN_VECS);
        for (auto i: randomNums)
            cout << i << ' ';
        cout << '\n';  
    }

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

    usleep(SLEEP_TIME);

    return randomNums; 
}




