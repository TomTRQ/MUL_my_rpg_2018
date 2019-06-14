/*
** EPITECH PROJECT, 2019
** function that initiates the clock struct
** File description:
** my_rpg
*/

#include <stdlib.h>
#include "rpg.h"

my_clock_t *initiate_time_struct(void)
{
    my_clock_t *time = malloc(sizeof(my_clock_t));

    if (time == NULL)
        return (NULL);
    time->clock = sfClock_create();
    if (time->clock == NULL)
        return (NULL);
    time->seconds = 0;
    time->milli = 0;
    return (time);
}

void time_clock(my_clock_t *time)
{
    time->elapsed = sfClock_getElapsedTime(time->clock);
    if ((time->elapsed.microseconds / 2000) > time->milli)
        time->milli = time->milli + 1;
    if (time->elapsed.microseconds / 1000000 > 1) {
        time->seconds = time->seconds + 1;
        time->milli = 0;
        sfClock_restart(time->clock);
    }
}