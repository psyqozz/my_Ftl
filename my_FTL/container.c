/*
** ETNA PROJECT, 12/11/2018 by juzain_d
** container 
** File description:
**      ...
*/

#include "ftl.h"

int add_container_to_ship(ship_t *ship)
{
    container_t *container = malloc(sizeof(container_t));
    
    my_putstr_color("blue", "adding the current container...\n");
    if (container == NULL) {
        my_putstr_color("red", "your ship exploded when you put the container down\n");
        return (0);
    } else {
        container->first = NULL;
        container->last = NULL;
        container->nb_elem = 0;
        ship->container = container;
        my_putstr_color("green", "the container was successfully added!\n");
        return (1);
    }
}

void add_freight_to_container(ship_t *ship, freight_t *freight)
{
    if (ship->container->first == NULL) {
        ship->container->first = freight;
        ship->container->last = freight;
        ship->container->first->next = NULL;
        ship->container->first->prev = NULL;
    } else {
        freight->next = NULL;
        freight->prev = ship->container->last;
        ship->container->last->next = freight;
        ship->container->last = freight;
    }
    ship->container->nb_elem = ship->container->nb_elem + 1;
}

void del_freight_from_container(ship_t *ship, freight_t *freight)
{
    if (freight == ship->container->first || freight == ship->container->last) {
        if (freight == ship->container->first) {
            ship->container->first = NULL;
            ship->container->last = NULL;
        } else {
            ship->container->last = freight->prev;
            ship->container->last->next = NULL;
        }
    } else {
        freight->prev->next = freight->next;
        freight->next->prev = freight->prev;
    }
    free(freight);
    ship->container->nb_elem = ship->container->nb_elem - 1;
}

void get_bonus(ship_t *ship)
{
    freight_t *freight = ship->container->first;
    
    while (freight != NULL) {
        if (my_strcmp(freight->item, "attackbonus") == 0) 
            ship->weapon->damage = ship->weapon->damage + 5;
        else if (my_strcmp(freight->item, "evadebonus") == 0) 
            ship->navigation_tools->evade = ship->navigation_tools->evade +3;
        else if (my_strcmp(freight->item, "energy") == 0) 
            ship->drive->energy = ship->drive->energy + 1;
        show_bonus(freight);
        freight = freight->next;
    }
    my_putstr_color("yellow", "(Show your stat for more informations)\n");
    freight = ship->container->last;
    while (freight != NULL) {
        del_freight_from_container(ship, freight);
        freight = freight->prev;
    }
}

void show_bonus(freight_t *frei)
{    
    if (my_strcmp(frei->item, "attackbonus") == 0)
        my_putstr_color("purple", "[SYSTEM]: Attack bonus +5\n");
    else if (my_strcmp(frei->item, "energy") == 0)
        my_putstr_color("purple", "[SYSTEM]: Energy +1\n");
    else if (my_strcmp(frei->item, "evadebonus") == 0)
        my_putstr_color("purple", "[SYSTEM]: Evade bonus +3\n");
}
