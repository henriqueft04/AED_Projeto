#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void process_directory(const char *folder_path);

int main() {
    char folder_path[20] = "./pgm";
    process_directory(folder_path);
    return 0;
}

void process_directory(const char *folder_path) {
    DIR *dir;
    struct dirent *entry;
    char full_path[1024];
    char command[2048];

    dir = opendir(folder_path);
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR) {
            
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                snprintf(full_path, sizeof(full_path), "%s/%s", folder_path, entry->d_name);
                process_directory(full_path);
            }
        } else if (entry->d_type == DT_REG) {
            // Construct full path
            snprintf(full_path, sizeof(full_path), "%s/%s", folder_path, entry->d_name);

            // Prepare and execute command
            snprintf(command, sizeof(command), "./imageTest %s test.pgm", full_path);
            system(command);
        }
    }
    closedir(dir);
}
