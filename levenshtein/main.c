#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

int lev(char * s1, char * s2) {
  int l1 = strlen(s1);
  int l2 = strlen(s2);
  char* t1 = s1 + 1;
  char* t2 = s2 + 1;

  if (l1 == 0) return l2;

  if (l2 == 0) return l1;

  if (*s1 == *s2) return lev(t1, t2);

  return 1 + MIN(lev(s1, t2), MIN(lev(t1, s2), lev(t1, t2)));
}

int main (int argc, char **argv) {
  if (argc != 3) {
    printf("2 strings need to be passed");
    return -1;
  }

  printf("%d", lev(argv[1], argv[2]));

  return 0;
}
