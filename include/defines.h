/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** all defines
*/

#ifndef DEFINES_H_
    #define DEFINES_H_

    static const int WIDTH = 1280;
    static const int HEIGHT = 720;
    static const int BITS_PIXELS = 32;
    static const int NB_SCENE = 13;
    static const char PATH_SCENE[] = "assets/configuration/all_path.txt";
    static const char PATH_BUTTON[] = "assets/button/all_path.txt";
    static const char ENEMY_STAT[] = "assets/enemies/enemy_stats.txt";
    #define GAME_WINDOW game[0]->sf_obj->window
    #define GAME_EVENT game[0]->sf_obj->event
    #define GAME_SCENE game[0]->scene[game[0]->scene_nb]
    #define GAME_PLAYER game[0]->player
    #define GAME_TIME game[0]->time
    #define GAME_MUSIC game[0]->music
    #define GAME_BOSS game[0]->scene[game[0]->scene_nb]->boss
    static const int PLAYER_HP = 200;
    static const int PLAYER_DMG = 100;
    static const int SPEED = 6;
    static const int ENEMY_SPAWN = 650;
    static const sfVector2f ZOOM = {2, 2};
    static const int VOLUME_ON = 30;
    static const int VOLUME_OFF = 0;
    static const int SIZE_SIDE = 48;
    static const char OBS = 'X'; // obstacle
    static const char COF = 'T'; // treasure (coffre)
    static const char VID = '.'; // empty
    static const char DON = 'D'; // donjon
    static const char SOR = 'S'; // sortie
    static const char FOR = 'F'; // forest
    static const char WAT = 'E'; // water
    static const char HOU = 'H'; // house
    static const char FLO = 'J'; // floor
    static const char MIN = 'M'; // mine
    static const char VIL = 'V'; // village
    static const char BOA = 'B'; // boat
    static const char STO = 'C'; // stone
    static const char PNJ_1 = '1'; // pnj 1
    static const char PNJ_2 = '2'; // pnj 2
    static const char PNJ_3 = '3'; // pnj 3
    static const char BOSS = '4'; // boss
    static const int CAN_MOVE = 0;
    static const int CANT_MOVE = 1;
    static const int AN_ERROR = 84;
    static const int A_SUCCESS = 0;
    static const int A_FAILED = 1;
    static const int RIGHT = 5;
    static const int LEFT = 3;
    static const int TOP = 4;
    static const int RUN = 2;
    static const int CONTRE = 4;
    static const int WIN = 1;
    static const int LOSE = 3;

#endif