/*
 * throw.h
 *
 * Originally written by Joseph Werle (2013) – MIT License
 * https://github.com/jwerle/throw.h
 *
 * Modified in 2025 by Bartosz Mazurowski <bartosz.mazurowski@protonmail.com>
 */
 
#ifndef THROW_H
#define THROW_H 1

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int code;
    char *name;
} error;

FILE *THROW_FD = NULL;

void throw_error(void *type, char *msg);

void throw_fatal(void *type, char *msg);

error error_new(int code, char *name);

error error_new(int code, char *name) {
    error err;
    err.code = code;
    err.name = name;
    return err;
}

void throw_error(void *type, char *msg) {
    error *err = (error *)type;
    if (THROW_FD == NULL) {
        THROW_FD = stderr;
    }
    
    fprintf(THROW_FD, "%s [%d]: %s\n", err->name, err->code, msg);
}

void throw_fatal(void *type, char *msg) {
    error *err = (error *)type;
    throw_error(type, msg);
    exit(err->code);
}

#endif
