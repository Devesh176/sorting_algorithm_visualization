#include "bubblesort.h"
#include <algorithm>

void BubbleSortdraw_state(std::vector<int>& v, SDL_Renderer* renderer, int n, int red, int blue){
    int max_val = *max_element(v.begin(), v.end());
    float x_scale = 1000.0f / n;
    float y_scale = 1000.0f / max_val;

    for(int i = 0; i < n; ++i){
        if (i == red){
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        } else if (i == blue){
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        } else {
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

void BubbleSortend(std::vector<int>& v, SDL_Renderer* renderer, int n){
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
        SDL_Delay(1000);
    }
}

void BubbleSort(std::vector<int>& A, int n){
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(1000, 1000, 0, &window, &renderer);

    for (int i = 0; i < n - 1; i++){
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++){
            if (A[j] > A[j + 1]){
                std::swap(A[j], A[j + 1]);
                swapped = true;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);

                BubbleSortdraw_state(A, renderer, n, j, j + 1);
                SDL_RenderPresent(renderer);
                SDL_Delay(1000);
            }
        }
        if (!swapped){
            break;
        }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    BubbleSortend(A, renderer, n);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
