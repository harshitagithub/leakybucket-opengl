#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<string.h>
int screen=0;
int wid;
char heading[]="Leaky Bucket Algorithm Simulation";
char authors[]="by Miss Shettys";
void displayText(int x,int y,char *string,void *font){
	glRasterPos2f(x,y);
	for(int i=0,len = (int) strlen(string);i< len;i++){
				glutBitmapCharacter(font,string[i]);
		}
}
void display(){
	if(screen == 0){
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.0,0.0,1.0);
		displayText(100,900,heading,GLUT_BITMAP_HELVETICA_18);
		glBegin(GL_LINES);
			glVertex2i(100,895);
			glVertex2i(322,895);
		glEnd();	
		glColor3f(0,0,0);
		displayText(100,850,authors,GLUT_BITMAP_HELVETICA_18);
	}else if(screen ==1){
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINES);
			glVertex2i(100,500);
			glVertex2i(120,400);
			glVertex2i(500,500);
			glVertex2i(480,400);
		glEnd();	
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
			glVertex2i(120,400);
			glVertex2i(200,100);
			glVertex2i(400,100);
			glVertex2i(480,400);
		glEnd();
	}
	glFlush();
}
void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluOrtho2D(0,1000.0,0,1000.0);
}
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 's':
		case 'S': screen=1;break;
		case 'b':
		case 'B': screen=0;break;
		case 'q':
		case 'Q':exit(0);


	}
}

int main(int argc,char ** argv)
{	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1280,720);
	glutInitWindowPosition(0,0);
	wid = glutCreateWindow("Leaky Bucket Algorithm Simulation");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	//glutFullScreen();
	myinit();
	glLineWidth(2.0);
	glutMainLoop();
}


