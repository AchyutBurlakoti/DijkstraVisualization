#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "dijkstra.h"

extern std::vector<grid> t_grid;

inline void swap(grid* a, grid* b)
{
    grid t = *a;
    *a = *b;
    *b = t;
}

inline int partition (int low, int high)
{
    int pivot = t_grid[high].distance_v;    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (t_grid[j].distance_v >= pivot)
        {
            i++;    // increment index of smaller element
            swap(&t_grid[i], &t_grid[j]);
        }
    }
    swap(&t_grid[i + 1], &t_grid[high]);
    return (i + 1);
}

inline void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

#endif // QUICKSORT_H
