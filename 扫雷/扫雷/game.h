#pragma once
#define x 12
#define y 12
#define COUNT 10
extern char show_mine[x][y];
extern char real_mine[x][y];

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void init_mine();
int count_show_mine();
int sweep_mine();
void open_mine(int m, int n);
int count_mine(int m, int n);
void set_mine();
void print_mine();
void print_player();
void muen();
void safe_mine();

