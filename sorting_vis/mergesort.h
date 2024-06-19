#ifndef MERGESORT_H
#define MERGESORT_H

#include <SDL2/SDL.h>
#include <vector>

void draw_state(std::vector<int>& v, SDL_Renderer* renderer, int n, int left, int mid, int right);
void end(std::vector<int>& v, SDL_Renderer* renderer, int n);
void MergeSort(std::vector<int>& A, int l, int r, SDL_Renderer* renderer, int n);
void Merge(std::vector<int>& A, int l, int m, int r, SDL_Renderer* renderer, int n);

#endif
