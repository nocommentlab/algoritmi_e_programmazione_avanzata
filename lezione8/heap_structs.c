#include <stdio.h>
#include <stdlib.h>
#include "TYPEDef.h"

void initList(struct Person **pPersonList);
void addPerson(struct Person **pPersonList, struct Person *pPerson);

struct Person *_pPersonList;
struct Person *_pPerson;

UINT32_T UINT32_NPerson;

void initList(struct Person **pPersonList)
{
   (*pPersonList) = NULL;
}

void requestNewPerson(struct Person **pPerson)
{

    *pPerson =  malloc(sizeof(struct Person));

    printf("Inserisci il nome:");
    scanf("%s", (*pPerson)->vCHAR_Name);
    printf("Inserisci eta:");
    scanf("%u", &((*pPerson)->UINT32_Age));

    (*pPerson)->pNextElement = NULL;
    
    
}

void addPerson(struct Person **pPersonList, struct Person *pPerson)
{
    struct Person *pTempPerson;

    if(*pPersonList == NULL)
    {
        printf("Entrato");
        *pPersonList = pPerson;
    }
    else
    {
        pTempPerson = *pPersonList;
        while(pTempPerson->pNextElement != NULL)
        {
            pTempPerson = pTempPerson->pNextElement;
        }

        pTempPerson->pNextElement = pPerson;

    }
} 

int main()
{
    initList(&_pPersonList);
    requestNewPerson(&_pPerson);
    addPerson(&_pPersonList, _pPerson);
    
    requestNewPerson(&_pPerson);
    addPerson(&_pPersonList, _pPerson);
    
    
    return 0;
}
