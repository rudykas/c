#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ymax, xmax; //size of screen 
int* xs; //xs of snake
int* ys;
int length;


void draw_snake(){ 
    for (int i=0; i < length; i++){ 
        mvaddstr(ys[i], xs[i], "s"); //1st - y, 2nd - x
    }	
}


void step_snake_add(int y,int x){
    xs[length] = x;
    ys[length] = y;
    length++;
	
}

void step_snake_remove(){
    for (int i=1; i < length; i++){
    	xs[i-1] = xs[i];
        ys[i-1] = ys[i];
    }
	length--;
}


void check_crash(int y,int x){
    for (int i=1; i < length; i++){
        if (x == xs[i] && y == ys[i]){
            endwin();
            exit(1);
        }
    }
}


int main()
{  
  initscr();      /* Start curses mode       */
  refresh();      /* Print it on to the real screen */
  // mvaddstr(10, 10, "s"); //add character to position 10, 10

  
  getmaxyx(stdscr, ymax, xmax); // finding size of the screen:
    //arrays of cooridinates
  xs = malloc(xmax*ymax*sizeof(int));
  ys = malloc(xmax*ymax*sizeof(int));
  length = 0; 


  
  srand(time(NULL)); //toask — why exactly null? - to randomize rand ok, but why nill? 
  int ya = rand()%ymax; //random coordinates of apple
  int xa = rand()%xmax;

  mvaddstr(ya, xa, "a"); //creating apple

  //getch();        /* Wait for user input */
  int y = 10;
  int x = 10;

  step_snake_add(y,x);

  halfdelay(2);

  char direction = 'd'; //initial direction

  while (1){
    draw_snake();
    mvaddstr(ya, xa, "a");
  	int key = getch();

  	//moving 
  	if (key != -1){
  	direction = key;
  	}
  	
  	if (direction == 'w'){
  		y = y-1;
  	}
  	else if (direction == 'a'){
  	  	x = x-1;
  	}
    else if (direction == 's'){
        y = y+1;
    }
    else if (direction == 'd'){
        x = x+1;
    }
  	
    check_crash(y,x);
  	

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
    if (x == xa && y == ya){ 
      ya = rand()%ymax; 
      xa = rand()%xmax;
      //length++;
    }
    else {step_snake_remove();} //toask when is this row executeted? always?

      
  	erase();
  }
  endwin();       /* End curses mode      */
  return 0;
}

//to compile clang snake.c -lncurses
