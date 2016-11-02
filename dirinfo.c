#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>


DIR * open_dir(char *dir_to_scan) {
  DIR *dir;
  
  dir = opendir(dir_to_scan);
  if (!dir) {
    return NULL; //dir not found
  }
  
  closedir(dir);
  return dir;
}

void scan_dir(DIR *dir) {
  struct dirent *dir_info;
  struct stat file;
  while ((dir_info = readdir(dir))) {
    printf("%s\n", dir_info -> d_name);
  }
}

int main() {
  DIR *dir = open_dir("test_dir");
  scan_dir(dir);
}
