#include <stdio.h>
#include <stdlib.h>

void funcion(void) {
    static int x = 0;
    x++;
    printf("%d\n", x);
}

int main(void)
{
    funcion();
    funcion();
    funcion();
    funcion();
    funcion();

    return EXIT_SUCCESS;
}

/* Explicacion del funcionamiento */
/* Al declarar como static a la variable x, la funcion guarda el valor que tuvo x al terminar de ejecutarse la vez inmediatamente anterior. */
/* De esta manera, la primera vez se inicializa en 0, se le suma uno y se imprime (en la pantalla se ve "1". */
/*Al usar la funcion por segunda vez, la funcion se inicializa en 1 ya que la vez que se ejecuto anteriormente habia arrojado el valor de "1". */
/* Entonces, se le sumara 1 al valor en el cual inicializo y se imprimira dicha suma, viendose en pantalla "2". */
/* Con el mismo razonamiento, la usar la funcion por tercera vez consecutiva, se inicalizara en 2, imprimendose un 3 en pantalla. */
/* Asi sucesivamente hasta que la ultima vez se inicualiza en 4 y se imprime un 5. */
