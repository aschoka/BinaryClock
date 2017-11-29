#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


int binconvert(int);
int main (void)
{


if (wiringPiSetup () == -1)
        exit (1);

//Set All Pin Modes to Output
int i;
for ( i = 0; i < 32; i++)
{
        pinMode(i,OUTPUT);
}

//Set All Pin Values to LOW (Off)
int k;
for ( k = 0; k < 32; k++)
{
        digitalWrite(k,LOW);
}

//Prompt User for Current Time
char time[10];
char *hour;
char *min;
char *sec;
const char s[2] = ":";

printf("Enter the Current Time (HH:MM:SS) : ");
fgets(time, sizeof(time),stdin);

hour = strtok( time, s );
min  = strtok( NULL, s);
sec = strtok( NULL, s);

int mint = atoi(min);
int hourt = atoi(hour);
int sect = atoi(sec);

//MAIN CLOCK FUNCTION
do {
        //Set Hour and Minute Pins to Current Values
        int binhour = binconvert(hourt);
        int binmin = binconvert(mint);
        int binsec = binconvert(sect);

        int hourarr[7];
        int minarr[9];
        int secarr[9];

        //DEBUGGING Print Current Time Code
        printf("H: %d   M: %d   S: %d   \n",binhour,binmin,binsec);

        //Hour Pins (WPi Pins 0,1,2,3,4)
        int d;
        int r;
        int one = binhour;
        for ( d = 0; d < 5; d++ )
        {
                r = ( one % 10 );
                hourarr[d] = r;
                one /= 10;
                digitalWrite(d,r);
        }

        //Minute Pins (WPi Pins 5,6,7,8,9,10)
        int e;
        int s;
        int x = 5;
        int two = binmin;
        for ( e = 0; e < 6; e++ )
        {
                s = ( two % 10 );
                minarr[e] = s;
                two /= 10;
                digitalWrite(x,s);
                x++;
        }

        //Second Pins (WPi Pins 11,12,13,14,15,16)
        int f;
        int t;
        int y = 11;
        int three = binsec;
        for ( f = 0; f < 6; f++ )
        {
                t = ( three % 10 );
                secarr[f] = t;
                three /= 10;
                digitalWrite(y,t);
                y++;
        }

        //Clock Digit Increment Code
        if ( sect < 60 )
        {
                sect++;
        }
        else
        {
                sect = 0;
                if ( mint < 60 )
                {
                        mint++;
                }
                else
                {
                        mint = 0;
                        if ( hourt < 24 )
                        {
                       {
                                hourt++;
                        }
                        else
                        {
                                hourt = 0;
                        }
                }
        }

        //Delay Code
        delay (950);

} while(wiringPiSetup () != 1);



return 0;
}

int binconvert(int dig)
{
        if ( dig == 0)
        {
                return 0;
        }
        else
        {
                return (dig % 2 + 10 * binconvert(dig / 2));
        }
}



