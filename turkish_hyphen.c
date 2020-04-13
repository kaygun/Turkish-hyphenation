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

#define DASH            45

#define MAX_WORD 256

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
	return(1);
	break;
      default         :
	return(0);
	break;
   }
 }

char *hyphen(unsigned char *word) { 
  unsigned short int i = 0, j = 0, flag = 0, dash = 0;
  char *ret;

  ret = (char *)malloc(MAX_WORD);
  if(ret == NULL) {
    fprintf(stderr,"Can't allocate memory for hyphen!?\n");
    exit(1);
  }
  bzero(ret,MAX_WORD);

  while(word[i+1] != '\0' && i < MAX_WORD-1) { 
    if(isvowel(word[i])) { 
      dash = isvowel(word[i+1]) || isvowel(word[i+2]);
      flag = 0;
    }
    else {
      if(flag) {
	dash = !isvowel(word[i+1]);
        if(!dash)
           ret[j++] = DASH;
      }
      flag = 1 - flag;
    }
    
    ret[j++] = word[i++];
    if(dash)
      ret[j++] = DASH;
    dash = 0;
  }
  ret[j++] = word[i];

  return(ret);
}
