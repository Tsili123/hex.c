#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct listmove *listptr;

typedef struct position
{
	int r;
	char c;
	char block;
}position;



struct listmove
{
	position a;
	listptr next;
};




/*

void drawgame(int par,char *string,position **array);
void copy_string(char *target, char *source);
void play(char *move,position **array,int size,char colour);
bool Win(position **array, int i, int j, char **sol, bool **visited,char *colour);
void undo(listptr *ptraddr,position **array);
bool isSafe(position **array, int i, int j,char *colour) ;
void solveMaze(position **array, char**sol, bool **visited ,char *colour) ;
void printSolution(char **sol,bool **visited,position **array,char *colour) ;
char turn(char *colour) ;
void insert_at_start(listptr *ptraddr,position value);
void changeColour(char *colour,int reset) ;
void initialize_arrays();
void printp(position move,position **array,int size,char *colour);
int maxy(int a, int b, int c, int d,int e,int f);
int evaluate(position **array,bool **visited,char *colour,int depth) ;
*/
int initialize_positions,max;

int main(int argc,char *argv[])
{
	int i,j,size=11,difficulty,counter=0,flag,start=0,gameover=0,reset=0,level=0;
	char command[15],*result,move[4],*token,*parse_move,**sol,player[6],colour[2];
	listptr alist;
	alist = NULL;
	bool **visited;
	const char s[3] = " \n";
	char numbers[3];
	position **array;
	for(i=1;i<argc;i++)
	{
		if(strcmp(argv[i], "-n")==0)
		{
			size=atoi(argv[i+1]);
		}
		else if(strcmp(argv[i], "-d")==0)
		{
			difficulty=atoi(argv[i+1]);
		}
		//else
		//	printf("error");
	}
//	printf("%d %d\n",size,difficulty);
void copy_string(char *target, char *source) {
   while (*source) {
      *target = *source;
      source++;
      target++;
   }
   *target = '\0';
}


copy_string(colour,"w");

array=malloc(size*sizeof(position*));
for(i=0;i<size;i++)
{
	array[i]=malloc(size*sizeof(position));
}

visited=malloc(size*sizeof(bool*));
for(i=0;i<size;i++)
{
	visited[i]=malloc(size*sizeof(bool));
}

sol=malloc(size*sizeof(char*));
for(i=0;i<size;i++)
{
	sol[i]=malloc(size*sizeof(char));
}

void initialize_arrays()
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			sol[i][j]=' ';
		}
	}
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			visited[i][j]=false;
		}
	}
}




