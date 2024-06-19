#include "insertionsort.h"
#include <algorithm>

void draw_state(std::vector<int>& v, SDL_Renderer* renderer, int n, int red, int blue){
    int max_val = *max_element(v.begin(), v.end());
    float x_scale = 1000.0f / n;
    float y_scale = 1000.0f / max_val;

    for(int i = 0; i < n; ++i){
        if (i == red){
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red for the current element
        } else if (i == blue){
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Green for the comparison element
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

void InsertionSort(std::vector<int>& A, int n){
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(1000, 1000, 0, &window, &renderer);

    for (int i = 1; i < n; i++){
        int x = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > x){
            A[j + 1] = A[j];

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
            SDL_RenderClear(renderer);

            draw_state(A, renderer, n, j + 1, i);  // Redraw the state
            SDL_RenderPresent(renderer);
            SDL_Delay(100);

            j--;
        }
        A[j + 1] = x;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
        SDL_RenderClear(renderer);

        draw_state(A, renderer, n, j + 1, i);  // Redraw the state
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
    SDL_RenderClear(renderer);

    end(A, renderer, n);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
