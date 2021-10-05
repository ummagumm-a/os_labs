#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* my_realloc(void* p, size_t size)
{
    if (p == NULL)
        return malloc(size);
    if (size == 0)
        free(p);

    void* np = malloc(size);
    memcpy(np, p, size);

    return np;
}

int main(){

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size: ");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = (int*) malloc(n1 * sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = (int*) my_realloc(a1, n2 * sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

//    for (int i = n1; i < n2; ++i)
//        a1[i] = 0;
	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	printf("\n");

    free(a1);
	
	return 0;
}
