/*****************************************************
* FUNCIONES DE ALFABETOS, CADENAS, ETC               *
* Create by: Gabriela Alejandra Pérez Arteaga        *
* Realiza las operaciones básicas con cadenas y      *
*   alfabetos. Práctica 1 para la clase de Teoría    *
*   Computacional                                    *
* 													 *
* Fecha Octubre - 2015.                              *
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX  254

int longitud(char *w); 			//INCISO A: DEVUELVE LONGITUD DE W1 O W2
int pre_suf(char *w);			//INCISO B: DEVUELVE SUBCADENAS DE W1 O W2
char *conca(char *w, char *w1);		//INCISO C: DEVUELVE CONCATENACION DE CADENAS
void pot_w2(char *w, int n);				//INCISO E: POTENCIA W2
int concurrencia(char *w, char c);
void pot(char *w);				//INCISO G: POTENCIA ALFABETO
char *nuevo(int tam);					//DEVUELVE APUNTADOR A MEMORIA DE UN ARREGLO NUEVO 
void menu();			//MENU

int main(void){
	int op=-1, op1=-1, tam=0, i=0;
	char *w1, *w2, *alf;
	char cadena[MAX], cadena2[MAX], aux;
	w1=cadena;
	w2=cadena2;


	printf("\n\t Cuantos caracteres tiene su alfabeto? \n\t >> ");
	scanf("%d", &tam);
	printf("Introducir alfabeto. Presione ENTER despues de ingresar cada simbolo. \n");
	alf = nuevo(tam);
		for(i=0; i<tam; i++){
			/*scanf("%c", &alf[i]);*/
			aux=getchar();
			if(isspace(aux)){
				i=i-1;
			}else{
				alf[i]=aux;
			}
		}
	printf("\t\t --  Su alfabeto es  -- \n { ");
	for(i=0; i<tam; i++){
			printf("  %c  ,", alf[i]);
		}
		printf(" } \n");
	while(op!=8){
		op1=0;
		menu();
		scanf("%d", &op);
		switch(op){
			case 0:		//INTRODUCIR ELEMENTOS
				printf("\n   --------------------------------- \n");
				printf("\n\t1. Introducir mas elementos al alfabeto \n\t2. Introducir palabras para analizar \n\t\t - Seleccion <<  ");				
				scanf("%d", &op1);
				switch(op1){
						case 1: //INTRODUCIR MÁS ELEMENTOS AL ALFABET
							break;
						case 2: //INTRODUCIR PALABRAS
								printf("\n\t - Primera palabra <<  ");
								setbuf(stdin,NULL);	//Limpia el buffer de la entrada
								gets (cadena);		//Obtiene la cadena
								printf("\n\t - Segunda palabra <<  ");
								setbuf(stdin,NULL);	//Limpia el buffer de la entrada
								gets (cadena2);		//Obtiene la cadena
							break;
						}
				break;
			case 1: //LONGITUD PALABRA
					
					printf("\n   --------------------------------- \n");
					printf("\n\tDe que palabra desea obtener su longitud? \n");
					printf("\n\t 1. %s  \n\t 2. %s \n\t - Seleccion <<  ", cadena, cadena2);
					scanf("%d", &op1);
					if(op1==1){
						printf("\nLa longitud de su palabra es %d ", longitud(cadena));	
					}else if(op1==2){
						printf("\nLa longitud de su palabra es %d ", longitud(cadena2));
					}else{
						printf("\n\n -- OPCION INVALIDA -- ");
					}
				break;
			case 2: //Subcadenas      
					printf("\n   --------------------------------- \n");
					printf("\n\tDe que palabra desea obtener sus Prefijos // Sufijos? \n");
					printf("\n\ta)  %s  \n\tb) %s \n\n\t1. Prefijos y sufijos de cadena a\n\t2. Prefijos y Sufijos de cadena b \n - Seleccion <<  ", cadena, cadena2);
					scanf("%d", &op1);
					switch(op1){
						case 1:   pre_suf(cadena);		
							break;
						case 2:	pre_suf(cadena2);
							break;
						default: printf("\n\t - OPCION INVALIDA -");
							break;
					}
				break;
			case 3: 		//CONCATENACIÓN  strcat(ca1, cad2);
					printf(" Las cadenas a y b concatenadas dan como resultado << \n  %s  \n ", conca(cadena, cadena2));
				break;
			case 4: //LONGITUD DE CONCATENACIÓN
					printf(" Las cadenas a y b concatenadas tienen una longitud de <<   %d \n ", longitud(conca(cadena, cadena2)));
				break;
			case 5: 		//POTTENCIA DE PALABRAS
						printf(" \n\t A que potencia desea la cadena 2? << \t");
						scanf("%d", &i);
						pot_w2(w2, i);
				break;
			case 6: 		//concurrencia
					printf("\n\t Que cadena desea analizar? <<    ");
					scanf("%d", &op1);
					printf("\n\t Que caracter desea encontrar? <<   ");
					aux=getchar();
					if(isspace(aux)){
						aux=getchar();
					}if(op1==1){
						printf("\n El numero de concurrencia del caracter es ::  %d ", concurrencia(cadena, aux));
						}else if(op1==2){
							printf("\n El numero de concurrencia del caracter es ::  %d ", concurrencia(cadena2, aux));
							}else{
						printf("\n\t\t ERROR 404 - OPCION INVALIDA \n");
								}
				break;
			case 7:					//POTENCIA ALFABETO
				break;
			case 8: 		printf("\n\n -- Buen dia --");	return 0;
				break;
			default:("O P C I Ó N     I N C O R R E C T A. Vuelve a intentar. ");
		}	
	}
	free(alf);
	return 0;
}

