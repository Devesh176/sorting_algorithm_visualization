#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <SDL2/SDL.h>
#include <vector>

// Function declarations
void draw_state(std::vector<int>& v, SDL_Renderer* renderer, int n, int red, int blue);
void end(std::vector<int>& v, SDL_Renderer* renderer, int n);
void InsertionSort(std::vector<int>& A, int n);

#endif