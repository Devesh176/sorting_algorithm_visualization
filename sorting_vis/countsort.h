#ifndef COUNTSORT_H
#define COUNTSORT_H

#include <SDL2/SDL.h>
#include <vector>

void draw_state(std::vector<int>& v, SDL_Renderer* renderer, int n, std::vector<int>& count, int stage);
void end(std::vector<int>& v, SDL_Renderer* renderer, int n);
void CountSort(std::vector<int>& A, int n, SDL_Renderer* renderer);

#endif
