#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void usage();
extern void version();

int all_cores();
int available_cores();

static const struct option options[] = {{"all", no_argument, 0, 'a'},
                                        {"ignore", required_argument, 0, 'i'},
                                        {"help", no_argument, 0, 'h'},
                                        {"version", no_argument, 0, 'v'},
                                        {0, 0, 0, 0}};

int main(int argc, char **argv) {
  bool report_all_cores = false;
  int ignore_core_count = 0;
  char c;
  while ((c = getopt_long(argc, argv, "ai:hv", options, NULL)) != -1) {
    switch (c) {
    case 'a': {
      report_all_cores = true;
      break;
    }
    case 'i': {
      ignore_core_count = atoi(optarg);
      break;
    }
    case 'h': {
      usage();
      return 0;
    }
    case 'v': {
      version();
      return 0;
    }
    default: {
      usage();
      return -1;
    }
    }
  }

  // Populate our core_count
  int core_count;
  if (report_all_cores) {
    core_count = all_cores();
  } else {
    core_count = available_cores();
  }

  // Apply ignored core count
  core_count -= ignore_core_count;

  // If we go < 1, then we set 1 because a negative or zero core count is silly
  if (core_count < 1)
    core_count = 1;

  // Actually print core count
  printf("%i\n", core_count);

  return 0;
}