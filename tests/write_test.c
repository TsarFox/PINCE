#include <stdio.h>
#include <unistd.h>

main() {
	FILE *fp;
	FILE *status;
	FILE *exit;
	FILE *initialize;
	char buff[255]="";
	char status_word[255]="";
	initialize = fopen("status.txt", "r");
	while(initialize==NULL){
		initialize = fopen("status.txt", "r");
	}
	fclose(initialize);
	while(1){
		sleep(1);
		status = fopen("status.txt", "w");
		fputs("sync-request-recieve", status);
		fclose(status);
		exit = fopen("abort-verify.txt", "r");
		if(exit!=NULL){
			fclose(exit);
			remove("abort-verify.txt");
			remove("status.txt");
			remove("PINCE-to-Inferior.txt");
			remove("Inferior-to-PINCE.txt");
			return 0;
		}
		fp = fopen("PINCE-to-Inferior.txt", "r");
		fscanf(fp, "%s", buff);
		printf("%s\n", buff );
		fclose(fp);
		fp = fopen("Inferior-to-PINCE.txt", "w");
		fputs("a", fp);
		fclose(fp);
	}
}