void drawgame(int par,char *string,position **array)
{
	int i,u,j,k=0,l=0,var1=0,var2=0,counter=0,counter2=0,bug=0,*position;
	char colour=' ',character='A';
	
	

	for(i=0;i<par;i++)
	{
		
		if(i==0)
		{
			
			//Showing colour of upper side
			for(j=0;j<(2*par);j++)
			{
				printf(" ");
				if(j==(2*par)-1)	
					printf("W H I T E");
			}
			printf("\n");
			//											_
			/*printing right number of spaces before  /   \ */
			for(j=0;j<6;j++)
			{
				printf(" ");
			}
			
			//Printing number of rows on upper dise(A,B,C etc)
			for(j=0;j<par;j++)
			{
				if(initialize_positions==0)
				{
					array[i][j].r=i+1;
					array[i][j].c=character;
					array[i][j].block=' ';
				}
				printf("%c   ",character++);
			}
			printf("\n");
			
			
			for(j=0;j<6;j++)
			{
				printf(" ");
			}
			
			for(j=0;j<par;j++)
			{
				printf("_   ");
			}
			printf("\n");
		
			for(j=0;j<5;j++)
			{
				printf(" ");
			}
		
			for(j=0;j<par;j++)
			{
			
				printf("/ ");
				putchar(92);
				if(j==par-1)
					break;
				printf("_");
			}
			printf("\n");
		}
		
		
		character='A';
		if(i>0)
		{
			for(j=0;j<par;j++)
			{
				if(initialize_positions==0)
				{
					array[i][j].r=i+1;
					array[i][j].c=character;
					array[i][j].block=' ';
					character++;
				}
			}
		}
		
		
		
		//Handling initial spaces and showing colour (before " | " character)
		for(j=0;j<2;j++)
		{
				printf(" ");
		}
		var1=k;
		while(var1)
		{
				if(i==(par/2-1)&&counter==0)
				{
					colour='B';
					putchar(colour);
					counter=1;
				}
				else if(i==par/2&&counter==1)
				{
					colour='A';
					putchar(colour);
					counter=2;
				}	
				else if(i==(par/2+1)&&counter==2)
				{
						colour='K';
						putchar(colour);
						counter=3;
				}	
				else if ( i>=9 && bug ==0)
				{
					bug=1;
				}
				else
					printf(" ");	
			var1--;
			}
	k=k+2;
		
		
		//Representing  " | " character
		for(j=0;j<par+1;j++)
		{
			if(j==0)
				printf("%d ",i+1);
			if(j!=par)
			{
				if(initialize_positions==1)
				{
					printf("| ");
				//	if(player==0)
				//		printf(" ");
				//	else
						printf("%c",array[i][j].block);
					printf(" ");
				}
				else
					printf("|   ");
			}
			if(j==par)
			{
				//showing number of rows from right side
				printf("|");
				printf(" %d",i+1);
			}
				
		}
		printf("\n");
		
		
		
		//Handling initial spaces and showing colour (before " \_/ " characters)
		for(j=0;j<5;j++)
		{
				if(i==(par/2-1)&&counter2==0&&j==2)
				{
					colour='L';
					putchar(colour);
					counter2=1;
				}
				else if(i==par/2&&counter2==1&&j==2)
				{
					colour='C';
					putchar(colour);
					counter2=2;
				}
				else	
					printf(" ");
		}
		var2=l;
		while(var2)
		{
				printf(" ");
				var2--;
		}
		l=l+2;
		
		
		//representing \_/ pattern
		for(j=0;j<par;j++)
		{
			putchar(92);
			printf("_");
			printf("/");
			if(j==par-1 && i!=par-1)
			{
				printf(" ");
				putchar(92);
			}
			printf(" ");
		}
		printf("\n");
		
		//Representing number of columns (A,B,C etc)
		if(i==par-1)
		{
			character='A';
			printf("\n");
			for(j=0;j<2*par+4;j++)
			{
				printf(" ");	
			}
			for(j=0;j<par;j++)
			{
				printf("%c   ",character++);
			}
		printf("\n");
		}
		
		//handling error when rows are more than 9(2-digit number)
		bug=0;
	}
	printf("\n");
	
	for(i=0;i<par;i++)
	{
		for(j=0;j<par;j++)
		{
			if(initialize_positions==0)
			{
				printf("%c %2d block:%c| ",array[i][j].c,array[i][j].r,array[i][j].block);
				if(i==par-1 && j==par-1)
					initialize_positions=1;
			}
		}
		if(initialize_positions==0)
			printf("\n");
	}
	printf("\n");
	printf("\n");
}


void insert_at_start(listptr *ptraddr,position value)
/* Insert v as first element of list *ptraddr */
{ 
	listptr templist;
	templist = *ptraddr; /* Save current start of list */
	*ptraddr = malloc(sizeof(struct listmove)); /* Space for new node */
	(*ptraddr)->a.r = value.r; /* Put value */
	(*ptraddr)->a.c = value.c; /* Put value */
	(*ptraddr)->a.block = value.block; /* Put value */
	(*ptraddr)->next = templist; /* Next element is former first */
}



