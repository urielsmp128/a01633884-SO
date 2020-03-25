
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void forkexample(){
    pid_t pid,pid2;
    if(pid == 0){
        execlp("ls", "ls", "-a", "/",(char *)NULL);
    }else{
        printf("Soy el padre\n");
    }
}

int main(){
    forkexample();
    return 0;
}