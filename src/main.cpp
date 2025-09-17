///LIBRERIAS
#include <stdlib.h>
#include "glm.h"
#include "texture.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>

#ifdef _APPLE_
#else
#include <GL/glut.h>
#endif

#include <GL/freeglut.h>

#define PI 3.14159265

using namespace std;
///CAMARA
float zoom = 0.0f;
float rotx = 0;
float roty = 0.001f;
float tx = 0;
float ty = -0.5;
int lastx=0;
int lasty=0;
unsigned char Buttons[3] = {0};
///VARIABLES
static float y = 40;
float trasx=0, trasy=0,trasz=0;
float velocidad=0.2;
float camara = 2;
int a,b,c,d,e,f,g,h,j,k,l,m,n,o,p,q,r,s,t,u,todo;
int A1=0,A2=0,A3=0,A4=0,A5=0,A6=0,A7=0,A8=0,A9=0,A10=0,A11=0,A12=0,A13=0,A14=0,A15=0,A16=0,A17=0,A18=0;
float movCabeza=0,movCuello=0,movBrazoD=0,movBrazoI=0,movMusloD=0,movMusloI=0,movCola=0,movAlaD=0,movAlaI=0;
float movantebrazoD=0,movantebrazoI=0,manoI=0,manoD=0,movpiernaI=0,movpiernaD=0,movpieI=0,movpieD=0,movtronco=0;

///VENTANA PRINCIPAL
int main_window;

