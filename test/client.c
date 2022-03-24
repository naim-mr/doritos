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
SemId sem_mem;
SemId sem_chan;

int cur;
void client(){
    

    

    P(sem_chan);
    cur=n_read_int();
    n_printf("current 1\n");
    //n_printf("current 1: %d\n",cur);
    
    V(sem_mem);
    V(sem_chan);
    
    
    
    
}

void client22(){
    
      P(sem_chan);   
      cur=n_read_int();
      n_printf("current 22\n");
      V(sem_mem);
      V(sem_chan);
    
  
    
}

void server(){
  
  
      P(sem_mem);
      n_printf("current serv: %d\n",cur); 
      
      V(sem_mem);
  
}

int

main()

{
  stop=0;
  cur=1;
  alive1=1;  
  sem_mem= SemCreate("memory",0);
  sem_chan= SemCreate("channel",1);
  ThreadId client1= threadCreate("client1",client);
  ThreadId client2=  threadCreate("client2",client22);
  ThreadId serv=  threadCreate("server",server);
  Join(client1);
  Join(client2);
  Join(serv);

  
  
  SemDestroy(sem_mem);
  SemDestroy(sem_chan);


  return 0;

}


