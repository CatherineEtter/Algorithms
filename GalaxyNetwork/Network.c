/*
============================================================
=   Catherine Etter
=   C Program for Programming II | Spring 2017
=   Network.c will:
=     Create a network representing a portion of the galaxy
============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{ //Includes galaxy, star systems, planets, and moons
    char name[60]; //Name of the node
    char descr[200]; //Description for the node
    struct node *contains[10]; //Objects within the node
    struct node *orbitedBy[10]; //Objects orbiting the node
    struct node *hasMoons[10]; //Moons orbiting the node
};
struct node milkyWay,alphaCentauri,acA,acB,acC,proximaCentB,solarSystem,sol,sol1,sol2,sol3,sol4,sol5,sol6,sol7,sol8,sol3m1,sol4m1,sol4m2,
sol5m1,sol5m2,sol5m3,sol5m4,sol6m1,sol6m2,sol6m3,sol6m4,sol7m1,sol7m2,sol7m3,sol7m4,sol8m1,sol8m2,sol8m3,sol8m4;

void createNetwork(int debugMode);
void printNode(struct node *object, int debugMode);

void main(int argc, char *argv[]){
    int debugMode = 0; //If debug mode is on
    
    if(argc > 1 && strcmp(argv[1],"debug") == 0){ //Notifys if debug is on
        printf("\n ************** DEBUG MODE ***************\n");
        debugMode = 1; //Allows easy checking of debug mode
    }
    printf(" *   *   *   *   *   *   *   *   *   *   *\n");
    printf("       Space... The Final Frontier\n");
    printf("  A network of our corner of the galaxy.\n");
    printf(" *   *   *   *   *   *   *   *   *   *   *\n");

    createNetwork(debugMode);
    if(debugMode){
        printf("...Now printing the nodes");
    }
    printNode(&milkyWay,debugMode); //send in node to be printed and if debug mode is on
    printNode(&alphaCentauri,debugMode);
    printNode(&acA,debugMode);
    printNode(&acB,debugMode);
    printNode(&acC,debugMode);
    printNode(&solarSystem,debugMode);
    printNode(&sol,debugMode);
    printNode(&sol3,debugMode);
    printNode(&sol4,debugMode);
    printNode(&sol5,debugMode);
    printNode(&sol6,debugMode);
    printNode(&sol7,debugMode);
    printNode(&sol8,debugMode);
}



void printNode(struct node *object, int debugMode){ //Prints the Node and it's connections. Uses a pointer to keep track of the addresses
    int i=0; //Incrementing variables
    
    printf("\n\n---[%s]---",object->name);
    if(debugMode){ //Print address of current node
        printf("(Address: %p)",object); 
    }
    if(object->descr != NULL){ //Prints description, if debug is on, prints the number of characters
        (debugMode) ? printf("[%s](%d Characters long)",object->descr,strlen(object->descr)) : printf("[%s]",object->descr);
    }
    if(object->contains[0] != NULL){ //List what the node contains, if any
        printf("\n Contains:");
        while(object->contains[i] != NULL){ //Lists what is contained, if debug is on, lists places
            (debugMode) ? printf(" %s[%d]  ",object->contains[i]->name,i) : printf(" %s  ",object->contains[i]->name);
            i++;
        }
    }
    i=0; //resets the i variable
    if(object->orbitedBy[0] != NULL){ //List what the node is orbited by, if any
        printf("\n Orbited by:");
        while(object->orbitedBy[i] != NULL){ //Lists orbits, if debug is on, lists places
            (debugMode) ? printf(" %s[%d]  ",object->orbitedBy[i]->name,i) : printf(" %s  ",object->orbitedBy[i]->name);
            i++;
        }
    }
    i=0;
    if(object->hasMoons[0] != NULL){ //List what moons the node has, if any
        printf("\n Has moons:");
        while(object->hasMoons[i] != NULL){ //Lists moons, if debug is on, lists places
            (debugMode) ? printf(" %s[%d]  ",object->hasMoons[i]->name,i) : printf(" %s  ",object->hasMoons[i]->name);
            i++;
        }
    }
}



void createNetwork(int debugMode){ //Creates the network
    if(debugMode){
        printf("...Creating the Network\n");
    }
    //GALAXY
    strcpy(milkyWay.name,"Milky Way"); //Set the name value of the node
    strcpy(milkyWay.descr,"A spiral arm galaxy"); //Set the description of the node
    milkyWay.contains[0] = &alphaCentauri; //Sets what the pointers in the array point to
    milkyWay.contains[1] = &solarSystem;
    //ALPHA CENTAURI SYSTEM
    strcpy(alphaCentauri.name,"Alpha Centauri");
    strcpy(alphaCentauri.descr,"Our closest neighbor at 4.37 light years");
    alphaCentauri.contains[0] = &acA;
    alphaCentauri.contains[1] = &acB;
    alphaCentauri.contains[2] = &acC;
    alphaCentauri.contains[3] = &proximaCentB;
    
    strcpy(acA.name,"Alpha Centauri A");
    strcpy(acA.descr,"The larger and more luminous star of the system");
    acA.orbitedBy[0] = &acB;
    acA.orbitedBy[1] = &acC;
    
    strcpy(acB.name,"Alpha Centauri B");
    strcpy(acB.descr,"Has a slightly orange color");
    acB.orbitedBy[0] = &acA;
    acB.orbitedBy[1] = &acC;
    
    strcpy(acC.name,"Alpha Centauri C");
    strcpy(acC.descr,"Also known as Proxima Centauri, a red dwarf star");
    acC.orbitedBy[0] = &acA;
    acC.orbitedBy[1] = &acB;
    acC.orbitedBy[2] = &proximaCentB;
    strcpy(proximaCentB.name,"Proxima Centauri b");
    //OUR SOLAR SYSTEM
    strcpy(solarSystem.name,"Solar System");
    strcpy(solarSystem.descr,"Located in the Orion Spur of the Milky Way");
    solarSystem.contains[0] = &sol;
    solarSystem.contains[1] = &sol1;
    solarSystem.contains[2] = &sol2;
    solarSystem.contains[3] = &sol3;
    solarSystem.contains[4] = &sol4;
    solarSystem.contains[5] = &sol5;
    solarSystem.contains[6] = &sol6;
    solarSystem.contains[7] = &sol7;
    solarSystem.contains[8] = &sol8;
    
    strcpy(sol.name,"Sun");
    strcpy(sol.descr,"A yellow dwarf star");
    sol.orbitedBy[0] = &sol1;
    sol.orbitedBy[1] = &sol2;
    sol.orbitedBy[2] = &sol3;
    sol.orbitedBy[3] = &sol4;
    sol.orbitedBy[4] = &sol5;
    sol.orbitedBy[5] = &sol6;
    sol.orbitedBy[6] = &sol7;
    sol.orbitedBy[7] = &sol8;
    
    strcpy(sol1.name,"Mercury");
    
    strcpy(sol2.name,"Venus");
    
    strcpy(sol3.name,"Earth");
    strcpy(sol3.descr,"Currently in an extinction event");
    sol3.orbitedBy[0] = &sol3m1;
    strcpy(sol3m1.name,"Moon");
    
    strcpy(sol4.name,"Mars");
    strcpy(sol4.descr,"Entirely inhabited by robots...as far as we know");
    sol4.hasMoons[0] = &sol4m1;
    sol4.hasMoons[1] = &sol4m2;
    strcpy(sol4m1.name,"Phobos");
    strcpy(sol4m2.name,"Deimos");
    
    strcpy(sol5.name,"Jupiter");
    strcpy(sol5.descr,"Has auroras");
    sol5.orbitedBy[0] = &sol5m1;
    sol5.orbitedBy[1] = &sol5m2;
    sol5.orbitedBy[2] = &sol5m3;
    sol5.orbitedBy[3] = &sol5m4;
    strcpy(sol5m1.name,"Ganymede");
    strcpy(sol5m2.name,"Europa");
    strcpy(sol5m3.name,"Io");
    strcpy(sol5m4.name,"Callisto");
    
    strcpy(sol6.name,"Saturn");
    strcpy(sol6.descr,"Named after the Roman god of agriculture");
    sol6.hasMoons[0] = &sol6m1;
    sol6.hasMoons[1] = &sol6m2;
    sol6.hasMoons[2] = &sol6m3;
    sol6.hasMoons[3] = &sol6m4;
    strcpy(sol6m1.name,"Titan");
    strcpy(sol6m2.name,"Enceladus");
    strcpy(sol6m3.name,"Mimas");
    strcpy(sol6m4.name,"Dione");
    
    strcpy(sol7.name,"Uranus");
    strcpy(sol7.descr,"Smallest of the gas giants");
    sol7.hasMoons[0] = &sol7m1;
    sol7.hasMoons[1] = &sol7m2;
    sol7.hasMoons[2] = &sol7m3;
    sol7.hasMoons[3] = &sol7m4;
    strcpy(sol7m1.name,"Titania");
    strcpy(sol7m2.name,"Miranda");
    strcpy(sol7m3.name,"Umbriel");
    strcpy(sol7m4.name,"Ariel");
    
    strcpy(sol8.name,"Neptune");
    strcpy(sol8.descr,"Once had a \"Great Dark Spot\"");
    sol8.hasMoons[0] = &sol8m1;
    sol8.hasMoons[1] = &sol8m2;
    sol8.hasMoons[2] = &sol8m3;
    sol8.hasMoons[3] = &sol8m4;
    strcpy(sol8m1.name,"Triton");
    strcpy(sol8m2.name,"Nereid");
    strcpy(sol8m3.name,"Proteus");
    strcpy(sol8m4.name,"Neso");
}
