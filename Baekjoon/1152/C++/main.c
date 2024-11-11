#include <stdio.h>

int main() {
    char str[1000001];
    int i = 0;
    int count = 0;
    
    fgets(str, sizeof(str), stdin); 
    
    
    if(str[0]!=' '){
    	count++;
	}
	
	if(str[0]=='\n'){
		count=0;
		printf("%d",count);
		return 0;
	}
    
    while (str[i] != '\0' && i <1000001) { 

		if (str[i] == ' ' && (str[i+1] >= 'A' && str[i+1] <= 'z')) {
            count++;
        }
        
        
        i++;
    }
    
    printf("%d\n", count); 
    

    
    
    return 0;
}

