#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int Search_Min_Element_Midlle(int **matrix, const int str, const int stolb, int indexStr_maxElement, int indexStolb_maxElement);
int Search_Min_Element_Right(int **matrix, const int str, const int stolb, int indexStr_maxElement, int indexStolb_maxElement);
int Search_Min_Element_Left(int **matrix, const int str, const int stolb, int indexStr_maxElement, int indexStolb_maxElement);

void Input_Matrix( int **matrix, const int str, const int stolb, int *max_element, int *index_element_str, int *index_element_stolb);
void Search_Desired_Method(int **matrix, const int str, const int stolb, int indexStr_maxElement, int indexStolb_maxElement);
void Print_Matrix( int **matrix, const int str, const int stolb );
void Give_out_Memory(int **mass, int str, int stolb);
void Clear_Memory(int **mass,int str);

int i, j;
int min = 1000;

int main() {

    srand(time(NULL));

    int str, stolb, index_str, index_stolb;
    int max_element = 0;
    int **mass_matrix;

    printf("Input Rectangular Matrix\n");
    printf("Number of lines:");
    scanf("%d", &str);
    printf("Number of columns: ");
    scanf("%d", &stolb);

    mass_matrix = (int **) malloc(str * sizeof(int *)); //Memory for an array of pointers

    Give_out_Memory(mass_matrix,str,stolb); //allocate memory

    Input_Matrix(mass_matrix,str,stolb,&max_element,&index_str,&index_stolb); // form a matrix

    Print_Matrix(mass_matrix,str,stolb); //Matrix output

    Search_Desired_Method(mass_matrix,str,stolb,index_str,index_stolb);

    Clear_Memory(mass_matrix,str); // clear memory

    free(mass_matrix);

    return 0;
}

void Search_Desired_Method(int **matrix, const int str, const int stolb, int indexStr_maxElement, int indexStolb_maxElement){
    int Variable = stolb / 2; //find position max. element in the matrix
    if(indexStr_maxElement!=str-1){
        if(Variable == indexStolb_maxElement){
            Search_Min_Element_Midlle(matrix,str,stolb,indexStr_maxElement,indexStolb_maxElement);
        } else if(Variable < stolb) {
            Search_Min_Element_Left(matrix,str,stolb,indexStr_maxElement,indexStolb_maxElement);
        } else if(Variable > stolb) {
            Search_Min_Element_Right(matrix,str,stolb,indexStr_maxElement,indexStolb_maxElement);
        }
    } else {
        printf("The minimum element could not be found because \n The element is on the last line");
    }

}

void Input_Matrix( int **matrix, const int str, const int stolb, int *max_element, int *index_element_str, int *index_element_stolb ){
    for (i = 0; i < str; i++) {
        for (j = 0; j < stolb; j++) {
            matrix[i][j] = rand()%10;
            if(*max_element < matrix[i][j]){
                *max_element = matrix[i][j]; //Finding max. element
                *index_element_str = i; //Finding indexes max. element
                *index_element_stolb = j;
            }
        }
    }
    printf("Maximum element in matrix = %d\n",*max_element);
    printf("Column index = %d \n Row index = %d\n", *index_element_stolb,*index_element_str);
}

void Print_Matrix( int **matrix, const int str, const int stolb ) { //Matrix output
    for ( i = 0; i < str; i++) {
        for ( j = 0; j < stolb; j++ ){
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void Give_out_Memory(int **mass, int str, int stolb){
    for (i = 0; i < str; i++)//Memory for each line
        mass[i] = (int *) malloc(stolb * sizeof(int));
}

void Clear_Memory(int **mass,int str){ // Clear memory
    for (i = 0; i < str; i++)
        free(mass[i]);
}

int Search_Min_Element_Midlle(int **matrix, const int str, const int stolb, int indexStr_maxElement, int indexStolb_maxElement) {
    int time;
    for(i = indexStr_maxElement+1; i < str; i++){
        time = i;
        if(i >= 2){
            time = i -1;
        }
        for(j = indexStr_maxElement - 1; j <stolb-time; j++){
            if(min > matrix[i][j]){
                min = matrix[i][j];
            }
        }
    }
    return  printf("Minimum element in selection = %d\n",min);
}

int Search_Min_Element_Right(int **matrix, const int str, const int stolb, int indexStr_maxElement, int indexStolb_maxElement){
    for(i = indexStr_maxElement+1; i < str; i++){
        for(j = indexStolb_maxElement; j <stolb; --j){
            if(min>matrix[i][j]){
                min = matrix[i][j];
            }
        }
    }
    return  printf("Minimum element in selection = %d\n",min);
}

int Search_Min_Element_Left(int **matrix, const int str, const int stolb, int indexStr_maxElement, int indexStolb_maxElement){
    for(i = indexStr_maxElement+1; i < str; i++){
        for(j = indexStolb_maxElement-1; j <stolb-1; j++){
            if(min>matrix[i][j]){
                min = matrix[i][j];
            }
        }
    }
    return  printf("Minimum element in selection = %d\n",min);
}
