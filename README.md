# Tarea 0 2021-1

La base de python se ejecuta con 
``` python3 ./python/main.py tests/test.txt out.txt```

El programa en c se compila con ```make``` y se ejecuta con

``` ./kevin-21 tests/test.txt out.txt```

### Test1
C
```
./kevin-21 ./tests/Compare/test_1.txt ouput.txt  0.32s user 0.11s system 79% cpu 0.545 total
```

Python
```
python3 ./python/main.py ./tests/Compare/test_1.txt ouput.txt  1.89s user 0.06s system 97% cpu 1.995 total
```

### Test2
C
```
./kevin-21 ./tests/Compare/test_2.txt ouput.txt  0.65s user 0.18s system 76% cpu 1.100 total
```

Python
```
python3 ./python/main.py ./tests/Compare/test_2.txt ouput.txt  3.42s user 0.12s system 98% cpu 3.581 total
```

### Test3
C
```
./kevin-21 ./tests/Compare/test_3.txt ouput.txt  1.09s user 0.29s system 73% cpu 1.888 total
```

Python
```
python3 ./python/main.py ./tests/Compare/test_3.txt ouput.txt  4.71s user 0.17s system 96% cpu 5.038 total
```

### Test4
C
```
./kevin-21 ./tests/Compare/test_4.txt ouput.txt  1.54s user 0.36s system 75% cpu 2.508 total
```

Python
```
python3 ./python/main.py ./tests/Compare/test_4.txt ouput.txt  6.34s user 0.24s system 96% cpu 6.834 total
```

### Test5
C
```
./kevin-21 ./tests/Compare/test_5.txt ouput.txt  1.71s user 0.42s system 77% cpu 2.732 total
```

Python
```
python3 ./python/main.py ./tests/Compare/test_5.txt ouput.txt  8.24s user 0.28s system 98% cpu 8.673 total
```

### Test6
C
```
./kevin-21 ./tests/Compare/test_6.txt ouput.txt  2.10s user 0.45s system 78% cpu 3.240 total
```

Python
```
python3 ./python/main.py ./tests/Compare/test_6.txt ouput.txt  9.74s user 0.29s system 96% cpu 10.401 total
``