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



SemId sem_mem;
SemId sem_chan;

int current;
void client(){
    P(sem_chan);
    current++;
    
    V(sem_chan);
    V(sem_mem);
}


void server(){
    P(sem_mem);
    
     n_printf("current: %d\n",current);
    

    V(sem_mem);
    
}

int

main()

{
  current=0;
  sem_mem= SemCreate("memory",0);
  sem_chan= SemCreate("channel",1);
  ThreadId client1= threadCreate("client1",client);
  ThreadId client2=  threadCreate("client2",client);
  ThreadId server=  threadCreate("server",client);
   
  Join(server);
  Join(client1);
  Join(client2);

  SemDestroy(sem_mem);
  SemDestroy(sem_chan);


  return 0;

}


