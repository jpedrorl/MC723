

#include <stdio.h>
#include <stdlib.h>

#define ENDERECO_LOCK (100 * 1024 * 1024)
#define SIZE 100

volatile int *lock = (int *) ENDERECO_LOCK;

volatile int core = 0;

int main1(){
  int this_core = 0;

  while(*lock);
  if(core == 1)this_core = 1;
  else this_core = 0;
  core += 1;
  *lock = 0;

  int i;
  for(i = 0; i < 50; i++);
  
  while(*lock);
  printf("core: %d\n", this_core);
  *lock = 0;

  return 0;
}

int main(){
  main1();  
  return 0;
}
