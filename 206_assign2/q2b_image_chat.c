#include <stdio.h>
#include <string.h>

char* decodeMessage(char *f){
	const int bmp_header_size = 54;
	const int max_msg_size = 1000;

	int i;
	int c;
	int img_idx = 0;
	int msg_idx = 0;
	int bit_idx = 0;

	char msg[max_msg_size];
	FILE *img_in = NULL;
	
	img_in = fopen( f, "rb" );

	if( img_in == NULL ){
		printf( "Could not open the input image file.\n" );
	}

	for( i=0; i < max_msg_size; i++ )
		msg[i] = 0;

	while( ( c = fgetc( img_in )) != EOF ){
		if( img_idx >= bmp_header_size ){
			char bit_mask = 0;
			if( ( c & 1 )  > 0 )
				bit_mask |= 1 << bit_idx;

			msg[msg_idx] |= bit_mask;

			bit_idx++;

			if( bit_idx >= 8 ){
				if( msg[msg_idx] == '\0' )
					break;
				bit_idx = 0;
				msg_idx++;
			}			
		}
		
		img_idx++;
	}

	//printf( "Processed %d bytes.\n", img_idx );
	//printf( "The secret message is: %s\n", msg );

	fclose(img_in);

	return msg;
}

void encodeMessage(int argc, char *argv[]){
	const int bmp_header_size = 54;
	const int max_msg_size = 1000;
	int i;
	int curr_message_position=0;
	int read_code;
	int msg_idx = 0;
	int img_idx = 0;
	int bit_idx = 0;
	char c;
	char msg[max_msg_size];
	FILE *img_in = NULL;
	FILE *img_out = NULL;

	if( argc < 3 ){
		printf( "Usage: %s source_bmp output_bmp message.\n", argv[0] );
	}
	
	img_in = fopen( argv[1], "rb" );
	if( img_in == NULL ){
		printf( "Could not open the input image file.\n" );
	}

	img_out = fopen( argv[2], "wb" );
	if( img_out == NULL ){
		printf( "Could not open the output file.\n" );
	}	

	for( i=3; i<argc; i++ ){
		strcpy( msg+curr_message_position, argv[i] );
		curr_message_position += strlen(argv[i]);

		if( i<argc-1 )
			msg[curr_message_position] = ' ';
			curr_message_position++;
	}
	msg[curr_message_position] = '\0';

	while( ( read_code = fgetc( img_in )) != EOF ){
		c = (char)read_code;

		if( img_idx >= bmp_header_size && msg_idx <= strlen( msg ) ){
			char bit_mask = 1 << bit_idx;
			
			if( ( msg[msg_idx] & bit_mask) > 0 )
				c |= 1;
			else
				c &= 254;

			bit_idx++;

			if( bit_idx >= 8 ){
				bit_idx = 0;
				msg_idx++;
			}			
		}

		fputc( c, img_out );
		img_idx++;
	}

	//printf( "I have hidden the secret within an image of %d bytes.\n", img_idx );
	//printf("%s\n", msg);

	fclose(img_in);
	fclose(img_out);

}

int getFileSize(FILE *f){
	int read_code;
	int i=0;
	while( ( read_code = fgetc( f )) != EOF ){
		i=i+1;	
	}	
	return i;
}

void debug(){
	int temp;
	scanf("%d", &temp);
}

int main(int argc, char *argv[]){
	FILE *in = NULL;
	FILE *out = NULL;
	const int max_msg_size = 1000;

	int reading=0;
	int read_code;
	
	char fileContents[max_msg_size];

	char *inputFileName=argv[1];
	char *outputFileName=argv[2];
	char *chatHandle=argv[3];

	if( argc < 3){
		printf( "Usage: %s source_bmp output_bmp message.\n", argv[0] );
		return 1;
	}	

<<<<<<< HEAD
	char decoded_message[1000];
	strcpy(decoded_message, decodeMessage( inputFileName ));

	if (decoded_message[0]=='\0'){
		printf("Nothing recieved yet.");
	}
	else{
		printf("Recieved: %s\n",decoded_message);
	}
=======
	char *decoded_message = decodeMessage( inputFileName );
	printf("Recieved: %s\n",decoded_message);
>>>>>>> 6839f91a1c562c3013d3da0134b8dbde8ca87847

	while(1){
		if (reading==1){
			//printf("In a reading phase\n");
			while(reading==1){
				char *msg = decodeMessage( inputFileName );
<<<<<<< HEAD
				//printf("Read msg: %s\n", msg);
				//printf("Prev: %s\n", decoded_message);

				if( strcmp(decoded_message,msg) != 0){
					printf("Recieved: %s\n", msg);
					strcpy( decoded_message, msg );
					reading=0;
				}
				sleep(1);
=======
				if( strcmp(decoded_message,msg) != 0){
					printf("Recieved %s\n", msg);
					decoded_message = msg;
					reading=0;
				}
				
>>>>>>> 6839f91a1c562c3013d3da0134b8dbde8ca87847
			}
		}
		else{
			//printf("In a writing phase\n");
			char message[1000];
			printf("Send: ");
			fgets(message,1000,stdin);
			//debug();
		
			int len = strlen(message);
			if (len > 0 && message[len-1] == '\n'){
  				message[len-1] = '\0';
			}
			
			char handle_plus_message[1000];
			out = fopen( outputFileName, "w");
			
			handle_plus_message[0] = '[';
			int i=0;
			int j=1;						
			while(i<strlen(chatHandle)){
				char ch=chatHandle[i];
				handle_plus_message[j] = ch;
				i=i+1;
				j=j+1;
			}
			handle_plus_message[j] = ']';
			j=j+1;
			i=0;
			while(i<strlen(message)){
				char ch=message[i];
				handle_plus_message[j] = ch;
				i=i+1;
				j=j+1;
			}
			handle_plus_message[j] = '\0';			

			fclose(out);
			
			//printf("Message to be sent: %s \n", handle_plus_message);
			char *newargs[] = {argv[0],inputFileName,outputFileName,handle_plus_message};
			encodeMessage(argc, newargs);
			reading=1;
			fflush(stdout);
		}
	}
	
}
