#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf(2, "Usage: sleep <ticks>\n");  // Pass file descriptor 2 (stderr)
        exit();
    }

    int time = atoi(argv[1]);
    if (time < 0) {
        printf(2, "sleep: Invalid time\n");  // Pass file descriptor 2 (stderr)
        exit();
    }

    sleep(time);
    exit();
}
