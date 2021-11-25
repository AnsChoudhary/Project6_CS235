#include <iostream>
#include <ctime>

#include "PriorityQueue.hpp"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    PriorityQueue<int> pq;

    int numbers[10] = { 66, 1, 69, 2, 85, 100, 3, 63, 14, 32 };

    for (size_t i = 0; i < 10; i++)
    {
        int priority = rand() % 5 + 1;

        pq.enqueue(numbers[i],priority);

    }
    pq.print();
    cout<<endl;

  //PriorityQueue<int>pq2(pq);
  //pq2.print();


    return 0;
}