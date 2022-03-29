#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

float encontrar_Relu(float uRel, float l, float s)
{

    float u;
    float R;
    u = (4* PI * pow(10, -7));
    R = l/(uRel * u * s);

    return R;
    

}


float CalculoGeral(float uRel, float l1, float l2, float le, float s1, float s2, float se, float n, float i)
{

    float R1;
    float R2;
    float Re;
    float ni;
    float B1;
    float u = (4 * PI * pow(10, -7)); // permeabilidade do ar

    R1 = encontrar_Relu(uRel, l1, s1);
    R2 = encontrar_Relu(uRel, l2, s2);
    Re = encontrar_Relu(1, le, se);
    float f2pf1 = (R1 + Re) / R2;
    float F2 = (n * i) / (R2 + R1 * ((1 / f2pf1) + 1));
    float F1 = F2 / f2pf1;
    float B = F1 / se;
    
    ni = R1 * (F2 + F2) + R2 * F2;

    
    printf("relutancias: \n\tR1: %.2E \n\tR2: %.2E \n\tRe: %.2E\n", R1, R2, Re);
    printf("Fluxos encontrados: \n\tFluxo 1: %.2E \n\tFluxo 2: %.2E \n ", F1, F2);
    printf("inducao magnetica do entreferro b1: %f \n", B);
    printf("meu n x i = %.f\n", ni);
    printf("\n\n\n\n ********************************\n");

    float ur = 4973.59;
    //variaveis para trabalhar no outro software
    printf("\n\t Valores das variaveis\n");
    printf("s1 =  %.2E\n", s1 );
    printf("s2 =  %.2E\n", s2);
    printf("se =  %.2E\n", se);
    printf("l1 =  %.2E\n", l1);
    printf("l2 =  %.2E\n", l2);
    printf("l2 =  %.2E\n", l2);
    printf("le =  %.2E\n", le);
    printf("ur =  %.2E\n", ur);
    printf("u =  %.2E\n", u);
    printf("\n\n ********************************\n");

    float b1_baixo;

    /*float b1_pt1 = (l1 / u * ur * s1) + (l2 / u * ur * s2);
    float b1_pt2 = (l1 / u * ur * s1) + (le / u * ur * se);
    float b1_pt5d = (l2 / u * ur * s2);

    b1_baixo = (l1 / u * ur * s1) + ((b1_pt1 * b1_pt2)/b1_pt5d);
    float b1_se;
    b1_se = se * b1_baixo;

    B1 = ni / b1_se;*/
    printf("\n\n\n\n ********************************\n");
}

void calculo_permeabilidade(float B, float H)
{
    float mi;
    float mir;
    float u = (4 * PI * pow(10, -7)); // permeabilidade do ar
    mi = B / H;
    mir = B / (H * u);

    printf("\tmi: %.2E \tmir = %f\n", mi, mir);
}

void permeabilidade_aco_fundido(){
    printf("permeabilidade do aco fundido: \n");
    calculo_permeabilidade(0.2, 200);
    calculo_permeabilidade(0.3, 250);
    calculo_permeabilidade(0.6, 400);
    calculo_permeabilidade(0.9, 600);
    calculo_permeabilidade(1.1, 800);
    calculo_permeabilidade(1.2, 1000);
}

float permeabilidade_aco_silicio()
{
    printf("permeabilidade do aco silicio: \n");
    calculo_permeabilidade(0.3, 48);
    calculo_permeabilidade(0.4, 50);
    calculo_permeabilidade(0.6, 75);
    calculo_permeabilidade(0.8, 100);
    calculo_permeabilidade(1.0, 200);
    calculo_permeabilidade(1.2, 500);
}

float permeabilidade_ferro_fundido()
{
    printf("permeabilidade do ferro fundido: \n");
    calculo_permeabilidade(0.1, 200);
    calculo_permeabilidade(0.19, 400);
    calculo_permeabilidade(0.2, 425);
    calculo_permeabilidade(0.3, 700);
    calculo_permeabilidade(0.4, 1000);
}

int main()
{

    float uRel = 2000;
    float l1 = 0.8;
    float l2 = 0.3;
    float le = 0.0003;
    float s1 = 0.001;
    float s2 = 0.0012;
    float se = s1;
    float n = 1000;
    float i = 0.8;
    float aux = pow(10, -3);

    printf("\t questao 1;\n\n\n");

    CalculoGeral(uRel, l1, l2, le, s1, s2, se, n, i);
    permeabilidade_aco_fundido();
    permeabilidade_aco_silicio();
    permeabilidade_ferro_fundido();
}











