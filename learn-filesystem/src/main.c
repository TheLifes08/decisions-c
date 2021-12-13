#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct dirent DirEnt;

long long int recCalculateFiles(const char* path, char operation) {
    long long int result = (operation == '*')? 1 : 0;
    DIR* directory = opendir(path);

    if (directory != NULL) {
        DirEnt* de = readdir(directory);

        while (de != NULL) {
            char* newDirectory = calloc(strlen(path) + 258, sizeof(char));

            strcat(newDirectory, path);
            strcat(newDirectory, "/");
            strcat(newDirectory, de->d_name);

            if (de->d_type == DT_DIR) {
                char action = '?';

                if (strcmp(de->d_name, "add") == 0) {
                    action = '+';
                } else if (strcmp(de->d_name, "mul") == 0) {
                    action = '*';
                }

                if (action != '?') {
                    if (operation == '+') {
                        result += recCalculateFiles(newDirectory, action);
                    } else if (operation == '*') {
                        result *= recCalculateFiles(newDirectory, action);
                    }
                }

            } else if (de->d_type == DT_REG) {
                FILE* file = fopen(newDirectory, "r");

                if (file != NULL) {
                    long long int value;

                    while (fscanf(file,"%lld", &value) == 1) {
                        if (operation == '+') {
                            result += value;
                        } else {
                            result *= value;
                        }
                    }
                }

                fclose(file);
            }

            free(newDirectory);
            de = readdir(directory);
        }
    }

    closedir(directory);

    return result;
}

int main() {
    long long int result = recCalculateFiles("/home/box/tmp", '+');
    FILE* file = fopen("/home/box/result.txt", "w");

    if (file != NULL) {
        fprintf(file, "%lld", result);
        fclose(file);
    }

    return 0;
}