#include "includes.h"

int main(int argc, char **argv){
    char buf[91];
    int **board;
    int *ret;
    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;
    int free_case = 0;

    board = (int **)malloc(sizeof(int *)*9);

    while(i < 9){
        board[i] = (int *)malloc(sizeof(int)*9);
        i++;
    }
    
    int fd = open(argv[1], O_RDONLY);
    int nb_read = read(fd,buf, 90);

    read(fd, buf, 90);
    printf("%i\n",argc);
    // printf("%s\n",buf);
    printf("%i\n", nb_read);
    buf[90]= '\0';
    close(fd);

    while(buf[j] != '\0') {
        board[n][m] = buf[j]-48;
        //if(board[n][m] != '0') {
        //   free_case ++;
        }
        if(buf[j] == '\n') {
            m = 0;
            n++;
            j++ ;
        } else {
            m++;
            j++;
            
        }
    }
    //printf("%i\n",free_case);

    n = 0;
    m = 0;
    while (m < 9){
        while(n < 9){
            printf("%i   ",board[m][n]);
            n++;
        }
        m++;
        n = 0;
        printf("%c \n", '\n');

    }

    

    i = 0;
    while(i < 9) {
        free(board[i]);
        i++;
    }
    free(board);

    return 0;

}
