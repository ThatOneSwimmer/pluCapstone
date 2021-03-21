#include "memman.h"
#include "sysregs.h"

.section ".text.boot"

.globl _start
_start:
	mrs	x0, mpidr_el1		
	and	x0, x0,#0xFF		// Check processor id
	cbz	x0, master		    // Hang for all non-primary CPU
	b	proc_hang

proc_hang: 
	b 	proc_hang

master:
    ldr	x0, =SCTLR_VALUE_MMU_DISABLED
	msr	sctlr_el1, xzr	
    ldr x0, =HCR_VALUE
    msr hcr_el2, x0
    ldr x0, =SPSR_VALUE
    msr spsr_el2, x0

    //mov x0, #0x431 this guy breaks it
    //msr scr_el3, x0

	//msr     sp_el1, x1
    // enable CNTP for EL1
    //mrs     x0, cnthctl_el2
    //orr     x0, x0, #3
   //msr     cnthctl_el2, x0
   // msr     cntvoff_el2, xzr
    // enable AArch64 in EL1
   // mov     x0, #(1 << 31)      // AArch64
   // msr     hcr_el2, x0
   // mrs     x0, hcr_el2
    // change execution level to EL1
  //  mov     x2, #0x3c5
 //   msr     spsr_el2, x2
    adr     x2, el1_entry
    msr     elr_el2, x2
    eret

el1_entry:
	adr	x0, bss_begin
	adr	x1, bss_end
	sub	x1, x1, x0
	bl 	memzero
    mov	sp, #LOW_MEMORY
	bl	kernel_main
	b 	proc_hang	