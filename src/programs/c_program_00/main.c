#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void def_ptr(int *p, size_t n)
{
  int max = 45;
  int min = 0;

  for (int i = 0; i < n; i++)
  {
    p[i] = rand() % (max - min + 1) + min;
  }
  for (int i = 0; i < n; i++)
  {
   for(int j=0;j<i;j++){
    if (p[i] == p[j])
    {
      p[i] = rand() % (max - min + 1) + min;
      j = -1; // Reset j to start checking from the beginning
    }
   }
  }
}
int comp(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

void printArr(int *p, size_t n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", p[i]);
  }
}
void win(int *a,int *b){
  int mistakes[6];
  int n=6;

  for(int i=0;i<n;i++){
    if(a[i]==b[i]){
      mistakes[i]=1;
    }
  }
}
int main(int argc, char **argv)
{
  srand(time(NULL));
  int n = 6;
  int *ptr = (int *)malloc(n * sizeof(int));

  def_ptr(ptr, n);

  qsort(ptr, n, sizeof(ptr[0]), comp);

  printArr(ptr, n);
  printf("\n");
  free(ptr);
  return 0;
}