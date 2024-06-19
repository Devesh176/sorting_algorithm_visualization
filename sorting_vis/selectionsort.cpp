#include "selectionsort.h"
#include <algorithm>

void SelectionSortdraw_state(std::vector<int>& v, SDL_Renderer* renderer, int n, int red, int green, int blue){
    int max_val = *max_element(v.begin(), v.end());
    float x_scale = 1000.0f / n;
    float y_scale = 1000.0f / max_val;

    for(int i = 0; i < n; ++i){
        if (i == red){
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red for the current element
        } else if (i == blue){
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Green for the minimum element
        } else if (i== green) {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Yellow for all other elements
        } else{
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        SDL_Rect rect;
        rect.x = i * x_scale;
        rect.y = 1000 - v[i] * y_scale;
        rect.w = x_scale;
        rect.h = v[i] * y_scale;
        SDL_RenderFillRect(renderer, &rect);
    }
}

void SelectionSortend(std::vector<int>& v, SDL_Renderer* renderer, int n){
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

void SelectionSort(std::vector<int>& A, int n){
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(1000, 1000, 0, &window, &renderer);

    for (int i = 0; i < n - 1; i++){
        int min_idx = i;
        for (int j = i + 1; j < n; j++){
            if (A[j] < A[min_idx]){
                min_idx = j;
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
            SDL_RenderClear(renderer);

            SelectionSortdraw_state(A, renderer, n, i, j, min_idx);  // Redraw the state
            SDL_RenderPresent(renderer);
            SDL_Delay(100);
        }
        std::swap(A[i], A[min_idx]);

        // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
        // SDL_RenderClear(renderer);

        // SelectionSortdraw_state(A, renderer, n, i, min_idx);  // Redraw the state
        // SDL_RenderPresent(renderer);
        // SDL_Delay(100);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
    SDL_RenderClear(renderer);

    SelectionSortend(A, renderer, n);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
