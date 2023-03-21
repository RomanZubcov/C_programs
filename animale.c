#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<float.h>
#include<ctype.h>

const float g = 9.8;

enum hrana { ierbivor, carnivor, omnivor };

typedef struct animal {
    char nume[50];
	enum hrana h;
    int varsta;
    int  masa;
    float greutate;
    struct animal* urm;
} nod;



nod* adaugarea(nod* lista)
{
	nod* temp;
	char nume[50];
	enum hrana h;
	int nr_hrana;
	int varsta;
	float masa;
	float greutate;
	temp = (nod*)malloc(sizeof(nod));


	printf("Nume Animal:\n");
	scanf("%s", nume);
	while (!(isupper(nume[0]))) {
		printf("\nNume eronat! Nume Animal:\n");
		scanf("%s", nume);
	}
	strcpy(temp->nume, nume);

	printf("Introduceti specia animalului (0 - ierbivor, 1 - carnivir, 2 - omnivor):\n ");
	scanf("%d", &nr_hrana);
	if (nr_hrana==0)
	{
		temp->h = ierbivor;
	}
	else if(nr_hrana==1)
	{
		temp->h = carnivor;
	}
	else if(nr_hrana == 2)
	{
		temp->h = omnivor;
	}

	printf("Varsta:\n");
	scanf("%d", &varsta);
	
	while (varsta>20 || varsta<0)
	{
		printf("Eroare\n");
		printf("Varsta =\n");
		scanf("%d", &varsta);
	}
	temp->varsta = varsta;
	
	printf("Masa:\n");
	scanf("%f", &masa);
	temp->masa = masa;
	
	temp->greutate = temp->masa * g;

	temp->urm = NULL;

	if (lista == NULL)
	{
		lista = temp;
	}
	else
	{
		temp->urm = lista;
		lista = temp;
		
	}
	return lista;
}

void afisare_animale(nod* afis)
{
	nod* temp;
	temp = afis;

	while (temp != NULL)
	{
		printf("\n%s	Tip:%d  Varsta:%d	Masa:%d	Greutatea:%.2f", temp->nume, temp->h, temp->varsta, temp->masa, temp->greutate);
		temp = temp->urm;
	}
	
}

void input_fisier(nod*afis) 
{
	nod* temp;
	temp = afis;
	FILE* f;
	char nume_fisier[50];
	printf("\nDati nume fisier:");
	scanf("%s", nume_fisier);
	

	f = fopen(nume_fisier, "wt");
	while (temp != NULL)
	{
		fprintf(f,"\n%s	Tip:%d  Varsta:%d	Masa:%d	Greutatea:%.2f", temp->nume, temp->h, temp->varsta, temp->masa, temp->greutate);
		temp = temp->urm;
	}
}
int main()
{
	nod* lista;
	lista = NULL;
	int opt;

	do
	{
		printf("\n1.Iesire");
		printf("\n2.Citire");
		printf("\n3.Afisare");
		printf("\n4.Adaugare in fisier");
		printf("\nOptiunea dvs:		>");
		scanf("%d", &opt);

			switch (opt)
			{
			case 1: exit(1);
				break;
			case 2:lista = adaugarea(lista);
				break;
			case 3:afisare_animale(lista);
				break;
			case 4:input_fisier(lista);
				break;
			default:
				break;
			}

	} while (1);
	
	system("pause");
	return 0;
}