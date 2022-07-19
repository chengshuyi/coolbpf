//+build ignore
#include "lbc.h"

SEC("kprobe/wake_up_new_task")
int j_wake_up_new_task(struct pt_regs *ctx)
{
	struct task_struct *parent = (struct task_struct *)PT_REGS_PARM1(ctx);

	bpf_printk("hello golcc, parent:%x\n", parent);
	return 0;
}

char LICENSE[] SEC("license") = "GPL";
