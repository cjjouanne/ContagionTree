# Tarea 0 2021-1 - El Virus de Kevin 🌎🦠😷
> Carlos Jouanne, 17642701


## Contenidos

* [Ejecución]()
* [Código]()
* [Tests]()


### Ejecución 💻
La base de python se ejecuta con ` python3 ./python/main.py tests/test.txt out.txt`, mientras que
el programa en c se compila con `make` y se ejecuta con ` ./kevin-21 tests/test.txt out.txt`. Compila sin errores, y Valgrind 
indica que no hay errores ni pérdida de memoria.

### Código 📂

* src/kevin-21
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
C
```
./kevin-21 ./tests/Compare/test_1.txt ouput.txt  0.32s user 0.11s system 79% cpu 0.545 total
```

Python
```
python3 ./python/main.py ./tests/Compare/test_1.txt ouput.txt  1.89s user 0.06s system 97% cpu 1.995 total
```

#### Test2
C
```
./kevin-21 ./tests/Compare/test_2.txt ouput.txt  0.65s user 0.18s system 76% cpu 1.100 total
```

Python
```
python3 ./python/main.py ./tests/Compare/test_2.txt ouput.txt  3.42s user 0.12s system 98% cpu 3.581 total
```

#### Test3
C
```
./kevin-21 ./tests/Compare/test_3.txt ouput.txt  1.09s user 0.29s system 73% cpu 1.888 total
```

Python
```
python3 ./python/main.py ./tests/Compare/test_3.txt ouput.txt  4.71s user 0.17s system 96% cpu 5.038 total
```

#### Test4
C
```
./kevin-21 ./tests/Compare/test_4.txt ouput.txt  1.54s user 0.36s system 75% cpu 2.508 total
```

Python
```
python3 ./python/main.py ./tests/Compare/test_4.txt ouput.txt  6.34s user 0.24s system 96% cpu 6.834 total
```

#### Test5
C
```
./kevin-21 ./tests/Compare/test_5.txt ouput.txt  1.71s user 0.42s system 77% cpu 2.732 total
```

Python
```
python3 ./python/main.py ./tests/Compare/test_5.txt ouput.txt  8.24s user 0.28s system 98% cpu 8.673 total
```

#### Test6
C
```
./kevin-21 ./tests/Compare/test_6.txt ouput.txt  2.10s user 0.45s system 78% cpu 3.240 total
```

Python
```
python3 ./python/main.py ./tests/Compare/test_6.txt ouput.txt  9.74s user 0.29s system 96% cpu 10.401 total
```
