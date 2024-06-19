#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <SDL2/SDL.h>
#include <vector>

// Function declarations
void BubbleSortdraw_state(std::vector<int>& v, SDL_Renderer* renderer, int n, int red, int blue);
void BubbleSortend(std::vector<int>& v, SDL_Renderer* renderer, int n);
void BubbleSort(std::vector<int>& A, int n);

#endif
