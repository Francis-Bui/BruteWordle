#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <windows.h>
#include <ctime>

using namespace std;

int x, y, i, letterCnt, t;
double duration;
char alp[64] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0',' '};
string userPhrase;

void wordgen(int letterCnt)
{
    int lock[letterCnt] = {0};
    
    for(y = 0; y <= letterCnt; y++)
    {
            
        int randkey = rand() % 64;
            
        if (i != letterCnt)
        {
                
            if (userPhrase[y] == alp[randkey]) // check for match
            {
                lock[y] = randkey; // store match into array
            }
            
            if (lock[y] == 0) // if not matched, generate random
            {
                cout << alp[randkey];
            }   
            
            else
            {
                cout << alp[lock[y]]; // print saved
                i++;
            }
            
            if (y == letterCnt) // reset loop
            {
                cout << "\n";
                y = -1;
                i = 0;
            }
        
        }
        
        if (i == letterCnt)
            {
            cout << alp[lock[y+1]];
            cout << "\n\n" << "Complete";
            y = 50;
            }
        
    }
    
}

int main()
{
    double duration;
    
    cin >> userPhrase;
    letterCnt = (userPhrase.size() - 1);
    
    clock_t start;
    start = clock();
    
    wordgen(letterCnt);
    
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    
    cout << "\n\n" << "Cracked in: " << duration << " seconds!";
}