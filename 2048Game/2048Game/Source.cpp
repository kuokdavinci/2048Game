#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void insertBoard(int a[])
{
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", a[i * 4 + j]);
        }
        printf("\n");
    }
}
void insertMove(char move)
{
    printf("\nEnter your next move:");
    scanf("%c", &move);
}
void doMove(int a[], char move)
{
    if (move = 'a')
    {

    }
}
void addBlock(int a[])
{
    bool full = true;
    for (int i = 0; i < 16; i++) {
        if (a[i] == 0) {
            full = false;
            break;
        }
    }

    if (full) {
        printf("Game Over");
        exit(0);
    }

    int addBlock = rand() % 16;
    do {
        addBlock = rand() % 16;
    } while (a[addBlock] != 0);
    a[addBlock] = 2;
    insertBoard(a);
}
void combineLeft(int a[])
{
    for (int i = 0; i < 3; i++)
    {
        if (a[i] > 0)
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (a[j] == a[i])
                {
                    a[i] = a[i] * 2;
                    a[j] = 0;
                    j = 3;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (a[i] == 0)
            count++;
    }
    do
    {
        for (int i = 0; i < 3; i++)
        {
            if (a[i] == 0 && a[i + 1] > 0)
            {
                int temp = a[i+1];
                a[i+1] = a[i ];
                a[i ] = temp;
                count--;
            }
        }
    } while (count > 0);
    insertBoard(a);
}

void main()
{
    char move;
    int a[16] = { 0 };
    a[3] = 0;
    a[2] = 2;
    a[1] = 0;
    a[0] = 2;
    insertBoard(a);
    // for(int i=0;i<16;i++)
    // {
    //   addBlock(a);
    // }
    //   insertMove(move);
    //     insertBoard(a); 
    combineLeft(a);
}