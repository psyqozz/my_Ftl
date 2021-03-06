/*
** ETNA PROJECT, 12/11/2018 by juzain_d
** system repair
** File description:
**      ...
*/

#include "ftl.h"

static const repair_command_t com[] =
{
    {"ftl_drive", ftl_drive_system_repair},
    {"navigation_tools", navigation_tools_system_repair},
    {"weapon", weapon_system_repair},
    {"all" , all},
    {NULL, NULL}
};

void ftl_drive_system_repair(ship_t *ship)
{
    my_putstr_color("blue", "repair of the reactor in progress...\n");
    free(ship->drive->system_state);
    ship->drive->system_state = my_strdup("online");
    if (ship->drive->system_state == NULL) 
        my_putstr_color("red", "the reactor repairs failed\n");
    else 
        my_putstr_color("green", "repair complete! reactor system OK!\n");
}

void navigation_tools_system_repair(ship_t *ship)
{
    my_putstr_color("blue", "repair of the navigation tools system in progress...\n");
    free(ship->navigation_tools->system_state);
    ship->navigation_tools->system_state = my_strdup("online");
    if (ship->navigation_tools->system_state == NULL) 
        my_putstr_color("red", "the navigation tools repairs failed\n");
    else 
        my_putstr_color("green", "repair complete! navigation tools system OK!\n");
}

void weapon_system_repair(ship_t *ship)
{
    my_putstr_color("blue", "repair of the weapon system in progress...\n");
    free(ship->weapon->system_state);
    ship->weapon->system_state = my_strdup("online");
    if (ship->weapon->system_state == NULL) 
        my_putstr_color("red", "the weapon system repairs failed\n");
    else 
        my_putstr_color("green", "repair complete! weapon system OK!\n");
}

void system_repair(ship_t *ship)
{
    char *user;
    int i = 0;
    int found = 0;
    
    my_putstr_color("yellow", "repair_system(for repair all systems write all)~>");
    user = my_readline();
    if (user) {
        while (com[i].repair && !found) {
            if (my_strcmp(com[i].repair, user) == 0)
                found = 1;
            else
                i++;
        }
        if (!found && user)
            my_putstr_color("red", "[SYSTEM FAILURE]: unknown command\n");
        if (found)
            com[i].repairs(ship);
    } else
        my_putstr_color("red","[SYSTEM FAILURE]: the control reader is blocked\n");
    free(user);    
}

void all(ship_t *ship)
{
    ftl_drive_system_repair(ship);
    navigation_tools_system_repair(ship);
    weapon_system_repair(ship);
}
