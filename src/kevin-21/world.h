#pragma once
#include "person.h"

struct world;

typedef struct world World;

struct world
{
    // Numero de paises
    int n_countries;
    // Número de regiones por país
    int *n_regions_countries;
    // Mundo, Personas por region en cada pais
    Person*** countries;
    // Cantidad de personas por region de cada pais
    int** people_count;
};

World* god_create_world(int n_countries);
void create_region(World* world, int country_id, int n_regions);
void thanos(World* world);
void add_contact(World* world, int country, int region, Person* person, int close_contacts);
