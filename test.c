/* name     :test.c
 * function    :调用init_deamon函数使进程变成守护进程，然后每个一秒向/tmp目录下的print_time文件打印当前时间
 * */
#include <stdio.h> 
#include <time.h> 

void init_deamon(void);//守护进程初始化函数 
void main() 
{ 
    FILE *fp; 
    time_t t; 
    init_deamon();//初始化为Daemon 

    while(1)//每隔一分钟向test.log报告运行状态 
    { 
        sleep(1);//睡眠一秒钟 
        if((fp=fopen("print_time","a")) >=0) 
        { 
            t=time(0); 
            fprintf(fp,"The time right now is : %s",asctime(localtime(&t))); 
            fclose(fp); 
        } 
    }
    return;
}