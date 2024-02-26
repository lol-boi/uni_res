#include <ctype.h>
#include <stdio.h>
int main(){
	char user_input;
    char next_alp;
    char continue_program;
     
    
    while(1){
    	printf("Hi! I'm a clever computer program that knows the alphabet.\nPlease enter a letter:\n");
    	scanf("%c",&user_input);
    	
    	if((user_input>='a' && user_input<='z') || (user_input>='A' && user_input<='Z')){
    		next_alp = ((user_input - 'a' + 1)%26 + 'a');
    		if(user_input>='A' && user_input<='Z'){
    			next_alp -=  'a' - 'A';
    		}
    		printf("The next letter is %c.\n", next_alp);
    		printf("Do you want to enter another letter (y = yes): "); 
            scanf("%c",&continue_program);
    		
            if((continue_program != 'y') && (continue_program != 'Y')){
    			printf("Goodbye!\n");
    			break;
            }else{
    			printf("Invalid input. PLease enter a single letter.\n");
            }
    			
    			
		}
	} 
		   return 0;
    		
}
