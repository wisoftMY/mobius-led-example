#include <wiringPi.h>
#include <stdio.h>
#include <string.h>

#define LED_PIN 7

int turn_on_led(){
	printf("%s\n", "Light ON!");
	digitalWrite(LED_PIN, HIGH); 
	
	return 0;
}

int turn_off_led(){
	printf("%s\n", "Light OFF!");
	digitalWrite(LED_PIN, LOW); 
	
	return 0;
}

int main (int argc,char *argv[])
{
	int i;
    	for (i=0; i < argc; i++)
        	printf("Argument %d is %s\n", i, argv[i]);
	
	wiringPiSetup() ;
	pinMode(LED_PIN, OUTPUT) ;

	if(argc == 2){
		char* comm = argv[1];
		
		if(strcmp(comm, "0") == 0){
			turn_off_led();
		} else if(strcmp(comm, "1") == 0){
			turn_on_led();
		}
	}

	return 0 ;
}