void play(char *move,position **array,int size,char *colour)
{
	int row=0,column,counter,i,j,flag;
	position value;
	char c1,c2;

			c1=move[0];

	printf("%c\n",c1);
	
	value.c=c1;
	
	for(i=1;i<3;i++)
	{
		if(move[i]!='\0')
			row=row*10+move[i]-'0';
	}

	printf("%d\n",row);
	
	value.r=row;
	
	if(row>size||row<1)
	{
		printf("out of range\n");
		reset=1;
		return;
	}
	
	value.block=*colour;
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			
			
					if(array[i][j].c==c1 && array[i][j].r==row)
					{
						if(array[i][j].block==' ')
						{
							array[i][j].block= *colour;
							insert_at_start(&alist, value);
						}
						else
						{
							//	changeColour(colour);
							printf("block owned \n ");
							reset=1;
							break;
							//	return;
						}
					}
					
		}
			if(reset==1)
				break;
	}
	
	


	
	drawgame(size,result,array);
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%c %2d block:%2c | ",array[i][j].c,array[i][j].r,array[i][j].block);
		}
		printf("\n");
	}
	
	printf("\n");
	

}


void undo(listptr *ptraddr,position **array)
{
	listptr templist;
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(array[i][j].c==(*ptraddr)->a.c && array[i][j].r==(*ptraddr)->a.r)	
			{
					array[i][j].block=' ';
					templist = (*ptraddr); /* Yes, save address of its node */
					(*ptraddr) = (*ptraddr)-> next;
					free(templist); /* Free memory for the corresponding node */
					
					drawgame(size,result,array);
					
					for(i=0;i<size;i++)
					{
						for(j=0;j<size;j++)
						{
							printf("%c %2d block:%2c | ",array[i][j].c,array[i][j].r,array[i][j].block);
						}
						printf("\n");
					}
					
					printf("\n");
			}			
		}
	}
		
}


/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(position **array, int i, int j,char *colour) 
{ 
    // if (i,j outside maze) return false 
    if(i >= 0 && i < size && j >= 0 && j < size && array[i][j].block == *colour) 
        return true; 
  
    return false; 
} 




/* A recursive utility function to solve Maze problem */
bool Win(position **array, int i, int j, char **sol, bool **visited,char *colour)
{ 
    // if (x,y is goal) return true 
    if(isSafe(array, i, j, colour) == true)
	    if(i == size-1 && array[i][j].block=='w' || j == size-1 && array[i][j].block=='b' ) 
	    { 
	    	visited[i][j]=true;
	        sol[i][j] = *colour; 
	        return true; 
	    } 
  
    // Check if maze[x][y] is valid 
    if(isSafe(array, i, j, colour) == true && visited[i][j] == false) 
    { 
        // mark x,y as part of solution path 
        sol[i][j] = *colour;
        visited[i][j]=true;
  		
		
			if (Win(array, i+1, j, sol, visited, colour) == true ) 
	            return true; 
			if (Win(array, i+1, j-1, sol, visited, colour) == true) 
	            return true; 
	        if (Win(array, i, j+1, sol, visited, colour) == true) 
	            return true; 
	  		if (Win(array, i, j-1, sol, visited, colour) == true) 
	            return true;   
	        if (Win(array, i-1, j+1, sol, visited, colour) == true) 
	            return true; 
			if (Win(array, i-1, j, sol, visited, colour) == true) 
	            return true; 
		
      sol[i][j] = 'X'; 
      
        return false; 
    }    
  	if(isSafe(array, i, j, colour) == true )
  	{
  		visited[i][j]=true; 
  		sol[i][j] = 'X';
	}
    return false; 
} 


/* A utility function to print solution matrix sol[N][N] */
void printSolution(char **sol,bool **visited,position **array,char *colour) 
{ 
	int i,j,flag=0;
	
    for ( i = 0; i < size; i++) 
    { 
        for ( j = 0; j < size; j++) 
           if(sol[i][j]=='w')
           {
           		if(flag==0 )
           		{
           		   if(strcmp(colour,"w")==0)
           		  		printf("White wins\n") ;
				  printf("The winning path is : ") ;
				  gameover=1;
				  flag=1;
				}
				if(visited[i][j]==true)
					printf("%c%d ",array[i][j].c,array[i][j].r);
		   }
		   else if(sol[i][j]=='b')
		   {
		   		if(flag==0 )
           		{
           		  if(strcmp(colour,"b")==0)
           		  	printf("Black Wins \n ") ;
				  printf("The winning path is : ") ;
				  gameover=1;
				  flag=1;
				}
				if(visited[i][j]==true)
					printf("%c%d ",array[i][j].c,array[i][j].r);
		   }
		    	 
    } 
     printf("\n"); 
    for ( i = 0; i < size; i++) 
    { 
        for ( j = 0; j < size; j++) 
		{
			printf("%2c",sol[i][j]);
		}	 
        printf("\n"); 
    } 
    
	printf("\n"); 
	
    for ( i = 0; i < size; i++) 
    { 
        for ( j = 0; j < size; j++) 
            printf(" %d", visited[i][j]); 
        printf("\n"); 
    } 
   initialize_arrays();
   
} 

