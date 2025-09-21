#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[argc + 1]) {
  FILE *fp;
  char buffer[256];
  int count = 0;

  fp = popen("lsblk -rno NAME,SIZE,TYPE,MOUNTPOINT | awk '$3==\"part\"{print $1, $2, $4}'", "r");
  if (fp == NULL) {
    perror("lsblk error");
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    if (count > 0) {
      printf("%2d: ", count++);
      printf("%s", buffer);
    } else
      count++;
  }

  pclose(fp);
  return 0;
}
