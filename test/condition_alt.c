/* hello.c

 *	Simple hello world program

 *

//  Copyright (c) 1999-2000 INSA de Rennes.

//  All rights reserved.  

//  See copyright_insa.h for copyright notice and limitation 

//  of liability and disclaimer of warranty provisions.

 */



#include "userlib/syscall.h"

#include "userlib/libnachos.h"
#include "userlib/syscall.h"

int alive1;
int stop;
CondId cond;
int cur;
void job(){
    n_printf("ici : %d\n",cur);
    if(cur==-1) {
        cur=0;
        CondWait(cond);
    }
    n_printf("ici : %d\n",cur);
    int i=0;
    for(i;i<200;i++){
        n_printf("%d: %d\n",(cur+1),i);
        cur = (cur + 1)%2;
        CondSignal(cond);
        CondWait(cond);
    }
}

int main()  {
  cur=-1;
  cond= CondCreate("condition test");
  ThreadId client1= threadCreate("client1",job);
  ThreadId client2=  threadCreate("client2",job);  
  return 0;
}


