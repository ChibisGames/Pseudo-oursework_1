#include <iostream>
#include <cstdio>
#include <string.h>

#include "input_output.h"
#include "book.h"
#include "client.h"
#include "order.h"
#include "order_detail.h"

using namespace std;


void write_client(char file_name[30], struct Client p)
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "a");

    if(file){
        fprintf(file, "%d %s %d %.2f\n", 
        p.id, p.name, p.age, p.salary);
        fclose(file);
    }else{
        printf("Error to open file\n");
    }
}


