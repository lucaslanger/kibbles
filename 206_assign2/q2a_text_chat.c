#include<stdio.h>
#include<string.h>

int getFileSize(FILE *f){
	int read_code;
	int i=0;
	while( ( read_code = fgetc( f )) != EOF ){
		i=i+1;	
	}	
	return i;

}

int main(int argc, char *argv[]){
	FILE *in = NULL;
	FILE *out = NULL;
	const int max_msg_size = 1000;

	int reading=0;
	int read_code;
	
	char fileContents[max_msg_size];
	char *chatHandle = argv[3];
	
	in = fopen( argv[1], "r" );
	if( in == NULL ){
		printf( "Nothing recieved yet.\n" );
	}
	else{
		int p=0;
		while( ( read_code = fgetc( in )) != EOF ){
			char c = (char) read_code;
			fileContents[p]=c;
			p=p+1;
		}
		fileContents[p]='\0';
		if (p==0){
			printf("Nothing recieved yet.\n");
		}
		else{
			printf("Received %s\n",fileContents);
		}
	}
	fclose(in);

	while(1){
		if (reading==1){
			int sameFile=1;
			while(reading==1){
				in = fopen( argv[1], "r" );
				int p=0;
				while( ( read_code = fgetc( in )) != EOF ){
					char c = (char) read_code;
					if (c!=fileContents[p]){
						sameFile=0;
					}
					fileContents[p]=c;
					p=p+1;
				}
				fileContents[p]='\0';
				if (sameFile==0){
					printf("Recieved %s\n",fileContents);
					reading=0;
				}
				
				fclose(in);
			}
		}
		else{
			char message[100];
			printf("Send: ");
			fgets(message,100,stdin);
		
			int len = strlen(message);
			if (len > 0 && message[len-1] == '\n'){
  				message[len-1] = '\0';
			}
			
			out = fopen( argv[2], "w");
			
			int i=0;						
			fputc('[',out);
			while(i<strlen(chatHandle)){
				char ch=chatHandle[i];
				fputc(ch, out);
				i=i+1;
			}
			fputc(']',out);

			i=0;
			while(i<strlen(message)){
				char ch=message[i];
				fputc(ch, out);
				i=i+1;
			}

			fclose(out);
			
			reading=1;
			fflush(stdout);
		}
	}
	
}
