// Copyright (C) 2019 <Dario Lanfranco Ruffener, Franco Anibal Rodriguez, Esteban Salvay Dilena> <dariolanfrancoruffener@gmail.com, francorod47@gmail.com, estebansaldil22@gmail.com>
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published bythe Free Software
// Foundation, either version 3 of the License, or at your option) any later version.
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see LICENSE.txt or <http://www.gnu.org/licenses/>.




#include "moviehouse.h"

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define N 80

/**
	Operaciones sobre lista
**/

//MANIPULACION DE TIPO ENUMERADO
const char* TIPO_GENERO[]={

	"Action\n","Comedy\n","Adventure\n","Drama\n","Horror\n","Sci-Fi\n","Fantasy\n","Animation\n"
};

const char* TIPO_COLOR[]={

	"Color\n","BW\n"
};

//Transforma el texto copiado del archivo a TGenero
void AsigGenero(char cadena[N],Movie *peli){

		if (strcmp(TIPO_GENERO[Action],cadena)==0){
			peli->genero=0;
		}
		else{
			if(strcmp(TIPO_GENERO[Comedy],cadena)==0){
				peli->genero=1;			
			}
			else{
				if(strcmp(TIPO_GENERO[Adventure],cadena)==0){
					peli->genero=2;
				}
				else{
					if(strcmp(TIPO_GENERO[Drama],cadena)==0){
						peli->genero=3;
					}
					else{
						if(strcmp(TIPO_GENERO[Horror],cadena)==0){
							peli->genero=4;
						}
						else{
							if(strcmp(TIPO_GENERO[SciFi],cadena)==0){
								peli->genero=5;
							}
							else{
								if(strcmp(TIPO_GENERO[Fantasy],cadena)==0){
									peli->genero=6;
								}
								else{
									peli->genero=7;
								}
							}
						}							
					}								
				}
			}
		}

}

//Transforma el texto copiado del archivo a TColor
void AsigColor(char cadena[N],Movie *peli){

		if(strcmp(TIPO_COLOR[Color],cadena)==0){
			peli->color=0;
		}		
		else{
			peli->color=1;
		}

}


//CREACION DE NODOS
struct Nodo * CrearNodo(FILE* f){
	struct Nodo *nuevo;
	
	char id2[N],genero2[N],likes2[N],cantV[N],votP[N],lanz[N],costo2[N],color2[N];

	nuevo = (struct Nodo *) malloc (sizeof(struct Nodo));
	
	if (nuevo==NULL){
	 	exit(EXIT_FAILURE); 
	}
	else {
		
 			
			fgets(id2,N,f);fflush(stdout);
				nuevo->pelicula.id=atoi(id2);
			fgets(nuevo->pelicula.titulo,N,f);fflush(stdout);
			fgets(nuevo->pelicula.director,N,f);fflush(stdout);	
			fgets(genero2,N,f);fflush(stdout);
				AsigGenero(genero2,&nuevo->pelicula);
			fgets(likes2,N,f);fflush(stdout);
				nuevo->pelicula.likes=atoi(likes2);
			fgets(cantV,N,f);fflush(stdout);
				nuevo->pelicula.cant_votantes=atoi(cantV);
			fgets(votP,N,f);fflush(stdout);
				nuevo->pelicula.voto_promedio=atof(votP);
			fgets(lanz,N,f);fflush(stdout);
				nuevo->pelicula.lanzamiento=atoi(lanz);
			fgets(costo2,N,f);fflush(stdout);
				nuevo->pelicula.costo=atof(costo2);
			fgets(color2,N,f);fflush(stdout);
				AsigColor(color2,&nuevo->pelicula);

			nuevo->next=NULL;

				
		return nuevo;
	}
}


//Inicializa la lista
void Inicializar(Lista *l){
	struct Nodo *puntQ;

		
		if(l->head!=NULL){
			while(l->head!=NULL){
				puntQ=l->head;
				l->head=puntQ->next;
				free(puntQ);
			}		
		}else{
	
			(l->head)=NULL;
	
		}		
}

//Inserta un nodo al comienzo de la lista
void Insertar(Lista *l,FILE* h){
	struct Nodo *puntQ;
		
		puntQ = CrearNodo(h);
		puntQ->next = l->head;
		l->head = puntQ;
}

