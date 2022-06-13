// Copyright (C) 2019 <Dario Lanfranco Ruffener, Franco Anibal Rodriguez, Esteban Salvay Dilena> <dariolanfrancoruffener@gmail.com, francorod47@gmail.com, estebansaldil22@gmail.com>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.

#include <stdio.h>
#include <stdlib.h>
#include "moviehouse.h"

Lista list;
FILE* g;
int op;
Arreglo a;


//Muestra por pantalla el menu principal
void MenuPrincipal();

//Muestra un mensaje al salir del programa
void CartelSalir();


//Programa Principal
int main(){
	
	DeTxtALista(&list,g);
   // MostrarLista(list);
	ArregColor(list,&a);
/*    printf("%d\n",a.cant);
    
    op=1;    
    while(op<=a.cant){
        printf("%s\n",a.peliculas[op].titulo);
        op=op+1;
    }
    printf("%d\n",op);
*/

	do{
		MenuPrincipal();
		scanf("%d",&op);
		switch(op){
			case 1: {
				MasPopulares(a);
				break;
			};
			case 2: {
				CantPeliculas(a);
				break;
			}
			case 3: {
				MostrarCostLanz(a);
				break;
			}
			case 4: {
				MostrarGenero(a);
				break;
			}
			case 5: {
                MostVotoPromedio(a);
				break;
			}
			case 6: {
				MostRating(a);
				break;
			}
			case 7: {
                Exportar(a,g);
				break;
			}
   			case 8: {
				Listar(g);
				break;
            }
			case 9: {
				CartelSalir();
				break;
			}
			default: {
				printf("Ingrese un valor entre 1 y 9.\n");
			}	

		}
	}while(op != 9);

	

}

//Muestra por pantalla el menu principal
void MenuPrincipal(){
	printf("|-------------------|\n");
	printf("|    Movie House    |\n");
	printf("| Elige una opción: |\n");
	printf("|-------------------|\n\n");
	printf("1: Peliculas más populares\n");
	printf("2: Ver la cantidad de peliculas de cada director\n");
	printf("3: Mostrar las peliculas mas caras por epoca de lanzamiento\n");
	printf("4: Mostrar por genero\n");
	printf("5: Mostrar por voto promedio segun genero\n");
	printf("6: Mostrar por Rating\n");
	printf("7: Exportar a un archivo binario\n");
    printf("8: Listar archivo binario\n");
	printf("9: Salir\n");
}

//Muestra un mensaje al salir del programa
void CartelSalir(){
	printf("---------------------------------------|\n");
	printf("|  ¡Gracias por utilizar Movie House!  |\n");
	printf("---------------------------------------|\n");
}














