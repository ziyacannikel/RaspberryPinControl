#define butona PORTA.RA2
#define butonb PORTA.RA3
#define butonc PORTA.RA4
#define pin1   PORTB.RB0
#define pin2   PORTB.RB1
#define pin3   PORTB.RB2
#define pin4   PORTB.RB3
#define pin5   PORTB.RB4
#define pin6   PORTB.RB5
#define pin7   PORTB.RB6
#define pin8   PORTB.RB7
#define pin9   PORTA.RA1
#define pin10  PORTA.RA5


char numara[10]; // display say�lar i�in dizi
char kontrol[10]; // input k�sm�nda kullan�lacak dizi
char sayac=0;
int i;      // d�ng� de�i�keni
int j;      // d�ng� de�i�keni

  // PIC OUTPUT MODUNDA �ALI�TIRMA FONKS�YONU
void output_mode(){
   trisb=0;
   trisa.RA1=0;
   trisa.RA5=0;

     portb=0;
     pin9=0;   // buton de�i�imi oldu�unda sorun olmamas� i�in
     pin10=0;


 while(butonb==0 && butonc==0){  //1.B�LGE
   portc=numara[1];  //HANG� B�LGE OLDU�U
   pin2=1;
   pin3=1;
   pin4=1;
   pin6=1;
   pin7=1;
   pin8=1;
   pin10=1;
   if(butona==1)
  {break;}
  }
     portb=0;
     pin9=0;   // buton de�i�imi oldu�unda sorun olmamas� i�in
     pin10=0;
  while(butonb==0 && butonc==1){ //2.B�LGE
   portc=numara[2]; //HANG� B�LGE OLDU�U
   pin1=1;
   pin2=1;
   pin5=1;
   pin6=1;
   pin7=1;
   pin8=1;
   pin9=1;
   if(butona==1)
  {break;}
  }
     portb=0;
     pin9=0;   // buton de�i�imi oldu�unda sorun olmamas� i�in
     pin10=0;
  while(butonb==1 && butonc==0){ //3.B�LGE
   portc=numara[3];   //HANG� B�LGE OLDU�U
   pin4=1;
   pin5=1;
   pin6=1;
   pin8=1;
   pin9=1;
   if(butona==1)
  {break;}
  }
     portb=0;
     pin9=0;   // buton de�i�imi oldu�unda sorun olmamas� i�in
     pin10=0;
  while(butonb==1 && butonc==1){ //4.B�LGE
   portc=numara[4] ;  //HANG� B�LGE OLDU�U
   pin1=1;
   pin2=1;
   pin3=1;
   pin6=1;
   pin8=1;
   pin9=1;
   pin10=1;
   if(butona==1)
  {break;}
  }

}
void yazdir(){
 for(i=0;i<10;i++){  // ka� tane hatal� pin var say
         if(kontrol[i]==1){
          sayac=sayac+1;
         }
       }
       if(sayac>1){ // hatal� pin 1 den fazlaysa yan-s�n �eklinde yazd�r
         for(i=0;i<10;i++){
           if(kontrol[i]==1){
              for(j=0;j<3;j++){

                if(butona==0)
                 {break;}
                portc=numara[i];
                delay_ms(500);
               if(butona==0)
                 {break;}
               portc=0;
               delay_ms(500);
              }

           }

         }

       }
       else if (sayac==1){  // tek pin sorunluysa yak ge�
          for(i=0;i<10;i++){
             portc=numara[i];
          }
       }
       else if (sayac==0) // hatal� pin yoksa ledleri kapat
       {portc=0;}
}

