

#include<stdio.h>
#include<unistd.h>
#include <sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>


int main(){
int fd,n;

pid_t  pi;
char sms[]="Wel come";
char buff[10];



mkfifo("rmn",0666);

pi=fork();

if(pi==0){



fd =open("rmn",O_WRONLY);
write(fd,sms,strlen(sms)+1);
printf("Chlid write information is: %s \n",sms);
close(fd);
}

else{


fd=open("rmn",O_RDONLY);

n=read(fd,buff,sizeof(buff));

printf("info recived by prnt is : %s\n",buff);
close(fd);

}


}



