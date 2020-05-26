#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argn, char **argv){
    char *fileName = argv[1];
    char buffer;
    char espacio = 0;
    unsigned int numChar = 0;
    unsigned int numNewL = 0;
    unsigned int numWord = 0;

    int fd = open(fileName, O_RDONLY);
    
    if (fd < 0){
        printf("No se pudo abrir \n");
        exit(1);
    }
    
    while(read(fd, &buffer, 1)) {
        numChar++;
        if (buffer == 10) numNewL++;
        if ((buffer == ' ' || buffer == '\n' ) && espacio == 0) {
            espacio = 1;
            numWord += 1;
        } else if (buffer != ' ' && buffer != '\n' && buffer != EOF) {
            espacio = 0;
        }
    }
    numWord += 1;
    printf(" %d \n", numNewL);
    printf(" %d \n", numWord);
    printf(" %d \n", numChar);
    printf("%s \n",fileName);
    close(fd);
    exit(0);
}