// PIC INPUT MODUNDA �ALI�TIRMA FONKS�YONU
void input_mode(){
   trisb=1;
   trisa.RA1=1;
   trisa.RA5=1;

      for(i=0;i<10;i++){  //t�m elemanlar� ba�ta s�f�rla
       kontrol[i]=0;
       }
    while(butonb==0 && butonc==0 ){  //1.B�LGE

       //�ALI�MASI GEREKEN P�NLER� KONTROL ET HATA OLANA 1 ATA
      if( pin2==0)
      {kontrol[1]=1;}

      if( pin3==0)
      {kontrol[2]=1;}

      if( pin4==0)
      {kontrol[3]=1;}

      if( pin6==0)
      {kontrol[5]=1;}

      if( pin7==0)
      {kontrol[6]=1;}

      if( pin8==0)
      {kontrol[7]=1;}

      if( pin10==0)
      {kontrol[9]=1;}

      yazdir(); // displaye yazd�r
      if(butona==0)
      {break;}
    }
      for(i=0;i<10;i++){  //t�m elemanlar� ba�ta s�f�rla
       kontrol[i]=0;
      }

    while(butonb==0 && butonc==1){  //2.B�LGE

       //�ALI�MASI GEREKEN P�NLER� KONTROL ET HATA OLANA 1 ATA
      if( pin1==0)
      {kontrol[0]=1;}

      if( pin2==0)
      {kontrol[1]=1;}

      if( pin5==0)
      {kontrol[4]=1;}

      if( pin6==0)
      {kontrol[5]=1;}

      if( pin7==0)
      {kontrol[6]=1;}

      if( pin8==0)
      {kontrol[7]=1;}

      if(pin9==0)
      {kontrol[8]=1;}

      if(butona==0)
      {break;}
      yazdir(); // displaye yazd�r

    }
      for(i=0;i<10;i++){  //t�m elemanlar� ba�ta s�f�rla
       kontrol[i]=0;
      }
    while(butonb==1 && butonc==0){  //3.B�LGE

       //�ALI�MASI GEREKEN P�NLER� KONTROL ET HATA OLANA 1 ATA

      if( pin4==0)
      {kontrol[3]=1;}

      if( pin5==0)
      {kontrol[4]=1;}

      if( pin6==0)
      {kontrol[5]=1;}

      if( pin8==0)
      {kontrol[7]=1;}

      if(pin9==0)
      {kontrol[8]=1;}
      if(butona==0)
      {break;}
      yazdir(); // displaye yazd�r

    }
      for(i=0;i<10;i++){  //t�m elemanlar� ba�ta s�f�rla
       kontrol[i]=0;
      }
    while(butonb==1 && butonc==1){  //4.B�LGE

       //�ALI�MASI GEREKEN P�NLER� KONTROL ET HATA OLANA 1 ATA
      if( pin1==0)
      {kontrol[0]=1;}

      if( pin2==0)
      {kontrol[1]=1;}

      if( pin3==0)
      {kontrol[2]=1;}

      if( pin6==0)
      {kontrol[5]=1;}

      if( pin8==0)
      {kontrol[7]=1;}

      if(pin9==0)
      {kontrol[8]=1;}

      if( pin10==0)
      {kontrol[9]=1;}
       if(butona==0)
      {break;}
      yazdir(); // displaye yazd�r

    }


}

void main() {
    ADCON1 = 0B00001110; //analog-digital converter kapatmak i�in
    CMCON = 0x07;   // comparator kapat
    trisa.RA2=1;
    trisa.RA3=1;
    trisa.RA4=1;
    trisc=0;
    PORTB=0;
    PORTC=0;
    
    // 7 SEGMENT D�SPLAY ���N GEREKL� SAYILAR
    numara[0]=0x3f;
    numara[1]=0x06;
    numara[2]=0x5b;
    numara[3]=0x4f;
    numara[4]=0x66;
    numara[5]=0x6d;
    numara[6]=0x7c;
    numara[7]=0x07;
    numara[8]=0x7f;
    numara[9]=0x67;


    while(1) {
             if(butona ==1){
             input_mode();    // input fonksiyonunu �a��r
             }
             if(butona==0){
             output_mode();   // output fonksiyonunu �a��r
             }
    }






}