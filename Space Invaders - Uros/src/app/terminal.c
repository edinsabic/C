//
// Created by urosjarc on 16. 12. 19.
//

#include <ncurses.h>
#include <zconf.h>
#include "terminal.h"
#include <stdlib.h>

int terminal_main() {

    World world = world_new();
    int rounds = 10;

    for (int j = 1; j <= rounds; j++) {

        int next_round = 0;

        if (j != 1){
            world_new_enemies(&world);
            ENEMY_speed -= 10;
        }

        char key;
        for (int i = 0; (key = getch()) != 'q'; i++) {

            terminal_draw_world(&world);
            terminal_draw_infos(&world, j);
            world_event(&world, key);

            if (i % ENEMY_speed == 0) {
                world_move_enemy(&world);

                if (world.enemies[0].y == world.height) {
                    break;
                }
            }
            if (i % LASER_speed == 0) {

                int hero_hit = world_move_enemy_lasers(&world);
                int enemy_alive_num = world_move_hero_laser(&world);

                if (!enemy_alive_num) {
                    terminal_draw_world(&world);
                    next_round = 1;
                    break;
                }

                if (hero_hit && !world.hero.lives) {
                    terminal_draw_infos(&world, j);
                    break;
                }

            }

            move(0, 0);
            usleep(1e4);
        }

        if (next_round) {
            if(j==rounds){
                terminal_msg(&world, "You Won!", 2);
                break;
            }
            terminal_msg(&world, "Next Round!", 2);
            continue;
        } else {
            terminal_msg(&world, "Game Over!", 2);
            break;
        }
    }

    endwin();
    return 0;
}

void terminal_init() {
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    refresh();
}

void terminal_msg(World *world, char *msg, int slp) {
    mvaddstr(world->height / 2, (int) ((world->width - (float) sizeof(msg) / sizeof(char)) / 2), msg);
    refresh();
    sleep(slp);
}

void terminal_draw_world(World *world) {

    //DRAW WORLD
    for (int h = 0; h < world->height + 1; h++) {
        for (int w = 1; w < world->width; w++)
            mvaddch(h, w, ' ');
        if (h < world->height) {
            mvaddch(h, 0, '|');
            mvaddch(h, world->width, '|');
        }
    }

    //PLACE HERO
    Hero hero = world->hero;
    for (int h = 0; h < world->height + 1; h++) mvaddch(h, hero.x, '|');
    mvaddch(hero.y, hero.x, '^');


    //PLACE HERO LASER
    if (hero.laser.is_alive) mvaddch(hero.laser.y, hero.laser.x, '^');

    //PLACE ENEMIES
    int enemy_num = world_enemy_num(world);
    for (int i = 0; i < enemy_num; i++) {
        Enemy enemy = world->enemies[i];
        Laser laser = enemy.laser;
        if (enemy.is_alive) mvaddch(enemy.y, enemy.x, 'x');
        if (laser.is_alive) mvaddch(laser.y, laser.x, '*');
    }
}

void terminal_draw_infos(World *world, int round) {
    char lives[10];
    char points[10];
    char rounds[10];
    sprintf(lives, "Lives: %i", world->hero.lives);
    sprintf(points, "Points: %i", world->hero.points);
    sprintf(rounds, "Round: %i", round);
    mvaddstr(world->height + 1, 0, lives);
    mvaddstr(world->height + 2, 0, points);
    mvaddstr(world->height + 3, 0, rounds);
    refresh();
}

