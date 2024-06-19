#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <SDL2/SDL.h>
#include <vector>

void draw_state(std::vector<int>& v, SDL_Renderer* renderer, int n, int pivot, int left, int right);
void end(std::vector<int>& v, SDL_Renderer* renderer, int n);
void QuickSort(std::vector<int>& A, int low, int high, SDL_Renderer* renderer, int n);
int Partition(std::vector<int>& A, int low, int high, SDL_Renderer* renderer, int n);

#endif