//Muestra toda la lista
void MostrarLista(Lista l){
	struct Nodo *puntQ;
    int i;
	
		puntQ=l.head;
	
		if(puntQ!=NULL){
            i=0;		
        	while(puntQ!=NULL){
			//	printf("%d\n",puntQ-> pelicula.id);
				printf("%s\n",puntQ-> pelicula.titulo);
			/*	printf("%s\n",puntQ-> pelicula.director);
				printf("%d\n",puntQ-> pelicula.genero);
				printf("%d\n",puntQ-> pelicula.likes);
				printf("%d\n",puntQ-> pelicula.cant_votantes);
				printf("%f\n",puntQ-> pelicula.voto_promedio);
				printf("%d\n",puntQ-> pelicula.lanzamiento);
				printf("%f\n",puntQ-> pelicula.costo);
				printf("%d\n",puntQ-> pelicula.color);
				printf("---------------------------\n");
              */  i=i+1;			
    
				puntQ=puntQ->next;
			}
		}
		else{
			printf("La lista esta vacia\n");
		}

        printf("%d\n",i);
}


// CARGA LISTA A ARREGLO
void ArregColor(Lista l, Arreglo *pelisC){           //CANT ademas queda como marca virtual final?????......
	int i;
    struct Nodo *p;
	
    p=l.head;
	i=0;
	while (p != NULL){
		if (p->pelicula.color == 0){                                  
			i=i+1;

			pelisC->peliculas[i].id = p->pelicula.id;fflush(stdout);
			strcpy(pelisC->peliculas[i].titulo,p->pelicula.titulo);fflush(stdout);
			strcpy(pelisC->peliculas[i].director,p->pelicula.director);fflush(stdout);
			pelisC->peliculas[i].genero = p->pelicula.genero;fflush(stdout);
			pelisC->peliculas[i].likes = p->pelicula.likes;fflush(stdout);
			pelisC->peliculas[i].cant_votantes = p->pelicula.cant_votantes;fflush(stdout);
			pelisC->peliculas[i].voto_promedio = p->pelicula.voto_promedio;fflush(stdout);
			pelisC->peliculas[i].lanzamiento = p->pelicula.lanzamiento;fflush(stdout);
			pelisC->peliculas[i].costo = p->pelicula.costo;fflush(stdout);
			pelisC->peliculas[i].color = p->pelicula.color;fflush(stdout);

			p=p->next;
		}else{
			p=p->next;
		}
	}
	pelisC->cant=i;fflush(stdout);
}


/*
	Acciones auxiliares
*/

//Ordena el ARREGLO segun la cantidad de Likes
void OrdenarPop(Arreglo *arre){
	Movie aux;
	int i,j,h;

	h=arre->cant-10;
	j=arre->cant;                           
	while(h<j){
		i=1;
		while(i<j){
			if(arre->peliculas[i].likes>arre->peliculas[i+1].likes){
					aux=arre->peliculas[i];
					arre->peliculas[i]=arre->peliculas[i+1];
					arre->peliculas[i+1]=aux;			
			}
			i=i+1;
		}
		j=j-1;
	}

}

//Ordenamiento segun director
void OrdDirec(Arreglo *arre){
	Movie aux;
	int i,j;

	j=arre->cant;                            
	while(1<j){
		i=1;
		while(i<j){
			if(strcmp(arre->peliculas[i].director,arre->peliculas[i+1].director)>0){
				aux=arre->peliculas[i];
				arre->peliculas[i]=arre->peliculas[i+1];
				arre->peliculas[i+1]=aux;			
			}
			i=i+1;
		}
	j=j-1;
	}
}

//Ordenamiento por lanzamiento
void OrdLanz(Arreglo *arre){
	Movie aux;
	int i,j;

	j=arre->cant;                            
	while(1<j){
		i=1;
		while(i<j){
			if(arre->peliculas[i].lanzamiento > arre->peliculas[i+1].lanzamiento ){
				aux=arre->peliculas[i];
				arre->peliculas[i]=arre->peliculas[i+1];
				arre->peliculas[i+1]=aux;			
			}
			i=i+1;
		}
	j=j-1;
	}
	
}
		
//Ordenamiento por costo
void OrdCost(Arreglo *arre){
	Movie aux;
	int i,j;

	j=arre->cant;                            
	while(1<j){
		i=1;
		while(i<j){
			if(arre->peliculas[i].costo > arre->peliculas[i+1].costo){
				aux=arre->peliculas[i];
				arre->peliculas[i]=arre->peliculas[i+1];
				arre->peliculas[i+1]=aux;			
			}
			i=i+1;
		}
	j=j-1;
	}
}


//Ordenamiento por genero
void OrdGen(Arreglo *arre){
	Movie aux;
	int i,j;

	j=arre->cant;                            
	while(1<j){
		i=1;
		while(i<j){
			if(arre->peliculas[i].genero > arre->peliculas[i+1].genero){
				aux=arre->peliculas[i];
				arre->peliculas[i]=arre->peliculas[i+1];
				arre->peliculas[i+1]=aux;			
			}
			i=i+1;
		}
	j=j-1;
	}

}

