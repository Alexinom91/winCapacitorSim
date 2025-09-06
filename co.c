
#include <math.h>
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#include <wincon.h>
#endif
#include <stdlib.h>

#ifdef __linux__
    #define CLEAR() system("clear")
#elif _WIN32
    #define CLEAR() system("cls")
#else
    #define CLEAR() ((void)0)
#endif

#ifdef __linux__
    #include <termios.h>
    
    static struct termios old, current;

    
    void initTermios(int echo) 
    {
    tcgetattr(0, &old); 
    current = old; 
    current.c_lflag &= ~ICANON; 
    if (echo) 
    {
        current.c_lflag |= ECHO; 
    }
    else 
    {
        current.c_lflag &= ~ECHO; 
    }
    tcsetattr(0, TCSANOW, &current); 
    }

    
    void resetTermios(void) 
    {
    tcsetattr(0, TCSANOW, &old);
    }

    
    char getch_(int echo) 
    {
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
    }

    char getch(void) 
    {
    return getch_(0);
    }

    #define GETCH() getch()

#elif _WIN32
    #define GETCH() system("pause>nul")
#else
    #define GETCH() ((void)0)
#endif


#define TYPE double

void lecture(TYPE *potGen, TYPE *capCap,  TYPE *freq,  TYPE *resis, int *cicli);
void Trcharge( TYPE  Vg,  TYPE vMin,  TYPE *vMax,  TYPE Ev);
TYPE partev(   TYPE freq,  TYPE resis,  TYPE capCap);
void TrDischarge( TYPE *vMin,  TYPE vMax , TYPE Ev);

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
int main(void)
{   
    
    //dichiaro le varibili
    TYPE potGen, capCap, freq, resis, vMax, vMin, Ev;
    int i=0, cicli;
   
    


    

    lecture( &potGen, &capCap, &freq, &resis, &cicli);
    Ev=partev( freq, resis, capCap);
    
   
    
    //
    vMax=potGen;
    vMin=( TYPE)0;
    for(i=0; i<cicli; i++)
    {   Trcharge( potGen,  vMin, &vMax,   Ev);
        TrDischarge(&vMin,  vMax , Ev);
    }
    CLEAR();
    printf("Il delta dovrebbe essere di %.18lf\n", ( TYPE)vMax - vMin);
    printf("vMax = %.18lf, vMin = %.18lf\n", vMax, vMin);
    GETCH();


   

    return 0;
}

void lecture(TYPE *potGen, TYPE *capCap, TYPE *freq, TYPE *resis, int *cicli)
{
    printf("Per tutte le misure che ti verranno richieste puoi inserire solo fino alla 16esima cifra decimale\n");
    GETCH();
    CLEAR();

    printf("Inserisci la tensione in V massima con cui viene alimentato il condensatore con un'onda quadra periodica avente duty cycle di 1/2: ");
    if (scanf("%lf", potGen) != 1) {
        printf("Errore nella lettura della tensione.\n");
        clearInputBuffer();
    }

    printf("Inserisci la capacita' del condensatore in F: ");
    if (scanf("%lf", capCap) != 1) {
        printf("Errore nella lettura della capacita'.\n");
        clearInputBuffer();
    }

    printf("Inserisci la frequenza del periodo di oscillazione dell'onda periodica generata dal generatore in Hz: ");
    if (scanf("%lf", freq) != 1) {
        printf("Errore nella lettura della frequenza.\n");
        clearInputBuffer();
    }

    printf("Inserisci la resistenza in OHM della/e resistenza/e in serie al condensatore del circuito RC: ");
    if (scanf("%lf", resis) != 1) {
        printf("Errore nella lettura della resistenza.\n");
        clearInputBuffer();
    }

    printf("Inserisci dopo quanti cicli vuoi vedere la delta V: ");
    if (scanf("%d", cicli) != 1) {
        printf("Errore nella lettura dei cicli.\n");
        clearInputBuffer();
    }
	CLEAR();
    // Debug
    printf("Debug: potGen = %.18lf, capCap = %.18lf, freq = %.18lf, resis = %.18lf, cicli = %d\n", *potGen, *capCap, *freq, *resis, *cicli);
    GETCH();
}



void Trcharge(TYPE  Vg, TYPE vMin,  TYPE *vMax,   TYPE Ev)
{
     TYPE pass1;
    pass1=(TYPE)1-Ev;
    *vMax=Vg-vMin;
    *vMax=(*vMax)*pass1;
    *vMax=(*vMax)+(vMin);
    
    
}
void TrDischarge( TYPE *vMin,  TYPE vMax , TYPE Ev)
{
    
    *vMin=(vMax)*(Ev);
    
    
}


TYPE partev(  TYPE freq,  TYPE resis,  TYPE capCap)
{   const  TYPE E=2.71828182845904523536;
    TYPE Ev, TAU ;
    TAU=resis*capCap;
    TYPE period=( TYPE)1/freq;
    period=(TYPE )period/2;
    

    Ev = powl(E, -(period / TAU));

    
    return Ev;
    
}
