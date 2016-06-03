#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* ConcatenateArrays(char* arrayA, int arrayASize,
                       char* arrayB, int arrayBSize,
                       int pos)
{
    int maxsize = arrayASize+arrayBSize;
    char* newarray = (char*)calloc(maxsize, sizeof(char));

    for(int i=0; i<pos; i++)
        newarray[i] = arrayA[i];

    for(int i=pos,j=0; j<arrayBSize && i<maxsize; j++,i++)
        newarray[i] = arrayB[j];

    for(int i=pos+arrayBSize, j=pos; i<maxsize; i++, j++)
        newarray[i] = arrayA[j];

    return newarray;

}

char* ConcatenateArrays_2(char* arrayA, int arrayASize,
                       char* arrayB, int arrayBSize,
					   char* arrayC, int arrayCSize,
                       int pos1, int pos2)
{
    int maxsize = arrayASize+arrayBSize+arrayCSize;
    char* newarray = (char*)calloc(maxsize, sizeof(char));

    for(int i=0; i<pos1; i++)
        newarray[i] = arrayA[i];

    for(int i=pos1,j=0; j<arrayBSize && i<maxsize; j++,i++)
        newarray[i] = arrayB[j];

    for(int i=pos1+pos2, k=0; k<arrayCSize && i<maxsize; k++, i++)
        newarray[i] = arrayC[k];

    return newarray;

}

char* ConcatenateArrays_3(char* arrayA, int arrayASize,
                       char* arrayB, int arrayBSize,
                       char* arrayC, int arrayCSize,
                       char* arrayD, int arrayDSize,
                       int pos1, int pos2, int pos3)
{
    int maxsize = arrayASize+arrayBSize+arrayCSize+arrayDSize;
    char* newarray = (char*)calloc(maxsize, sizeof(char));

    for(int i=0; i<pos1; i++)
        newarray[i] = arrayA[i];

    for(int i=pos1,j=0; j<arrayBSize && i<maxsize; j++,i++)
        newarray[i] = arrayB[j];

    for(int i=pos1+pos2, k=0; k<arrayCSize && i<maxsize; k++, i++)
        newarray[i] = arrayC[k];
    for(int i=pos1+pos2+pos3, q=0; q<arrayDSize && i<maxsize; q++, i++)
    	newarray[i] = arrayD[q];
    

    return newarray;

}




