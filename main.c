#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
void swap();
void insertionSort();
void selectionSort();
void exchangeSort();
void printArray();
void saveFile();

void printOptions();

void fullfillArray();
void fullfillRandFile();
void readAndSortFile();
void almost_sorted_tab();

int main()
{
    char input = '0', input2='0';


    int* tab;

                tab= (int*)malloc(sizeof(int) * 1);



    int size=1;
    printOptions();



    if (tab!= NULL) {
        do
        {

            scanf(" %c", &input);
            switch (input)
            {
            case '1':

                tab= (int*)malloc(sizeof(int) * 1);
                puts("Czy tablica wstepnie posortowana? 1-tak, 0-nie");
                scanf(" %c", &input2);


                if (input2=='0')
                    readAndSortFile("not_sorted.txt", tab, &size, insertionSort);

                else if(input2=='1')
                    readAndSortFile("sorted.txt", tab, &size, insertionSort);

                else
                    puts("Podano zla opcje\n");

                break;
            case '2':
                tab= (int*)malloc(sizeof(int) * 1);
                puts("Czy tablica wstepnie posortowana? 1-tak, 0-nie");
                scanf(" %c", &input2);


                if (input2=='0')
                    readAndSortFile("not_sorted.txt", tab, &size, exchangeSort);

                else if(input2=='1')
                    readAndSortFile("sorted.txt", tab, &size, exchangeSort);

                else
                    puts("Podano zla opcje\n");

                break;
            case '3':
                tab= (int*)malloc(sizeof(int) * 1);
                puts("czy tablica wstepnie posortowana? 1-tak, 0-nie");
                scanf(" %c", &input2);


                if (input2=='0')
                    readAndSortFile("not_sorted.txt", tab, &size, selectionSort);

                else if(input2=='1')
                    readAndSortFile("sorted.txt", tab, &size, selectionSort);

                else
                    puts("Podano zla opcje\n");

                break;

           /* case '1':
                puts("\nPodaj liczbe elementow w tablicy:(100000 max (powyzej trwa wiecej niz 10 sekund)");
                scanf(" %d", &size);
                puts("czy tablica wstepnie posortowana? 1-tak, 0-nie");
                scanf(" %c", &input2);
                if (input2=='0')
                {
                    tmp = (int *) realloc(tab, sizeof(int) * size);

                    if (tmp != NULL)
                    {
                        tab = tmp;
                        fullfillArray(tab, size);
                        before = clock();//mierzenie czasu
                        insertionSort(tab, size);
                        after = clock();
                        printArray(tab, size);
                        elapsed = (double)(after - before) / CLOCKS_PER_SEC;
                        printf("Czas sortowania: %lf\n", elapsed);

                    }

                    else
                        puts("przydzielenie pamieci nie powiodlo sie");

                }
                else if(input2=='1')
                {
                     tmp = (int *) realloc(tab, sizeof(int) * size);

                    if (tmp != NULL)
                    {
                        tab = tmp;
                        fullfillArray(tab, size);
                        almost_sorted_tab(tab,size);
                        before = clock();//mierzenie czasu
                        insertionSort(tab, size);
                        after = clock();
                        printArray(tab, size);
                        elapsed = (double)(after - before) / CLOCKS_PER_SEC;
                        printf("Czas sortowania: %lf\n", elapsed);

                    }

                    else
                        puts("przydzielenie pamiêci nie powiodlo sie");

                }
                else
                    puts("Podano zla opcje");

                break;
            case '2':
                puts("\nPodaj liczbe elementow w tablicy:(100000 max powyzej trwa wiecej niz 10 sekund)");
                scanf(" %d", &size);
                puts("czy tablica wstepnie posortowana? 1-tak, 0-nie");
                scanf(" %c", &input2);
                if (input2=='0')
                {
                    tmp = (int *) realloc(tab, sizeof(int) * size);

                    if (tmp != NULL)
                    {
                        tab = tmp;
                        fullfillArray(tab, size);
                        before = clock();//mierzenie czasu
                        exchangeSort(tab, size);
                        after = clock();
                        printArray(tab, size);
                        elapsed = (double)(after - before) / CLOCKS_PER_SEC;
                        printf("Czas sortowania: %lf\n", elapsed);

                    }

                    else
                        puts("przydzielenie pamiêci nie powiodlo sie");

                }
                else if(input2=='1')
                {
                     tmp = (int *) realloc(tab, sizeof(int) * size);

                    if (tmp != NULL)
                    {
                        tab = tmp;
                        fullfillArray(tab, size);
                        almost_sorted_tab(tab,size);
                        before = clock();//mierzenie czasu
                        exchangeSort(tab, size);
                        after = clock();
                        printArray(tab, size);
                        elapsed = (double)(after - before) / CLOCKS_PER_SEC;
                        printf("Czas sortowania: %lf\n", elapsed);

                    }

                    else
                        puts("przydzielenie pamiêci nie powiodlo sie");

                }
                else
                    puts("Podano zla opcje");

                break;
            case '3':
                 puts("\nPodaj liczbe elementow w tablicy:(100000 max powyzej trwa wiecej niz 10 sekund)");
                scanf(" %d", &size);
                puts("czy tablica wstepnie posortowana? 1-tak, 0-nie");
                scanf(" %c", &input2);
                if (input2=='0')
                {
                    tmp = (int *) realloc(tab, sizeof(int) * size);

                    if (tmp != NULL)
                    {
                        tab = tmp;
                        fullfillArray(tab, size);
                        before = clock();//mierzenie czasu
                        selectionSort(tab, size);
                        after = clock();
                        printArray(tab, size);
                        elapsed = (double)(after - before) / CLOCKS_PER_SEC;
                        printf("Czas sortowania: %lf\n", elapsed);

                    }

                    else
                        puts("przydzielenie pamiêci nie powiodlo sie");

                }
                else if(input2=='1')
                {
                     tmp = (int *) realloc(tab, sizeof(int) * size);

                    if (tmp != NULL)
                    {
                        tab = tmp;
                        fullfillArray(tab, size);
                        almost_sorted_tab(tab,size);
                        before = clock();//mierzenie czasu
                        selectionSort(tab, size);
                        after = clock();
                        printArray(tab, size);
                        elapsed = (double)(after - before) / CLOCKS_PER_SEC;
                        printf("Czas sortowania: %lf\n", elapsed);

                    }

                    else
                        puts("przydzielenie pamiêci nie powiodlo sie");

                }
                else
                    puts("Podano zla opcje");

                break;

            case 'i':
                puts("'i'-Lista instrukcji 'n'-nowa tablica '0'- wyjscie z programu, '1'-insertionSort, '2'- exchangeSort, '3'- selectionSort\n");
                break;
            */
            case 'n':
                puts("\nPodaj liczbe elementow w tablicy:(100000 max powyzej trwa wiecej niz 10 sekund)");
                scanf(" %d", &size);
                puts("czy tablica wstepnie posortowana? 1-tak, 0-nie");
                scanf(" %c", &input2);
                if (input2=='0')
                {

                    fullfillRandFile("not_sorted.txt",size);

                }
                else if(input2=='1')
                {
                    almost_sorted_file("sorted.txt",size);

                }
                else
                    puts("Podano zla opcje");

                break;



            case 't':

                puts("czy tablica wstepnie posortowana? 1-tak, 0-nie");
                scanf(" %c", &input2);


                if (input2=='0')
                    readAndSortFile("not_sorted.txt", tab, &size, selectionSort);

                else if(input2=='1')
                    readAndSortFile("sorted.txt", tab, &size, exchangeSort);

                else
                    puts("Podano zla opcje\n");

                break;

            case 'i':
                printOptions();
                break;




            default:
                puts("Podano zla opcje\n");
                break;
            }

        } while (input != '0');

        free(tab);
    }
    else
        puts("blad przydzialu pamieci\n");




    return 0;
}




