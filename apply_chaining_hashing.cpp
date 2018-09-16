#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstdbool>
using namespace std ;

#define SIZE 20
#define endl '\n'

struct DataItem
{
    int key ;
    int data ;
};

struct DataItem* dataList[SIZE][SIZE] ;
struct DataItem* singleItem ;
struct DataItem* item ;

int getHashCode(int key)
{
    return key%SIZE ;
}

struct DataItem *search(int key)
{
    int hashIndex = getHashCode(key) ;
    int i = 0 ;

    while(dataList[hashIndex][i] != NULL)
    {
        if(dataList[hashIndex][i]->key == key)
        {
            return dataList[hashIndex][i] ;
        }
        i++ ;
        i %= SIZE ;
    }
    return NULL ;
};


void insert(int key, int data)
{
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem)) ;
    item->key = key ;
    item->data = data ;

    int hashIndex = getHashCode(key) ;
    int i = 0 ;

    while(dataList[hashIndex][i] != NULL && dataList[hashIndex][i]->key != -1)
    {
        i++ ;
        i %= SIZE ;
    }

    dataList[hashIndex][i] = item ;
};


struct DataItem *del(struct DataItem *item)
{
    int key = item->key ;

    int hashIndex = getHashCode(key) ;

    int i = 0 ;

    while(dataList[hashIndex][i] != NULL && dataList[hashIndex][i]->key != -1)
    {
        if(dataList[hashIndex][i]->key == key)
        {
            struct DataItem *temp = dataList[hashIndex][i] ;
            dataList[hashIndex][i] = singleItem ;
            return temp ;
        }
        i++ ;
        i %= SIZE ;
    }
    return NULL ;
};

void display()
{
    for(int j=0;j<SIZE;j++)
    {
        for(int i=0;i<SIZE;i++)
        {
            if(dataList[j][i] != NULL)
            {
                printf(" (%d, %d) ", dataList[j][i]->key, dataList[j][i]->data) ;
            }
            else printf(" ~~ ") ;
        }
        printf("\nEND\n") ;
    }

    printf("\n") ;
}

int main()
{
    struct DataItem *singleItem = (struct DataItem*) malloc(sizeof(struct DataItem)) ;
    singleItem->key = -1 ;
    singleItem->data = -1 ;

    insert(11, 256) ;
    insert(25, 111);
    insert(7, 33);
    insert(26, 5);
    insert(13, 63);
    insert(37, 85);
    insert(3, 25);
    insert(82, 2);
    insert(15, 3);
    insert(11, 25);

    display() ;

    item = search(26) ;

    item != NULL ? printf("Element found : %d\n", item->data) : printf("Element not found...!\n");

    del(item) ;

    item = search(26) ;

    item != NULL ? printf("Element found : %d\n", item->data) : printf("Element not found...!\n");

    display() ;

    return 0 ;
}
