/*
0;136;0c** ETNA PROJECT, 12/11/2018 by juzain_d
** ftl
** File description:
**      ...
*/

#ifndef _FTL_H_
#define _FTL_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>

typedef struct freight_s freight_t;
typedef struct direct_enemy_s direct_enemy_t;

typedef struct freight_s {
    char *item;
    freight_t *next;
    freight_t *prev;
}              freight_t;

typedef struct container_s {
    freight_t *first;
    freight_t *last;
    int nb_elem;
}              container_t;

typedef struct navigation_tools_s {
    char *system_state;
    int sector;
    int evade;
    int detect;
    direct_enemy_t *enemy;
}              navigation_tools_t;
    
typedef struct ftl_drive_s {
    char *system_state;
    int energy;
}              ftl_drive_t;

typedef struct weapon_s {
    char *system_state;
    int damage;
}              weapon_t;

typedef struct ship_s {
    int hull;
    weapon_t *weapon;
    ftl_drive_t *drive;
    navigation_tools_t *navigation_tools;
    container_t *container;
}              ship_t;

typedef struct repair_command_s {
    char *repair;
    void (*repairs)(ship_t *ship);
}              repair_command_t;

typedef struct game_command_s {
    char *command;
    void (*fonc_comm)(ship_t *ship);
}              game_command_t;

typedef struct enemy_s {
    int damage;
    int life;
}              enemy_t;

typedef struct direct_enemy_s {
    enemy_t *enemy;
    int here;
    int nb_elem;
}             direct_enemy_t;
    
ship_t *create_ship();
int add_weapon_to_ship(ship_t *ship);
int add_ftl_drive_to_ship(ship_t *ship);
int add_navigation_tools_to_ship(ship_t *ship);
int add_container_to_ship(ship_t *ship);
void add_freight_to_container(ship_t *ship, freight_t *freight);
void del_freight_from_container(ship_t *ship, freight_t *freight);
void get_bonus(ship_t *ship);
void ftl_drive_system_check(ship_t *ship);
void navigation_tools_system_check(ship_t *ship);
void weapon_system_check(ship_t *ship);
void system_control(ship_t *ship);
void ftl_drive_system_repair(ship_t *ship);
void navigation_tools_system_repair(ship_t *ship);
void weapon_system_repair(ship_t *ship);
void system_repair(ship_t *ship);
void all(ship_t *ship);
void game_loop(ship_t *ship);
void jump(ship_t *ship);
void attack (ship_t *ship);
void stat(ship_t *ship);
void command(ship_t *ship);
void create_enemy(ship_t *ship);
void enemy_attack(ship_t *ship);
void random_system_broken(ship_t *ship, int random);
void lost_energy(ship_t *ship);
char *init_bonus();
void create_bonus(ship_t *ship);
void show_bonus(freight_t *frei);
void detect (ship_t *ship);
void my_putstr(char *str);
void my_putstr_color(char *color, char *str);
char *my_strdup(char *str);
int my_strlen(char *str);
void my_putchar(char c);
int my_strcmp(char *s1, char *s2);
char *my_readline();
void my_putnbr(int n);
long int random(void);
void srandom(unsigned int seed);

#endif 
