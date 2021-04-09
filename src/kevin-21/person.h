#pragma once

struct person;

typedef struct  person Person;

struct person
{
    int id;
    int state;

    /*Nodo padre correspondiente al árbol*/
    Person* parent;

    /*Nodo cabeza y cola correspondiente a la lista ligada-nodos hijos*/
    Person* head;
    Person* tail;

    /*Nodo ant-erior y siguiente correspondiente a los nodos hermanos*/
    Person* prev;
    Person* _next;
};

Person* init_tree();
void append_contact(Person* person, int id, int state);
void person_destroy(Person* person);
Person* search_contact(Person* person, int id);
void recursive_inform(Person* person, int depth, FILE* output_file);
void positive_exam(Person* person);
void correct(Person* person1, Person* person2);
int count_state(Person* person, int state);
void recursive_statistics(Person* person, FILE* output_file);