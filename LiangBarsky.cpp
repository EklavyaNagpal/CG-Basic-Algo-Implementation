#include<GL/gl.h>
#include<stdio.h>
#include<GL/freeglut.h>
float p[4], q[4], t1,t2;
bool b1=false,b2=false;
int lb=0,rb=0;
int xmin=100,xmax=700,ymin=100,ymax=700;
int x1,y1,x2,y2;
void initgl()
{
    glClearColor(0.0,0.0,0.0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,900,0,900);
}
void display();
void liang(int xi,int yi, int xf, int yf);
void draw(int xx1,int yy1,int xx2,int yy2);
void draw(int xx1,int yy1,int xx2,int yy2)
{
    glColor3f(255,0,0);
    glBegin(GL_LINES);
    glVertex2i(xx1,yy1);
    glVertex2i(xx2,yy2);
    glEnd();
    glFlush();
}
int cliptest(double p,double q,double *t1,double *t2)
{      // p is denominator in division and q is numerator                  
// t1 is t entering and t2 is t ending
    double t=q/p;
    if(p<0.0)        //entry point ,update te
    {    if(t>*t1) *t1=t;
        if(t>*t2) return(0); //line portion is outside where t(entering) has become more than t(ending)
    }
    else if(p>0.0) //Ending point ,update tend
        {
        if(t<*t2) *t2=t;
            if(t<*t1) return(0); //line portion is outside
        }
        else if(p==0.0)
            { if(q<0.0)
                 return(0);//line parallel to window but outside
            }
            return(1);
}
void liangbaraskylineclipanddraw(double x0,double y0,double x1,double y1)
{
    double dx= x1-x0,dy=y1-y0, tenter=0.0,tend=1.0;
 if(cliptest(-dx,x0-xmin,&tenter,&tend))// inside test wrt left edge and P=-dx and q1=x1-xwmin as done in class

    if(cliptest(dx,xmax-x0,&tenter,&tend))// inside test wrt right edge and P=dx and q1=xwmax-x1 as done in class

    if(cliptest(-dy,y0-ymin,&tenter,&tend))// inside test wrt bottom edge and P=-dy and q3=y1-ywmin as done in class
 
    if(cliptest(dy,ymax-y0,&tenter,&tend))// inside test wrt top edge and P=dy and q4=y1-ywmax as done in class
 
    {
        if(tend<1.0)
        {
            x1=x0+tend*dx;
            y1=y0+tend*dy;
        }
        if(tenter>0.0)
        {    
            x0=x0+tenter*dx;
            y0=y0+tenter*dy;
        }
    }
void display()
{
    // glRasterPos2f(200,880 );
//   glColor3f(0.4, 0.7, 0.7);
//   glutBitmapString(GLUT_BITMAP_HELVETICA_12,(const unsigned char*)"Hariom \t Eklavya");
//   glRasterPos2f(200, 860);
//   glColor3f(0.4, 0.7, 0.7);
//   glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10,(const unsigned char*)"Roll No-45(B1)");
//   glRasterPos2f(200, 840);
//   glColor3f(0.4, 0.7, 0.7);
//   glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10,(const unsigned char*)"CSE-CCVT(6th sem)");
//   glRasterPos2f(200, 810);
//   glColor3f(0.4, 0.8, 0.7);
//   glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10,(const unsigned char*)"Liang Barsky Algorithm");

  glColor3f(1.0, 1.0, 1.0);

    //  glColor3ub(0,255,0);
 glBegin(GL_LINE_LOOP);
 glVertex2i(xmin,ymin);
 glVertex2i(xmax,ymin);
 glVertex2i(xmax,ymax);
 glVertex2i(xmin,ymax);
 glEnd();
glFlush();
}
void mouse(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x1=x;
        y1=900-y;
       lb++;
    }

    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        x2=x;
        y2=900-y;
      rb++;
    }
if(lb!=0 && rb!=0)
liang(x1,y1,x2,y2);
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Liang Barskey Clipping Algorithm");
    initgl();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}