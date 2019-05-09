/*
 *                  UNIVERSIDAD TÉCNICA DEL NORTE 
 *                     FICA-CIERCOM-EMBEBIDOS
 * Nombre: Fernández Sergio Rolando
 * Fecha:08/05/2019
 * 
 * Tema: Regresión lineal simple
 */
#include "Datos.h" //Base de datos 
float sumxi; //Variable Suma de la fila en x
float sumyi; //VariableSuma de la fila en y
float xpromedio;//Variable promedio de x
float ypromedio;//Variable promedio de y 
float prodx[29];
float prody[29];
float ppdxy[29];
float prodx2[29];
float SSxy;
float SSxx;
float m; // Variable de la pendiente
float Bo; //Variable Ordenanda del origen
int fil=0; //Variable recorre las filas
int i=0; //Variable para realizar ciclo de impresion

void setup() {
 Serial.begin(9600); //Habilitacion CX
 
}

void loop() {
//----------------for para realizar las sumatorias x y y---------
for(;fil<29;fil++){
  sumxi=sumxi+matriz[fil][0]; //sumatoria fila x
  sumyi=sumyi+matriz[fil][1]; //sumatoria fila y
  }
  xpromedio=sumxi/29; //promedio de x
  ypromedio=sumyi/29; //promedio de y

//----------------for para realizar (xi-xpromedio) ---------
for(fil=0;fil<29;fil++){
  prodx[fil]=matriz[fil][0]-xpromedio; 
  prody[fil]=matriz[fil][1]-ypromedio; 
  }
//----------------for para realizar (xi-promedio)(yi-ypromedio)---
for(fil=0;fil<29;fil++){
   ppdxy[fil]=prodx[fil]*prody[fil];
   }
//----------------for para realizar (xi-xpromedio)^2------
for(fil=0;fil<29;fil++){
  prodx2[fil]=pow(prodx[fil],2);
}
//Serial.println(prodx2[28]);
//----------------for para realizar las sumatorias---
for(fil=0;fil<29;fil++){
  SSxy=SSxy+ppdxy[fil]; 
  SSxx=SSxx+prodx2[fil]; 
  }
  m=SSxy/SSxx; //pendiente 
  Bo=ypromedio-m*xpromedio; //Ordenanda del origen 

//--------If para realizar una impresion----------
   if(i==0){ 
   Serial.print("Pendiente m=");
   Serial.println(m);//Impresion de pendiente
   Serial.print("Ordenada del origen Bo=");
   Serial.println(Bo); //Impresion Ordenanda del origen
   Serial.println("LA ECUACION RESULTANTE");
   Serial.print("y="); //Impresion de caracteres
   Serial.print(m); //Impresion de pendiente
   Serial.print("x"); //Impresion de caracteres
   Serial.print(Bo); //Impresion Ordenanda del origen 
   i=1;
   }  
}

