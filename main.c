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
                printSecondOptions();
                scanf(" %c", &input2);


                if (input2=='0')
                    readAndSortFile("not_sorted.txt", tab, &size, insertionSort);

                else if(input2=='1')
                    readAndSortFile("sorted.txt", tab, &size, insertionSort);

                else if(input2=='2')
                    readAndSortFile("descending.txt", tab, &size, insertionSort);

                else
                    puts("Podano zla opcje\n");

                break;
            case '2':
                tab= (int*)malloc(sizeof(int) * 1);
                printSecondOptions();
                scanf(" %c", &input2);


                if (input2=='0')
                    readAndSortFile("not_sorted.txt", tab, &size, exchangeSort);

                else if(input2=='1')
                    readAndSortFile("sorted.txt", tab, &size, exchangeSort);

                else if(input2=='2')
                    readAndSortFile("descending.txt", tab, &size, exchangeSort);




                else
                    puts("Podano zla opcje\n");

                break;
            case '3':
                tab= (int*)malloc(sizeof(int) * 1);
                printSecondOptions();
                scanf(" %c", &input2);


                if (input2=='0')
                    readAndSortFile("not_sorted.txt", tab, &size, selectionSort);

                else if(input2=='1')
                    readAndSortFile("sorted.txt", tab, &size, selectionSort);

                else if(input2=='2')
                    readAndSortFile("descending.txt", tab, &size, selectionSort);


                else
                    puts("Podano zla opcje\n");

                break;

             case 't':

                tab= (int*)malloc(sizeof(int) * 1);
                printSecondOptions();
                scanf(" %c", &input2);
                if (input2=='0'){
                    readAndSortFile("not_sorted.txt", tab, &size, insertionSort);
                    tab= (int*)malloc(sizeof(int) * 1);
                    readAndSortFile("not_sorted.txt", tab, &size, exchangeSort);
                    tab= (int*)malloc(sizeof(int) * 1);
                    readAndSortFile("not_sorted.txt", tab, &size, selectionSort);
                }
                else if (input2=='1'){
                    readAndSortFile("sorted.txt", tab, &size, insertionSort);
                    tab= (int*)malloc(sizeof(int) * 1);
                    readAndSortFile("sorted.txt", tab, &size, exchangeSort);
                    tab= (int*)malloc(sizeof(int) * 1);
                    readAndSortFile("sorted.txt", tab, &size, selectionSort);
                }
                else if (input2=='2'){
                    readAndSortFile("descending.txt", tab, &size, insertionSort);
                    tab= (int*)malloc(sizeof(int) * 1);
                    readAndSortFile("descending.txt", tab, &size, exchangeSort);
                    tab= (int*)malloc(sizeof(int) * 1);
                    readAndSortFile("descending.txt", tab, &size, selectionSort);
                }








                break;


            case 'n':
                puts("\nPodaj liczbe elementow w tablicy:(100000 max powyzej trwa wiecej niz 10 sekund)");
                scanf(" %d", &size);
                printSecondOptions();
                scanf(" %c", &input2);
                if (input2=='0')
                {

                    fullfillRandFile("not_sorted.txt",size);

                }
                else if(input2=='1')
                {
                    almost_sorted_file("sorted.txt",size);

                }
                 else if(input2=='2')
                {
                    descending_order_file("descending.txt",size);

                }
                else
                    puts("Podano zla opcje");

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


void insertionSort(int tab[], int size)
{

    double elapsed= 0;
    long long after = 0 ,before = 0;
    before = clock();//mierzenie czasu
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > key) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = key;
    }

    after = clock();
   elapsed = (double)(after - before) / CLOCKS_PER_SEC;
    printf("\nCzas sortowania %s: %lf\n",__func__, elapsed);
}

void exchangeSort(int tab[], int size) {

    double elapsed= 0;
    long long after = 0 ,before = 0;
    before = clock();//mierzenie czasu
    int i, j;
    for (i = 0; i < (size - 1); i++)
    {
        for (j = (i + 1); j < size; j++)
        {
            if (tab[i] > tab[j])// znak zamienia kolejnosc sortowania
            {
                swap(&tab[i], &tab[j]);
            }
        }
    }

    after = clock();
    elapsed = (double)(after - before) / CLOCKS_PER_SEC;
    printf("\nCzas sortowania %s: %lf\n",__func__, elapsed);

}

void selectionSort(int tab[], int size)
{

    double elapsed= 0;
    long long after = 0 ,before = 0;
    before = clock();//mierzenie czasu
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) {


        min_idx = i;
        for (j = i + 1; j < size; j++)
            if (tab[j] < tab[min_idx])
                min_idx = j;


        swap(&tab[min_idx], &tab[i]);
    }
    after = clock();
   elapsed = (double)(after - before) / CLOCKS_PER_SEC;
    printf("\nCzas sortowania ,%s: %lf\n",__func__, elapsed);





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
    srand(time(NULL));
    for (; i < n; i++)
        fprintf(fp, "%d ", rand()% 201 - 100);

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


void descending_order_file(char* output, int size)//tablica z 1% nieposortowanych
{
    FILE* fp = fopen(output, "w");
    fprintf(fp, "SIZE: %d\n", size);
    register int i = 0, j= 0;
    srand(time(0));



    int k=size/100;
    for (i,j=100; i<size;i++)
    {
        if (i==k){
            fprintf(fp, "%d ", j);
            j-=2;
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

    FILE* fp = fopen(output, "r");
    fseek(fp, 0, SEEK_SET);


    int i = 0;
    int value;
    fscanf(fp, "SIZE: %d", &(*size));


    tab = (int*) realloc(tab, sizeof(int) * (*size));

    for (i=0; i < *size; i++) {
        fscanf(fp, "%d", &value);
        tab[i]=value;
            //printf("%d ", tab[i]);

    }



    operation(tab, *size);





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

void printSecondOptions()
{
    printf("'0' - tablica nieposortowana\n");
    printf("'1' - tablica posortowana (1 procent elementow nieposortowanych)\n");
    printf("'2' - tablica posortowana malejąco\n");
}

