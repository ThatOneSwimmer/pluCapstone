#include "util.h"
#include "printf.h"
#include "timer.h"

const unsigned int interval = 2000000;
unsigned int curVal = 0;

void timer_init ( void )
{
	curVal = get32(TIMER_CLO);
    //printf("curVal: %d \n\r", curVal);
	curVal += interval;
    //printf("goal value: %d \n\r", curVal);
	put32(TIMER_C1, curVal);
}

void handle_timer_irq( void ) 
{
	curVal += interval;
	put32(TIMER_C1, curVal);
	put32(TIMER_CS, TIMER_CS_M1);
	printf("Timer interrupt received\n\r");
}

void current_time( void ){
    unsigned int goal_val = get32(TIMER_C1);
    curVal = get32(TIMER_CLO);
    printf("cur Time: %d goal time: %d \n\r", curVal, goal_val);
}