void menu(){
	printf("\n   --------------------------------- \n");
	printf("\t/* OPERACIONES CON ALFABETOS */ \n\t --  TEORIA COMPUTACIONAL -- \n");
	printf("\n\t0. Introducir elementos  \n\t1. Longitud de palabra \n\t2. Subcadenas \n\t3. Concatenacion de cadenas \n\t4. Longitud de concatenacion \n\t5. Potencia de palabras \n\t6. Concurrencia\n\t7. Potenciar Alfabeto \n\t8. SALIR");
	printf("\n\nSu seleccion fue << \t");			//MENU
}

char *nuevo(int tam){
	char *n;
			n = (char*)malloc(sizeof(char)*(tam+1));
			if(n == NULL){
				perror("\n\n\t\t FATALY ERROR. UNABLE TO ALLOCATE REQUIRED MEMORY \n\n");
				return 0;
			}
	return n;		//CREA NUEVO ESPACIO DINAMICO PARA ARREGLO CHAR
}

int longitud(char *w){				//DEVUELVE LONGITUD CADENA 
	int lg=0;
		lg=strlen(w);
	return lg;
}

int pre_suf(char *w){				//DEVUELVE PREFIJOS Y SUFIJOS 
	// n==1 PREFIJOS
	char cad[MAX];
	*cad='\0';				//LIMPIA CADENAS
	char aux[MAX];
	*aux='\0';
	int i=0, j=0;

		printf("\n ---------  PREFIJOS  --------- \n");
		printf("\n    Cadena vacia     \n");

		for(i=0; i<longitud(w); i++){
			aux[0] = w[i];
			
		}
		*cad='\0';
		*aux='\0';

		printf("\n ---------  SUFIJOS  --------- \n");
		printf("\n    Cadena vacia     \n");
		for(i=longitud(w); i>=0; i--){
				aux[0] = w[i];
				strcat(cad, aux);
				printf(" %s \n", cad);
			}
	return 0;
}	

char *conca(char *w, char *w1){			//CONCATENA CADENAS
	char *cad;
	cad =  nuevo(MAX);
	cad = strcat(w, w1);
	return cad;
}

void pot_w2(char *w, int n){				// POTENCIA W2
	char cad[MAX];
	char aux[MAX];
	*aux='\0';
	*cad='\0';
	int i=0, j=0;

	if(n>0){				//POTENCIA POSITIVA
		for(i=0; i<n; i++){
			strcat(cad, w);
		}
		puts(cad);
	}else if(n<0){				//POTENCIA NEGATIVA  pendiente
		printf("BANDERA");
		for(i=longitud(w), j=0; i>=0; i--, j++){
				aux[j]=w[i];
			}
		puts(aux);

		for(i=0; i<n; i++){
			strcat(cad, aux);
		}
		puts(cad);
	}else{				//POTENCIA CERO
		printf("\n  CADENA VACIA  \n");
	}
}

int concurrencia(char *w, char c){
	int cont=0, i=0;
		for(i=0; i<longitud(w); i++){
			if(w[i]==c)			cont=cont+1;
		}
	return cont;
}

