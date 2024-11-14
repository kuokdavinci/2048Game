
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
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", a[i * 4 + j]);
        }
        printf("\n");
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
}
void combineLeft(int a[]) {
    for (int k = 0; k < 4; k++) {
        int start = k * 4; 
        
          for (int i = start; i < start + 3; i++) {
            for (int j = i + 1; j < start + 4; j++) {
              if (a[i] != 0 && a[i] == a[j]) {
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
    insertBoard(a);
}
void combineRight(int a[]) {
    for (int k = 3; k >= 0; k--) {
        int start = k * 4; 
        
        for (int i = start+3 ; i >  start ; i--) {
          for (int j = i - 1; j >= start ; j--) {
            if (a[i] != 0 && a[i] == a[j]) {
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
        insertBoard(a);
}
void combineUp(int a[])
{
    for (int k = 0; k < 4; k++) {
      int start =k;
        
           for (int i = start ; i <= start + 8; i+=4) {
             for (int j = i + 4; j <= start + 12; j+=4) {
              if (a[i] != 0 && a[i] == a[j]) {
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
    insertBoard(a);
}
void combineDown(int a[])
{
    for (int k = 3; k >=0; k--) {
      int start = k;
        
           for (int i = start + 12 ; i >= start + 4; i=i-4) {
             for (int j = i - 4; j >= start ; j=j-4) {
              if (a[i] != 0 && a[i] == a[j]) {
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
    insertBoard(a);
}
int main()
{
    char move;
    int a[16] = { 0 };
    a[1]=4;
    a[2]=4;
    a[3]=4;
    // for(int i=0;i<12;i++)
    // {
    //   addBlock(a);
    // }
    // insertBoard(a);
    // insertMove(a,move);
   printf("\nEnter:\n");
   scanf("%c",&move);
   printf("\n%c",move);
    return 0;
}