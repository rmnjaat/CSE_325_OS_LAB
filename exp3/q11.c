#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int n, m;
    off_t l = 0;
    
    n = open("apple.txt", O_RDONLY);
    
    if (n == -1) {
        perror("Error opening apple.txt");
        return 1;
    }
    
    m = open("mango.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
    
    if (m == -1) {
        perror("Error opening mango.txt");
        return 1;
    }
    
    l = lseek(n, 0, SEEK_END);
    
    char buff[l/2];
    
    if (l == -1) {
        perror("Error seeking to end of apple.txt");
        close(n);
        close(m);
        return 1;
    }
    
    if (lseek(n, 0, SEEK_SET) == -1) {
        perror("Error seeking to start of apple.txt");
        close(n);
        close(m);
        return 1;
    }
    
    ssize_t bytesRead = read(n, buff, sizeof(buff));
    
    if (bytesRead == -1) {
        perror("Error reading from apple.txt");
        close(n);
        close(m);
        return 1;
    }
    
    ssize_t bytesWritten = write(m, buff, bytesRead);
    
    if (bytesWritten == -1 || bytesWritten != bytesRead) {
        perror("Error writing to mango.txt");
        close(n);
        close(m);
       return 1;
   }
   
   printf("Content successfully copied from apple.txt to mango.txt\n");

   close(n);
   close(m);

   return 0;
}