void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void insertionSort(int tab[], int n)
{
    register int i, k, j;
    for (i = 1; i < n; i++)
    {
        k = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > k) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = k;
    }
}

void exchangeSort(int tab[], int n) {
    int i, j;
    for (i = 0; i < (n - 1); i++)
    {
        for (j = (i + 1); j < n; j++)
        {
            if (tab[i] > tab[j])// znak zamienia kolejnosc sortowania
            {
                swap(&tab[i], &tab[j]);
            }
        }
    }
}

void selectionSort(int* tab, int n)
{
    int i, j, k;
    for (i = 0; i < n; i++) {
        k = i;
        for (j = i + 1; j < n; j++)
            if (tab[j] < tab[k])
                k = j;
        swap(&tab[k], &tab[i]);
    }
}



void printArray(int* tab, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n\n\n");
}

void fullfillArray(int* tab, int n)
{
    int i = 0;
    srand(time(NULL));
    for (i; i < n; i++) {
        tab[i] = rand() % 201 - 100;

    }

}





void saveFile(int* tab, char* output, int count)
{
    FILE * fp = fopen(output, "w");
    fprintf(fp, tab);
    fclose(fp);

}

void fullfillRandFile(char* output, int n)
{
    FILE* fp = fopen(output, "w");
    fprintf(fp, "SIZE: %d\n", n);
    register int i = 0;
    srand(time(0));
    for (i; i < n; i++)
        fprintf(fp, "%d ", rand() % 201 - 100);

    printf("\n");

    fclose(fp);

}
void almost_sorted_file(char* output, int size)//tablica z 1% nieposortowanych
{
    FILE* fp = fopen(output, "w");
    fprintf(fp, "SIZE: %d\n", size);
    register int i = 0, j= 0;
    srand(time(0));



    int k=size/100;
    for (i,j=-100; i<size;i++)
    {
        if (i==k){
            fprintf(fp, "%d ", rand() % 201 - 100);
            j+=2;
            k+=size/100;
        }
        else {
            fprintf(fp, "%d ", j);
        }

    }
    printf("\n");


    fclose(fp);

}



void readAndSortFile( char* output,  int *tab, int *size, void (*operation)(int *, int))
{
    double elapsed= 0;
    long long after ,before ;

    FILE* fp = fopen(output, "r");
    fseek(fp, 0, SEEK_SET);


    int i = 0;
    int value;
    fscanf(fp, "SIZE: %d", &(*size));


    tab = (int*) realloc(tab, sizeof(int) * (*size));

    for (i=0; i < *size; i++) {
        fscanf(fp, "%d", &value);
        tab[i]=value;
            printf("%d ", tab[i]);

    }


    before = clock();//mierzenie czasu
    operation(tab, *size);
    after = clock();
   elapsed = (double)(after - before) / CLOCKS_PER_SEC;
    printf("\nCzas sortowania: %lf\n", elapsed);




    fclose(fp);

}



void almost_sorted_tab(int* tab, int n)//tablica z 1% nieposortowanych
{
    selectionSort(tab, n);
    srand(time(0));
    int i;
    int k=n/100;
    for (i=0; i<n;i+=k)
        tab[k] = rand() % 201 - 100;


}


void printOptions()
{
    printf("'0'- wyjscie z programu\n'1'-insertionSort\n'2'- exchangeSort\n'3'- selectionSort\n'n' - nowa tablica elementow\n");
    printf("'i' - wyswietl opcje do wyboru\n");
}


