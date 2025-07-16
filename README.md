# throw

Create errors and throw them easily

## install

```sh
$ nibble add throw
```

## usage 

```c
#include "src/throw.h"

int main() {
    error test = error_new(1, "test error");
    
    throw(&test, "This will print error to stderr or whatever THROW_FD is set to");

    throw_fatal(&test, "This will exit after throwing");
}
```