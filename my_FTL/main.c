/*
** ETNA PROJECT, 12/11/2018 by juzain_d
** main
** File description:
**      ...
*/

#include "ftl.h"

const game_command_t commands[] =
{
    {"attack", attack},
    {"detect", detect},
    {"jump", jump},
    {"getbonus", get_bonus},
    {"repair_system", system_repair},
    {"control_system", system_control},
    {"stat", stat},
    {"command", command},
    {NULL, NULL}
};

int main()
{
    ship_t *ship;
    ship  = create_ship();
    add_weapon_to_ship(ship);
    add_ftl_drive_to_ship(ship);
    add_navigation_tools_to_ship(ship);
    add_container_to_ship(ship);
    srandom(time(NULL));
    my_putstr_color("purple", "Welcome to FTL Game\n");
    while (ship->navigation_tools->sector < 10 && ship->drive->energy > 0 && ship->hull > 0) {
        game_loop(ship);
    }
    if (ship->navigation_tools->sector == 10)
        my_putstr_color("cyan", "YOU WIN !\n");
    else if (ship->hull <= 0)
        my_putstr_color("cyan", "GAME OVER ! your ship has been destroyed by rebel enemy.\n");
    else
        my_putstr_color("cyan", "GAME OVER ! we have no more energy.\n"); 
    free(ship);
    return (0);
}

void game_loop(ship_t *ship)
{
    char *com = "attack";
    char *user;
    int i = 0;
    int found = 0;
    my_putstr( "Enter a command (Write command to see the menu) : ");
    user = my_readline();
    if (user) {
        while (commands[i].command && found == 0) {
            if (my_strcmp(commands[i].command, user) == 0) {
                if (my_strcmp(user, com) == 0)
                    enemy_attack(ship);
                commands[i].fonc_comm(ship);
                found = 1;
            } else
                i++;
        }
        if (!found && user)
            my_putstr_color("red", "[ORDER FAILURE]: unknown command\n");
    } else
        my_putstr_color("red", "[ORDER FAILURE]: the control reader is blocked\n");
}

void command(ship_t *ship)
{
    int i;
    
    if (ship->navigation_tools->sector < 10)
        i = 0;
    while (commands[i].command) {
        my_putstr_color("yellow", "command ");
        my_putstr_color("purple", commands[i].command);
        my_putstr_color("yellow", " : ");
        my_putstr(commands[i].command);
        my_putchar('\n');
        i++;
    }
}
