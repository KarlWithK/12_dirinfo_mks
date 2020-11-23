#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
	int d_size;
  DIR *current_dir = opendir(".");
  struct dirent *curr = readdir(current_dir);
  printf("Statistics for directory: %s\n", ".");
  while (curr) {
    if (curr->d_type == 4) { // check if it is a dir
      printf("%s\t\tDirectory\n", curr->d_name);
    }
    curr = readdir(current_dir);
  }
	struct stat sb;
	rewinddir(current_dir); // reset pointer
	curr = readdir(current_dir);
  while (curr) {
    if (curr->d_type == 8) { // check if it is a dir
      printf("%s\t\tFile\n", curr->d_name);
			stat(curr->d_name, &sb);
			d_size += sb.st_size;
    }
    curr = readdir(current_dir);
	}
	printf("Total Size of Files: %d\n", d_size);
  closedir(current_dir);
  return 0;
}
