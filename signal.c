#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>



void processSignal(int s){
    printf("recibi signal %d\n", s);
    
}

void dontkillSignal(int m){
    if(m==15){
        printf("No me puedes matar %d\n", m);
    }
    
}



int main(){
    
    signal(10, processSignal);
    signal(15, dontkillSignal);
    while (1) {
    sleep(3);
    printf("Trabajando\n");
    }

    return 1;
   
}