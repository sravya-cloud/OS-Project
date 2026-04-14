#include <stdlib.h>

int main() {
    void *ptr;
    while(1) {
        ptr = malloc(1024 * 1024);
    }
    return 0;
}
