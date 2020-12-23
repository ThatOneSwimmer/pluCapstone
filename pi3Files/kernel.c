#include "mini_uart.h"
#include "util.h"
#include "printf.h"

void kernel_main(void){
    uart_init();
    uart_send_string("Hello, world!\r\n");
    init_printf(0, putc);
    int el = get_el();
    printf("Exception Level: %d \r\n", el);

    while(1){
        uart_send(uart_recv());
    }
}
