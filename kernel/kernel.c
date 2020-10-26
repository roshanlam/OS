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

// login system
void login(){
char UN[10],pw[8],emailid[20],mobno[10],username[10],password[8];
int choice,counter=0;
int a=0,cl=0,sl=0,n=0;
do{
 		printf("+=====================+\n");
		printf("| Sign in.........[1] |\n");
		printf("| Sign up.........[2] |\n");
		printf("| Exit............[3] |\n");
		printf("+=====================+\n->");
scanf("%d",&choice);

switch (choice){
case 1:
          
printf("Enter username : ");
scanf("%s",&UN);
pass:
 printf("Enter password : ");
scanf("%s",&pw);

if (strlen(pw)<=8){
  for(int i=0;i<strlen(pw);i++){
      a=pw[i];
      if (a>=65 && a<=90){
              cl++;
      }
      else if (a>=97 && a<=122){
              sl++;
      }
      else if(a>=48 && a<=57){
               n++;
     }
 }
}else{
    printf("\nPlease Enter password less than 8 length\n ");
    goto pass;
}
if ((cl==0) || (sl==0) || (n==0)){
     printf("\nPlease Enter atleast 1UC and 1LC and number\n ");
    goto pass;
}
else{
    printf("password accepted...\n");
}
a = 0;
ei:printf("\nEnter email ID : ");
scanf("%s",&emailid);
a = emailid[0];
if(a>=48 && a<=57){
    printf("\nFirst latter should be character");
    goto ei;
}
a = 0;
for(int i = 0; i < strlen(emailid); i++){  
    if (emailid[i]==64)
         a++;
}
if(a<1 || a>1){
   printf("\n Enter valid email id\n");
   goto ei;
}
else{
     printf("%s your email id is %s   \n",UN,emailid);
     printf("\nEmail accepted...\n");
}
mob:printf("\nEnter mobile number : ");
scanf("%s",&mobno);
a = 0;
n = 0;
cl = 0;
sl = 0;
for (int i = 0; i < strlen(mobno); i++){ 
  a = mobno[i];
  if (a>=48 && a<=57){
     n++;
  }
  else if (a>=65 && a<=90){
      cl++;
  }
   else if (a>=97 && a<=122){
              sl++;
             }  
}

if(n>10){
     printf("\nyou have entered more than 10 digits\n ");
      goto mob;
}
else{
       printf("\nmobile number accepted");
}
    printf("\nSIGNUP SUCCESSFULL");
    break;
case 2:              
u1:printf("\nEnter username : ");
  scanf("%s",&username);
  if (strcmp(UN,username)==0){
    p1:  printf("\nEnter password : ");
      scanf("%s",&password);
      if (strcmp(pw,password)==0){
         printf("\nWellcome %s you login successfully....",username);
      }
  else{
       counter++;
       printf("\n Incorrect password");
       printf("\nyou have %d attempt",3-counter);
       if (counter<3)
          goto p1;
       else
          break;
    }
  }
  else{
       printf("\n Incorrect Username");
       goto u1;
  }
  
  
     break;
default:
  printf("\n Exit\n");
    break;
}
 
} while (choice == 1 || choice == 2);

    return 0;
}
