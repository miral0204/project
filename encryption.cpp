#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int pass=9999;
void ceasercypher();
void vernam();
void password();
int main()
{
	int choice;
	
	printf("SELECT THE ALGORITHM YOU WANT TO USE FOR ENCRYPTING YOUR MESSAGE\n");
	printf("1.Using ceaser cypher Algorithm\n");
	printf("2.Using vernam Algorithm (ONE TIME PAD)\n");
	printf("3.Using Pin password\n");
	printf("enter ur choice");
	scanf("%d",&choice);
	fflush(stdin);
	
	switch(choice)
	{
		case 1:
			{
				ceasercypher();
				break;
			}
		case 2:
			{
				vernam();
				break;
			}
		case 3:
			{
				password();
				break;
			}
		case 4:
			{
				printf("Invalid choice");
				break;
			}
			
		
	}
	return 0;
}
void ceasercypher()
{
	char ch;
	int key;
	char msg[100];
	
	printf("Enter the message to be encrypted...");
	gets(msg);
	printf("Enter the key ");
	scanf("%d",&key);
	
    printf("The encrypted message is :\n");
	for(int i=0;msg[i]!='\0';i++)
	{
		ch=msg[i];
		if(ch>='a' && ch<='z')
		{
			ch=ch+key;
				if(ch>'z')
			{
				ch=ch-'z'+'a'-1;
			}
			
		msg[i]=ch;
		}
		if(msg[i]>='A' && msg[i]<='Z')
		{
			ch=ch+key;
			if(ch>'Z')
			{
				ch=ch-'Z'+'A'-1;
			}
			
		msg[i]=ch;
		
		}
		
	}
	printf("ENCRYPTED MESSAGE IS %s\n",msg);
	
	printf("The decrypted message is:\n");
	for(int i=0;msg[i]!='\0';i++)
	{
		ch=msg[i];
		if(ch >= 'a' && ch <= 'z')
		{
			ch = ch-key;
            if(ch < 'a')
			{
				ch = ch+'z'-'a'+1;
			}
			msg[i]= ch;
		}
		else if(ch >= 'A' && ch <= 'Z')
		{
			ch =ch-key;
			if(ch < 'A')
			{
				ch =ch+'Z'-'A'+1;
			}					
			msg[i] = ch;
		}
    }
		printf("THE DECRYPTED MESSAGE IS %s",msg);	
}	
void vernam()
{
 int i,j,len1,len2,numstr[100],numkey[100],numcipher[100];
 char str[100],key[100],cipher[100];
 printf("Enter a string text to encrypt using vernam algorithm\n");
 gets(str);
 for(i=0,j=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  {
   str[j]=toupper(str[i]);   //same array store in upper case removing blank spaces
   j++;
  }
 }
 str[j]='\0';
 
 //obtaining numerical plain text ex A-0,B-1,C-2,..
    for(i=0;i<strlen(str);i++)
    {
     numstr[i]=str[i]-'A';    
    }   
    
    printf("Enter key string \n");
    gets(key);
 for(i=0,j=0;i<strlen(key);i++)
 {
  if(key[i]!=' ')
  {
   key[j]=toupper(key[i]);   
   j++;
  }
 }
 key[j]='\0';
 //obtaining numerical one time pad(OTP) or key
    for(i=0;i<strlen(key);i++)
    {
     numkey[i]=key[i]-'A';    
    }  
    
    for(i=0;i<strlen(str);i++)
    {
     numcipher[i]=numstr[i]+numkey[i];
    }
    //To loop the number within 25 i.e if addition of numstr and numkey is 27 then numcipher should be 1
    for(i=0;i<strlen(str);i++)
    {
     if(numcipher[i]>25)
     {
      numcipher[i]=numcipher[i]-26;
     }
    }
    printf("One Time Pad Cipher(OTP) text is\n");
    for(i=0;i<strlen(str);i++)
    {
      printf("%c",(numcipher[i]+'A')); 
    }
    printf("\n");

}
void password()
{
	char ch;
	int key;
	int p;
	char msg[100];
	
	printf("Enter the message to be encrypted...");
	gets(msg);
	printf("Enter the key ");
	scanf("%d",&key);
	
    printf("The encrypted message is :\n");
	for(int i=0;msg[i]!='\0';i++)
	{
		ch=msg[i];
		if(ch>='a' && ch<='z')
		{
			ch=ch+key;
				if(ch>'z')
			{
				ch=ch-'z'+'a'-1;
			}
			
		msg[i]=ch;
		}
		if(msg[i]>='A' && msg[i]<='Z')
		{
			ch=ch+key;
			if(ch>'Z')
			{
				ch=ch-'Z'+'A'-1;
			}
			
		msg[i]=ch;
		
		}
		
	}
	printf("ENCRYPTED MESSAGE IS %s\n",msg);
	
	printf("Enter password to decrypt the message");
	scanf("%d",&p);
	if(p==pass)
	  {
	
	    for(int i=0;msg[i]!='\0';i++)
	    {
		ch=msg[i];
		  if(ch >= 'a' && ch <= 'z')
		  {
			ch = ch-key;
            if(ch < 'a')
			{
				ch = ch+'z'-'a'+1;
			}
			msg[i]= ch;
	      }
		    else if(ch >= 'A' && ch <= 'Z')
	        {   
			ch =ch-key;
			if(ch < 'A')
			{
				ch =ch+'Z'-'A'+1;
			}					
			msg[i] = ch;
			}     
   		 }	     	  
		printf("THE DECRYPTED MESSAGE IS %s",msg);	
}
    else
    {
    	printf("Incorrect password");
	}
}