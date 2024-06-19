#include "mergesort.h"
#include <algorithm>

void draw_state(std::vector<int>& v, SDL_Renderer* renderer, int n, int left, int mid, int right){
    int max_val = *max_element(v.begin(), v.end());
    float x_scale = 1000.0f / n;
    float y_scale = 1000.0f / max_val;

    for(int i = 0; i < n; ++i){
        if (i >= left && i <= mid){
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red for the left half
        } else if (i > mid && i <= right){
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Green for the right half
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

void Merge(std::vector<int>& A, int l, int m, int r, SDL_Renderer* renderer, int n){
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
        SDL_RenderClear(renderer);

        draw_state(A, renderer, n, l, m, r);  // Redraw the state
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }

    while (i < n1){
        A[k] = L[i];
        i++;
        k++;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
        SDL_RenderClear(renderer);

        draw_state(A, renderer, n, l, m, r);  // Redraw the state
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }

    while (j < n2){
        A[k] = R[j];
        j++;
        k++;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear screen
        SDL_RenderClear(renderer);

        draw_state(A, renderer, n, l, m, r);  // Redraw the state
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
}

void MergeSort(std::vector<int>& A, int l, int r, SDL_Renderer* renderer, int n){
    if (l < r){
        int m = l + (r - l) / 2;

        MergeSort(A, l, m, renderer, n);
        MergeSort(A, m + 1, r, renderer, n);
        Merge(A, l, m, r, renderer, n);
    }
}
