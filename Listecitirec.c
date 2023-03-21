#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Utilizare macroinstructiune pentru scoala
#define Afisare(n) printf("Numele este: %s\nVarsta este: %d \n", n->nume,n->varsta);
// SINTAXA STRUCT PENTRU LISTE SIMPLU INLANTUITE
// struct nume_struct{
// 		Ce doriti voi sa mai contina lista
// 		struct nume_struct *urm;
// };
// exemplu de liste simplu inlantuite, sa zicem ca este vorba de o clasa, lista noastra o sa contina elevi din aceasta clasa
// atunci in cutie o sa punem:
// numele elevului (char sir de caractere), scoala la care invata elevul (char pointer)
// varsta elevului (int), notele elevului (int pointer)
struct scoala{
	char nume[20];
	int varsta;
	struct scoala *urm;
}nod;
// struct scoala{
// 	char nume[20];
// 	int varsta;
// 	struct scoala *stanga, *dreapta;
// }nod;
// prim->stanga =NULL
// element din mijloc st 
// ultim-> dreapta = null
//adaugare element in struct la final
// liste circulare
// ultim -> urm != prim
struct scoala *adaugare_final(struct scoala *prim)
{
	int varsta;
	char nume[20];
	struct scoala *elev, *aux;
	aux = prim;
	elev = (struct socala*) malloc(sizeof(nod));
	//AICI AM CREAT UN ELEMENT DE TIP STRUCT
	printf("dati un nume elevului\n");
	scanf("%s",nume);
	strcpy(elev->nume,nume);
	printf("ce varsta are elevul?\n");
	scanf("%d", &elev->varsta);
	elev->urm=NULL;
	if(prim == NULL)
		prim = elev;
	else
	{
		while(aux->urm!=NULL)
		{
			aux=aux->urm;
		}
		// 1->00211231
		// 2->12322123
		// 3->12312112
		// elev->1
		aux->urm=elev;
	}
	return prim;
}
//adaugare element la inceputul listei
struct scoala *adaugare_inceput(struct scoala *prim)
{
	int varsta;
	char nume[20];
	struct scoala *elev, *aux;
	aux = prim;
	elev = (struct socala*) malloc(sizeof(nod));
	//AICI AM CREAT UN ELEMENT DE TIP STRUCT
	printf("dati un nume elevului\n");
	scanf("%s",nume);
	strcpy(elev->nume,nume);
	printf("ce varsta are elevul?\n");
	scanf("%d", &elev->varsta);
	elev->urm=prim;
	return elev;
}
//adaugare element in lista cu conditii
//in acest exemplu o sa folosim adaugarea in ordine alfabetica
struct scoala *adaugare_cu_conditii(struct scoala *prim)
{
	int varsta,verificare = 0;
	char nume[20];
	struct scoala *elev, *aux, *ajutor;
	aux = prim;
	elev = (struct socala*) malloc(sizeof(nod));
	//AICI AM CREAT UN ELEMENT DE TIP STRUCT
	printf("\n\n");
	printf("dati un nume elevului\n");
	scanf("%s",nume);
	strcpy(elev->nume,nume);
	printf("ce varsta are elevul?\n");
	scanf("%d", &elev->varsta);
	elev->urm = NULL;
	if(prim == NULL)
		prim = elev;
	else
	{
		if(strcmp(prim->nume,elev->nume)>0)
		{
			elev->urm=prim;
			return elev;
		}
		else{
			// ex primul element.nume = Andreea -> 302
			// (302)trebie sa ne punem aici Bob -> 001
			// (001)al doilea element.nume = Maria (aux) -> urm = elev; elev->urm = Nico
			// al trilea element.nume = Nico
			// elev.nume = BOB
			while(aux->urm!=NULL)
			{
				// printf("%s %s", aux->nume,elev->nume);
				if(strcmp(aux->urm->nume,elev->nume)>0)
				{
					//retinem ce urma dupa nodul curent
					elev->urm = aux->urm;
					//punem dupa nodul curent nodul creat
					aux->urm = elev;
					return prim;
				}
				aux=aux->urm;
			}
			if(verificare == 0)
			{
				aux=prim;
				while(aux->urm)
				{
					aux= aux->urm;
				}
				aux->urm = elev;
			}
		}
	}
	return prim;
}
int main()
{
	int i;
	//declarare de struct (echivalent cu o declarare clasica)
	struct scoala *prim=NULL, *aux;
	//cand vorbim de liste, noi trebuie sa retinem primul element din acesta
	for(i=0;i<6;i++)
	{
		printf("%d",i);
		prim = adaugare_cu_conditii(prim);
	}
	aux = prim;
	while(aux)
	{
		Afisare(aux);
		aux= aux->urm;
	}
	return 0;
}