# Tarea 0 2021-1 - El Virus de Kevin 🌎🦠😷
> Carlos Jouanne, 17642701


## Contenidos

* [Ejecución](#Ejecución)
* [Código](#Código)
* [Tests](#Tests)


### Ejecución 💻
La base de python se ejecuta con ` python3 ./python/main.py tests/test.txt out.txt`, mientras que
el programa en c se compila con `make` y se ejecuta con ` ./kevin-21 tests/test.txt out.txt`. Compila sin errores, y Valgrind 
indica que no hay errores ni pérdida de memoria.

### Código 📂

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


### Tests

#### Test1

| Versión           | user    | system  | cpu   | total |
| ----------------- |:-------:| :------:|:-----:|------:|
| Pyhon3            | 1.89s   | 0.06s   | 97%   | 1.995 |
| C                 | 0.32s   | 0.11s.  | 79%   | 0.32  |
| **Differencia**   | 1.57s   | 0.05s   | 18%   | 1.675 |

#### Test2

| Versión           | user    | system  | cpu   | total |
| ----------------- |:-------:| :------:|:-----:|------:|
| Pyhon3            | 3.42s   | 0.12s   | 98%   | 3.581 |
| C                 | 0.65s   | 0.18s.  | 76%   | 1.100 |
| **Differencia**   | 2.77s   | 0.06s   | 22%   | 2.481 |

#### Test3

| Versión           | user    | system  | cpu   | total |
| ----------------- |:-------:| :------:|:-----:|------:|
| Pyhon3            | 4.71s   | 0.17s   | 96%   | 5.038 |
| C                 | 1.09s   | 0.29s.  | 73%   | 1.888 |
| **Differencia**   | 3.62s   | 0.12s   | 23%   | 4.150 |

#### Test4

| Versión           | user    | system  | cpu   | total |
| ----------------- |:-------:| :------:|:-----:|------:|
| Pyhon3            | 6.34s   | 0.24s   | 96%   | 6.834 |
| C                 | 1.54s   | 0.36s.  | 75%   | 2.508 |
| **Differencia**   | 4.80s   | 0.12s   | 21%   | 4.326 |

#### Test5

| Versión           | user    | system  | cpu   | total |
| ----------------- |:-------:| :------:|:-----:|------:|
| Pyhon3            | 8.24s   | 0.28s   | 98%   | 8.673 |
| C                 | 1.71s   | 0.42s.  | 77%   | 2.732 |
| **Differencia**   | 6.53s   | 0.14s   | 21%   | 5.941 |

#### Test6

| Versión           | user    | system  | cpu   | total |
| ----------------- |:-------:| :------:|:-----:|------:|
| Pyhon3            | 9.74s   | 0.29s   | 96%   | 10.401|
| C                 | 2.10s   | 0.45s.  | 78%   | 3.240 |
| **Differencia**   | 7.64s   | 0.16s   | 18%   | 7.161 |
