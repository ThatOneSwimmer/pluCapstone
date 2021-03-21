#include "mini_uart.h"
#include "util.h"
#include "printf.h"
#include "timer.h"
#include "irq.h"

void kernel_main(void){
    uart_init();
    init_printf(0, putc);
    printf("Hello World \r\n");
    int el = get_el();
    printf("Exception level: %d \r\n", el);
    irq_vector_init();
    timer_init();
    enable_interrupt_controller();
    enable_irq();
    //check_irq();

    while(1){
        //check_irq();
        uart_send(uart_recv());
    }
}