int maxy(int a, int b, int c, int d,int e,int f) 
{
    if (a > b && a > c && a > d && a > e && a > f )
        return a;
    if (b > a && b > c && b > d && b > e && b > f)
        return b;
    if (c > a && c > b && c > d && c > e && c > f)
        return c;
    if (d > a && d > b && d > c && d > e && d > f)
        return d;
    if (e > a && e > b && e > c && e > d && e > f)
        return e;
    if (f > a && f > b && f > c && f > d && f > e)
        return f;
}

// A recursive utility function to solve Maze problem 
int sequence(position **array, int i, int j, bool **visited,char *colour)
{ 


    // Check if maze[x][y] is valid 
    if(isSafe(array, i, j, colour) == true && visited[i][j] == false) 
    { 
       
        visited[i][j]=true;
  		
        return maxy(sequence(array, i+1, j, visited, colour),
        sequence(array, i+1, j-1,  visited, colour) ,
		sequence(array, i, j+1, visited, colour) ,
		sequence(array, i, j-1, visited, colour) ,
		sequence(array, i-1, j+1, visited, colour) ,
		sequence(array, i-1, j, visited, colour) ) + 1;
		
    }   
	 
  	if(isSafe(array, i, j, colour) == true )
  	{
  		visited[i][j]=true; 
	}
		return 0;
  		
} 


/* This function solves the Maze problem using Backtracking.  It mainly 
   uses solveMazeUtil() to solve the problem. It returns false if no  
   path is possible, otherwise return true and prints the path in the 
   form of 1s. Please note that there may be more than one solutions,  
   this function prints one of the feasible solutions.*/
void solveMaze(position **array,char **sol,bool **visited,char *colour) 
{ 
    bool gameover;
  	int j;
  	
  	if(strcmp(colour,"w")==0)
  	{
	    for(j=0;j<size;j++)
		{
			Win(array, 0, j, sol, visited , colour) ; 
		}
			printSolution(sol,visited,array,colour);
	}
		
    printf("\n");
	initialize_arrays();
    
    if(strcmp(colour,"b")==0)
    {
		for(i=0;i<size;i++)
		{
			Win(array, i, 0, sol, visited , colour) ; 
		}
			printSolution(sol,visited,array,colour);
	}
    printf("\n");
	initialize_arrays();
} 


void changeColour(char *colour,int reset) 
{
    
	if(strcmp(colour,"w")==0)
	{
		if(reset==0)
		{
			printf("Black plays\n");
		}
		copy_string(colour,"b");
	}	
    else if(strcmp(colour,"b")==0)
    {
    	if(reset==0)
    	{
    		printf("White plays\n") ;
		}
    	copy_string(colour,"w");
	}
    	
}



// This function returns true if there are moves 
// remaining on the board. It returns false if 
// there are no moves left to play. 
bool isMovesLeft(position **array) 
{ 
int i,j;
    for ( i = 0; i<size; i++) 
        for ( j = 0; j<size; j++) 
            if (array[i][j].block ==' ') 
                return true; 
    return false; 
} 


