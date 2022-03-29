#include <stdio.h>
typedef int keytype;
typedef float otherkey;
typedef struct {
	keytype key;
	otherkey otherfields;
}recordtype;

void Swap(recordtype *x,recordtype *y){
	recordtype temp = *x;
		       *x = *y;
	           *y = temp;
}

void selectionSort(recordtype a[],int n){
    int i,j,low_index;
    keytype low_key;
		for(i=0;i<n-2;i++){
			low_index = i;
	        low_key = a[i].key;
			for(j=i+1;j<n-1;j++){
				if(a[j].key < low_key){
				     low_key = a[j].key;
					 low_index = j;	
			}	
		}
		Swap(&a[i],&a[low_index]);	
	}
}

void Read_Data(recordtype a[],int *n){
     FILE *f;
	 f =fopen("data.txt","r");
	 int i = 0;
	 if(f!=NULL)
	 while (!feof(f)){
	 	fscanf(f,"%d%f", &a[i].key, &a[i].otherfields);
	 	i++;
	 } else printf("Loi mo file\n");
     fclose(f);
     *n=i;
}

void Print_Data(recordtype a[],int n){
    int i;
	for(i=0;i<n;i++){
		printf("%3d %5d %8.2f\n",i+1,a[i].key,a[i].otherfields);
	}
}

int main(){
	recordtype a[100];
	int n;
    
	printf("Thuat toan selection Sort\n\n");
	Read_Data(a,&n);
	printf("Du lieu truoc khi sap xep:\n");
	Print_Data(a,n);

	selectionSort(a,n);
	printf("Du lieu sau khi sap xep:\n");
	Print_Data(a,n);
	
	return 0;
}
