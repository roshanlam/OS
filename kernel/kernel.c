#include <stdio.h>

#include "kernel.h"
#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "../libc/string.h"
#include "sign.h"

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


// login system 
void login(){
 unsigned char opc;
    do{
        printf("+=====================+\n");
		printf("| Sign in.........[1] |\n");
		printf("| Sign up.........[2] |\n");
		printf("| Exit............[3] |\n");
		printf("+=====================+\n->");
        opc = getchar();
		__fpurge(stdin);
		switch(opc){
			case '1':
				sign_in();
				break;
			case '2':
				sign_up();
				break;
			case '3':
				break;
			default:
				printf("Incorrect Option...\n\n");
    }
} while(opc != '3');
