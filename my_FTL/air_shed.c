/*
** ETNA PROJECT, 12/11/2018 by juzain_d
** air shed
** File description:
**      ...
*/

#include "ftl.h"

ship_t *create_ship()
{
    ship_t *ship = malloc(sizeof(ship_t));

    my_putstr_color("blue", "building of the ship in progress...\n");
    if (ship == NULL) {
        my_putstr_color("red", "the ship could not be built due to lack of materials\n");
        return (NULL);
    } else {
        ship->hull = 50;
        ship->weapon = NULL;
        ship->drive = NULL;
        ship->navigation_tools = NULL;
        ship->container = NULL;
        my_putstr_color("green" , "ship improvement is finished!\n");
        return (ship);
    }
}

int add_weapon_to_ship(ship_t *ship)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    my_putstr_color("blue", "adding weapons in progress...\n");
    if (weapon == NULL) {
        my_putstr_color("red", "your ship exploded when you tried to add the weapons\n");
        return (0);
    } else {
        weapon->damage = 10;
        weapon->system_state = my_strdup("online");
        ship->weapon = weapon;
        my_putstr_color("green", "weapons were successfully added!\n");
        return (1);
    }
}

int add_ftl_drive_to_ship(ship_t *ship)
{
    ftl_drive_t *drive = malloc(sizeof(ftl_drive_t));

    my_putstr_color("blue", "adding the reactor in progress...\n");
    if (drive == NULL) {
        my_putstr_color("red", "your ship exploded when you put the reactor in\n ");
        return (0);
    } else {
        drive->energy = 10;
        drive->system_state = my_strdup("online");
        ship->drive = drive;
        my_putstr_color("green", "the reactor was successfully added!\n");
        return (1);
    }
}

int add_navigation_tools_to_ship(ship_t *ship)
{
    direct_enemy_t *enemy = malloc(sizeof(direct_enemy_t));
    navigation_tools_t *navigation_tools = malloc(sizeof(navigation_tools_t));
    my_putstr_color("blue", "adding navigation tools...\n");
    if (navigation_tools == NULL) {
        my_putstr_color("red", "your ship exploded when you put in the navigation tools\n");
        return (0);
    } else {
        if( enemy == NULL)
            return (0);
        enemy->enemy = NULL;
        enemy->here = 0;
        enemy->nb_elem = 0;
        navigation_tools->detect = 0;
        navigation_tools->sector = 0;
        navigation_tools->evade = 25;
        navigation_tools->system_state = my_strdup("online");
        ship->navigation_tools = navigation_tools;
        navigation_tools->enemy = enemy;
        my_putstr_color("green", "navigation tools were successfully added!\n");
        return (1);
    }
}