int main()
{
	char chislo[10];
	char ch='0';
	for (int i=0; i<10; i++)
	{
		chislo[i]=ch;
		ch++;
	}
	char letters_up[26];
	ch='A';
	for (int i=0; i<26; i++)
	{
		letters_up[i]=ch;
		ch++;
	}
	char letters_dn[26];
	ch='a';
	for (int i=0; i<26; i++)
	{
		letters_dn[i]=ch;
		ch++;
	}
	char symbol[31]={' ','!','"','#','$','%','&','`','(',')','*','+',',','-','.','/',':',';','<','=','>','?','@','[',']','|','^','_','{','}','~'};
	
	int c=10, l=26, s=31;
	int sum=0;
	
    
    char* all_1= ConcatenateArrays(chislo,10, letters_up,26,10);
    
    char* all_2= ConcatenateArrays(chislo,10, letters_dn,26,10);
    
    char* all_3= ConcatenateArrays(chislo,10, symbol,36,10);
    
    char* all_4= ConcatenateArrays(letters_up,26, letters_dn,26,26);

    char* all_5= ConcatenateArrays(letters_up,26, symbol,31,26);
   
    char* all_6= ConcatenateArrays(letters_dn,26, symbol,31,26);
  
    char* all_7= ConcatenateArrays_2(chislo,10, letters_up,26, letters_dn, 26 ,10, 26);
  
    char* all_8= ConcatenateArrays_2(chislo,10, letters_up,26, symbol, 31 ,10, 26);
   
    char* all_9= ConcatenateArrays_2(chislo,10, letters_dn,26, symbol, 31 ,10, 26);
   
    char* all_10= ConcatenateArrays_3(chislo,10, letters_up,26, letters_dn,26, symbol, 31 ,10, 26,26);
   
    int n=0;
    printf("Please enter the length of your password: ");
    scanf("%d", &n);
    char *out_arr =  (char*)calloc(n, sizeof(char));;
    srand(time(NULL));
    
    
    if ((n>=6) && (n<=128))
	{
   
	    printf ("\nPlease type the answer: \n1. Numbers \n2. Uppercase letters \n3. Lowercase letters \n4. Symbols \n5. Numbers and uppercase letters \n6. Numbers and lowercase letters \n7. Numbers and symbols \n8. Uppercase and lowercase letters \n9. Uppercase letters and symbols \n10. Lowercase letters and symbols \n11. Numbers, uppercase letters and lowercase letters \n12. Numbers, uppercase letters and symbols \n13. Numbers, lowercase letters and symbols \n14. Numbers, uppercase letters, lowercase letters and symbols\n");
	    int m;
	    printf("\nYour choice:");
	    scanf("%d", &m);
		
		if (m == 1)
		{
			sum=c;
			for (int i=0; i<n; i++)
			{
				out_arr[i]=chislo[rand() % sum];
				printf("%c", out_arr[i]);
			}
		}
		else if (m == 2)
		{
			sum=l;
			for (int i=0; i<n; i++)
			{
				out_arr[i]=letters_up[rand() % sum];
				printf("%c ", out_arr[i]);
			}
		}
		else if (m == 3)
		{
			sum=l;
			for (int i=0; i<n; i++)
			{
				out_arr[i]=letters_dn[rand() % sum];
				printf("%c ", out_arr[i]);
			}
		}
		else if (m == 4)
		{
			sum=s;
			for (int i=0; i<n; i++)
			{
				out_arr[i]=symbol[rand() % sum];
				printf("%c ", out_arr[i]);
			}
		}
		else if (m == 5)
		{
		   	sum=c+l;
		   	for (int i=0; i<n; i++)
			{
		   		out_arr[i]=all_1[rand() % sum];
		   		printf("%c ", out_arr[i]);
			}
		}
	   else if (m == 6)
	    {
	    	sum=c+l;
	    	for (int i=0; i<n; i++)
	    	{
	    		out_arr[i]=all_2[rand() % sum];
	    		printf("%c ", out_arr[i]);
			}
	    }
	    else if (m == 7)
	    {
	    	sum=c+s;
	    	for (int i=0; i<n; i++)
	    	{
	    		out_arr[i]=all_3[rand() % sum];
	    		printf("%c ", out_arr[i]);
			}
	    }
	    else if (m == 8)
	    {
	    	sum=2*l;
	    	for (int i=0; i<n; i++)
	    	{
	    		out_arr[i]=all_4[rand() % sum];
	    		printf("%c ", out_arr[i]);
			}
	    }
	    else if (m == 9)
	    {
	    	sum=l+s;
	    	for (int i=0; i<n; i++)
	    	{
	    		out_arr[i]=all_5[rand() % sum];
	    		printf("%c ", out_arr[i]);
			}
	    }
	    else if (m == 10)
	    {
	    	sum=l+s;
	    	for (int i=0; i<n; i++)
	    	{
	    		out_arr[i]=all_6[rand() % sum];
	    		printf("%c ", out_arr[i]);
			}
	    }
		else if (m == 11)
		{
			sum=n+l+l;
			for (int i=0; i<n; i++)
			{
				out_arr[i]=all_7[rand() % sum];
	    		printf("%c ", out_arr[i]);
			}
		}
	    else if (m == 12)
		{
			sum=n+l+s;
			for (int i=0; i<n; i++)
			{
				out_arr[i]=all_8[rand() % sum];
	    		printf("%c ", out_arr[i]);
			}
		}
	    else if (m == 13)
		{
			sum=n+l+s;
			for (int i=0; i<n; i++)
			{
				out_arr[i]=all_9[rand() % sum];
	    		printf("%c ", out_arr[i]);
			}
		}	    
		else if (m == 14)
		{
			sum=n+l+l+s;
			for (int i=0; i<n; i++)
			{
				out_arr[i]=all_10[rand() % sum];
	    		printf("%c", out_arr[i]);
			}
		}
	}
	else 
	{
		printf ("ERROR");
	}
	

	return 0;
}
