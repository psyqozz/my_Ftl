/*
** ETNA PROJECT, 12/11/2018 by juzain_d
** system control
** File description:
**      ...
*/

#include "ftl.h"

void ftl_drive_system_check(ship_t *ship)
{
    my_putstr_color("blue", "checking the reactor in progress...\n");
    if ((my_strcmp(ship->drive->system_state, "online") == 0)) 
        my_putstr_color("green", "reactor OK!\n");
    else 
        my_putstr_color("red", "reactor out of order!\n");
}

void navigation_tools_system_check(ship_t *ship)
{
    my_putstr_color("blue", "checking the navigation tools in progress...\n");
    if ((my_strcmp(ship->navigation_tools->system_state, "online") == 0))
        my_putstr_color("green", "navigation tools OK!\n");
    else
        my_putstr_color("red", "navigation tools out of order!\n");
}

void weapon_system_check(ship_t *ship)
{
    my_putstr_color("blue", "checking weapon system in progress...\n");
    if ((my_strcmp(ship->weapon->system_state, "online") == 0))
        my_putstr_color("green", "weapon system OK!\n");
    else
        my_putstr_color("red", "weapon system out of order!\n");
}

void system_control(ship_t *ship)
{
    ftl_drive_system_check(ship);
    navigation_tools_system_check(ship);
    weapon_system_check(ship);
}
        
