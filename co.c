
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <wincon.h>
#include <stdlib.h>


void lecture(double *potGen, double *capCap,  double *freq,  double *resis, int *cicli);
void Trcharge( double  Vg,  double vMin,  double *vMax,  double Ev);
double partev(   double freq,  double resis,  double capCap);
void TrDischarge( double *vMin,  double vMax , double Ev);

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
int main(void)
{   
    
    //dichiaro le varibili
    double potGen, potCap, capCap, freq, vMaxSt, vMinSt, cycle, resis, period, vMax, vMin, Ev, TAU;
    int i=0, cicli;
   
    


    

    lecture( &potGen, &capCap, &freq, &resis, &cicli);
    Ev=partev( freq, resis, capCap);
    
   
    
    //
    vMax=potGen;
    vMin=( double)0;
    for(i=0; i<cicli; i++)
    {   Trcharge( potGen,  vMin, &vMax,   Ev);
        TrDischarge(&vMin,  vMax , Ev);
    }
    system("cls");
    printf("Il delta dovrebbe essere di %.18Lf\n", ( double)vMax - vMin);
    printf("vMax = %.18lf, vMin = %.18lf\n", vMax, vMin);
    system("pause>nul");


   

    return 0;
}

void lecture(double *potGen, double *capCap, double *freq, double *resis, int *cicli)
{
    printf("Per tutte le misure che ti verranno richieste puoi inserire solo fino alla 16esima cifra decimale\n");
    system("pause>nul");
    system("cls");

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
	system("cls");
    // Debug
    printf("Debug: potGen = %.18lf, capCap = %.18lf, freq = %.18lf, resis = %.18lf, cicli = %d\n", *potGen, *capCap, *freq, *resis, *cicli);
    system("pause>nul");
}



void Trcharge(double  Vg, double vMin,  double *vMax,   double Ev)
{
     double pass1, pass2, pass3 ;
    pass1=(double)1-Ev;
    *vMax=Vg-vMin;
    *vMax=(*vMax)*pass1;
    *vMax=(*vMax)+(vMin);
    
    
}
void TrDischarge( double *vMin,  double vMax , double Ev)
{
    
    *vMin=(vMax)*(Ev);
    
    
}


double partev(  double freq,  double resis,  double capCap)
{   const  double E=2.71828182845904523536;
    double pass1, pass2, pass3, Ev, TAU ;
    TAU=resis*capCap;
    double period=( double)1/freq;
    period=(double )period/2;
    

    Ev = powl(E, -(period / TAU));

    
    return Ev;
    
}
