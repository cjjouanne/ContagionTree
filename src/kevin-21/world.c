#include <stdio.h>
#include <stdlib.h>

#include "person.h"
#include "world.h"

// Esta función solo sirve para crear al planeta tierra (No testeado en otros planetas)
World* god_create_world(int n_countries)
{
    // El primer dia dios creo el mundo (solo Dios puede crear el mundo)
    World *earth = malloc(sizeof(World));
    // Cantidad de paises
    earth -> n_countries = n_countries;
    // Memoria para los otros atributos
    earth -> n_regions_countries = malloc(sizeof(int) * earth -> n_countries);
    earth -> countries = malloc(sizeof(Person**) * n_countries);
    earth -> people_count = malloc(sizeof(int*) * n_countries);

    return earth;
}

void create_region(World *world, int country_index, int n_regions)
{
    world -> n_regions_countries[country_index] = n_regions;
    world -> countries[country_index] = malloc(sizeof(Person*) * n_regions);
    world -> people_count[country_index] = malloc(sizeof(int) * n_regions);

    for (int region_index = 0; region_index < n_regions; region_index++)
    {
        // cada región empieza con un contacto contagiado
        world -> people_count[country_index][region_index] = 1;
        world -> countries[country_index][region_index] = init_tree();
    }
}

void add_contact(World *world, int country, int region, Person *person, int close_contacts)
{
    if (person -> state == 2)
    {
        for (int contact = 0; contact < close_contacts; contact++)
        {
            int id = world -> people_count[country][region];
            append_contact(person, id, 1);
            world -> people_count[country][region] = id + 1;
        }
    } else {
        for (int contact = 0; contact < close_contacts; contact++)
        {
            int id = world -> people_count[country][region];
            append_contact(person, id, 0);
            world -> people_count[country][region] = id + 1;
        }
    }
}

void thanos(World *world)
{
    for (int country_id=0;country_id<world->n_countries;country_id++)
    {
        for (int region_id=0;region_id<world->n_regions_countries[country_id];region_id++)
        {
            Person*curr=world->countries[country_id][region_id];
            person_destroy(curr);
        }
        free(world->people_count[country_id]);
        free(world->countries[country_id]);
    }
    free(world->n_regions_countries);
    free(world->countries);
    free(world->people_count);
    free(world);
}
