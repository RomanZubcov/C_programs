#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX 50

typedef struct {

	char cuv[MAX];
}nod;

int citire_cuvint(nod** cuvinte)
{

	int dimensiunea = 0;
	*cuvinte = malloc(MAX * sizeof(nod));

	
		while (1)
		{
			printf("Introduceti un cuvant (STOP pentru a opri citirea): ");
			scanf("%s", (*cuvinte)[dimensiunea].cuv);

			if (strcmp((*cuvinte)[dimensiunea].cuv, "STOP") == 0) 
			{

				break;
			}dimensiunea++;
			if (dimensiunea >= MAX)
			{
				printf("Ati depasit numarul maxim de cuvinte.\n");
				break;
			}
			*cuvinte = realloc(*cuvinte, (dimensiunea + 1) * sizeof(nod));
		}
		

		return dimensiunea;
		
	
}


int comp(const void* a, const void* b) {
	nod* pa = (nod*)a;
	nod* pb = (nod*)b;
	return strcmp(pa->cuv, pb->cuv);
}

void afisare_cuvinte_ordonate(nod* cuvinte, int dimensiunea) {
	qsort(cuvinte, dimensiunea, sizeof(nod), comp);
	printf("Cuvintele ordonate sunt:\n");
	for (int i = 0; i < dimensiunea; i++) {
		printf("%s\n", cuvinte[i].cuv);
	}
}

void adaugare_fisier(nod* cuvinte, int dimensiunea)
{
	FILE* f = fopen("cuvinte.txt", "wt");
	
	for (int i = 0; i < (dimensiunea + 1); i++) {
		fprintf(f, "%s\n", (cuvinte)[dimensiunea].cuv);
	}
	
	fclose(f);

}

int main()

{
	nod* cuvinte;
	int dimensiunea;
	
	
	int opt;
	do
	{
		printf("1.Citirea cuvintelor\n");
		printf("2.Ordonarea alfabetica si afisarea cuvintelor\n");
		printf("3.Adaugare in fisier\n");
		printf("\nOptiunea este:	->");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			dimensiunea = citire_cuvint(&cuvinte);
			printf("Cuvintele citite sunt:\n");
			for (int i = 0; i < dimensiunea; i++)
			{
				printf("%s\n", cuvinte[i].cuv);
			}
		
			break;
		case 2:afisare_cuvinte_ordonate(&cuvinte, dimensiunea);
			break;
		case 3:adaugare_fisier(&cuvinte, dimensiunea);
			break;
		default:
			break;
		}


	} while (1);
	
}