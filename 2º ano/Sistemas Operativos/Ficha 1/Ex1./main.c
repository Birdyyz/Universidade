#include "mycat.h"

int main(int argc, char* argv []){
    if(argc==1){
        mycat();
    }
    else{
        mycat(argv[1]);
    }
    return 0;
}