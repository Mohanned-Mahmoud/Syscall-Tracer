#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "syscall.h"
#include "defs.h"

uint64
sys_trace(void)
{
  int mask;
  if(argint(0, &mask) < 0)
    return -1;
  
  myproc()->tracing = (mask != 0);
  if(mask != 0) {
    myproc()->trace_mask = mask;
    myproc()->start_ticks = ticks;
  }
  return 0;
}
