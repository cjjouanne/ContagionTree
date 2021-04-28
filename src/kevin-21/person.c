#include <stdio.h>
#include <stdlib.h>
#include "person.h"

Person* init_tree()
{
    Person* person = malloc(sizeof(Person));
    person -> id = 0;
    person -> state = 2;
    person -> parent = NULL;
    person -> head = NULL;
    person -> tail = NULL;
    person -> prev = NULL;
    person -> _next = NULL;

    return person;
}

void append_contact(Person* parent, int id, int state)
{
    Person* person = malloc(sizeof(Person));
    person -> id = id;
    person -> state = state;
    person -> parent = parent;
    person -> head = NULL;
    person -> tail = NULL;
    person -> _next = NULL;


    if (parent -> head == NULL)
    {
        parent -> head = person;
        person -> prev = NULL;
    } else {
        parent -> tail ->_next = person;
        person -> prev = parent -> tail;
    }
    parent -> tail = person;
}

void person_destroy(Person* person)
{
    if (person -> head)
    {
        Person* curr = person -> head ->_next;
        Person* prev = person -> head;
        //int destroyed = malloc(sizeof(int));
        while (curr)
        {
            person_destroy(prev);
            prev = curr;
            curr = curr -> _next;
        }
        
        person_destroy(prev);
    }
    if ((person ->_next) && (person -> prev)) 
    {
        person -> _next -> prev = person -> prev;
        person -> prev -> _next = person -> _next;
    }
    else if (person -> _next)
    {
        person -> parent -> head = person -> _next;
        person -> _next -> prev = NULL;
    }
    else if (person -> prev)
    {
        person -> parent -> tail = person -> prev;
        person -> prev -> _next = NULL;
    }
    else if (person -> parent)
    {
        person -> parent -> head = NULL;
        person -> parent -> tail = NULL;
    }
    free(person);
}

Person* search_contact(Person* person, int id)
{
    if (person -> id == id)
    {
        return person;
    }
    // Busca el nodo hijo con id dado
    Person* curr = person -> head;
    while (curr)
    {
        if (curr -> id == id)
        {
            return curr;
        }
        curr = curr -> _next;
    }
    return NULL;
}

void recursive_inform(Person *person, int depth, FILE* output_file)
{
    for (int i = 0; i < depth; i++)
    {
        fprintf(output_file, "    ");
    }
    fprintf(output_file, "%i:%i\n", person -> id, person->state);
    Person *curr = person -> head;
    while (curr)
    {
        recursive_inform(curr, depth + 1, output_file);
        curr = curr -> _next;
    }
}

void positive_exam(Person* person)
{
    person -> state = 2;
    if (person -> head)
    {
        Person *curr = person -> head;
        while (curr)
        {
            curr -> state = 1;
            curr = curr -> _next; 
        }
    }
}

void correct(Person* person1, Person* person2)
{
    Person* curr1 = person1 -> head;
    while (curr1)
    {
        curr1 -> parent = person2;
        if (curr1 -> parent -> state == 2 && curr1 -> state < 2)
        {
            curr1 -> state = 1;
        }
        curr1 = curr1 -> _next;
    }
    Person* curr2 = person2 -> head;
    while (curr2)
    {
        curr2 -> parent = person1;
        if (curr2 -> parent -> state == 2 && curr2 -> state < 2)
        {
            curr2 -> state = 1;
        }
        curr2 = curr2 -> _next;
    }
    if ((person1 -> head) && (person2 -> head))
    {
        Person* head = person2 -> head;
        Person* tail = person2 -> tail;
        person2 -> head = person1 -> head;
        person2 -> tail = person1 -> tail;
        person1 -> head = head;
        person1 -> tail = tail;
    }
    else if (person1 -> head)
    {
        person2 -> head = person1 -> head;
        person2 -> tail = person1 -> tail;
        person1 -> head = NULL;
        person1 -> tail = NULL;
    }
    else if (person2 -> head)
    {
        person1 -> head = person2 -> head;
        person1 -> tail = person2 -> tail;
        person2 -> head = NULL;
        person2 -> tail = NULL;
    }
}

int count_state(Person* person, int state)
{
    int count = 0;
    if (person -> state == state)
    {
        count += 1;
    }
    Person* curr = person -> head;
    while (curr)
    {
        count += count_state(curr, state);
        curr = curr -> _next;
    }
    return count;
}

void recursive_statistics(Person* person, FILE* output_file)
{
    int state0 = count_state(person, 0);
    fprintf(output_file, "0:%i\n", state0);
    int state1 = count_state(person, 1);
    fprintf(output_file, "1:%i\n", state1);
    int state2 = count_state(person, 2);
    fprintf(output_file, "2:%i\n", state2);
    int state3 = count_state(person, 3);
    fprintf(output_file, "3:%i\n", state3);
}
