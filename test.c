#include "src/throw.h"

int main() {
    error test = error_new(1, "test error");
    
    throw_error(&test, "This will print error to stderr or whatever THROW_FD is set to");

    throw_fatal(&test, "This will exit after throwing");
}