// This is the evaluation function as discussed 
int evaluate(position **array,bool **visited,char *colour,int depth) 
{ 
	
  	int i,j,max_w=0,max_b=0,temp=0;
  	

  	initialize_arrays();
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			temp=sequence(array, i, j,visited,"w");
			if(max_w<temp)
			{
				max_w=temp;
			}
			initialize_arrays();
		}
	}
	
	temp=0;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			temp=sequence(array, i, j,visited,"b");
			if(max_b<temp)
			{
				max_b=temp;
			}
			initialize_arrays();
		}
	}
	
	
	
	if(strcmp(colour,"w")==0)
  	{
	    for(j=0;j<size;j++)
		{
			Win(array, 0, j, sol, visited , colour) ; 
		}
		
	}
		
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
				if(sol[i][j]=='w')
					return -1001+depth;//-1001;
		}
	}
    //printf("\n");
	initialize_arrays();
    
    if(strcmp(colour,"b")==0)
    {
		for(i=0;i<size;i++)
		{
			Win(array, i, 0, sol, visited , colour) ; 
		}	
	}
	//initialize_arrays();
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
				if(sol[i][j]=='b')
					return +1001-depth;//+1001;
		}
	}
//	initialize_arrays();
	
	
	
	
//	if(max_w-max_b>0)
//		return max_w-max_b-depth;
//	else if(max_w-max_b<0)
		return max_w-max_b;
		

}



int max(int a, int b)
{
	if(a>b)
		return a;
	else if(b>a)
		return b;
}

int min(int a, int b)
{
	if(a<b)
		return a;
	else if(b<a)
		return b;
}


// This is the minimax function. It considers all 
// the possible ways the game can go and returns 
// the value of the board 
int minimax(position **array, int depth, bool isMax, char *colour) 
{ 
	int score=0;
	int best=0;
	if(depth==0)
	{
		score = evaluate(array,visited,colour,depth); 
		return score; 
	}
  	int i,j;
    // If Maximizer or Minimizer has bigger sequence return score
   // if (score>0||score<0) 
   //     return score; 
  
  	score = evaluate(array,visited,colour,depth); 
    best=score;
  
    // If this maximizer's move 
    if (isMax) 
    { 
       // int best = -1000; 
  
        // Traverse all cells 
        for (i = 0; i<size; i++) 
        { 
            for (j = 0; j<size; j++) 
            { 
                // Check if cell is empty 
                if (array[i][j].block==' ') 
                { 
                    // Make the move 
                    array[i][j].block = 'w'; 
  
                    // Call minimax recursively and choose 
                    // the maximum value 
                    
                    score = evaluate(array,visited,colour,depth); 
                    
                    best = max( best, minimax(array, depth-1, !isMax, "w") ); 
  					
                    // Undo the move 
                    array[i][j].block = ' '; 
                    
                } 
            } 
        } 
        return best; 
    } 
  
    // If this minimizer's move 
    else
    { 
      //  int best = 1000; 
  
        // Traverse all cells 
        for (j = 0; j<size; j++) 
        { 
            for ( i = 0; i<size; i++) 
            { 
                // Check if cell is empty 
                if (array[i][j].block==' ') 
                { 
                    // Make the move 
                    array[i][j].block = 'b'; 
  					
  					score = evaluate(array,visited,colour,depth); 
                    // Call minimax recursively and choose 
                    // the minimum value 
                    best = min(best, minimax(array, depth-1, !isMax, "b")); 
  
                    // Undo the move 
                    array[i][j].block = ' '; 
                } 
            } 
        } 
        return best; 
    } 
} 



// This will return the best possible move for the player 
position findBestMove(position **array,char *colour) 
{ 
  
    int bestVal = -1000; 
    position bestMove; 
    bestMove.r = -1; 
    bestMove.c = -1; 
    char column='A';
  
    // Traverse all cells, evaluate minimax function for 
    // all empty cells. And return the cell with optimal 
    // value. 
    for ( i = 0; i<size; i++) 
    { 
        for ( j = 0; j<size; j++) 
        { 
            // Check if cell is empty 
            if (array[i][j].block == ' ') 
            { 
                // Make the move 
                array[i][j].block= *colour; 
  
                // compute evaluation function for this 
                // move. 
                int moveVal = minimax(array, difficulty, false, colour); 
  
                // Undo the move 
                array[i][j].block = ' '; 
  
                // If the value of the current move is 
                // more than the best value, then update 
                // best
                if (moveVal > bestVal) 
                { 
                    bestMove.r = i+1; 
                    bestMove.c = column; 
                    bestVal = moveVal; 
                } 
                
            } 
            column++;
        } 
        column='A';
    } 

    printf("The value of the best Move is : %d\n\n", bestVal); 
  
    return bestMove; 
} 




