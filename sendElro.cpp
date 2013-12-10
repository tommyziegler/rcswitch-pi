#include "HomeControlAPI.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{
    SwitchElro(argv[1], argv[2], atoi(argv[3]));
    return 0;
}