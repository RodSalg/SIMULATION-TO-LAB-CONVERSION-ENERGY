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

float calculoCircuito(float uRel, float l1, float l2, float le, float s1, float s2, float se, float n, float i)
{

    float R1;
    float R2;
    float Re;

    R1 = encontrar_Relu(uRel, l1, s1);
    R2 = encontrar_Relu(uRel, l2, s2);
    Re = encontrar_Relu(1, le, se);
    float f2pf1 = (R1 + Re) / R2;
    float F2 = (n * i) / (R2 + R1 * ((1 / f2pf1) + 1));
    float F1 = F2 / f2pf1;
    float B = F1 / se;

    printf("relutancias: \nR1: %.2E \nR2: %.2E \nRe: %.2E\n", R1, R2, Re);
    printf("Fluxos encontrados: \nFluxo 1: %f \nFluxo 2: %f \n ", F1, F2);
    printf("inducao magnetica do entregerro b1: %f \n", B);
    printf("catchau\n\n\n\n ********************************\n");
    
}

void permeabilidade_aco_fundido(float B, float H){
    float mi;
    float mir;
    float u = (4 * PI * pow(10, -7)); //permeabilidade do ar
    mi = B / H;
    mir = B/ (H * u );

    printf("\tmi: %.2E \tmir = %f\n", mi, mir);


}

float permeabilidade_aco_silicio(float B, float H)
{
    float mi;
    float mir;
    float u = (4 * PI * pow(10, -7)); // permeabilidade do ar
    mi = B / H;
    mir = B / (H * u);

    printf("\tmi: %.2E \tmir = %f\n", mi, mir);
}

float permeabilidade_ferro_fundido(float B, float H)
{
    float mi;
    float mir;
    float u = (4 * PI * pow(10, -7)); // permeabilidade do ar
    mi = B / H;
    mir = B / (H * u);

    printf("\tmi: %.2E \tmir = %f\n", mi, mir);
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

    calculoCircuito(uRel, l1, l2, le, s1, s2, se, n, i);
    printf("permeabilidade do aco fundido: \n");
    permeabilidade_aco_fundido(0.2, 200);
    permeabilidade_aco_fundido(0.3, 250);
    permeabilidade_aco_fundido(0.6, 400);
    permeabilidade_aco_fundido(0.9, 600);
    permeabilidade_aco_fundido(1.1, 800);
    permeabilidade_aco_fundido(1.2, 1000);
    printf("permeabilidade do aco silicio: \n");
    permeabilidade_aco_silicio(0.3, 48);
    permeabilidade_aco_silicio(0.4, 50);
    permeabilidade_aco_silicio(0.6, 75);
    permeabilidade_aco_silicio(0.8, 100);
    permeabilidade_aco_silicio(1.0, 200);
    permeabilidade_aco_silicio(1.2, 500);
    printf("permeabilidade do ferro fundido: \n");
    permeabilidade_ferro_fundido(0.1, 200);
    permeabilidade_ferro_fundido(0.19, 400);
    permeabilidade_ferro_fundido(0.2, 425);
    permeabilidade_ferro_fundido(0.3, 700);
    permeabilidade_ferro_fundido(0.4, 1000);
}











