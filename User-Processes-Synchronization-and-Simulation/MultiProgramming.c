/*
Name: John Lam
Student ID: 103603126
Course: 60-330
Date: August 11, 2014
Final Multi-programming
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>


double equation(double);
double simpsonRule(double, double, int);

int main(int argc, char *argv[]){
    double simpson, parent_simpson = 0, val;
    int status, fd[4], n = 4, i, j;
    pid_t pid, pids[4];

    // create pipe descriptors
        pipe(fd);
        /* Start children. */
        simpson = 0.0;
        for (i = 0; i < n; ++i) {
            if ((pids[i] = fork()) < 0) {
                perror("fork");
                abort();
            }
            else if (pids[i] == 0) { //child process
                close(fd[0]); //close reading, since we only write in children
                switch(i){
                        //break the interval of 0-1 to 4 and 8000 slices and send to parent
                        //whose fd is == fd[1]
                    case 0: simpson = simpsonRule(0.25, 0, 8000);
                            write(fd[1], &simpson, sizeof(simpson));
                            exit(0); 
                            break;
                    case 1: simpson = simpsonRule(0.5, 0.25, 8000);
                            write(fd[1], &simpson, sizeof(simpson));
                            exit(0);
                            break;
                    case 2: simpson = simpsonRule(0.75, 0.5, 8000);
                            write(fd[1], &simpson, sizeof(simpson));
                            exit(0);
                            break;
                    case 3: simpson = simpsonRule(1.0, 0.75, 8000);
                            write(fd[1], &simpson, sizeof(simpson));
                            exit(0);
                            break;
                    default: break;
                }
                close(fd[1]);
                exit(0);
            }
           
        }

        
       
        while (n > 0) {
            pid = wait(&status); //wait for child
            close(fd[1]); //close sending since we only read
            read(fd[0], &val, sizeof(val)); //read the values sent by the children
            parent_simpson += val; //accumulate the value
            --n;
        }    
        close(fd[0]);
     
    printf("Sigma: %10.10g\n", parent_simpson );
    for(n = 0; n < 4; n++){
        kill(pids[n], SIGKILL); //kill ALL the children
    }
    return 0;
}

double equation(double x){
    return 4/(1+x*x);
}

double simpsonRule(double upper_limit, double lower_limit, int interval){
    double simpson, h;
    int i;
    for (int j =0; j < 100000; j++){
        h = (upper_limit - lower_limit)/interval;
        simpson = equation(lower_limit)+equation(upper_limit)+4*equation(lower_limit+h);
        for(i = 3; i<=interval-1; i+=2){
            simpson += 4*equation(lower_limit+i*h) + 2*equation(lower_limit+(i-1)*h);
        }
        return ((h/3)*simpson);
    }
}
