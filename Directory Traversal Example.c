#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void listFiles(const char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    char fullpath[1024];

    if (!dir) return;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        printf("%s\n", fullpath);

        struct stat st;
        if (stat(fullpath, &st) == 0 && S_ISDIR(st.st_mode)) {
            listFiles(fullpath);  // Recursive call for subdirectories
        }
    }
    closedir(dir);
}

int main() {
    listFiles(".");  // Start from current directory
    return 0;
}
