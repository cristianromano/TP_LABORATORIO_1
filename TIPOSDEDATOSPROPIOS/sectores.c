#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "bibloteca.h"
#include "sectores.h"

void listarSectores(eSector sectores[] , int tamsec)
{

  int i;

  printf("ID    SECTOR\n");
  for(i=0;i<tamsec;i++)
  {

      printf("%d     %s\n",sectores[i].id,sectores[i].descripcion);

  }

}

