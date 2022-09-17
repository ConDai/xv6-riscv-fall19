#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {

  int p2c[2];
  int c2p[2];
  int pid;
  // Create parent to child pipe
  pipe(p2c);
  // Create child to parent pipe
  pipe(c2p);

  char buf = 'O';
  // Fork child and parent
  pid = fork();

  // pid >= -1

  // If we failed to fork
  if (pid == -1) {
    fprintf(2, "Failed to fork\n");
    exit();
  }

  if (pid == 0) {
    // 1. Read byte from parent
    read(p2c[0], &buf, 1);
    fprintf(0, "%d: received ping\n", pid);
    // 2. Send byte to parent
    write(c2p[1], &buf, 1);
  } else { // (pid > 0)
    // 1. Send a byte to child
    write(p2c[1], &buf, 1);
    // 2. Read byte from child and exit
    read(c2p[0], &buf, 1);
    fprintf(0, "%d: received pong\n", pid);
  }
  exit();

  // Use pipe to create a pipe
  // Use fork to create a child
  // Use `read` to read from a pipe and `write` to write to a pipe
  // Use `getpid` to find the process ID of the calling process
  // Add the program to UPROGS in Makefile
}