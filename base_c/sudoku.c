#include "includes.h" // import des bibliotheques grace au fichier includes.h

int main(int argc, char **argv) { // fonction principal
    /*
    initialisation des variables
    */
    char buf[91];
    int **board;
    int *ret;
    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;


    board = (int **)malloc(sizeof(int *)*9);//atribut de place pour le tableau

    while(i < 9){
        board[i] = (int *)malloc(sizeof(int)*9);
        i++;
    }
    /*
    ouvrire et lire le fichier texte 
    */
    int fd = open(argv[1], O_RDONLY);
    int nb_read = read(fd,buf, 90);

    read(fd, buf, 90);
    printf("%i\n",argc);
    // printf("%s\n",buf);
    printf("%i\n", nb_read);
    buf[90]= '\0';
    close(fd);

    /*
    stockage des valeur dans le tableau
    */
    while(buf[j] != '\0') {
        board[n][m] = buf[j]-48;
        if(buf[j] == '\n') {
            m = 0;
            n++;
            j++ ;
        } else {
            m++;
            j++;
            
        }
    }

    /*
    affichage des valeurs
    */

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

    
    /*
    liberer la place pour pas faire crash un pc
    */
    i = 0;
    while(i < 9) {
        free(board[i]);
        i++;
    }
    free(board);

    return 0;

}
