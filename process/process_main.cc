#include <sys/file.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
                                        
int main (int argc, char ** argv)
{
    if (argc != 3) {
        printf("argc is not 3");
        exit(0);
    }
    //char *StrParentSetsid = argv[1];
    //char *StrChildSetsid = argv[2];
    bool ParentSetsid = atoi(argv[1]) > 0;
    bool ChildSetsid = atoi(argv[2]) > 0;
    if ( fork() > 0 ) {
        printf ( "parent begin\n" ) ;
        if (ParentSetsid) 
            setsid();
        
        sleep(40);
        
        printf ( "parent exit\n" ) ;
        exit ( 0 ) ;
    }
    if (ChildSetsid)
        setsid();
    
    printf ( "child begin\n" ) ;
    sleep(50);
    
    printf ( "child exit\n" ) ;
    return 0 ;
}
