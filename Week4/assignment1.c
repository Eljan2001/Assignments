#include <stdio.h>

void printMaze(char **maze, const int HT, const int WD); // prints the maze

int solveMaze(char **maze, const int HT, const int WD, int y, int x); // draws a path to the exit on the maze string

int main(){
    char mazeStr[] ="  ##############"
		    "#    ##     ####"
		    "# ####* ### ####"
		    "#    ###### ####"
		    "#### # #### ####"
		    "#    # #### ####"
		    "#### # #### ####"
		    "####        ####"
		    "################";
    const int HT = 9;
    const int WD = 16;
    char *maze[HT];

    for (int i=0; i<HT ; i++)		// filling the 2D char array
	maze[i]=&mazeStr[i*WD];
    
    solveMaze(maze, HT, WD, 0, 0);
    
    printMaze(maze, HT, WD);
    
    return 0;
}


int solveMaze(char **maze, const int HT, const int WD, int p, int o){
	int DEADEND=0;
	for (int x=0; x<HT; x++)
	{
		
		for (int y=0; y<WD; y++)
		{
			
		if (maze[x][y]!=*"#" && maze[x][y]!=*"*")
                        {
                                maze[x][y]=*".";
                        }
		}
	}
	for (int x=0; x<HT; x++)
        {

                for (int y=0; y<WD; y++)
                {
		if (x==0)
			{
			if (maze[x][y]!=*"#" && maze[x][y+1]==*"#" && maze[x+1][y]==*"#" && maze[x][y]!=*"*") // Right deadend
                                        {
                                                printf("%d %d\n", x, y);
                                                DEADEND+=1;
                                                for (int r=y; r>0; r--)
                                                        {
                                                        if ((maze[x+1][r]==*"#" && maze[x][r-1]!=*"#") || (maze[x+1][r]!=*"#" && maze[x][r-1]==*"#"))
                                                                {
                                                                maze[x][r]=*" ";
                                                                }
                                                        else 
                                                                {
                                                                        break;
                                                                }
                                                        }
                                        }
                        if (maze[x][y]!=*"#" && maze[x][y-1]==*"#" && maze[x+1][y]==*"#" && maze[x][y]!=*"*") // Left deadend
                                        {
                                                printf("%d %d\n", x, y);
                                                DEADEND+=1;
                                                for (int Y=y; Y<WD; Y++)
                                                        {
                                                        if ((maze[x+1][Y]==*"#" && maze[x][Y+1]!=*"#") || (maze[x+1][Y]!=*"#" && maze[x][Y+1]==*"#"))
                                                                {
                                                                maze[x][Y]=*" ";
                                                                }
							else
                                                                {
                                                                break;
                                                                }
                                                        }
                                        }
                        if (maze[x][y]!=*"#" && maze[x][y+1]==*"#" && maze[x][y-1]==*"#" && maze[x+1][y]==*"#" && maze[x][y]!=*"*") // Bottom deadend
                                        {
                                                printf("%d %d\n", x, y);
                                                DEADEND+=1;
                                                for (x; x>0; x++)
                                                {

                                                        if (maze[x][y+1]==*"#" && maze[x][y-1]==*"#")
                                                        {
                                                                maze[x+1][y]=*" ";
                                                        }	
							else
							{
								break;
							}
						}
					}
			if (maze[x][y]!=*"#" && maze[x][y+1]==*"#" && maze[x][y-1]==*"#" && maze[x][y]!=*"*") // Top deadend
                                        {
                                                printf("%d %d\n", x, y);
                                                DEADEND+=1;
                                                for (int X=x; X<HT; X++)
                                                {

                                                        if (maze[X][y+1]==*"#" && maze[X][y-1]==*"#")
                                                        {
                                                                maze[X][y]=*" ";
                                                        }
                                                        else
                                                        {
                                                                break;
                                                        }
                                                }
                                        }

			}
		if (x==HT-1)
			{
				if (maze[x][y]!=*"#" && maze[x][y+1]==*"#" && maze[x-1][y]==*"#" && maze[x][y]!=*"*") // Right deadend
                                        {
                                                printf("%d %d\n", x, y);
                                                DEADEND+=1;
                                                for (int r=y; r>0; r--)
                                                        {

                                                        if ((maze[x-1][r]==*"#" && maze[x][r-1]!=*"#") || (maze[x-1][r]!=*"#" && maze[x][r-1]==*"#"))
                                                                {
                                                                maze[x][r]=*" ";
                                                                }
                                                        else
                                                                {
                                                                        break;
                                                                }

                                                        }

                                        }
                        if (maze[x][y]!=*"#" && maze[x][y-1]==*"#" && maze[x-1][y]==*"#" && maze[x][y]!=*"*") // Left deadend
                                        {
                                                printf("%d %d\n", x, y);

                                                DEADEND+=1;
                                                for (int Y=y; Y<WD; Y++)
                                                        {
                                                        if ((maze[x-1][Y]==*"#" && maze[x][Y+1]!=*"#") || (maze[x-1][Y]!=*"#" && maze[x][Y+1]==*"#"))
                                                                {
                                                                maze[x][Y]=*" ";
                                                                }
							else
                                                                {
                                                                break;
                                                                }

                                                        }
                                        }
			if (maze[x][y]!=*"#" && maze[x][y+1]==*"#" && maze[x][y-1]==*"#" && maze[x][y]!=*"*") // Bottom deadend
                                        {
                                                printf("%d %d\n", x, y);
                                                DEADEND+=1;
                                                for (int X=x; X>0; X--)
                                                {

                                                        if (maze[X][y+1]==*"#" && maze[X][y-1]==*"#")
                                                        {
                                                                maze[X][y]=*" ";
                                                        }
                                                        else
                                                        {
                                                                break;
                                                        }
                                                }
                                        }

			if (maze[x][y]!=*"#" && maze[x][y+1]==*"#" && maze[x][y-1]==*"#" && maze[x-1][y]==*"#" && maze[x][y]!=*"*") // Top deadend
                                        {
                                                printf("%d %d\n", x, y);
                                                DEADEND+=1;
                                                for (int X=x; X<HT; X++)
                                                {

                                                        if (maze[X][y+1]==*"#" && maze[X][y-1]==*"#")
                                                        {
                                                                maze[X][y]=*" ";
                                                        }
                                                        else
                                                        {
                                                                break;
                                                        }
                                                }
                                        }
			}
		if (x!=0 && x!=HT-1)
			{	
			if (maze[x][y]!=*"#" && maze[x][y+1]==*"#" && maze[x+1][y]==*"#" && maze[x-1][y]==*"#" && maze[x][y]!=*"*") // Right deadend
					{
						printf("%d %d\n", x, y);
						DEADEND+=1;
						for (int r=y; r>0; r--)
							{
								
							if (maze[x+1][r]==*"#" && maze[x-1][r]==*"#")
								{	
								maze[x][r]=*" ";
								}
							else
						       		{
									break;
								}

							}
						
					}
			if (maze[x][y]!=*"#" && maze[x][y-1]==*"#" && maze[x+1][y]==*"#" && maze[x-1][y]==*"#" && maze[x][y]!=*"*") // Left deadend
					{	
						printf("%d %d\n", x, y);

        			                DEADEND+=1;
						for (int Y=y; Y<WD; Y++)
							{	
                                                        if (maze[x+1][Y]==*"#" && maze[x-1][Y]==*"#")
                                                                {
                                                                maze[x][Y]=*" ";
                                                                }
							else
                                                                {
                                                                break;
                                                                }

							}
					}
			if ((maze[x][y]!=*"#") && (maze[x][y+1]==*"#" && maze[x][y-1]==*"#" && maze[x+1][y]==*"#" && maze[x][y]!=*"*")) // Bottom deadend
					{
						printf("%d %d\n", x, y);
		                                DEADEND+=1;
						for (int X=x; X>0; X--)
                                                {

                                                        if (maze[X][y+1]==*"#" && maze[X][y-1]==*"#")
                                                        {
                                                                maze[X][y]=*" ";
                                                        }
                                                        else
                                                                {

                                                                        break;
                                                                }
							
                                                }

					}
			

			if (maze[x][y]!=*"#" && maze[x][y+1]==*"#" && maze[x][y-1]==*"#" && maze[x-1][y]==*"#" && maze[x][y]!=*"*") // Top deadend
					{
						printf("%d %d\n", x, y);
		                                DEADEND+=1;
						for (int X=x; X<HT; X++)
                                                {
								
                                                        if (maze[X][y+1]==*"#" && maze[X][y-1]==*"#")
                                                        {
                                                                maze[X][y]=*" ";
                                                        }
							else 
							{
								break;
							}
						}
					}
			
							
			}
		}
	}
	printf("The number of deadends is: %d\n", DEADEND);
		
}


void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
	for(int j=0; j<WD-1; j++)
	  printf("%c",maze[i][j]);
	printf("%c\n",maze[i][WD-1]);
    }
    }
