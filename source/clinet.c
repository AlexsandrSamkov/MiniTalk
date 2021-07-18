// #include "../includes/client.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#define ONE		0b00000001
#define TWO		0b00000010
#define THREE	0b00000100
#define FOUR	0b00001000
#define FIVE	0b00010000
#define SIX		0b00100000
#define SEVEN	0b01000000
#define EGHIT	0b10000000


void go_sig(pid_t pid,char n)
{
	if (n)
		kill(pid,SIGUSR1);
	else	
		kill(pid,SIGUSR2);
	usleep(50);
}



void decoder(char *s)
{
	char c = 0;
	if (s[0] == '1')
		c |= ONE;
	if (s[1] == '1')
		c |= TWO;
	if (s[2] == '1')
		c |= THREE;
	if (s[3] == '1')
		c |= FOUR;			
	if (s[4] == '1')
		c |= FIVE;
	if (s[5] == '1')
		c |= SIX;	
	if (s[6] == '1')
		c |= SEVEN;	
	if (s[7] == '1')
		c |= EGHIT;		
	printf("%c",c);	
}

void coder(pid_t pid, char c)
{
	go_sig(pid,(int)(c & ONE));
	go_sig(pid,(int)(c & TWO));
	go_sig(pid,(int)(c & THREE));
	go_sig(pid,(int)(c & FOUR));
	go_sig(pid,(int)(c & FIVE));
	go_sig(pid,(int)(c & SIX));
	go_sig(pid,(int)(c & SEVEN));
	go_sig(pid,(int)(c & EGHIT));
}

int main()
{
	decoder("00001100");
	
}