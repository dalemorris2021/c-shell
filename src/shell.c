#include <stdlib.h>

#include "shell.h"

#define MAX_LINE_DATA 68

void Shell_run(Config *config) {
    char line[MAX_LINE_DATA];
    while (fgets(line, MAX_LINE_DATA, config->inFile) != NULL) {
        printf("%s", line);
    }
}

Config *Config_create(void) {
    Config *config = malloc(sizeof(Config));
    return config;
}

void Config_destroy(Config *config) {
    free(config);
}
