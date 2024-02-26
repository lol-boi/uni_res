#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void saveMatrixToFile(const char *filename, double matrix[][2], int rows) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < rows; i++)
        fprintf(file, "%f %f\n", matrix[i][0], matrix[i][1]);
    fclose(file);
}

int main(){
    double matrix[1000][2] = {};
    int counter = 0;
    for(int val = 10; val <= 10000; val+=10){  
        clock_t start,end; 
        int i,n,j,temp,k;
        n = val; 
        int *p=(int*) malloc(n*sizeof(int));
        for(i=0;i<n;i++) *(p+i)=rand();
        start = clock();
        for(i=0;i<n;i++){
	        for(j=0;j<n-1;j++){ //optimised version uses j<n-i-1 insted of j<n-1
			    if(*(p+j)>*(p+j+1)){
				    temp=*(p+j);
				    *(p+j)=*(p+j+1);
				    *(p+j+1)=temp;
		        }
		    }
	    }
        end = clock();
        double time = (double)(end-start)/CLOCKS_PER_SEC; 
        printf("The time for the event was: %f \n",time);
        matrix[counter][0] = time;
        matrix[counter++][1] = val;
        free(p);
    }
    int rows  = sizeof(matrix)/sizeof(matrix[0]);
    saveMatrixToFile("data.txt", matrix,rows); 
    return 0;
}
