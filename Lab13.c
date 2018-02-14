#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100
	
	typedef struct{
		int xx;
		int yy;
		int zz; 
		int mm;
		char nickname[SIZE];
	} address_t;

void scan_address(address_t alladd[]);
void print_address(address_t alladd[]);
int local_address(address_t add1, address_t add2);

int main (){
	
	address_t alladd[SIZE];
	scan_address(alladd);
	print_address(alladd);
	address_t add1 = alladd[0];
	address_t add2 = alladd[1];
	local_address(add1, add2);
	printf("Enter two nicknames\n");
	int i;
	int z;
	char j[40];
	char k[40];
	for(i = 0; i < SIZE; i++){
	    scanf("%s %s", j, k);
	    for(z = 0; z < SIZE; z++){
	        if(strcmp(j, alladd[z].nickname) == 0){
	            add1 =  alladd[z];
	        }
	        if(strcmp(k, alladd[z].nickname) == 0){
	            add2 = alladd[z];
	        }
	    }
	    if(local_address(add1, add2) == 1){
	    printf("Machine %s and %s are on the same local network\n", &(add1.nickname), &(add2.nickname));
	    }
	    
	}
	return 0;
}
void scan_address(address_t alladd[]){
	int i;
	FILE *in;
	in = fopen("SampleData.txt", "r");
	for(i = 0; i < SIZE; i++){
		fscanf(in, "%d.%d.%d.%d %s", &(alladd[i].xx), &(alladd[i].yy), &(alladd[i].zz), &(alladd[i].mm), &(alladd[i].nickname));
	}
	fclose(in);
}
void print_address(address_t alladd[]){
	
	int i;
	for(i = 0; i < SIZE; i++){
	    printf("%d.%d.%d.%d %s\n", alladd[i].xx, alladd[i].yy, alladd[i].zz, alladd[i].mm, alladd[i].nickname);
	}
}
int local_address(address_t add1, address_t add2){
	int i;
	
	if(add1.xx  == add1.xx && add1.yy == add2.yy){
	   
	    return 1;
	}
	else{
		return 0;
	}
}


