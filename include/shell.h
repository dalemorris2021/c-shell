#include <stdio.h>

#pragma once

typedef struct Config {
    FILE *inFile;
} Config;

void Shell_run(Config *config);

Config *Config_create();

void Config_destroy(Config *config);
