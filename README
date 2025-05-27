# xv6 System Call Tracer (strace-like)

## Overview

This project extends the xv6 operating system by implementing a **system call tracer** similar to the Unix `strace` tool. The tracer logs all system calls made by processes, including the syscall name, arguments, and return values, enabling detailed monitoring and debugging of process behavior at the system call level.

---

## Features

- **Per-process syscall tracing:** Enable or disable syscall tracing on a per-process basis.
- **Detailed syscall logging:** Logs syscall name, process ID, process name, and return value.
- **Supports tracing child processes:** Optionally trace syscalls made by child processes created via `fork()`.
- **User-level trace control program:** A built-in user program (`trace`) to test and demonstrate tracing functionality.
- **Shell command integration:** Added `trace` and `untrace` commands in the shell to toggle tracing on and off.

---

## Implementation Details

### Kernel Modifications

- **Process Structure (`proc.h`):**  
  Added a `traced` flag in the process control block to indicate if tracing is enabled for that process.

- **New System Call `trace` (`syscall.h`, `syscall.c`, `defs.h`):**  
  Introduced a new syscall to enable or disable tracing for the current process.

- **System Call Dispatch (`syscall.c`):**  
  Modified the syscall dispatcher to check the `traced` flag and print syscall information (name, PID, process name, return value) when tracing is enabled.

- **Syscall Name Mapping:**  
  Added human-readable syscall names for logging.

- **Shell (`sh.c`):**  
  Integrated `trace` and `untrace` commands to control tracing from the shell. These commands toggle a global tracing flag that enables/disables syscall tracing for processes spawned by the shell.

### User-Level Program

- **trace.c:**  
  A user program to test syscall tracing. It demonstrates enabling tracing, running commands with tracing enabled, including for child processes, and disabling tracing.

### Build System

- **Makefile:**  
  Added `trace` to the list of user programs to be compiled and included in the xv6 image.

---

## How to Use

1. **Build and Run:**  
   Build xv6 with the modified source and run it in QEMU or your preferred emulator.

2. **Enable Tracing:**  
   From the xv6 shell, type:
to enable syscall tracing.

3. **Run Commands:**  
Any subsequent commands you run will have their syscalls logged.

4. **Disable Tracing:**  
To stop tracing, type:

5. **Use the `trace` program:**  
You can also run the `trace` user program to see examples of syscall tracing in action.

---

## Example Output

Each syscall traced is logged with:

- **PID:** Process ID of the calling process
- **Process Name:** Name of the program
- **Syscall Name:** The syscall invoked
- **Return Value:** Result returned by the syscall

Example:

---

## Testing

- Successfully tested on xv6 running in QEMU.
- Verified correct syscall logging for common commands (`echo`, `cat`, `rm`, `sh`).
- Verified tracing toggles correctly with `trace` and `untrace` commands.
- Confirmed tracing propagates to child processes when enabled.

---

## Files Modified / Added

- `proc.h` — Added `traced` flag to `struct proc`
- `syscall.h`, `syscall.c`, `defs.h` — Added `trace` syscall and logging enhancements
- `sh.c` — Added `trace` and `untrace` shell commands
- `user/trace.c` — User program to test tracing functionality
- `Makefile` — Added `trace` to user programs list

---

## Acknowledgements

This project was developed as part of an operating systems course assignment to implement syscall tracing in xv6.

---

Feel free to reach out if you have questions or want to contribute!
