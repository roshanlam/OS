#include "kernel.h"
#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "../libc/string.h"

void kernel(){
    clear_screen();
    isr_install();
    irq_install();

    print("Type Something, it will go through the kernel\n");
    print("Type END to halt the CPI\n> ");
}

void user_input(char *input){
    if(strcmp(input, "END") == 0){
        printf("Stopping the CPU. Bye!\n");
        __asm__ __volatile__("hlt");
    }

    printf("You said: ");
    printf(input);
    printf("\n> ");
}
