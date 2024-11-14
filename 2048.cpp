
#include <bits/stdc++.h>
using namespace std;
void Merge( int &a, int &b)
{
  a= a*2;
  b= 0;
}
void insertBoard(int a[])
{
    printf("\n");
    printf("--------------------------\n");
    printf("     YOUR SCORE : %d      \n",a[16]);
    printf("--------------------------\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", a[i * 4 + j]);
        }
        printf("\n");
    }
     printf("--------------------------\n");
}
bool addBlock(int a[])
{
    bool full =true;
    for (int i = 0; i < 16; i++) {
        if (a[i] == 0) {
            full = false;
            break;
        }
    }
    if (full) {
         printf("--------------------------\n");
        printf("\n        GAME OVER\n");
         printf("       YOUR SCORE: %d\n",a[16]);
         printf("--------------------------\n");
        exit(0);
    }

    int addBlock = rand() % 16;
    do {
        addBlock = rand() % 16;
    } while (a[addBlock] != 0);
    a[addBlock] = 2;
    return full;
}
void combineLeft(int a[]) {
    for (int k = 0; k < 4; k++) {
        int start = k * 4; 
        
          for (int i = start; i < start + 3; i++) {
            for (int j = i + 1; j < start + 4; j++) {
              if (a[i] != 0 && a[i] == a[j]) {
                a[16]=a[16]+a[i];
               Merge(a[i],a[j]);
               break;
             }
            }
          }

        for (int i = start; i < start + 3; i++) {
            if (a[i] == 0) {
                for (int j = i + 1; j < start + 4; j++) {
                    if (a[j] != 0) {
                       swap(a[i],a[j]);
                        break;
                    }
                }
            }

        }
   }
}
void combineRight(int a[]) {
    for (int k = 3; k >= 0; k--) {
        int start = k * 4; 
        
        for (int i = start+3 ; i >  start ; i--) {
          for (int j = i - 1; j >= start ; j--) {
            if (a[i] != 0 && a[i] == a[j]) {
                a[16]=a[16]+a[i];
                Merge(a[i],a[j]);
                break;
            }
        }
        }

        for (int i = start+ 3; i > start ; i--) {
            if (a[i] == 0) {
                for (int j = i - 1; j >= start ; j--) {
                    if (a[j] != 0) {
                      swap(a[i],a[j]);
                        break;
                    }
                }
            }
        }
        }
}
void combineUp(int a[])
{
    for (int k = 0; k < 4; k++) {
      int start =k;
        
           for (int i = start ; i <= start + 8; i+=4) {
             for (int j = i + 4; j <= start + 12; j+=4) {
              if (a[i] != 0 && a[i] == a[j]) {
                a[16]=a[16]+a[i];
               Merge(a[i],a[j]);
               break;
             }
            }
          }

        for (int i = start ; i <= start + 8; i+=4) {
            if (a[i] == 0) {
                for (int j = i + 4; j <= start + 12; j+=4) {
                    if (a[j] != 0) {
                       swap(a[i],a[j]);
                        break;
                    }
                }
            }

        }
   }
}
void combineDown(int a[])
{
    for (int k = 3; k >=0; k--) {
      int start = k;
        
           for (int i = start + 12 ; i >= start + 4; i=i-4) {
             for (int j = i - 4; j >= start ; j=j-4) {
              if (a[i] != 0 && a[i] == a[j]) {
                a[16]=a[16]+a[i];
               Merge(a[i],a[j]);
               break;
             }
            }
          }

         for (int i = start +12 ; i >= start + 4; i-=4) {
            if (a[i] == 0) {
                 for (int j = i - 4; j >= start ; j-=4) {
                    if (a[j] != 0) {
                       swap(a[i],a[j]);
                        break;
                    }
                }
            }

        }
   }
}
void insertMove(int a[],char &move)
{
    printf("Enter your next move(w/a/s/d):\t");
    scanf("%c", &move);
    getchar();
    if (move =='a')
    {
    combineLeft(a);
    }
    if (move =='s')
    {
    combineDown(a);
    }
    if(move=='d')
    {
    combineRight(a);
    }
    if(move =='w')
    {
    combineUp(a);
    }
}

int main()
{
    char move;
    int a[17] = { 0 };
    insertBoard(a);
    while(addBlock(a)!=true)
    {
    insertBoard(a);    
    insertMove(a,move);
    }
    return 0;
}