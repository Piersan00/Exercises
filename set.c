#include <stdio.h>

#define MAX_SIZE 100

void addToSet(int set[], int *size, int element)
{
    if (*size < MAX_SIZE)
    {
        // check if element is already in the set
        for (int i = 0; i < *size; i++)
        {
            if (set[i] == element)
            {
                return;
            }
        }

        set[*size] = element;
        (*size)++;
    }  
}

int searchInSet(const int set[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (set[i] == element)
        {
            return i;  
        }
    }
    return -1; 
}

// remove
void removeFromSet(int set[], int *size, int element)
{
    int index = searchInSet(set, *size, element);
    if (index != -1)
    {
        // remove then move next element
        for (int i = index; i < *size - 1; i++)
        {
            set[i] = set[i + 1];
        }
        (*size)--;
    }
}

void printSet(const int set[], int size)
{
    printf("Set: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d,", set[i]);      
    }   
}

int main()
{
    int mySet[MAX_SIZE];
    int setSize = 0;

    addToSet(mySet, &setSize, 10);
    addToSet(mySet, &setSize, 20);
    addToSet(mySet, &setSize, 30);
    addToSet(mySet, &setSize, 40);
    addToSet(mySet, &setSize, 50);
    

    printSet(mySet, setSize);
    
    // search
    int elementToSearch = 20;
    int searchResult = searchInSet(mySet, setSize, elementToSearch);
    if (searchResult != -1)
    {
        printf("%d is at index %d.\n", elementToSearch, searchResult);
    }
    else
    {
        printf("%d isn't in the set.\n", elementToSearch);
    }

    // remove
    int elementToRemove = 30;
    removeFromSet(mySet, &setSize, elementToRemove);
    printSet(mySet, setSize);

    return 0;
}