///PUNTEROS MODELO
GLMmodel* punteroM1 = NULL;
GLMmodel* punteroM2 = NULL;
GLMmodel* punteroM3 = NULL;
GLMmodel* punteroM4 = NULL;
GLMmodel* punteroM5 = NULL;
GLMmodel* punteroM6 = NULL;
GLMmodel* punteroM7 = NULL;
GLMmodel* punteroM8 = NULL;
GLMmodel* punteroM9 = NULL;
GLMmodel* punteroM10 = NULL;
GLMmodel* punteroM11 = NULL;
GLMmodel* punteroM12 = NULL;
GLMmodel* punteroM13 = NULL;
GLMmodel* punteroM14 = NULL;
GLMmodel* punteroM15 = NULL;
GLMmodel* punteroM16 = NULL;
GLMmodel* punteroM17 = NULL;
GLMmodel* punteroM18 = NULL;
GLMmodel* punteroM19 = NULL;
GLMmodel* punteroM20 = NULL;
///VARIBLES TEXTURAS
GLuint	texture;
Texture	treeTextureAr[3];
bool LoadTreeTextures()
{
	int i;
	if (LoadTGA(&treeTextureAr[0],"src/assets/textures/body.tga")
     &&LoadTGA(&treeTextureAr[1],"src/assets/textures/fullsize3.tga")
     &&LoadTGA(&treeTextureAr[2],"src/assets/textures/textura.tga"))
	{
		for (i = 0; i<3; i++){

			glGenTextures(1, &treeTextureAr[i].texID);
			glBindTexture(GL_TEXTURE_2D, treeTextureAr[i].texID);
			glTexImage2D(GL_TEXTURE_2D, 0, treeTextureAr[i].bpp / 8, treeTextureAr[i].width, treeTextureAr[i].height, 0, treeTextureAr[i].type, GL_UNSIGNED_BYTE, treeTextureAr[i].imageData);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			if (treeTextureAr[i].imageData)
			{
				free(treeTextureAr[i].imageData);
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

void IlumincaionDimencional(){
            glDisable(GL_LIGHT0);

            const GLfloat light_ambient[]  = { 0.0f, 1.0f, 0.0f, 1.0f };
            const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
            const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
            const GLfloat light_position[] = { 5.0f, 5.0f, 5.0f, 0.0f };

            const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
            const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
            const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
            const GLfloat high_shininess[] = { 100.0f };

            glDisable(GL_LIGHTING);
            glEnable(GL_LIGHT1);
            glEnable(GL_NORMALIZE);
            glEnable(GL_COLOR_MATERIAL);
            glEnable(GL_LIGHTING);

            glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient);
            glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse);
            glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
            glLightfv(GL_LIGHT1, GL_POSITION, light_position);

            glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
            glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
            glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}
void luzYMaterial(){
    const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

    const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}
void init(void)
{
	glClearColor(0.5, 0.5, 0.5, 0.0);
	LoadTreeTextures();
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
}

void dragon(void)
{
    ///TRONCO
    glPushMatrix();

       glRotatef(10,-1,0,0);

        if(a || todo){
        glTranslatef(trasx,0,trasz);
        glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
        glmDraw(punteroM1, GLM_SMOOTH | GLM_TEXTURE);
        }
            ///CUELLO
            glPushMatrix();
                if(b|| todo){
                glRotatef(movCuello,1,1,0);
                glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                glmDraw(punteroM2, GLM_SMOOTH | GLM_TEXTURE);
                }
                    ///CABEZA
                    glPushMatrix();
                        if(c|| todo){
                        glRotatef(movCabeza,1,1,0);
                        glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                        glmDraw(punteroM3, GLM_SMOOTH | GLM_TEXTURE);
                        }
                    glPopMatrix();
                    ///FIN CABEZA
            glPopMatrix();
            ///FIN CUELLO

            ///BRAZO IZQUIERDO
            glPushMatrix();
                if(d|| todo){
                glRotatef(movBrazoI,0,1,0);
                glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                glmDraw(punteroM4, GLM_SMOOTH | GLM_TEXTURE);
                }
                ///ANTEBRAZO IZQUIERDO
                glPushMatrix();
                    if(e|| todo){
                    glRotatef(movantebrazoI,0,1,0);
                    glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                    glmDraw(punteroM5, GLM_SMOOTH | GLM_TEXTURE);
                    }
                    ///MANO IZQUIERDA
                    glPushMatrix();
                        if(f|| todo){
                        glRotatef(manoI,1,0,1);
                        glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                        glmDraw(punteroM6, GLM_SMOOTH | GLM_TEXTURE);
                        }
                    glPopMatrix();
                    ///FIN MANO IZQUIERDA
                glPopMatrix();
                ///FIN ANTEBRAZO IZQUIERDO
            glPopMatrix();
            ///FIN BRAZO IZQUIERDO

            ///BRAZO DERECHO
            glPushMatrix();
                if(g|| todo){
                glRotatef(movBrazoD,0,1,0);
                glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                glmDraw(punteroM7, GLM_SMOOTH | GLM_TEXTURE);
                }
                ///ANTEBRAZO DERECHO
                glPushMatrix();
                    if(h|| todo){
                    glRotatef(movantebrazoD,0,1,0);
                    glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                    glmDraw(punteroM8, GLM_SMOOTH | GLM_TEXTURE);
                    }
                    ///MANO DERECHA
                    glPushMatrix();
                        if(j|| todo){
                        glRotatef(manoD,1,0,1);
                        glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                        glmDraw(punteroM9, GLM_SMOOTH | GLM_TEXTURE);
                        }
                    glPopMatrix();
                    ///FIN MANO DERECHA
                glPopMatrix();
                ///FIN ANTEBRAZO IZQUIERDO
            glPopMatrix();
            ///FIN BRAZO IZQUIERDO

            ///MUSLO IZQUIERDO
            glPushMatrix();
                if(k|| todo){
                glRotatef(movMusloI,1,0,1);
                glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                glmDraw(punteroM10, GLM_SMOOTH | GLM_TEXTURE);
                }
                ///PIERNA IZQUIERDA
                glPushMatrix();
                    if(l|| todo){
                    glRotatef(movpiernaI,1,1,0);
                    glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                    glmDraw(punteroM11, GLM_SMOOTH | GLM_TEXTURE);
                    }
                    ///PIE IZQUIERDO
                    glPushMatrix();
                        if(m|| todo){
                        glRotatef(movpieI,1,1,0);
                        glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                        glmDraw(punteroM12, GLM_SMOOTH | GLM_TEXTURE);
                        }
                    glPopMatrix();
                    ///FIN PIE IZQUIERDO
                glPopMatrix();
                ///FIN PIERNA IZQUIERDA
            glPopMatrix();
            ///FIN MUSLO IZQUIERDO

            ///MUSLO DERECHO
            glPushMatrix();
                if(n|| todo){
                glRotatef(movMusloD,0,1,1);
                glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                glmDraw(punteroM13, GLM_SMOOTH | GLM_TEXTURE);
                }
                ///PIERNA DERECHA
                glPushMatrix();
                    if(o|| todo){
                    glRotatef(movpiernaD,1,1,0);
                    glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                    glmDraw(punteroM14, GLM_SMOOTH | GLM_TEXTURE);
                    }
                    ///PIE DERECHO
                    glPushMatrix();
                        if(p|| todo){
                        glRotatef(movpieD,1,1,0);
                        glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                        glmDraw(punteroM15, GLM_SMOOTH | GLM_TEXTURE);
                        }
                    glPopMatrix();
                    ///FIN PIE DERECHO
                glPopMatrix();
                ///FIN PIERNA DERECHA
            glPopMatrix();
            ///FIN MUSLO DERECHO

            ///ALA IZQUIERDA
            glPushMatrix();
                if(q|| todo){
                glRotatef(movAlaI,0,1,0);
                glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                glmDraw(punteroM16, GLM_SMOOTH | GLM_TEXTURE);
                }
            glPopMatrix();
            ///FIN ALA IZQUIERDA

            ///ALA DERECHA
            glPushMatrix();
                if(r|| todo){
                glRotatef(movAlaD,0,1,0);
                glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                glmDraw(punteroM17, GLM_SMOOTH | GLM_TEXTURE);
                }
            glPopMatrix();
            ///FIN ALA DERECHA

            ///COLA
            glPushMatrix();
                if(s|| todo){
                glRotatef(movCola,1,1,1);
                glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
                glmDraw(punteroM18, GLM_SMOOTH | GLM_TEXTURE);
                }
            glPopMatrix();
            ///FIN COLA


    glPopMatrix();
    ///FIN TRONCO
    glPushMatrix();
                if(t|| todo){
                glTranslatef(0.6,-2.4,-0.8);
                glScalef(1,1,1);
                glRotatef(-20,0,1,0);
                glBindTexture(GL_TEXTURE_2D, treeTextureAr[1].texID);
                glmDraw(punteroM19, GLM_SMOOTH | GLM_TEXTURE);
                }
    glPopMatrix();

    glPushMatrix();
                if(u|| todo){
                glTranslatef(0,0,0);
                glBindTexture(GL_TEXTURE_2D, treeTextureAr[2].texID);
                glmDraw(punteroM20, GLM_SMOOTH | GLM_TEXTURE);
                }
    glPopMatrix();
}
void graficar(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camara,camara,camara, 0.0, 0.0, 0.0, 0.0f, 1.0f, 0.0f);
    glTranslatef(0,-0.5,0);
    glScalef(0.8,0.8,0.8);
    glRotatef(y, 0, 1, 0);
    glTranslatef(0,0,-zoom);//
	glTranslatef(tx,ty,0);
	glRotatef(rotx,1,0,0);
	glRotatef(roty,0,1,0);//
    dragon();
    glutSwapBuffers();
}
void myGlutIdle( void )
{
	if ( glutGetWindow() != main_window ){
		glutSetWindow(main_window);
	}
	glutPostRedisplay();
}

// Función para mostrar ayuda de controles
void mostrarAyuda() {
    printf("\n=== CONTROLES ===\n");
    printf("Movimiento:\n");
    printf("  W/S: Adelante/Atrás   A/D: Izquierda/Derecha\n");
    printf("  Flechas: También controlan movimiento\n");
    printf("Cámara/Vista:\n");
    printf("  I/K: Rotar arriba/abajo   J/L: Rotar izquierda/derecha\n");
    printf("  Z/X: Zoom in/out          +/-: Cámara cerca/lejos\n");
    printf("  R: Reset vista\n");
    printf("Partes del modelo (toggle on/off):\n");
    printf("  0: Todo   1: Tronco    2: Cuello    3: Cabeza\n");
    printf("  4: B.Izq  5: AB.Izq    6: M.Izq     7: B.Der\n");
    printf("  8: AB.Der 9: M.Der     T: Escenario U: Cielo\n");
    printf("Otros:\n");
    printf("  H: Esta ayuda   Q/ESC: Salir\n");
    printf("===============\n\n");
}

// Callback de teclado para controles sin GLUI
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        // Movimiento con WASD
        case 'a': case 'A': trasx -= velocidad; break;   // izquierda
        case 'd': case 'D': trasx += velocidad; break;   // derecha  
        case 'w': case 'W': trasz += velocidad; break;   // adelante
        case 's': case 'S': trasz -= velocidad; break;   // atrás
        
        // Zoom con z/x
        case 'z': case 'Z': zoom += 0.2f; break;
        case 'x': case 'X': zoom -= 0.2f; break;
        
        // Rotación con ijkl
        case 'j': case 'J': roty -= 2.0f; break;
        case 'l': case 'L': roty += 2.0f; break;
        case 'i': case 'I': rotx -= 2.0f; break;
        case 'k': case 'K': rotx += 2.0f; break;
        
        // Cámara más cerca/lejos
        case '+': case '=': camara -= 0.1f; break;
        case '-': case '_': camara += 0.1f; break;
        
        // Controles de partes del modelo (toggle)
        case '0': todo = !todo; break;
        case '1': a = !a; break;        // Tronco
        case '2': b = !b; break;        // Cuello
        case '3': c = !c; break;        // Cabeza
        case '4': d = !d; break;        // Brazo Izquierdo
        case '5': e = !e; break;        // Antebrazo Izquierdo  
        case '6': f = !f; break;        // Mano Izquierda
        case '7': g = !g; break;        // Brazo Derecho
        case '8': h = !h; break;        // Antebrazo Derecho
        case '9': j = !j; break;        // Mano Derecha
        case 't': case 'T': t = !t; break; // Escenario
        case 'u': case 'U': u = !u; break; // Cielo
        
        // Rotación del modelo Y
        case 'n': case 'N': y -= 2.0f; break;
        case 'm': case 'M': y += 2.0f; break;
        
        // Reset de vista
        case 'r': case 'R':
            zoom = 0.0f; rotx = 0.0f; roty = 0.001f; 
            tx = 0.0f; ty = -0.5f; trasx = 0.0f; trasy = 0.0f; trasz = 0.0f; 
            camara = 2.0f; y = 40.0f;
            break;
            
        // Ayuda
        case 'h': case 'H': mostrarAyuda(); break;
        
        // Salir
        case 27: /* ESC */ exit(0);
        case 'q': case 'Q': exit(0);
        
        default: break;
    }
    glutPostRedisplay();
}
///COMIENZO CAMARA
void reshape(int w, int h)
{
	if(w==0)
		h = 1;

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,(float)w/h,0.1,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


//-------------------------------------------------------------------------------
//
void Motion(int x,int y)
{
	int diffx=x-lastx;
	int diffy=y-lasty;
	lastx=x;
	lasty=y;

	if( Buttons[0] && Buttons[1] )
	{
		zoom -= (float) 0.05f * diffx;
	}
	else
		if( Buttons[0] )
		{
			rotx += (float) 0.5f * diffy;
			roty += (float) 0.5f * diffx;
		}
		else
			if( Buttons[1] )
			{
				tx += (float) 0.05f * diffx;
				ty -= (float) 0.05f * diffy;
			}
			glutPostRedisplay();
}

//-------------------------------------------------------------------------------
//
void mouseWheel(int button, int dir, int x, int y){
    if (dir > 0){


            camara = camara - 0.1;
        }
        else {

            camara = camara + 0.1;
        }

    glutPostRedisplay();
    return;
}
void Mouse(int b,int s,int x,int y)
{
	lastx=x;
	lasty=y;
	switch(b)
	{
	case GLUT_LEFT_BUTTON:
		Buttons[0] = ((GLUT_DOWN==s)?1:0);
		break;
	case GLUT_MIDDLE_BUTTON:
		Buttons[1] = ((GLUT_DOWN==s)?1:0);
		break;
	case GLUT_RIGHT_BUTTON:
		Buttons[2] = ((GLUT_DOWN==s)?1:0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}///FIN CAMARA


void Cabeza(int i){
     switch(A1){
     case 0:
         if(movCabeza<1){
             movCabeza= movCabeza+0.1;
         }else{
            A1 = 1;
        }
     break;
     case 1:
         if(movCabeza>1){
             movCabeza = movCabeza-0.1;
         }else
             A1 = 0;
     }
    glutPostRedisplay();
    glutTimerFunc(20,Cabeza,1);
}
void Cuello(int i){
     switch(A2){
     case 0:
         if(movCuello<1){
             movCuello = movCuello + 0.1;
         }else{
            A2 = 1;
        }
     break;
     case 1:
         if(movCuello>-1){
             movCuello = movCuello - 0.1;
         }else
            A2 = 0;
     }
    glutPostRedisplay();
    glutTimerFunc(20,Cuello,2);
}
void Tronco(int i){
     switch(A3){
     case 0:
         if(movtronco<0.2){
             movtronco = movtronco + 0.05;
         }else{
            A3 = 1;
        }
     break;
     case 1:
         if(movtronco>-0.2){
             movtronco = movtronco - 0.05;
         }else
             A3 = 0;
     }
    glutPostRedisplay();
    glutTimerFunc(80,Tronco,3);
}
void AlaD(int i){
     switch(A4){
     case 0:
         if(movAlaD<15){
             movAlaD = movAlaD + 0.5;
         }else{
            A4 = 1;
        }
     break;
     case 1:
         if(movAlaD>-1){
             movAlaD = movAlaD - 0.5;
         }else
             A4 = 0;
     }

    glutPostRedisplay();
    glutTimerFunc(15,AlaD,4);
}
void AlaI(int i){
     switch(A5){
     case 0:
         if(movAlaI<12){
             movAlaI = movAlaI + 0.5;
         }else{
            A5 = 1;
        }
     break;
     case 1:
         if(movAlaI>-1){
             movAlaI = movAlaI - 0.5;
         }else
             A5 = 0;
     }

    glutPostRedisplay();
    glutTimerFunc(15,AlaI,5);
}
void BrazoD(int i){
     switch(A6){
     case 0:
         if(movBrazoD<0.8){
             movBrazoD = movBrazoD + 0.1;
         }else{
            A6 = 1;
        }
     break;
     case 1:
         if(movBrazoD>-0.8){
             movBrazoD = movBrazoD - 0.1;
         }else
             A6 = 0;

     }
    glutPostRedisplay();
    glutTimerFunc(30,BrazoD,6);
}
void BrazoI(int i){
     switch(A7){
     case 0:
         if(movBrazoI<0.8){
             movBrazoI = movBrazoI + 0.1;
         }else{
            A7 = 1;
        }
     break;
     case 1:
         if(movBrazoI>-0.8){
             movBrazoI = movBrazoI - 0.1;
         }else
             A7 = 0;

     }
    glutPostRedisplay();
    glutTimerFunc(30,BrazoI,7);
}
void AntebrazoD(int i){
    switch(A8){
     case 0:
         if(movantebrazoD<0.5){
             movantebrazoD = movantebrazoD + 0.1;
         }else{
            A8 = 1;
        }
     break;
     case 1:
         if(movantebrazoD>-0.5){
             movantebrazoD = movantebrazoD - 0.1;
         }else
             A8 = 0;

     }
    glutPostRedisplay();
    glutTimerFunc(30,AntebrazoD,8);
}
void AntebrazoI(int i){
    switch(A9){
     case 0:
         if(movantebrazoI<0.8){
             movantebrazoI = movantebrazoI + 0.1;
         }else{
            A9 = 1;
        }
     break;
     case 1:
         if(movantebrazoI>-0.8){
             movantebrazoI = movantebrazoI - 0.1;
         }else
             A9 = 0;

     }
    glutPostRedisplay();
    glutTimerFunc(30,AntebrazoI,9);
}
void ManoD(int i){
    switch(A10){
     case 0:
         if(manoD<0.8){
             manoD = manoD + 0.1;
         }else{
            A10 = 1;
        }
     break;
     case 1:
         if(manoD>-0.8){
             manoD = manoD - 0.1;
         }else
             A10 = 0;

     }
    glutPostRedisplay();
    glutTimerFunc(30,ManoD,10);
}
void ManoI(int i){
    switch(A11){
     case 0:
         if(manoI<0.8){
             manoI = manoI + 0.1;
         }else{
            A11 = 1;
        }
     break;
     case 1:
         if(manoI>-0.8){
             manoI = manoI - 0.1;
         }else
             A11 = 0;

     }
    glutPostRedisplay();
    glutTimerFunc(30,ManoI,11);
}
void MusloD(int i){
    switch(A12){

    case 0:
            if(movMusloD<1){
                movMusloD = movMusloD+0.1;
            }else{
                A12 = 1;
            }
    break;
    case 1:
            if(movMusloD>-1){
                movMusloD = movMusloD -0.1;
            }else{
                A12 = 0;
            }
    break;
    }
    glutPostRedisplay();
    glutTimerFunc(30,MusloD,12);
}
void MusloI(int i){
     switch(A13){

    case 0:
            if(movMusloI<1){
                movMusloI = movMusloI+0.1;
            }else{
                A13 = 1;
            }
    break;
    case 1:
            if(movMusloI>-1){
                movMusloI = movMusloI -0.1;
            }else{
                A13 = 0;
            }
    break;
    }
    glutPostRedisplay();
    glutTimerFunc(30,MusloI,13);
}
void PiernaD(int i){
    switch(A14){

    case 0:
        if(movpiernaD<0.8){
            movpiernaD = movpiernaD+0.1;
        }else{
            A14 = 1;
        }
    break;
    case 1:
        if(movpiernaD>-0.8){
            movpiernaD = movpiernaD -0.1;
        }else{
            A14 = 0;
        }
    break;
    }
    glutPostRedisplay();
    glutTimerFunc(30,PiernaD,14);
}
void PiernaI(int i){
    switch(A15){

    case 0:
        if(movpiernaI<0.8){
            movpiernaI = movpiernaI+0.1;
        }else{
            A15 = 1;
        }
    break;
    case 1:
        if(movpiernaI>-0.8){
            movpiernaI = movpiernaI -0.1;
        }else{
            A15 = 0;
        }
    break;
    }
    glutPostRedisplay();
    glutTimerFunc(30,PiernaI,15);
}
void PieD(int i){
    switch(A16){

    case 0:
        if(movpieD<0.8){
            movpieD = movpieD+0.1;
        }else{
            A16 = 1;
        }
    break;
    case 1:
        if(movpieD>-0.8){
            movpieD = movpieD -0.1;
        }else{
            A16 = 0;
        }
    break;
    }
    glutPostRedisplay();
    glutTimerFunc(30,PieD,16);
}
void PieI(int i){
    switch(A17){

    case 0:
        if(movpieI<0.8){
            movpieI = movpieI+0.1;
        }else{
            A17 = 1;
        }
    break;
    case 1:
        if(movpieI>-0.8){
            movpieI = movpieI -0.1;
        }else{
            A17 = 0;
        }
    break;
    }
    glutPostRedisplay();
    glutTimerFunc(30,PieI,17);
}
void Cola(int i){
    switch(A18){

    case 0:
        if(movCola<5){
            movCola = movCola+0.1;
        }else{
            A18 = 1;
        }
    break;
    case 1:
        if(movCola>-4){
            movCola = movCola -0.1;
        }else{
            A18 = 0;
        }
    break;
    }
    glutPostRedisplay();
    glutTimerFunc(30,Cola,17);
}

void volardr(int key, int x, int y){
  switch (key){
  case GLUT_KEY_RIGHT :
    trasx+= velocidad;
    glutPostRedisplay() ;
    break ;
  case GLUT_KEY_LEFT :
      trasx-= velocidad ;
      glutPostRedisplay() ;
      break ;
  case GLUT_KEY_UP :
    trasz+= velocidad ;
    glutPostRedisplay() ;
    break ;
  case GLUT_KEY_DOWN :
      trasz-= velocidad ;
      glutPostRedisplay() ;
      break ;
  }
}
int main(int argc, char** argv)
{
    // Mostrar controles al inicio
    printf("DRAGON 3D - Version Linux (sin GLUI)\n");
    mostrarAyuda();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(50, -50);

	///NOMBRAR VENTANA PRINCIPAL
	main_window = glutCreateWindow( "DRAGON 3D - Linux" );
	init();
	///iluminacion
	 luzYMaterial();

    // Por defecto, mostrar todo el modelo (sin GLUI)
    todo = 1; a=b=c=d=e=f=g=h=j=k=l=m=n=o=p=q=r=s=t=u=1;

	///modelos OBJ
    punteroM1 = glmReadOBJ("src/assets/models3d/Tronco.obj");
    punteroM2 = glmReadOBJ("src/assets/models3d/Cuello.obj");
    punteroM3 = glmReadOBJ("src/assets/models3d/Cabeza.obj");
    punteroM4 = glmReadOBJ("src/assets/models3d/BrazoIzquierdo.obj");
    punteroM5 = glmReadOBJ("src/assets/models3d/AntebrazoIzquierdo.obj");
    punteroM6 = glmReadOBJ("src/assets/models3d/ManoIzquierda.obj");
    punteroM7 = glmReadOBJ("src/assets/models3d/BrazoDerecho.obj");
    punteroM8 = glmReadOBJ("src/assets/models3d/AntebrazoDerecho.obj");
    punteroM9 = glmReadOBJ("src/assets/models3d/ManoDerecha.obj");
    punteroM10 = glmReadOBJ("src/assets/models3d/MusloIzquierdo.obj");
    punteroM11 = glmReadOBJ("src/assets/models3d/PiernaIzquierda.obj");
    punteroM12 = glmReadOBJ("src/assets/models3d/PieIzquierdo.obj");
    punteroM13 = glmReadOBJ("src/assets/models3d/MusloDerecho.obj");
    punteroM14 = glmReadOBJ("src/assets/models3d/PiernaDerecha.obj");
    punteroM15 = glmReadOBJ("src/assets/models3d/PieDerecho.obj");
    punteroM16 = glmReadOBJ("src/assets/models3d/AlaIzquierda.obj");
    punteroM17 = glmReadOBJ("src/assets/models3d/AlaDerecha.obj");
    punteroM18 = glmReadOBJ("src/assets/models3d/Cola.obj");
    punteroM19 = glmReadOBJ("src/assets/models3d/Escenario.obj");
    punteroM20 = glmReadOBJ("src/assets/models3d/cielo.obj");

	glutDisplayFunc(graficar);
    glutReshapeFunc(reshape);
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
    glutMouseWheelFunc(mouseWheel);
    glutSpecialFunc(volardr); // Flechas
    glutKeyboardFunc(keyboard); // Controles por teclado
    glutIdleFunc(myGlutIdle);

	///ANIMACIONES
	glutTimerFunc(5,Cabeza,1);
	glutTimerFunc(5,Cuello,2);
    glutTimerFunc(50,Tronco,3);
    glutTimerFunc(5,AlaD,4);
    glutTimerFunc(5,AlaI,5);
    glutTimerFunc(30,BrazoD,6);
	glutTimerFunc(30,BrazoI,7);
    glutTimerFunc(30,AntebrazoD,8);
    glutTimerFunc(30,AntebrazoI,9);
    glutTimerFunc(30,ManoD,10);
    glutTimerFunc(30,ManoI,11);
	glutTimerFunc(30,MusloD,12);
    glutTimerFunc(30,MusloI,13);
    glutTimerFunc(30,PiernaD,14);
    glutTimerFunc(30,PiernaI,15);
    glutTimerFunc(30,PieD,16);
	glutTimerFunc(30,PieI,17);
    glutTimerFunc(30,Cola,18);

	glutMainLoop();
	return 0;
}


