#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "HeaderFile.h"



int TableToNumber(int numbers[] , int length){
    int i ,temp=0;
    length--;
    for (i=0 ; i <= length ; i++){
        temp =  temp + (int)( numbers[i] * ( pow(10,length - i) ) )  ; // metatroph se dekadiko arithmo apo ton pinaka
    }
    return temp;
}




void CheckIfSolution (char newString[][11]  , int length1 , int length2 , int length3 , char Letters[] , int numbers[]){
    int i , x;

    //~~~Arxikopoihsh Pinaka Arithmwn 1 ~~~
    i=0, x=0;
    int  numbers1[length1] ; //desmeyw enan pinaka osa kai ta grammata ths lekshs
    while (i<length1){
        if (newString[0][i] == Letters[x]){
        	numbers1[i] = numbers[x];
        	x=0;
        	i++;                                                // BRISKW THN ANTISTOIXIA TWN ARITHMWM ME TA GRAMMATA
		}
		else {
			x++;
		}
    }

    //~~~Arxikopoihsh Pinaka Arithmwn 2 ~~~
    i=0, x=0;
    int  numbers2[length2] ; //desmeyw enan pinaka osa kai ta grammata ths lekshs
    while (i<length2){
        if (newString[1][i] == Letters[x]){
        	numbers2[i] = numbers[x];
        	x=0;
        	i++;
		}
		else {
			x++;
		}
    }

    //~~~Arxikopoihsh Pinaka Arithmwn 3 ~~~
    i=0, x=0;
    int  numbers3[length3] ; //desmeyw enan pinaka osa kai ta grammata ths lekshs
    while (i<length3){
        if (newString[2][i] == Letters[x]){
        	numbers3[i] = numbers[x];
        	x=0;
        	i++;
		}
		else {
			x++;
		}
    }

    //~~~ Telos Arxikopoihsewn ~~~


    int n1 =TableToNumber(numbers1 ,length1);
    int n2 =TableToNumber(numbers2 ,length2);
    int n3 =TableToNumber(numbers3 ,length3);   
   	//printf("n1 = %d , n2 = %d , n3 = %d \n" , n1 ,n2 , n3);
   	
    if (n1 + n2 == n3 ){  
        //printf("One Solution is : \n");
        PrintAllTheList(Letters, numbers);
    }
    

}

void PrintAllTheList (char Letters[] , int numbers[] ){

    int i=0 ; 
	
   	for (i=0 ; i<10 ; i++){
   	    if (Letters[i] != '#'){
   			 printf("%c  =   %d   " , Letters[i] , numbers[i]);
	    }
	}  
    printf("\n");
    printf("----------------------------------------------------------------------------------------------------\n");
}




// The function below switch elements i and j from the array T given
int* _switch(int* T,int i,int j){
	
	int Temp=T[i];
	T[i]=T[j];
	T[j]=Temp;
	return T;

}
// The function below prints the array given as parameter

void print_array(int* T,int len_T){
	int i;
	for(i=0;i<len_T;i++)
		printf("%d ", T[i]);
	
	printf("\n");
}


/*
	This function is recursive. it returns all combinations
	The pivot is the first element which will be switched with all elements after
	example: for T={0,1,2,3} with 1 as pivot, means that 1 will be switched with 2 and 3 (as result: {0,2,1,3} and {0,3,2,1} )
	the function calls itself with the same array, and the pivot moved to the right.
	
*/


void combination(int* T,int len_T,int pivot /*used for the CheckIfSol-> */, char newString[][11]  , int length1 , int length2 , int length3 , char Letters[]){
	
	if(pivot==0){
		CheckIfSolution (newString , length1 , length2 , length3 , Letters , T);
			//print_array(T,len_T);
	}
	
	
	if(pivot<len_T-1){
		combination(T, len_T ,pivot+1, newString , length1 ,length2 ,length3 , Letters );
		int j;
		
		for(j=pivot+1;j<10;j++){

			T=_switch(T,pivot,j);
			
			CheckIfSolution (newString , length1 , length2 , length3 , Letters , T);
		    //	print_array(T,len_T);
			
			combination(T, len_T ,pivot+1, newString , length1 ,length2 ,length3 , Letters );
			T=_switch(T,j,pivot);

		}

	}

}


void Cryptography(void){            

    char word[100];
    char newString[3][11]; // tha dwsei 3 lekshs max megethoys 10 xarakthrws +1 to \0
    int i,j,ctr;
    
    printf(" Input  a string : ");
    fgets(word, sizeof word, stdin);	
 
    j=0; ctr=0;
    for(i=0;i<=(strlen(word));i++)
    {
        // if + or = or NULL found, assign NULL into newString[ctr]
        if(word[i]=='+'||word[i]=='=' ||word[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
        	if(word[i]!=' '){	// An o xarakthras den einai to keno
        		newString[ctr][j]=word[i];
            	j++;	
			}
            
        }
    }
        printf("\n Strings or words after spliting are :\n");
        printf(" %s\n",newString[0]);
        printf(" %s\n",newString[1]);
        printf(" %s\n",newString[2]);


    char Letters[10]; // max 10 giati oi arithmoi poy mporei na antistixistei ena gramma einai 0-9 
    int  x , count , found ;
    
    for (x=0;x<10;x++){
    	Letters[x]= '#';			//arxikopoihsh pinaka me #
	}

    i = 0 ;		                 // metablhth gia to perasma olhs ths word
    count = 0 ;	                 // grammata ksexwrista poy brethikan
    while (word[i] != '\0' ) {   // Oso den exei teleiwsei h leksh  kai den einai to keno h to + h to =
	    x = 0;		             // metablhth gia to perasma toy Letters
        found = 0 ;
        while (x < count && found == 0){      // Elegxos an yparxei hdh stin lista to stoixeio
		    if (word[i] == Letters[x]){
                found = 1;                    // logikh metablhth - to gramma yparxei hdh stin lista
            }
            x++; 
        }
        if (found == 0 && word[i] != ' ' && word[i] != '+' && word[i] != '=' && word[i] != '\n') {   // An den yparxei ston pinaka , den einai keno , + , = ,\n
            Letters[count] = word[i];
            count++;
        }
        
    	i++;
	}
    //printf("The letters is = %s\n", Letters);
    
    // count = POSA KSEXWRISTA GRAMMATA YPARXOYN
    //printf("Ksexwrista Gramma = %d" , count);
    
    int length1 , length2 , length3 ;
   
    length1 = strlen(newString[0]);            
    length2 = strlen(newString[1]);             // krataw to megethos twn 3 leksewn
    length3 = strlen(newString[2]) ;
    length3 --;     // ypologize ena parapanw xarakthra sto 3o

    //printf("Length1 = %d , Length2 = %d , Length3 = %d  \n", length1 , length2 , length3);

    int numbers[]={0,1,2,3,4,5,6,7,8,9};  // Arxikopoihsh pinaka me noymera - The array that we would find all combinations
	int START_PIVOT=0;    
    
    printf("The Solutions are : \n");
	combination(numbers, count+1 ,START_PIVOT, newString , length1 ,length2 ,length3 , Letters );

    printf("\n");
    printf("\n");
    printf("\n");
    printf("PROGRAM ENDED SUCCESSFULLY\n");

}