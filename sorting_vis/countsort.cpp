#include "countsort.h"
#include <algorithm>

void draw_state(std::vector<int>& v, SDL_Renderer* renderer, int n, std::vector<int>& count, int stage){
    int max_val = *max_element(v.begin(), v.end());
    int count_max = *max_element(count.begin(), count.end());
    float x_scale = 1000.0f / n;
    float y_scale = 1000.0f / max_val;
    float count_y_scale = 1000.0f / count_max;

    for(int i = 0; i < n; ++i){
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);  // Yellow for array elements

        SDL_Rect rect;
        rect.x = i * x_scale;
        rect.y = 1000 - v[i] * y_scale;
        rect.w = x_scale;
        rect.h = v[i] * y_scale;
        SDL_RenderFillRect(renderer, &rect);
    }

    for(int i = 0; i < count.size(); ++i){
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);  // Cyan for count array

        SDL_Rect rect;
        rect.x = i * (1000.0f / count.size());
        rect.y = 1000 - count[i] * count_y_scale;
        rect.w = (1000.0f / count.size());
        rect.h = count[i] * count_y_scale;
        SDL_RenderFillRect(renderer, &rect);
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(stage == 0 ? 1000 : 500);  // Delay to visualize different stages
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

void CountSort(std::vector<int>& A, int n, SDL_Renderer* renderer){
    int max_val = *max_element(A.begin(), A.end());
    std::vector<int> count(max_val + 1, 0);
    std::vector<int> output(n);

    // Count array
    for(int i = 0; i < n; ++i){
        count[A[i]]++;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
        SDL_RenderClear(renderer);
        draw_state(A, renderer, n, count, 0);  // Draw count array update
    }

    // Cumulative count
    for(int i = 1; i <= max_val; ++i){
        count[i] += count[i - 1];
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
        SDL_RenderClear(renderer);
        draw_state(A, renderer, n, count, 1);  // Draw cumulative count update
    }

    // Build the output array
    for(int i = n - 1; i >= 0; --i){
        output[count[A[i]] - 1] = A[i];
        count[A[i]]--;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
        SDL_RenderClear(renderer);
        draw_state(output, renderer, n, count, 2);  // Draw output array construction
    }

    // Copy the output array to A
    for(int i = 0; i < n; ++i){
        A[i] = output[i];
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
    SDL_RenderClear(renderer);
    end(A, renderer, n);  // Draw final sorted array
}
