#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf env;

void SIGHandler(int pid) {
  printf("Bro what was that\n");
  longjmp(env, 1);
}

int main(void) {

  signal(SIGFPE, SIGHandler);

  int i = setjmp(env);
  if (i == 1) {
    printf("a;lldskfjaj;sdlkj\n");
    exit(0);
  }
  else {
    int temp = 1 / 0;
  }

  return 0;
}
