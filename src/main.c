#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "shell.h"

int main(int argc, char **argv) {
    const char *versionMessage = "v0.1.0";
    const char *usageMessage = "Usage: shell [-i input-file]";
    const char *fileMessage = "Couldn't open file";

    Config *config = Config_create();
    config->inFile = stdin;

    int opt;
    while ((opt = getopt(argc, argv, ":vVhHi:")) != -1) {
        switch (opt) {
        case 'v':
        case 'V':
            printf("%s\n", versionMessage);
            exit(EXIT_SUCCESS);
        case 'h':
        case 'H':
            printf("%s\n", usageMessage);
            exit(EXIT_SUCCESS);
        case 'i':
            config->inFile = fopen(optarg, "r");
            if (!config->inFile) {
                fprintf(stderr, "%s\n", fileMessage);
            }
            break;
        case ':':
            fprintf(stderr, "%s\n", usageMessage);
            exit(EXIT_FAILURE);
        case '?':
            fprintf(stderr, "Unknown option: %c\n", optopt);
            exit(EXIT_FAILURE);
        }
    }

    Shell_run(config);

    Config_destroy(config);

    exit(EXIT_SUCCESS);
}
