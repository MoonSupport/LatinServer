//
//  main.cpp
//  low_open
//
//  Created by 문지원 on 03/01/2020.
//  Copyright © 2020 문지원. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
void error_handling(char* message);

int main(int argc, const char * argv[]) {
    using namespace std;
    
    int fd;
    
    char buf[] = "Let's go! \n";
    
    fd=open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);
    
    cout << O_CREAT << endl;
    cout << O_WRONLY << endl;
    cout << O_TRUNC << endl;
    
    cout << (O_CREAT | O_WRONLY) << endl;
    cout << (O_WRONLY | O_TRUNC) << endl;
    cout << (O_CREAT | O_TRUNC) << endl;
    
    cout << (O_CREAT | O_WRONLY | O_TRUNC) << endl;


    
    if(fd==-1)
        error_handling((char*)"open Error");
    printf("file descriptor: %d \n", fd);
    
    if(write(fd, buf, sizeof(buf)) == -1)
        error_handling((char*)"write() error!");
    close(fd);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
