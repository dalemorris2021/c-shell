#include <getopt.h>
#include <stdio.h>

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
            return 0;
        case 'h':
        case 'H':
            printf("%s\n", usageMessage);
            return 0;
        case 'i':
            config->inFile = fopen(optarg, "r");
            if (!config->inFile) {
                fprintf(stderr, "%s\n", fileMessage);
            }
            break;
        case ':':
            fprintf(stderr, "%s\n", usageMessage);
            return 1;
        case '?':
            fprintf(stderr, "Unknown option: %c\n", optopt);
            return 1;
        }
    }

    Shell_run(config);

    Config_destroy(config);

    return 0;
}
