/**
 * BOP 3.2: Telephone number and its corrsponding English word
 */

#include <cstdio>
#include <iostream>

char g_lookupTable[10][10] =
{
    "", // 0
    "", // 1
    "ABC", // 2
    "DEF", // 3
    "GHI", // 4
    "JKL", // 5
    "MNO", // 6
    "PQRS", // 7
    "TUV", // 8
    "WXYZ" // 9
};

int g_numChars[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
int g_digitLength = 8;

void solution1(int* telephone, int* charPos, int digitLength);
void solution2(int* telephone, int* charPos, int digitLength);

void solution1(int* telephone, int* charPos, int digitLength)
{
    while (true)
    {
        
        for (int k = 0; k < digitLength; ++k)
        {
            printf("-----------%d%d%c,", telephone[k], charPos[k], g_lookupTable[telephone[k]][charPos[k]]);
        }
        std::cout << std::endl;
        
        int k = digitLength - 1;
        while (k >= 0)
        {
            printf("k=%d, charPos=%d, g_numChars[%d]=%d\n", k, charPos[k], telephone[k], g_numChars[telephone[k]]);
            if (charPos[k] < g_numChars[telephone[k]] - 1)
            {
                charPos[k]++;
                printf("charpos[%d]++ = %d, break\n", k, charPos[k]);
                break;
            }
            else
            {
                charPos[k] = 0;
                k--;
                printf("charpos[%d] = %d, k-- = %d\n", k+1, charPos[k+1], k);
            }
        }
        
        if (k < 0)
        {
            break;
        }
    }
}

void printTelephone(int* telephone, int* charPos, int digitLength)
{
    for (int k = 0; k < digitLength; ++k)
    {
        printf("%d%d%c,", telephone[k], charPos[k], g_lookupTable[telephone[k]][charPos[k]]);
    }
    printf("\n");
}

void solution2(int* telephone, int* charPos, int digitLength)
{
    for (;;)
    {
        printTelephone(telephone, charPos, digitLength);
        
        // adjust cursors
        int k = 0;
        for (;;)
        {
            // 当前要输出的数字在范围内，because we have printed telephone before this cursor moves, should use (N-1), instead of N.
            if (charPos[k] < g_numChars[telephone[k]] - 1)
            {
                charPos[k]++;
                break;
            }
            else // 本次输出已经完成，重置当前charpos游标，并移动next digit的游标。
            {
                charPos[k] = 0;
                k++;
                
                if (k >= digitLength)
                {
                    break;
                }
            }
        }
        
        // when adjust all the cursors, quit loop.
        if (k >= digitLength)
        {
            break;
        }
    }
    
//        for (int i=0; i<digitLength; ++i)
//        {
//            //int number = telephone[i];
//            //std::cout << number << ":" << std::endl;
//         
//            for (int ii=0; ii<i; ++ii)
//            {
//                for (charPos[ii]=0; charPos[i]<g_numChars[telephone[i]]; ++charPos[i])
//                {
//                    
//                }
//                charPos[i] = 0;
//
//            }
//            
//            
//            i=0: 123
//            i=1: 123, 123.
//            
//            while (charPos[i] < g_numChars[number])
//            {
//                
//                charPos[i]++;
//            }
//            
//            {
//                charPos[i] = 0;
//            }
//            
//            //std::cout << number << "," << charPos[i] << ":" << g_lookupTable[number][charPos[i]] << ";";
//            
//            
//            
//            for (int k=0; k<g_numChars[number]; ++k)
//            {
//                //charPos[i] = k;
//                //int pos = charPos[i];
//                //std::cout << pos << "," << g_lookupTable[number][pos] << ";";
//            }
//            std::cout << std::endl;
//        }
//        break;
//    }

}

void recursiveSolution(int* telephone, int* charPos, int index, int digitLength)
{
    //printf("----------\n");
    if (index == digitLength)
    {
        printTelephone(telephone, charPos, digitLength);
        return;
    }
    
    for (charPos[index] = 0; charPos[index] < g_numChars[telephone[index]]; ++charPos[index])
    {
        //printf("index:charPos=%d:%d < %d:%d\n", index, charPos[index], telephone[index], g_numChars[telephone[index]]);
        recursiveSolution(telephone, charPos, index + 1, digitLength);
    }
    if (telephone[index] == 0)
    {
        recursiveSolution(telephone, charPos, index + 1, digitLength);
    }
}

#define MAX_DIGITS 10
int main(int argc, const char * argv[])
{
    int digitLength = 8;
    int telephone[MAX_DIGITS];
    for (int i=0; i<digitLength; ++i)
    {
        telephone[i] = rand()%10;
    }
    
    for (int i=0; i<digitLength; ++i)
    {
        std::cout << telephone[i];
    }
    std::cout << std::endl;
    
    int charPos[MAX_DIGITS];
    memset(charPos, 0, digitLength*sizeof(int));
    
    
    //solution1(telephone, charPos);
    //solution2(telephone, charPos, digitLength);
    recursiveSolution(telephone, charPos, 0, digitLength);
    
    return 0;
}

