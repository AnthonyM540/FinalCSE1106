#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#define PIN 17

int getChoice();
double getTemp();
int checkTemp(double temp, double low, double high);
void saveTemp(double temp, int warning);
void seeAverage(double total, int count);

int main(int argc, char* argv[]){
double temp;
double low =68.0;
double high =76.0;
double total = 0;
int count =0;
int choice;
int warning;

gpioInitialise();
	gpioSetMode(PIN,PI_OUTPUT);
	gpioWrite(PIN,0);
do{
	printf("\n===== Classroom Comfort Monitor =====\n");
	printf("1. Enter Temperature \n");
	printf("2. Change Temperature Range\n");
	printf("3. Display average temperature\n");
	printf("4. Exit\n");
	printf("Enter Choice: ");
	choice = getChoice();
	
	switch (choice){
		case 1:
		printf("Enter temperature in Fahrenheit: ");
		temp = getTemp();
		total =total + temp;
		count++;
		if(warning ==1){
			printf("Warning\n");
			gpioWrite(PIN,1);
		}
		else{
			printf("Normal\n");
			gpioWrite(PIN,0);
		}
		saveTemp(temp,warning);
		break;
		case 2:
		printf("Enter new minimum temperature: ");
		low = getTemp();
		
		printf("Enter new maximum temperature: ");
		high = getTemp();
		
		if(low >= high){
			printf("Invalid range");	

	
