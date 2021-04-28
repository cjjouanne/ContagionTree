# Tarea 0 2021-1 - El Virus de Kevin 🌎🦠😷
> Carlos Jouanne, 17642701


## Contenidos

* [Ejecución](#Ejecucion-)
* [Código](#Codigo-)
* [Tests](#Tests)
* [Análisis](#Analisis)


### Ejecucion 💻
La base de python se ejecuta con ` python3 ./python/main.py tests/test.txt out.txt`, mientras que
el programa en c se compila con `make` y se ejecuta con ` ./kevin-21 tests/test.txt out.txt`. Compila sin errores, y Valgrind 
indica que no hay errores ni pérdida de memoria.

### Codigo 📂

* [src/kevin-21](https://github.com/IIC2133-PUC/T0-2021-1-cjjouanne/tree/master/src/kevin-21)
  * [main.c](https://github.com/IIC2133-PUC/T0-2021-1-cjjouanne/blob/master/src/kevin-21/main.c)
  * [person.c](https://github.com/IIC2133-PUC/T0-2021-1-cjjouanne/blob/master/src/kevin-21/person.c)
  * [person.h](https://github.com/IIC2133-PUC/T0-2021-1-cjjouanne/blob/master/src/kevin-21/person.h)
  * [world.c](https://github.com/IIC2133-PUC/T0-2021-1-cjjouanne/blob/master/src/kevin-21/world.c)
  * [world.h](https://github.com/IIC2133-PUC/T0-2021-1-cjjouanne/blob/master/src/kevin-21/world.h)
* [Makefile](https://github.com/IIC2133-PUC/T0-2021-1-cjjouanne/blob/master/Makefile)

#### main.c

Este archivo no fue mayormente modificado. Se instanción el mundo en la linea `56:2`, y se pobló de paises y regiones en la linea `64:4`. En cada condicional
se llama a la función para encontrar a la persona utilizando la ruta si es que corresponde, y después se ejecuta la función asociada al comando.

#### person.c & person.h
En estos se declaran y definen la **struct** `person`, y las siguinetes funciones:
* `Person* init_tree()`: instancia una persona que es la raiz de un arbol, sin padre, ni elementos en su lista ligada.
* `void append_contact(Person* person, int id, int state)`: añade un hijo a `person`, con el `id` y `state` indicado.
* `void person_destroy(Person* person)`: elimina a la persona, y a todos sus hijos, y además libera la memoria pedida al momento de crearlos.
* `Person* search_contact(Person* person, int id)`: Busca el nodo hijo con el id dado.
* `void recursive_inform(Person *person, int depth, FILE* output_file)`: retorna una representación del árbol que se guarda en el archivo `output_file`.
* `positive_exam(Person* person)`: Este evento registra que una cierta Persona que era sospechosa en espera recibe un Test positivo, por lo que su estado cambia a contagiado. En caso de tener contactos estrechos, cambia el estado de cada uno a sospechoso en espera.
* `correct(Person* person1, Person* person2)`: intercambia los nodos hijos entre `person1` y `person2`.
* `positive_exam(Person* person)`: Este evento registra que una cierta Persona que era sospechosa en espera recibe un Test positivo, por lo que su estado cambia a contagiado. En caso de tener contactos estrechos, cambia el estado de cada uno a sospechoso en espera.
* `int count_state(Person* person, int state)`: cuenta la cantidad de personas que se encuentran en un estado determinado.
* `void recursive_statistics(Person* person, FILE* output_file)`: guarda un reporte mostrando cuantas personas se encuentran en un arbol.

#### world.c & world.h
En estos se declaran y definen la **struct** `world`, y las siguinetes funciones:
* `World* god_create_world(int n_countries)`: genera una instancia del mundo con `n_countries` paises.
* `void create_region(World *world, int country_index, int n_regions)`: crea `n_regions` en un país determinado, en un mundo establecido, y en cada región inicializa el arbol con un caso base.
* `void add_contact(World *world, int country, int region, Person *person, int close_contacts)`: añade `close_contacts` hijos a `person`.
* `void thanos(World *world)`: destruye el mundo, y libera su memoria.

### Analisis

> ⚠️ No se nada de complejidad, ni cálculos de complejidad. Puede estar todo malo.

A continuación, se muestra la complejidad teórica de cada acción considerando el peor caso:
* La complejidad de búsqueda de un paciente 0 es _O(1)_, muentras que en el peor de los casos es de _O(n)_ donde _n_ es el número de nodos del árbol.
  * **ADD_CONTACTS**: encontrar la persona a la cual se le añade un contacto tiene complejidad hasta _O(n)_. Añadir un elemento al final de una lista ligada tiene complejidad _O(1)_, al iterar sobre estacción, tenemos una complejidad de _O(n)_, por lo tanto, la complejidad total es _O(n)_.
  * **RECOVERD**: en el peor de los casos es _O(n)_, ya que la busqueda es _O(n)_ y el cambio de estado es _O(1)_.
  * **POSITIVE**: en el pero de los casos, la búsqueda es _O(n)_, el cambio de estado es _O(1)_, y el cambio de estado de los hijos es tambien hasta _O(n)_, por lo tanto tiene cmplejidad hasta _O(n)_.
  * **NEGATIVE**: en el pero de los casos, la búsqueda es _O(n)_, y borrar este nodo y sus hijos correspondientes tiene una complejidad de _O(n)_, por lo tanto tiene cmplejidad hasta _O(n)_.
  * **CORRECT**: cada búsqueda tiene una complejidad de _O(n)_, el cambio de padre de cada nodo tiene complejidad _O(1)_, por lo que la operación total, tiene complejidad hasta _O(n)_.

* **INFORM**: tiene siempre una complejidad de _O(n)_ pues siempre debe recorrer el arbol entero.
* **STATISTICS**: tiene siempre una complejidad de _O(n)_ pues siempre debe recorrer el arbol entero.
* Si se cambiase la estructura del arbol de personas, según se propone en el enunciado, pasando de utilizar una lista ligada a utilizar un arreglo, donde además del id, se conoce el índice en el cual se encuentra un nodo, se simplificaría la búsqueda ya que la búsqueda en un arreglo ordenado es _O(1)_ (_O(log n)_ si no supieramos el índice), mientras que en una lista ligada es _O(n)_. Almismo tiempo, las operaciones de _Insertar_ y _Eliminar_ elementos en la mitad se vuelven mas "costosas" ya que hay que volver a indexar todos los elementos posteriores a la posición en la que se inserta/elimina el elemento, dejando una complejidad de _O(n)_, mientras que en una lista ligada, estas operaciones tienen una complejidad de _O(1)_.

### Tests

Al *testear* el programa con los *tests* de los niveles *Easy*, *Medium* y *Hard* se obtuvieron resultados **correctos** de manera **eficiente**. Además, **_Valgrind_ indicó que el programa no tiene errores de memoria**, y que **no hay _memory leaks_**. El programa fue desarrollado y ejecutado con un procesador
Intel® Core i5 2da generación, 4GB de RAM, GPU NVIDIA® GEFORCE 2GB, utilizando el sistema operativo Kali Linux. 

#### Compare

Al ejecutar los tests obtenidos de la carpeta `./Compare`, utilizando el comando `time` de **bash**, se obtiene para cada test los siguientes resultados:

| Test   | Versión           | user     | system  | cpu    | total  |
|--------| :---------------: |:--------:| :------:|:------:|-------:|
| Test1  | Pyhon3            | 1.89s    | 0.06s   | 97%    | 1.995  |
|        | C                 | 0.32s    | 0.11s.  | 79%    | 0.545  |
|        | **Differencia**   | `1.57s`  | `0.05s` | `18%`  |`1.450` |
|        | **(porcentual)**  | `-83.06%`| `+83.3%`|`-18.5%`|`-72.7%`|
| Test2  | Pyhon3            | 3.42s    | 0.12s   | 98%    | 3.581  |
|        | C                 | 0.65s    | 0.18s.  | 76%    | 1.100  | 
|        | **Differencia**   | `2.77s`  | `0.06s` | `22%`  |`2.481` |
|        | **(porcentual)**  | `-80.99%`| `+50.0%`|`-22.4%`|`-69.2%`|
| Test3  | Pyhon3            | 4.71s    | 0.17s   | 96%    | 5.038  |
|        | C                 | 1.09s    | 0.29s.  | 73%    | 1.888  |
|        | **Differencia**   | `3.62s`  | `0.12s` | `23%`  |`4.150` |
|        | **(porcentual)**  | `-76.85%`| `+70.5%`|`-24.0%`|`-82.4%`|
| Test4  | Pyhon3            | 6.34s    | 0.24s   | 96%    | 6.834  |
|        | C                 | 1.54s    | 0.36s.  | 75%    | 2.508  |
|        | **Differencia**   | `4.80s`  | `0.12s` | `21%`  |`4.326` |
|        | **(porcentual)**  | `-75.70%`| `+50.0%`|`-21.8%`|`-63.3%`|
| Test5  | Pyhon3            | 8.24s    | 0.28s   | 98%    | 8.673  |
|        | C                 | 1.71s    | 0.42s.  | 77%    | 2.732  |
|        | **Differencia**   | `6.53s`  | `0.14s` | `21%`  |`5.941` |
|        | **(porcentual)**  | `-79.24%`| `+50.0%`|`-21.4%`|`-68.4%`|
| Test6  | Pyhon3            | 9.74s    | 0.29s   | 96%    | 10.401 |
|        | C                 | 2.10s    | 0.45s.  | 78%    | 3.240  |
|        | **Differencia**   | `7.64s`  | `0.16s` | `18%`  |`7.161` |
|        | **(porcentual)**  | `-78.43%`| `+55.2%`|`-18.8%`|`-68.8%`|
| Avg.   |                   |          |         |        |        |
|        | **Differencia**   | `79.04%` | `+59.8%`|`-21.2%`|`-70.8%`|

Como se puede ver en la tabla, el tiepo de ejecución del programa `user` esen promedio un **79.04% menor en C**, en relación a ejecutar el mismo test
en **Python3**. Además, utiliza un **21.2% menos de CPU**, y el valor total entregado por `time` es también un **70.8% menor en C**. Con esto podemos decir, que
evidentemente **C es más rápido que Python3**, ya que ejecuta la misma tarea en aproximadamente **1/5 del tiempo**. A pesar de esto, en la columna **system**, se
puede ver los tiempos para **C son 59.8% mayores que para Python3**. Esto quiere decir la cantidad de tiempo que la CPU (s) pasó realizando llamadas del sistema para el kernel en nombre del programa es mayor para **C** que para **Python3** (Al menos en la configuración en la cual los tests fueron ejecutados).

