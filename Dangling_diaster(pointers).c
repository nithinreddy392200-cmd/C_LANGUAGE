#include <stdio.h>

int* get_dangling_pointer() {
    int local_var = 42; 
    return &local_var;  // WARNING: Returning address of local variable
}

int main() {
    int *ptr = get_dangling_pointer();
    
    printf("Attempting to read ptr...\n");
    
    // This might print 42, or it might print 0, or crash.
    // The memory 'local_var' occupied is now "garbage" area.
    printf("Value at ptr: %d\n", *ptr); 

    // Doing something else (like calling another function) 
    // will definitely overwrite that memory.
    printf("After another call, value is: %d\n", *ptr);

    return 0;
}