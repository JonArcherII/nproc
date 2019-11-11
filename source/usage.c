#include <stdio.h>

void usage() {
  printf("Usage: nproc [options]\n");
  printf("Options:\n");
  printf("  -a, --all\t\tPrint the number of installed processors\n");
  printf("  -i, --ignore=N\tIgnore (if possible) N number of available CPUs\n");
  printf("  -h, --help\t\tDisplay this message\n");
  printf("  -v, --version\t\tShow the version of this utility along with a "
         "copyright notice\n");
  printf("Default behavior:\n");
  printf("  Print the number of processors available to the running process\n");
}