// Accion recursiva para mostrar titulos del genero dado
void GeneroRecursivo(Arreglo pelisC, int gen2, int i){
 
 	if(pelisC.peliculas[i].genero != gen2){ 
		
	}else{
		printf("\n");
		printf("%s\n", pelisC.peliculas[i].titulo);
		GeneroRecursivo(pelisC,gen2,i+1);
	}
}

//Ordena el arreglo segun el rating
void OrdRating(Arreglo *arre){
	Movie aux;
	int i,j;
	float c;
	//Calculo del voto promedio sobre el total del catalogo
	i=1;
	c=0;
	while(i<=arre->cant){
		c=c+arre->peliculas[i].voto_promedio;
		i=i+1;
	}
	c=c/arre->cant;
	
	
	//Asignar rating a cada elemento
	i=1;
	while(i<=arre->cant){
		arre->peliculas[i].rating=((arre->peliculas[i].voto_promedio*arre->peliculas[i].cant_votantes)+(c*25000))/(arre->peliculas[i].cant_votantes+25000);
		i=i+1;
	}
	
	//Ordenamiento al fin!
	j=arre->cant;                            
	while(1<j){
		i=1;
		while(i<j){
			if(arre->peliculas[i].rating > arre->peliculas[i+1].rating){
				aux=arre->peliculas[i];
				arre->peliculas[i]=arre->peliculas[i+1];
				arre->peliculas[i+1]=aux;			
			}
			i=i+1;
		}
	j=j-1;
	}
}

//Accion que ordena por voto_promedio
void OrdVoto(Arreglo *arre){
	Movie aux;
	int i,j;

	j=arre->cant;                            
	while(1<j){
		i=1;
		while(i<j){
			if(arre->peliculas[i].voto_promedio > arre->peliculas[i+1].voto_promedio){
				aux=arre->peliculas[i];
				arre->peliculas[i]=arre->peliculas[i+1];
				arre->peliculas[i+1]=aux;			
			}
			i=i+1;
		}
	j=j-1;
	}
}


/**
	Funcionalidades del proyecto
**/

//Dado un archivo de texto con la información de las peliculas, 
//guarda en la lista todas las pelicuas usando el registro Movie
void DeTxtALista(Lista *l, FILE *h){

	h=fopen("peliculas.txt","r");	

	while(!feof(h)){
		Insertar(l,h);
	}

	fclose(h);
}

//Acción que calcula y muestra cuales son las peliculas mas populares
void MasPopulares(Arreglo a){
	
	int i;

	OrdenarPop(&a);
	i=a.cant-10;
	while(i<a.cant){
		printf("%s\n",a.peliculas[a.cant].titulo);
		printf("--------------------------\n");
		a.cant=a.cant-1;
	}

}

//accion que muestra al director y su cantidad de peliculas
void CantPeliculas(Arreglo pelisC){
	int i;
	int num;
	
	OrdDirec(&pelisC);
	i = 1;
	num = 1;
	while (i < pelisC.cant){
		if(strcmp(pelisC.peliculas[i].director,pelisC.peliculas[i+1].director)==0){
		num = num + 1;
		}else{
			printf("El director %s dirigió: %d peliculas\n", pelisC.peliculas[i].director, num);
			printf("....................................\n");
			num = 1;
		}
		i = i + 1;
	}
	printf("El director %s dirigió: %d peliculas\n", pelisC.peliculas[i].director, num);
	printf("....................................\n");

}

//Muestra las m peliculas mas costosas de cada lanzamiento
void MostrarCostLanz(Arreglo pelisC){
	int m,i,j;

	OrdLanz(&pelisC);
	OrdCost(&pelisC);
	OrdLanz(&pelisC);
	
	printf("Ingrese la cantidad de peliculas que desea consultar por lanzamiento:\n");
	scanf("%d",&m);

	i=pelisC.cant;
	while(1<i){
		j=1;
		printf("Lanzamiento: %d\n",pelisC.peliculas[i].lanzamiento);
		printf("\n");
		while((j<=m)&&(pelisC.peliculas[i].lanzamiento==pelisC.peliculas[i-1].lanzamiento)){
			printf("%s\n",pelisC.peliculas[i].titulo);
			i=i-1;
			j=j+1;
		}
	

		if(j>m){
			while(pelisC.peliculas[i].lanzamiento==pelisC.peliculas[i-1].lanzamiento){
					i=i-1;		
			}
			i = i-1;
		}else{
			if(pelisC.peliculas[i].lanzamiento!=pelisC.peliculas[i-1].lanzamiento){
				printf("%s\n",pelisC.peliculas[i].titulo);
				i = i - 1;
			}
		}		
	}

	if(pelisC.peliculas[1].lanzamiento==pelisC.peliculas[2].lanzamiento){
		if(j<=m){
			printf("%s\n",pelisC.peliculas[1].titulo);
		}
	}else{
		printf("Lanzamiento:%d\n",pelisC.peliculas[1].lanzamiento);
		printf("%s\n",pelisC.peliculas[1].titulo);
	}
}

