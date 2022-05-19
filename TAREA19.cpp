/*Autor: oscar ramirez  fecha: 18/04/2022

Hacer un programa que utilice la estructura de Alumno y almacene los datos de 10 alumnos
Debe tener el siguiente menú:
0. Salir
1. Agregar alumnos
2. Imprimir
3. Alumnos Aprobados
4. Alumnos Reprobados
5. Promedio del grupo
6. Porcentaje de alumnos Aprobados
NOTA: Para hacer operaciones con las calificaciones de los alumnos(Opciones 3,4,5 y 6 del menú) se siguen las siguientes reglas
Si el numero de faltas es <=6, la calificación es la que esta almacenada en el dato promedio de la estructura
 Pero si no, la calificación que se toma es 5
*/
#include<stdio.h>
#include<stdlib.h>
#include "milibreria.h"

//declaraciones globales 
#define MAX 10
struct alumno{
	char nombre[30];
	float promedio;
	int faltas;
};
int n=0;

//prototipos
int menu();
void agregar(struct alumno x[]);
void imprimir(struct alumno x[], int tipo);
void promedio( struct alumno x[]);
void porcentaje(struct alumno x[]);

//principal
int main(){
	int op;
	struct alumno grupo[MAX];
	float cal[MAX];
	do{
		op=menu();
		switch(op){
			case 0:	printf("Adios...\n");
					break;
			case 1: agregar(grupo);
					break; 
			case 2: imprimir(grupo,0);
					break; 
			case 3: imprimir(grupo,1);
					break; 
			case 4: imprimir(grupo,2);
					break; 
			case 5: promedio(grupo);
			
					break; 
			case 6: porcentaje(grupo);
					break; 
		}
	}while(op!=0);
	return 0;
}
//menu de inicio 
int menu(){
	int opcion;
	printf("------MENU-----	\n");
	printf("0. SALIR	\n");
	printf("1. AGREGAR ALUMNOS	\n");
	printf("2. IMPRIMIR	\n");
	printf("3. ALUMNOS APROBADOS	\n");
	printf("4. ALUMNOS REPROBADOS	\n");
	printf("5. PROMEDIO DEL GRUPO	\n");
	printf("6. PORCENTAJE DE ALUMNOS APROBADOS	\n");
	opcion=leerd("selecciona una opcion: ",0,6);
	return opcion;
}
//se agregan alumnos 
void agregar(struct alumno x[]){
	int pregunta;
	int Reprobo=0;
	// ciclo para agregar nombre, promedio y faltas, hasta max
	while(n<MAX){
		leers("nombre: ",x[n].nombre,30);
		x[n].promedio=leerf("promedio: ",0,10);
		x[n].faltas=leerd("Faltas: ",0,32);	
		if(x[n].faltas>=7){
		
			x[n].promedio=5;
		}
		
		n++;	
		pregunta=leerd("agregar a otro alumno? (1-si, 0-no):",0,1);
		//si NO se desea agregar otro alumno, se rompe el while
		if(pregunta==0){
			break;
		}
	}
	//si el contador es igual que MAX nos manda mensaje de arreglo lleno
	if(n==MAX){
		printf("Arreglo lleno!!\n");
		system("PAUSE");
		}
}
//la funcion imprimir en el parametro tipo se le indica que va a imprimir
//0 a todos, 1 aaprobados, 2 reprobados
void imprimir(struct alumno x[], int tipo){
	char mensaje[20];
	switch(tipo){
		case 0:	strcpy(mensaje,"TOTALES");
				break;
		case 1:	strcpy(mensaje,"APROBADOS");
				break;
		case 2:	strcpy(mensaje,"REPROBADOS");
				break;
				
	}
	printf("---------------------------ALUMNOS %s-------------------------------\n",mensaje);
	printf("No.\tNOMBRE\t\t	FALTAS\t\t\tPROMEDIO\n");
	printf("--------------------------------------------------------------------------\n");
	for(int i=0; i<n; i++){
		switch(tipo){
			case 0:	printf("%2d\t%-30s\t%2d\t%4.1f\n", i+1,x[i].nombre,x[i].faltas,x[i].promedio);	
					break;
			case 1: if(x[i].promedio>=7){
				printf("%2d\t%-30s\t%2d\t%4.1f\n", i+1,x[i].nombre,x[i].faltas,x[i].promedio);
				}
					break;
			case 2: if(x[i].promedio<7){
				printf("%2d\t%-30s\t%2d\t%4.1f\n", i+1,x[i].nombre,x[i].faltas,x[i].promedio);
				}
					break;
			
		}
		
	}
	printf("-----------------------------------------------------------------\n");
	system("PAUSE");

}
//aqui esta la logica para calcular el promedio y lo regresa el valor
void promedio( struct alumno x[]) {
		float suma=0,  prom;
		for (int i=0; i<MAX; i++){
			suma= suma +x[i].promedio;

		}
		prom=suma/MAX;
		printf("PROMEDIO DEL GRUPO\n");
		printf("----------------------------\n");
		printf("El promedio es %f\n",prom);
		printf("----------------------------\n");
		
	}
// logica para calcular el porcentaje 
void porcentaje(struct alumno x[]){
	float suma=0,  por;
	int c=0, Reprobo=0;
		for (int i=0; i<MAX; i++){
			if(x[i].faltas>=6){
				Reprobo++;
			}
			else{
				c++;
			}
			
		}
		por=(c*100)/MAX;
		printf("\n porcentaje de alumnos aprobados: %f \n",por);
}

