/*
** ETNA PROJECT, 12/11/2018 by juzain_d
** enemy 
** File description:
**      ...
*/

#include "ftl.h"
void create_enemy(ship_t *ship)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    int life;
    int damage;
    
    damage = 10 * ((0.5 * ship->navigation_tools->enemy->nb_elem) + 1);
    life = 20 * ((0.5 * ship->navigation_tools->enemy->nb_elem) + 1);
    if (enemy != 0) {
        if (ship->navigation_tools->sector < 10)
            my_putstr_color("yellow", "[SYSTEM DETECT]: New Enemy, prepare to fight!\n");
        enemy->damage = damage;
        enemy->life = life;
        ship->navigation_tools->enemy->enemy = enemy;
        ship->navigation_tools->enemy->nb_elem++;
        ship->navigation_tools->enemy->here = 1;
    }
}

void enemy_attack(ship_t *ship)
{
    int system_touch;
    
    if (ship->navigation_tools->enemy->here == 1) {
        if ((random() % 100) < ship->navigation_tools->evade)
            my_putstr_color("cyan", "[CAPTAIN]: we avoided the attack!\n");
        else {
            ship->hull = (ship->hull - ship->navigation_tools->enemy->enemy->damage);
            if((my_strcmp(ship->weapon->system_state, "online") == 0) && ship->hull > 0)
               my_putstr_color("red", "[CAPTAIN]: we were touched!\n");
            if ((random() % 100 < 20)) {
                system_touch = (random() % 3);
                random_system_broken(ship, system_touch);
            }
        }
    }
}

void random_system_broken(ship_t *ship, int random)
{
    if (random == 0) {
        my_putstr_color("red", "[CRITICAL HIT]: hit weapon system!\n");
        free(ship->weapon->system_state);
        ship->weapon->system_state = my_strdup("off");
    } else if (random == 1) {
        my_putstr_color("red", "[CRITICAL HIT]: hit ftl drive system!\n");
        free(ship->drive->system_state);
        ship->drive->system_state = my_strdup("off");
    } else {
        my_putstr_color("red", "[CRITICAL HIT]: hit navaigation system!\n");
        free(ship->navigation_tools->system_state);
        ship->navigation_tools->system_state = my_strdup("off");
    }
}