void printp(position move,position **array,int size,char *colour)
{
	int row=0,column,counter,i,j,flag;
	char c;
	

	c=move.c;

	printf("%c\n",c);
	
	row=move.r;

	printf("%d\n",row);
	
	if(row>size||row<1)
	{
		printf("out of range\n");
		reset=1;
		return;
	}
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			
			
					if(array[i][j].c==c && array[i][j].r==row)
					{
						if(array[i][j].block==' ')
							array[i][j].block= *colour;
						else
						{
							//	changeColour(colour);
							printf("block owned \n ");
							reset=1;
							break;
							//	return;
						}
					}
					
		}
			if(reset==1)
				break;
	}
	
	
	
	
	drawgame(size,result,array);
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%c %2d block:%2c | ",array[i][j].c,array[i][j].r,array[i][j].block);
		}
		printf("\n");
	}
	
	printf("\n");
	

}


void print(listptr list) /* Print elements of list */
{ 
	while (list != NULL) { /* Visit list elements up to the end */
	printf("%d %c %c->", list->a.r,list->a.c,list->a.block ); /* Print current element */
	list = list->next; /* Go to next element */
	}
	printf("NULL\n"); /* Print end of list */
}



while(i)
{
	int i,j,max=0,temp=0;
	position p;
		

	

	result=fgets(command, sizeof(command), stdin);
	
	if(strcmp(result,"newgame\n")==0)
	{
		drawgame(size,result,array);
		fflush(stdin);
	}
	
	printf("\n");
	
	if(strcmp(result,"showstate\n")==0)
	{
		drawgame(size,result,array);
		fflush(stdin);
		continue;
	}
	
	if(strcmp(result,"level\n")==0)
	{
		 printf("The difficulty of the game is %d \n",difficulty);
	}
	
	if(strcmp(result,"undo\n")==0)
	{
		undo(&alist,array);
	}
	
	if(strcmp(result,"quit\n")==0)
	{
		 break;
	}
	
	
	if(strcmp(result,"cont\n")==0)
	{
	/*	//setbuf(stdout, NULL);
	initialize_arrays();
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			temp=sequence(array, i, j,visited,colour);
			if(max<temp)
			{
				max=temp;
			}
			initialize_arrays();
		}
	}
	
	printf("black max %d",max);
	*/
		//drawgame(size,result,array);
		p=findBestMove(array, colour) ;
		//printf("%d %c\n",p.r,p.c);
		print(alist);
		printp(p,array,size,colour);
		initialize_arrays();
		fflush(stdin);
	//	changeColour(colour,reset) ;
		
	}
	
	
	
	
	token = strtok(result,s);
	
	while( token != NULL ) {
		counter++;
		if(level==1)
		{
			int i;
			difficulty=0;
			copy_string(numbers,token);
			for(i=0;i<2;i++)
			{
				if(numbers[i]!='\0')
					difficulty=difficulty*10+numbers[i]-'0';
			}
			printf("The difficulty of the game is %d \n",difficulty);
		}
		if(counter==1)
		{
			if(strcmp(token,"play")==0)
			{
				flag=1;
				start=1;
			}
			else if(strcmp(token,"level")==0)
			{
				flag=1;
				level=1;
			}
		}
		if(counter==2&& flag==1 && level==0)
		{
	    	//printf("%s\n", token );
	    	copy_string(move,token);
	    	//printf("%s\n",move);
	    	print(alist);
	    	play(move,array,size,colour);
	    	
	    }
	    token = strtok(NULL, s);
	}
	
	
	solveMaze(array,sol,visited,colour);
	
	if(reset==1)
	{
		changeColour(colour,reset) ;
		reset=0;
	}
		
	
	if(start==1 && gameover==0)
		changeColour(colour,reset) ;
	
	
	
	counter=0;
	flag=0;
	level=0;
	fflush(stdin);
	
	if(gameover==1)
		break;

	
}

return 0;

}



