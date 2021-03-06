/*
** ETNA PROJECT, 12/11/2018 by juzain_d
** player move
** File description:
**      ...
*/

#include "ftl.h"

void jump(ship_t *ship)
{
    int percent = 30;
    int new_enemy;
    
    if (my_strcmp(ship->drive->system_state, "online") == 0) {
        if (ship->navigation_tools->enemy->here == 0) {
            ship->navigation_tools->sector = ship->navigation_tools->sector + 1;
            ship->drive->energy = ship->drive->energy - 1;
            ship->navigation_tools->detect = 0;
            my_putstr_color("green", "[CAPTAIN]: To infinity and beyond!\n");
            new_enemy = (random() % 100);
            if(new_enemy < percent)
                create_enemy(ship);
        } else
            my_putstr_color("red","[ORDER FAILURE]: Can not use jump, there is a new enemy\n");
    } else
        my_putstr_color("red","[SYSTEM FAILURE]: FTL Drive out of order!\n");
}

void attack(ship_t *ship)
{
    int percent;
    
    if (ship->navigation_tools->enemy->here == 0 && ship->navigation_tools->sector < 10)
        my_putstr_color("red", "[ORDER FAILURE]: No enemy in the sector\n");
    else {
        if (my_strcmp(ship->weapon->system_state, "online") == 0) {
            ship->navigation_tools->enemy->enemy->life =
                ship->navigation_tools->enemy->enemy->life - ship->weapon->damage;
            percent = (random() % 100);
        } else
            my_putstr_color("red","[SYSTEM FAILURE]: Weapon out of order!\n");
    }
    if ((ship->navigation_tools->enemy->here) &&
        (ship->navigation_tools->enemy->enemy->life <= 0)) {
        ship->navigation_tools->enemy->here = 0;
        my_putstr_color("green", "[CAPTAIN]: Enemy is Dead GOOD JOB!\n");
        if(percent < 50)
             lost_energy(ship);
    } else if (ship->navigation_tools->enemy->here)
        my_putstr_color("cyan", "[CAPTAIN]: We hit the enemy!\n");
}

void detect(ship_t *ship)
{
    if (my_strcmp(ship->navigation_tools->system_state, "online") == 0) { 
        if (ship->navigation_tools->detect == 0) {
            my_putstr_color("yellow","[SYSTEM DETECT]: Freight detected ! addition in progress...\n");
            ship->navigation_tools->detect = 1;
            create_bonus(ship);
            my_putstr_color("green", "[CAPTAIN]: Freight added!\n");
        }
        else if (ship->navigation_tools->detect == 1)
            my_putstr_color("red", "[ORDER FAILURE]: Freight already done.\n");
    } else
        my_putstr_color("red", "[SYSTEM FAILURE]: Navigation out of order!\n");
}

void stat(ship_t *ship)
{
    my_putstr_color("yellow", "hull stat : ");
    my_putnbr(ship->hull);
    my_putchar('\n');
    my_putstr_color("yellow", "energy stat : ");
    my_putnbr(ship->drive->energy);
    my_putchar('\n');
    my_putstr_color("yellow", "dammage stat : ");
    my_putnbr(ship->weapon->damage);
    my_putchar('\n');
    my_putstr_color("yellow", "evade stat : ");
    my_putnbr(ship->navigation_tools->evade);
    my_putchar('\n');
    my_putstr_color("yellow", "sector : ");
    my_putnbr(ship->navigation_tools->sector);
    my_putchar('\n');
}
