#include <ncurses.h>
#include <stdio.h>
#include<stdlib.h>
#include <time.h>

int ymax, xmax;
int* xs;
int* ys;
int length;


void draw_snake(){ 
    for (int i=0; i == length; i++){
        mvaddstr(ys[i], xs[i], "s"); //1st - y, 2nd - x
    }	
}


void step_snake_add(int y,int x){
    xs[length] = x;
    ys[length] = y;
    length++;
	
}

void step_snake_remove(){
    for (int i=1; i == length-1; i++){
    	xs[i-1] = xs[i];
    }
	length--;
}


int main()
{  
  initscr();      /* Start curses mode       */
  refresh();      /* Print it on to the real screen */
  mvaddstr(10, 10, "s"); //add charecter to position 10, 10

  
  getmaxyx(stdscr, ymax, xmax); // finding size of the screen:
    //arrays of cooridinates
  xs = malloc(xmax*ymax*sizeof(int));
  ys = malloc(xmax*ymax*sizeof(int));
  length = 0; 


  
  srand(time(NULL));
  int ya = rand()%ymax; //random coordinates of apple
  int xa = rand()%xmax;

  mvaddstr(ya, xa, "a"); //creating apple

  //getch();        /* Wait for user input */
  int y = 10;
  int x = 10;






  while (1){
    draw_snake();
    mvaddstr(ya, xa, "a");
  	char key = getch();

  	//moving 
  	if (key == 'w'){
  		y = y-1;
  	}
  	else if (key == 'a'){
  	  	x = x-1;
  	}
    else if (key == 's'){
        y = y+1;
    }
    else if (key == 'd'){
        x = x+1;
    }
  	//todo add s and d - done 
  	//todo hw 1. char instead of Hello world. - done 
    //2. borders behaviour, make screen as a tor


    // border behaviour 
    if (x == xmax){
      x = 0; 
    }
    if (y == ymax){
      y = 0; 
    }
    else if (x == -1){
        x = xmax-1;
    }
     else if (y == -1){
        y = ymax-1;
    }

    step_snake_add(y,x);
    
    
    //create new apple when ate
    if (x == xa & y == ya){ 
      ya = rand()%ymax; 
      xa = rand()%xmax;
    }
    else {step_snake_remove();}


    
  	erase();
  }
  endwin();       /* End curses mode      */
  return 0;
}
