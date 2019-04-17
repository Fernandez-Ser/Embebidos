/*
 *            UNIVERSIDAD TÉCNICA DEL NORTE 
 *                FICA-CIERCOM-EMBEBIDOS
 * Nombre: Fernandez Sergio
 * Fecha: 16/04/2019
 *      
 */


#include "datos.h"  //Matriz de entrenamiento
int on;
void setup() {
  Serial.begin(9600);// Habilitacion de comunicacion serial
  
}

void loop() {
  on=knn(90,5,3,3);
  switch(on){
    case 1:
    Serial.println("Iris-Setosa");
    break;
    case 2:
    Serial.println("Iris-Versicolor");
    break;
    case 3:
    Serial.println("Iris-Virginica");
    break;
  }
}

int knn(int fil, int columna, int vecinos, int etiquetas){
int col;
int fila=0;
float promedio=0; 
float distancia=0; //raiz entre 2 puntos
float datos_entrada[5]={5.2,3.5,1.5,0.2,1};
int k=3;
float dist_menores[2][k];
int i=0;
int j;
int x=0;
float respuesta;
float mayor=0;
float num_etiquetas[2][etiquetas];
float aux,aux1;

 
 for(;i<k;i++){
    dist_menores[0][i]=4000+i;
    dist_menores[1][i]=0;
  }
  i=0;
  for(;i<k;i++){
   num_etiquetas[0][i]=i+1;
   num_etiquetas[1][i]=0;  
  }
  i=0; 

for(;fila<fil;fila++){
     for(col=0;col<columna-2;col++){
     promedio=promedio+pow(datos_entrada[col]-matriz[fila][col],2);
     distancia= sqrt(promedio);//Raiz del promedio
     promedio=0;
     if(distancia,dist_menores[0][k-1]){
      dist_menores[0][k-1]=distancia;
      dist_menores[1][k-1]=matriz[fila][4];
      
     }
     //ordenamiento de vector de menor a mayor
     for(i=0;i<k;i++){
      for(j=i+1;j<k;j++){
        if(dist_menores[0][i]>dist_menores[0][j]){
          aux=dist_menores[0][i];
          dist_menores[0][i]=dist_menores[0][j];
          dist_menores[0][j]=aux;
          //etiquetas
          aux1=dist_menores[1][i];
          dist_menores[1][i]=dist_menores[1][j];
          dist_menores[1][j]=aux1;
        }
      }
     }
     
     }
     for(i=0;i<k;i++){
      for(j=0;j<k;j++){
        if(num_etiquetas[0][i]=dist_menores[1][j]){
        num_etiquetas[1][i]=1+num_etiquetas[1][j];
      }
     }
     
  }
 //etiquetas
  for(;x<k;x++){
  if(num_etiquetas[1][x]>mayor){
    mayor=num_etiquetas[1][x];
    respuesta=num_etiquetas[0][x];
  }
}
return(respuesta);

}
}
