#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

void basic_argument_parsing(int argc, char *argv[]) {
    printf("number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argument %d: %s\n", i, argv[i]);
    }
}

void getopt_example(int argc, char *argv[]) {
    int opt;
    char *filename = NULL;
    int verbose = 0;

    while ((opt = getopt(argc, argv, "hvf:")) != -1) {
        switch (opt) {
            case 'h':
                printf("usage: %s [-h] [-v] [-f filename]\n", argv[0]);
                return;
            case 'v':
                verbose = 1;
                break;
            case 'f':
                filename = optarg;
                break;
            default:
                printf("usage: %s [-h] [-v] [-f filename]\n", argv[0]);
                return;
        }
    }

    if (verbose) {
        printf("verbose mode enabled.\n");
    }

    if (filename) {
        printf("file to process: %s\n", filename);
    } else {
        printf("no file specified.\n");
    }
}

void getopt_long_example(int argc, char *argv[]) {
    int opt;
    char *filename = NULL;

    struct option long_options[] = {
        {"help",    no_argument,       0, 'h'},
        {"version", no_argument,       0, 'v'},
        {"file",    required_argument, 0, 'f'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "hvf:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'h':
                printf("usage: %s [--help] [--version] [--file filename]\n", argv[0]);
                return;
            case 'v':
                printf("version 1.0.0\n");
                return;
            case 'f':
                filename = optarg;
                break;
            default:
                printf("usage: %s [--help] [--version] [--file filename]\n", argv[0]);
                return;
        }
    }

    if (filename) {
        printf("file to process: %s\n", filename);
    } else {
        printf("no file specified.\n");
    }
}

int main(int argc, char *argv[]) {
    printf("=== basic argument parsing ===\n");
    basic_argument_parsing(argc, argv);

    printf("\n=== getopt example ===\n");
    getopt_example(argc, argv);

    printf("\n=== getopt_long example ===\n");
    getopt_long_example(argc, argv);

    return 0;
}
