/*
 *        UNIVERSIDAD TECNICA DEL NORTE 
 *            FICA-CIERCOM-EMBEBIDOS
 *  Nombre:Fernández Sergio
 *  Fecha: 03/7/2019
 *      
 */
 //----------------------Variables-------
float potone=0;
float pottwo=0;
float pconverone=0;
float pconvertwo=0;

void setup() {
  Serial.begin(9600); // Cx
}

void loop() {
   potone=analogRead(A0);
   pconverone =  potone*5/1023;
  Serial.print("Dato1:");
  Serial.println(pconverone);
   delay(500);
  pottwo=analogRead(A1);
  pconvertwo=pottwo*5/1023;
  Serial.println("Dato2:");
  delay(500);
  Serial.println(pconvertwo);
   delay(500);

if(pconverone>0 && pconverone<=1.5){
  Serial.println("Verde");
  } 
   
  if(pconverone<1.5 && pconverone<=3.5){
  Serial.println("Naranja");
  }  

if(pconverone>3.5 && pconverone<=5){
  Serial.println("Rojo");
   delay(500);
    } 
   

  }


void conteo(){
   
    Serial.print(random(100));
    }

