#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<malloc.h>

#define K_AGAH          226
#define K_CANKIRI       231
#define K_AGRI          240
#define K_IHLARA        253
#define K_ISTANBUL      105
#define K_ILMI          238
#define K_ODEMIS        246
#define K_SEHREMINI     254
#define K_URGUP         252
#define AGAH            194
#define CANKIRI         199
#define AGRI            208
#define IHLARA          73
#define ISTANBUL        221
#define ILMI            206
#define ODEMIS          214
#define SEHREMINI       222
#define URGUP           220

#define TAB             9
#define NEWLINE		10
#define SPACE		32
#define APPOSTROFF	39
#define DASH            45

#define CONSONANT     0
#define VOWEL         1

#define YES           1
#define NO            0

#define MAX_WORD 256

#define CONSONANT     0
#define VOWEL         1

#define YES           1
#define NO            0

int isvowel(unsigned char c) {  
   switch(c) {  
      case 'a'        :
      case K_AGAH     :
      case 'e'        :
      case K_IHLARA   :
      case K_ISTANBUL :
      case K_ILMI     :
      case 'o'        :
      case 'u'        :
      case K_URGUP    :
      case K_ODEMIS   :
      case AGAH       :
      case 'A'        :
      case 'E'        :
      case IHLARA     :
      case ISTANBUL   :
      case ILMI       :
      case 'O'        :
      case 'U'        :
      case URGUP      :
      case ODEMIS     :
	return VOWEL;
	break;
      default         :
	return CONSONANT;
	break;
   }
 }

char *hyphen(unsigned char *word) { 
  unsigned short int i=0,j=0,flag=0,dash=NO;
  char *ret;

  ret = (char *)malloc(MAX_WORD);
  if(ret == NULL) {
    fprintf(stderr,"Can't allocate memory for hyphen!?\n");
    exit(1);
  }
  bzero(ret,MAX_WORD);

  while(word[i+1]!='\0' && i<MAX_WORD-1) { 
    if(isvowel(word[i])) { 
      if(isvowel(word[i+1]))
	dash=YES;
      else 
	if(isvowel(word[i+2]))
	  dash=YES;
      flag=0;
    }
    else
      if(!flag)
	flag=1;
      else {  
        if(!isvowel(word[i+1]))
	   dash=YES;
        else { 
           ret[j++]=DASH;
	   dash=NO;
        }
	flag=0;
      }
    ret[j++] = word[i++];
    if(dash==YES)
      ret[j++] = DASH;
    dash=NO;
  }
  ret[j++] = word[i];

  return(ret);
}
