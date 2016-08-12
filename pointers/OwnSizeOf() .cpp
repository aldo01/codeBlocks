#include<stdio.h>
#define MY_SIZE_OF(type)(char *)(&type+1)-(char *)(&type)
#define DECLARE_A_DATA_TYPE(data_type) __typeof__(data_type) new_variable
int main(){
int  var_int_type;
#if 1
        /*Usecase 1 */
	    /* int_type variable is passed as argument */
	    DECLARE_A_DATA_TYPE(double);   //same as int new_variable

	    /* Prints the size of the data type,Here it is integer data type */
            printf("\nThe size of the Variable is %d\n", MY_SIZE_OF(new_variable));

	#else
	    /*use case 2*/
	    /* a datatype is passed as argument */
	    DECLARE_A_DATA_TYPE(int);          //same as int new_variable

	    /* Prints the size of the data type,Here the data type name int is passed */
	    printf("The size of the Variable is %d\n", MY_SIZE_OF(new_variable));
	#endif

	return 0;
}//main}
