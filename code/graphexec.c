#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "makeargv.h"

// for 'status' variable:
#define INELIGIBLE 0
#define READY 1
#define RUNNING 2
#define FINISHED 3
typedef struct node {
       int id; // corresponds to line number in graph text file
       char prog[1024]; // prog + arguments
       char input[1024]; // filename
       char output[1024]; // filename
       int children[10]; // children IDs
       int num_children; // how many children this node has
       int status; // ineligible/ready/running/finished
       pid_t pid; // track it when it's running
} node_t;



int main(int argc, char *argv[]){
  FILE *inputfd = fopen(argv[1], "r"); //pointer to input file
  int c = 0; //counter variable
  char children[51][20];
  int i;	//counter variable for reading tokens into node members
  char child;
  char line[1024]; //variable to store individual lines of the .txt file
  char **arguments; //double pointer for passing input to makeargv
  node_t graph[51]; //array of nodes representing graph
  int nodes;
  char realchildren[51][10];
  int j;
  int haveparents[51][10];
  int count = 0;
  char canex[51];
  int k,l;
  for(i=0;i<55;i++)
    {
      for(j=0;j<15;j++)
	{
	  realchildren[i][j] == 100;
	}
    }
  fgets(line, sizeof(line), inputfd);
  while(!feof(inputfd)){
    //add check to make sure I haven't run out of room in the array
    makeargv(line, ":", &arguments);
    graph[c].id = c;
    //read program and arguments into .prog member
    //need to streamline the for loops
    for(i=0; i <= 1024; i++){
      graph[c].prog[i] = arguments[0][i];
    }
    for(i=0; i <= 10; i++){
      children[c][i] = arguments[1][i];
    }
    for(i=0; i <= 1024; i++){
      graph[c].input[i] = arguments[2][i];
    }
    for(i = 0; i <= 20; i++) {
      graph[c].children[i] = arguments[1][i];
    }
    for(i = 0; i <= 1024; i++) {
      graph[c].output[i] = arguments[3][i];
    }
     i = 0;
     child = 0;
     while(arguments[1][i] != 0) // finds number of arguments in arguments
      {
	
	child++;
	i++;

      }
    
   
     if(child > 1)  // sees how many children and sets there id to realchildren
      {
	graph[c].num_children =(child+1)-2;
      }
    else{
      graph[c].num_children = 1;
    }
    if(children[c][0] == 'n')
      {graph[c].num_children = 0;
      }
    else
      {
	j = 0;
	for(i=0; i<graph[c].num_children;i++)
	  {
	    realchildren[c][i] = children[c][j]-48;
	    j = j+2;
	  }
      }


    printf("%s", line);
    printf("id: %d\n", graph[c].id);
    printf("prog: %s\n", graph[c].prog);
    printf("children: %s\n",children[c]);
    printf("input: %s\n", graph[c].input);
    printf("output: %s\n", graph[c].output);
    printf("number of children %d\n", graph[c].num_children);
    printf("\n");
    fgets(line, sizeof(line), inputfd);
    c++;
  }
  nodes = c;
  for(i = 0;i<51;i++) // intializes haveparents to 100
    {
      for(j=0;j<10;j++)
	{
	 haveparents[i][j] = 100;
	}
    }
  for(i=0;i<51;i++) // inialtize canex to 100
    {
      canex[i] = 100;
    }
  /* for(i = 0; i<nodes; i++)
    {
     
      if(graph[c].num_children > 1)
	{
	  for(j = 0; j <graph[i].num_children; j++)
	    {
	      haveparents[i][j] = realchildren[i][j];
	    }
	}
      

	}*/

  l= 0;
  for(k = 0;k<nodes; k++)  //tests which nodes have no parents
    {
  count = 0;
  for(i = 0; i < nodes; i++)
    {
      for(j = 0; j < 10; j++)
	{
	  if(realchildren[i][j] == k)
	    {
	      count++;
	    }
	    
	}
    }
      if(count == 0)
	{
	  canex[l] = k;
	  l++;
	}
    }
  printf("can exucute %d\n",canex[0]);
  printf("c e %d\n",canex[4]);
  printf("nodes = %d\n",nodes);
  
  
  return 0;
}
