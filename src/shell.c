#include <stdlib.h>
#include <string.h>

#include "shell.h"

#define MAX_LINE_DATA 69
#define LINE_DATA 65
#define LINES 32

void Shell_run(Config *config) {
    char line[MAX_LINE_DATA];
    char content[LINES][LINE_DATA];

    for (size_t i = 0; i < 2; i++) {
        if (fgets(line, MAX_LINE_DATA, config->inFile) == NULL) {
            return;
        }
    }

    for (size_t i = 0; i < LINES; i++) {
        if (fgets(line, MAX_LINE_DATA, config->inFile) != NULL) {
            line[strcspn(line, "\n")] = '\0';
            strncpy(content[i], line + 3, LINE_DATA);
        } else {
            return;
        }
    }

    printf("XX:                1               2               3\n");
    printf("XX:0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF\n");
    for (int i = 0; i < LINES; i++) {
        printf("%02X:%s\n", i, content[i]);
    }
}

Config *Config_create(void) {
    Config *config = malloc(sizeof(Config));
    return config;
}

void Config_destroy(Config *config) {
    if (config->inFile != stdin) {
        fclose(config->inFile);
    }

    free(config);
}
