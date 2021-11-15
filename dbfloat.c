#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void db_to_float(double db) {
    double f = pow(10, db / 20);
    printf("%.8f ( %.02f%% )\n", f, f*100);
}

bool float_to_db(float f) {
    if (f <= 0) {
        fprintf(stderr, "Invalid argument: %f, positive number required\n", f);
        return false;
    }
    double db = 20.0 * log10(f);
    printf("%.02f dBFS ( %.7f )\n", db, db);
    return true;
}

void print_help(FILE * out) {
    fprintf(out,
            "Usage:\n"
            "\n"
            "  dbfloat FLOAT | FLOAT%%\n"
            "    Convert float number or percent value to dBFS value.\n"
            "\n"
            "  dbfloat FLOATdb\n"
            "    Convert dBFS value to float number and percent value.\n"
        );
}

int main(int argc, char * argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Need an argument.\n");
        print_help(stderr);
        exit(EXIT_FAILURE);
    }
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_help(stdout);
        exit(EXIT_SUCCESS);
    }

    float num;
    char suffix[10] = { 0 };

    sscanf(argv[1], "%f %9s",  &num, suffix);

    for (char * c = suffix; *c != '\0'; c++) {
        *c = tolower(*c);
    }

    bool isSuccess = true;
    if (strcmp(suffix, "db") == 0 || strcmp(suffix, "dbfs") == 0) {
        db_to_float(num);
    } else if (strcmp(suffix, "%") == 0) {
        float_to_db(num / 100);
    } else if (strlen(suffix) == 0) {
        isSuccess = float_to_db(num);
    } else {
        fprintf(stderr, "Invalid argument: %s\n", argv[1]);
        isSuccess = false;
    }
    exit(isSuccess ? EXIT_SUCCESS : EXIT_FAILURE);
}
