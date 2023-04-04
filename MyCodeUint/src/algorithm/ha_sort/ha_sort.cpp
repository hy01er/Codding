/**
 * Date: 2021/12/15
 * Title: sort.cpp
 * Description: Implement some encapsulation of the sorting algorithm
 *
 */

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}