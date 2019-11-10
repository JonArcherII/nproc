#include <stdio.h>
#include <sys/sysctl.h>

int all_cores() {
  int cpu_count;
  size_t len = sizeof(cpu_count);
  if (sysctl((int[]){CTL_HW, HW_NCPU}, 2, &cpu_count, &len, NULL, 0) < 0) {
    perror("sysctl");

    // If we can't get a value, just return 1
    return 1;
  }
  return cpu_count;
}

int available_cores() {
  int cpu_count;
  size_t len = sizeof(cpu_count);
  if (sysctl((int[]){CTL_HW, HW_AVAILCPU}, 2, &cpu_count, &len, NULL, 0) < 0) {
    perror("sysctl");

    // If we can't get a value, just return 1
    return 1;
  }
  return cpu_count;
}