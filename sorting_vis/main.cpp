#include <SDL2/SDL.h>
#include <iostream>
#include <random>
#include <vector>
// #include "bubblesort.h"
// #include "insertionsort.h"
#include "selectionsort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "countsort.h"



using namespace std;

template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++){
        cout << vec[i] << flush;
        if (i < n - 1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int main(){
    random_device rd;
    vector<int> v;
    cout << "Enter the dimension of the list: ";
    int n = 0;
    cin >> n;
    cout << "Write the elements one by one:" << endl;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    // SDL_Window* window = nullptr;
    // SDL_Renderer* renderer = nullptr;
    // SDL_CreateWindowAndRenderer(1000, 1000, 0, &window, &renderer);

    // QuickSort(v, 0, n - 1, renderer, n);
    // Print(v, n, "Sorted v");

    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();


    // SDL_Window* window = nullptr;
    // SDL_Renderer* renderer = nullptr;
    // SDL_CreateWindowAndRenderer(1000, 1000, 0, &window, &renderer);

    // MergeSort(v, 0, n - 1, renderer, n);

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(1000, 1000, 0, &window, &renderer);

    CountSort(v, n, renderer);

    Print(v, n, "Sorted v");

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    

    return 0;
    

}
