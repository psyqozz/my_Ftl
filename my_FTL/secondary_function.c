/*
** ETNA PROJECT, 12/11/2018 by juzain_d
** secondary fonction
** File description:
**      ...
*/

#include "ftl.h"

void lost_energy(ship_t *ship)
{
    ship->drive->energy = ship->drive->energy - 1;
    my_putstr_color("red","[SYSTEM DETECT]: We lost energy!\n");
}

char *init_bonus()
{
    char *result;
    int nb_rand;
    int nb_bonus;
    
    nb_rand = (random() % 100);
    if (nb_rand <= 70)
        result = "scrap";
    else {
        nb_bonus = (random() % 100);
        if (nb_bonus < 33 && nb_rand > 0)
            result = "energy";
        else if (nb_bonus < 66 && nb_rand >= 33 )
            result = "attackbonus";
        else if (nb_bonus < 99 && nb_rand >= 66)
            result = "evadebonus";
        else
            result = "scrap";
    }
    return (result);
}

void create_bonus(ship_t *ship)
{
    int i = 0;
    freight_t *frei[10];

    while (i < 10) {
        frei[i] = NULL;
        if ((frei[i] = malloc(sizeof(freight_t))) == NULL)
            return;
        else {
            frei[i]->item = my_strdup(init_bonus());
            add_freight_to_container(ship, frei[i]);
        }
        i++;
    }
}
void my_putnbr(int n)
{
    int tot = 0;
    int div = 0;
    
    if (n < -2147483647)
        my_putstr("-2147483648");
    else {
        if (n < 0) {
            my_putchar('-');
            n = -n;
        }
        div = 1;
        while ((n / div) >= 10)
            div = div * 10;
        while (div > 0) {
            tot = (n / div) % 10;
            my_putchar(tot + 48);
            div = div / 10;
        }
    }
}
