#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <SDL2/SDL.h>
#include <vector>

void SelectionSortdraw_state(std::vector<int>& v, SDL_Renderer* renderer, int n, int red, int blue);
void SelectionSortend(std::vector<int>& v, SDL_Renderer* renderer, int n);
void SelectionSort(std::vector<int>& A, int n);

#endif