//Accion que muestra todas las peliculas dependiendo el genero
void MostrarGenero(Arreglo pelisC){
	int gen;
	int i;
	
	OrdGen(&pelisC);	
	printf("Ingrese el genero deseado\n");fflush(stdout);
	printf("Generos:\n0)Action\n1)Comedy\n2)Adventure\n3)Drama\n4)Horror\n5)Sci-Fi\n6)Fantasy\n7)Animation\n");fflush(stdout);
	scanf("%d",&gen);fflush(stdout);
	
	
	while(!((gen==0)||(gen==1)||(gen==2)||(gen==3)||(gen==4)||(gen==5)||(gen==6)||(gen==7))){
		
		printf("Ingrese el genero deseado\n");fflush(stdout);
		printf("Generos:\n0)Action\n1)Comedy\n2)Adventure\n3)Drama\n4)Horror\n5)Sci-Fi\n6)Fantasy\n7)Animation\n");fflush(stdout);
		scanf("%d",&gen);fflush(stdout);		
					
	}
	i = 1;
	while ((i <= pelisC.cant) && (gen != pelisC.peliculas[i].genero)){
		i = i + 1;
	}
	GeneroRecursivo(pelisC,gen,i);
}

//Accion que muestra las 10 peliculas con mejor voto promedio dependiendo del genero ingresado por el usuario
void MostVotoPromedio(Arreglo pelisC){
        
    int gen;
	int i,j;        

        OrdGen(&pelisC);
        OrdVoto(&pelisC);
        OrdGen(&pelisC);
   
	
	    printf("Ingrese el genero deseado\n");fflush(stdout);
	    printf("Generos:\n0)Action\n1)Comedy\n2)Adventure\n3)Drama\n4)Horror\n5)Sci-Fi\n6)Fantasy\n7)Animation\n");fflush(stdout);
	    scanf("%d",&gen);fflush(stdout);
	
	
	    while(!((gen==0)||(gen==1)||(gen==2)||(gen==3)||(gen==4)||(gen==5)||(gen==6)||(gen==7))){
		
		    printf("Ingrese el genero deseado\n");fflush(stdout);
		    printf("Generos:\n0)Action\n1)Comedy\n2)Adventure\n3)Drama\n4)Horror\n5)Sci-Fi\n6)Fantasy\n7)Animation\n");fflush(stdout);
		    scanf("%d",&gen);fflush(stdout);		
					
    	}

    	i = pelisC.cant;

    	while ((1 <= i) && (gen != pelisC.peliculas[i].genero)){

		    i = i - 1;
	    }
     
       j=1;           
       while((1<i)&&(j <= 10) && (pelisC.peliculas[i].genero==pelisC.peliculas[i-1].genero)){
            printf("%s\n",pelisC.peliculas[i].titulo);
            i = i-1;
            j = j+1;
       }
       if((1==i)&&(j <= 10) && (pelisC.peliculas[i].genero==gen)){
            printf("%s\n",pelisC.peliculas[i].titulo);
        }    
}
        
                
        
    



//Muestra las 10 peliculas con mejor rating
void MostRating(Arreglo pelisC){
	int i;
	
	OrdRating(&pelisC);
	i=pelisC.cant-10;
	while(i<pelisC.cant){
		printf("%s\n",pelisC.peliculas[pelisC.cant].titulo);
		printf("--------------------------\n");
		pelisC.cant=pelisC.cant-1;
	}
}

//Accion exportar peliculas 
void Exportar(Arreglo pelisC, FILE *e){
    int i;

    e=fopen("peliculas.dat","wb");
    
    i=0;

    while(i < pelisC.cant){

        i=i+1;
        
        fwrite(&pelisC.peliculas[i],sizeof(Movie),1,e);
        
    };

    fclose(e);

}

//Accion que lista los elementos del archivo binario
void Listar(FILE *f){
    Movie pelis;

    f=fopen("peliculas.dat","rb");

    if(f==NULL){
        printf("No se puedo abrir el archivo, pruebe exportarlo primero\n");
    }
    else{
        while(!feof(f)){ 

            fread(&pelis,sizeof(pelis),1,f);
            printf("%s\n",pelis.titulo);
            printf("\n");            
        };

    }
    fclose(f);

}









