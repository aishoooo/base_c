#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include  <sys/types.h>
#include  <sys/stat.h>
#include  <fcntl.h>



int main(int argc, char **argv){
    char buf [91];
    int grid [9][9];
    int grid_total;

    grid_total = grid;

    int fd = open(argv[1], O_RDONLY);
    int nb_read = read(fd,buf, 90);

    char *ret = (char*)malloc(sizeof(char) *grid);


    read(fd, buf, 90);
    printf("%i\n",argc);
    printf("%s\n",buf);
    printf("%i\n", nb_read);
    printf("%s\n",ret);
    printf("%s\n",grid_total);
    buf[90]= '\0';
    close(fd);
}