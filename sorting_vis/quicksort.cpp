#include "quicksort.h"
#include <algorithm>

void draw_state(std::vector<int>& v, SDL_Renderer* renderer, int n, int pivot, int left, int right){
    int max_val = *max_element(v.begin(), v.end());
    float x_scale = 1000.0f / n;
    float y_scale = 1000.0f / max_val;

    for(int i = 0; i < n; ++i){
        if (i == pivot){
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red for the pivot element
        } else if (i == left){
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Green for the left element
        } else if (i == right){
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Blue for the right element
        } else {
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);  // Yellow for all other elements
        }

        SDL_Rect rect;
        rect.x = i * x_scale;
        rect.y = 1000 - v[i] * y_scale;
        rect.w = x_scale;
        rect.h = v[i] * y_scale;
        SDL_RenderFillRect(renderer, &rect);
    }
}

void end(std::vector<int>& v, SDL_Renderer* renderer, int n){
    int max_val = *max_element(v.begin(), v.end());
    float x_scale = 1000.0f / n;
    float y_scale = 1000.0f / max_val;

    for (int i = 0; i < n; ++i){
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

        SDL_Rect rect;
        rect.x = i * x_scale;
        rect.y = 1000 - v[i] * y_scale;
        rect.w = x_scale;
        rect.h = v[i] * y_scale;
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
}

int Partition(std::vector<int>& A, int low, int high, SDL_Renderer* renderer, int n){
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (A[j] < pivot){
            i++;
            std::swap(A[i], A[j]);

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
            SDL_RenderClear(renderer);

            draw_state(A, renderer, n, high, i, j);  // Redraw the state
            SDL_RenderPresent(renderer);
            SDL_Delay(100);
        }
    }
    std::swap(A[i + 1], A[high]);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
    SDL_RenderClear(renderer);

    draw_state(A, renderer, n, high, i + 1, high);  // Redraw the state
    SDL_RenderPresent(renderer);
    SDL_Delay(100);

    return i + 1;
}

void QuickSort(std::vector<int>& A, int low, int high, SDL_Renderer* renderer, int n){
    if (low < high){
        int pi = Partition(A, low, high, renderer, n);

        QuickSort(A, low, pi - 1, renderer, n);
        QuickSort(A, pi + 1, high, renderer, n);
    }
}
