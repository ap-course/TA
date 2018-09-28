#include <iostream>
#include <limits>

const int MAX_NUM = 100 + 7;

void getMarkers(int *markers_num, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        markers_num[x]++;
    }
}

int findMin(int *markers_num, int n)
{
    int min_num = std::numeric_limits<int>::max();
    int min_index = 0;
    for (int i = 0; i < MAX_NUM; i++)
    {
        if (markers_num[i] != 0 and markers_num[i] < min_num)
        {
            min_num = markers_num[i];
            min_index = i;
        }
    }
    return min_index;
}

int main()
{
    int markers_num[MAX_NUM] = {0};
    int n;
    std::cin >> n;
    getMarkers(markers_num, n);

    std::cout << findMin(markers_num, n) << std::endl;
    return 0;
}

