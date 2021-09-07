# MECÁNICA FUNCION

### ¿Qué hace?

La función devuelve un puntero con una linea de un archivo.

> Si es llamada en bucle deberá devolver la siguiente linea no solo la primera.

Si no tiene salto de linea deberá devolver todo el archivo entero.

## Flujograma

		![https://media.vlpt.us/images/ljiwoo59/post/e1bf1799-8b15-426a-9055-2909b3687c0c/gnl-3.png](https://media.vlpt.us/images/ljiwoo59/post/e1bf1799-8b15-426a-9055-2909b3687c0c/gnl-3.png)

1. Chequea si la variable estática `saved*[fd]*` incluye la '\n'.

    → If *yes*, copia la string en `saved*[fd]` hasta que reciba otra* '\n'.

    → Entonces, *`saved[fd]`* will be overwritten into *saved[fd]* after a new line.

2. Read a file with the amount of BUFFER_SIZE.> Join existing *saved[fd]* with *buf*.> Return to *step 1*.

### ¿Cómo?

Por un lado tiene el `BUFFER_SIZE=xx`  este deberá de ser usado para determinar el buffer de las lecturas de `get_next_line`. 

Ejemplo 1:

```c
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=3 <archivos>.c.

1-  A B C D 1 2 3 4 '\n'
	      | |   | '--> SE VUELVE A JUNTAR TODO Y SE DEVUELVE PORQUE HA ENCONTRADO UN '\n'
	      | |   '---> the same shit
              | |          se junta con strjoin a la anterior. str = (A B C D ) 
	      | '---> se inicia el otra vez la función por dentro y recurre al la static para no volver a leer lo mismo.
	      |       se junta con strjoin a la anterior. str = (A B C D )
	      '---> se acumula en el static *char;
```

lee hasta null

### Desglose funciones.

- l**GNL MAIN FUNCTION**

    ### `char *get_next_line(int fd)`

![GNL Diagram](/flow_charts/gnl_flow_chart.png)

- **CHECK FUNCTION**

    ### `char *check(char *static);`

    1. → comprueba si la str recibida es valor nulo.
        1. libera memoria y retorna NULL
    2. → Recorre la linea por dentro hasta que llegue a valor nulo o '\n'. Incrementando un contador.

    Retorna a otra función el contador, el str y el fd

![GNL Diagram](/flow_charts/ft_check_chart.png)

- **GET LINE**

    ### `char *get_line(char *static, int len, const int fd);`
    1. Si tiene salto de linea, creamos una nueva str con substr dando como fin la len de la anterior función, duplicamos la static en una str temporal, hacemos free y después lo volvemos a asignar 
    2. Si no entra porque no tiene '\n' se duplica la string, se limpia y se devuelve la string 
 
![GNL Diagram](/flow_charts/ft_get_line_chart.png)
