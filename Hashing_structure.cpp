#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstdbool>
#include<string>
using namespace std;


#define SIZE 20
#define endl '\n'

struct Data
{
    int lastTwoDigitOfReg;
    string name;
    double cgpa;

};


struct DataItem
{
    int key;
    struct Data *data;

};


struct DataItem* dataList[SIZE];
struct DataItem* singleItem;
struct DataItem* item;


int getHashCode(int key)
{

    return key%SIZE;
}

struct DataItem *search(int key)
{
    int hashIndex = getHashCode(key);

    while(dataList[hashIndex] !=  NULL)
    {
        if(dataList[hashIndex] ->key == key)
        {
            return dataList[hashIndex];
        }

        hashIndex++;
        hashIndex %= SIZE;

    }

    return NULL;

};


void insert(int key, string name, int lastTwoDigitOfReg, double cgpa)
{

    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    struct Data *idata = (struct Data*) malloc(sizeof(struct Data));

    item->key = key;
    idata->name = name;
    idata->lastTwoDigitOfReg  =lastTwoDigitOfReg;
    idata->cgpa = cgpa;
    item->data = idata;

    int hashIndex = getHashCode(key);

    while(dataList[hashIndex] != NULL && dataList[hashIndex]->key != -1)
    {

        hashIndex++;
        hashIndex %= SIZE;
    }

    dataList[hashIndex] = item;
}

struct DataItem *del(struct DataItem *item)
{

    int key = item->key;

    int hashIndex = getHashCode(key);

    while(dataList[hashIndex] != NULL && dataList[hashIndex]->key != -1)
    {

        if(dataList[hashIndex] ->key == key)
        {
            struct DataItem *temp= dataList[hashIndex];
            dataList[hashIndex] = singleItem;
            return temp;
        }
        hashIndex++;
        hashIndex %= SIZE;
    }
    return NULL;
};

void display()
{
    for(int i=0;i<SIZE;i++){
         if(dataList[i] != NULL)
        {
            printf(" (%d -> %s, %d, %f) ", dataList[i]->key, dataList[i]->data->name.c_str(), dataList[i]->data->lastTwoDigitOfReg, dataList[i]->data->cgpa) ;
        }
        else printf(" ~~ ") ;
    }
     printf("\n") ;
}


int main()
{
     struct DataItem *singleItem = (struct DataItem*) malloc(sizeof(struct DataItem)) ;
     singleItem->key = -1;
     singleItem->data = NULL;

    insert(11, "Arman", 21, 3.33) ;
    insert(25, "Efaz", 18, 2.52) ;
    insert(7, "Tuli", 19, 3.00) ;
    insert(26, "Naimul", 24, 3.20) ;
    insert(13, "Ikram", 11, 1.75) ;
    insert(37, "Yunus", 15, 2.10) ;
    insert(3, "Sofik", 33, 4.00) ;
    insert(82, "Zamil", 27, 2.55) ;
    insert(15, "Mehedi", 13, 2.75) ;
    insert(11, "Fakrur", 20, 3.03) ;

    display() ;

    item = search(26) ;

    item != NULL ? cout<<"Element found : "<<item->data->name<<endl : cout<<"Element not found...!"<<endl;

    del(item) ;

    item = search(26) ;

    item != NULL ? printf("Element found : %d\n", item->data->name) : printf("Element not found...!\n");

    display() ;

    return 0 ;



}
