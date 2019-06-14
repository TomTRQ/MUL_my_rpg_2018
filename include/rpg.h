/*
** EPITECH PROJECT, 2019
** prototypes file for the project
** File description:
** my_rpg
*/

#ifndef RPG_H_
    #define RPG_H_

    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Vector3.h>
    #include "struct.h"
    #include "my.h"
    #include "defines.h"
    #include "inventory.h"

    // PROTOTYPES OF SRC FUNCTIONS


    // Music
    int initiate_music_struct(game_t **game);
    void setting_volume_music(game_t **game, int sound);
    void destroy_music(game_t **game);
    void handle_music(game_t **game, sfMusic *music);
    void choose_music_fight(game_t **game, enemy_t *enemy);
    void close_music_fight(game_t **game, enemy_t *enemy, sfMusic *playing);
    sfMusic *get_playing_music(game_t **game);
    void play_sound(sfSoundBuffer *buffer);

    // Pnj
    int initiate_pnj(game_t **game);
    int setup_text_from_file(char *path, pnj_t *pnj);
    int get_text_to_display(game_t **game, pnj_t *pnj);
    void display_pnj(pnj_t *pnj, game_t **game);
    int initiate_pnj_struct(game_t **game);
    void print_character_information(pnj_t *pnj, game_t **game);
    void initiate_pnj_faces(pnj_t *pnj);
    void set_text(sfText *text, sfFont *font, sfVector2f vector, game_t **game);

    // State
    int initiate_state(game_t **game);
    int initiate_all_button(game_t **game);
    int initiate_all_scene(game_t **game);
    int initiate_sf_object(game_t **game);
    int setup_name(game_t **game, char **av);
    int load_map(char *path, scene_t **scene);

    // Clock
    void time_clock(my_clock_t *);
    my_clock_t *initiate_time_struct(void);

    // Player
    player_t *initiate_player(void);
    int handle_player_movements(game_t **);
    int ask_name(char **name);
    int go_out(game_t **game);
    int go_donjon(game_t **game);
    int setup_position_to_check(scene_t *scene, sfVector2i move, game_t **game);
    int move_to_boss(game_t **game, sfVector2i move);

    // Enemy
    int initiate_enemy(game_t **game);
    int initiate_enemies_on_scene(game_t **game);
    pnj_t *get_pnj(game_t **game, char c);

    // Display
    int display(game_t **game);
    int change_scene(game_t **game, char *new_scene);
    void modify_cursor(game_t **game);
    int draw_night(game_t **game);
    void draw_walk_effect(game_t **game, int nb);
    int is_map(scene_t *scene);
    int is_out_map(scene_t *scene);
    int is_fight_scene(scene_t *scene);
    void destroy_free_all(game_t **game);

    // Dialog
    void print_dialog_background(game_t **game, char *file, int nb);
    void print_text_line(game_t **game, char *first_text, char *item, char
        *second_text);
    int check_if_activate_dialogs(game_t **game, sfSound *sound,
        sfSoundBuffer *buffer);

    // Button
    int check_button(game_t **game);
    int change_volume(game_t **game);
    int start_game(game_t **game);
    int exit_game(game_t **game);
    int pause_game(game_t **game);
    int menu_game(game_t **game);

    // Boat
    void draw_boat(game_t **game);
    int verif_boat(game_t **game);
    int active_boat(game_t **game);
    int open_treasure(game_t **game);

    // movement camera
    void player_movement_left(game_t **game);
    void player_movement_right(game_t **game);
    void player_movement_up(game_t **game);
    void player_movement_down(game_t **game);

    // display
    int display_scene(scene_t *scene, sfRenderWindow *window);
    int display_button(button_t *button, sfRenderWindow *window);

    //fight
    void anim_player_atk(game_t **game, enemy_t *enemy);
    void anim_player_def(game_t **game, enemy_t *enemy);
    void anim_enemy_atk(game_t **game, enemy_t *enemy);
    int enemy_turn(game_t **game, enemy_t *enemy, player_t *player, int def);
    int player_turn(game_t **game, enemy_t *enemy);
    player_t *init_player_fight(player_t *player);
    enemy_t *init_enemy_fight(enemy_t *enemy);
    int launch_fight(game_t **game, enemy_t *enemy);
    void win_fight(game_t **game, enemy_t *enemy);
    void lose_fight(game_t **game);
    void leave_fight(game_t **game);
    void display_fight(player_t *player, enemy_t *enemy, scene_t *scene,
        game_t **game);
    int check_start_fight(game_t **game);
    void fight_lifebar(sfRenderWindow *window, sfVector2f vector,
        int max_hp, int hp);
    int print_damage(game_t **game, sfVector2f pos, int dmg);

#endif
