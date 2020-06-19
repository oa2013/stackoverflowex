#include <stdio.h>
#include <unistd.h>

//  Class code from: https://samsclass.info/127/proj/p13-64bo.htm

//  gcc -no-pie -fno-stack-protector -z execstack stackoverflow.c -o stackoverflow 

int vuln() {
    char buf[400];
    int r;
    register int i asm("rsp");
    printf("Welcome to the Proj 13 Server!\n\n");
    printf("$rsp = %#018x\n\nEnter some text:\n", i);
    r = read(0, buf, 800);
    printf("You said: %s\n", buf);
    return 0;
}

int main(int argc, char *argv[]) {
    vuln();
    printf("Bye!\n");
    return 0;
}
