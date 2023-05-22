#include <stdio.h>
#include <math.h>
#define eps 0.00001


char *dvostruko(char *b)
{
	int broj=0;
	char *poc=b;
	while(*b!='\0')
	{
		int h=0,bb=0,bb1;
		long long int sum=0,novibr=0;
		if(*b>'0' && *b<='9')//trazi karakter koji je veci od nule medjutim ako je broj negativan on ce preskociti taj minus tj ostat ce karakter
		{
		while(*(b+h)>='0' && *(b+h)<='9')
		{
			broj=*(b+h)-48;//uzima karakter koji je u stringu u asci vrijednosti i da bi dobili stvarnu vrijednost broja oduzmemo 48
			sum=sum*10+broj;
			h++;
		}
		char *f=(b+h);//pokazivac na mjesto iza zadnje cifre
		char *g=(b+h);//pokazivac na mjesto iza zadnje cifre
		sum=sum*2;
		novibr=sum;
		while(novibr>0)
		{
			novibr=novibr/10;
			bb++;
		}
		if(fabs(bb-h)<eps)//za brojeve koji ne prelaze broj cifri starog broja
		{
			while(sum>0)
			{
				bb1=sum%10;
				bb1=bb1+48;
				*(b+(h-1))=bb1;
				h--;
				sum=sum/10;
			}
		}
		else if((bb-h)>eps)
		{
			while(*f!='\0')//funkcija da se dovede pokazivac na kraj stringa da bi mogli prosiriti string
			{
				f++;
			}
			while(f>=(b+h))//funkcija koja prosiruje string za onoliko mjesta koliko je veci novi broj nego stari
			{
				*(f+1)=*f;
				f--;
			}
			while(h>=0)//pomocu while-a vracamo novi broj u string
			{
				bb1=sum%10;
				bb1=bb1+48;
				*(b+h)=bb1;
				sum=sum/10;
				h--;
			}
		}
		b=g;//postavljanje glavnog pokazivaca na mjesto kraja novog broja
		}
		++b;


	}

	return poc;
}
int main() {
	char tekst[1000]="9999 jesu 212 1 1 3300 000.010.0";
	printf("'%s'",dvostruko(tekst));
	return 0;
}
