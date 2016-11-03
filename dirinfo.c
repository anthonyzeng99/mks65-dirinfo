#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int scan_dir(char *dir_to_scan) {
  DIR *dir = opendir(dir_to_scan);
  if (!dir) {
    return -1; //dir not found
  }
  
  struct dirent *dir_info;
  struct stat *file;
  int total_size = 0;
  while ((dir_info = readdir(dir))) {
    stat(dir_info -> d_name, file);
    total_size += file -> st_size;
  }
  printf("Statistics for directory: %s\n", dir_to_scan);
  printf("Total Directory Size: %d bytes\n", total_size);


  printf("\nDirectories:\n");
  rewinddir(dir);
  while ((dir_info = readdir(dir))) {
    if (dir_info -> d_type == DT_DIR) {
      printf("%s\n", dir_info -> d_name);
    }
  }

  printf("\nRegular Files:\n");
  rewinddir(dir);
  while ((dir_info = readdir(dir))) {
    if (dir_info -> d_type == DT_REG) {
      printf("%s\n", dir_info -> d_name);
    }
  }

  closedir(dir);
  return 0;
}

int main() {≈
  scan_dir("test_dir");
}
