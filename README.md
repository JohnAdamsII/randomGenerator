*Simple program to generate random vectors*

**COMPILE**: g++ randomGenerator.cpp -o randGen

## USAGE: ./randGen NUM_VECS VEC_LEN MIN MAX

## OPTIONS:
        NUM_VECS: number of vectors to be printed to stdout
        VEC_LEN:  length of each vector
        MIN:      smallest possible random number to be generated
        MAX:      largest possible random number to be generated

## EXAMPLE: ./randGen 5 10 0 1

## OUTPUT:
    1000100011
    1000010010
    1101111101
    0110110010
    1101101000
    
    Generated 5 random vectors of length 10 in: 0.0000s
