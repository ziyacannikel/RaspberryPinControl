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


char numara[10]; // display sayýlar için dizi
char kontrol[10]; // input kýsmýnda kullanýlacak dizi
char sayac=0;
int i;      // döngü deðiþkeni
int j;      // döngü deðiþkeni

  // PIC OUTPUT MODUNDA ÇALIÞTIRMA FONKSÝYONU
void output_mode(){
   trisb=0;
   trisa.RA1=0;
   trisa.RA5=0;

     portb=0;
     pin9=0;   // buton deðiþimi olduðunda sorun olmamasý için
     pin10=0;


 while(butonb==0 && butonc==0){  //1.BÖLGE
   portc=numara[1];  //HANGÝ BÖLGE OLDUÐU
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
     pin9=0;   // buton deðiþimi olduðunda sorun olmamasý için
     pin10=0;
  while(butonb==0 && butonc==1){ //2.BÖLGE
   portc=numara[2]; //HANGÝ BÖLGE OLDUÐU
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
     pin9=0;   // buton deðiþimi olduðunda sorun olmamasý için
     pin10=0;
  while(butonb==1 && butonc==0){ //3.BÖLGE
   portc=numara[3];   //HANGÝ BÖLGE OLDUÐU
   pin4=1;
   pin5=1;
   pin6=1;
   pin8=1;
   pin9=1;
   if(butona==1)
  {break;}
  }
     portb=0;
     pin9=0;   // buton deðiþimi olduðunda sorun olmamasý için
     pin10=0;
  while(butonb==1 && butonc==1){ //4.BÖLGE
   portc=numara[4] ;  //HANGÝ BÖLGE OLDUÐU
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
 for(i=0;i<10;i++){  // kaç tane hatalý pin var say
         if(kontrol[i]==1){
          sayac=sayac+1;
         }
       }
       if(sayac>1){ // hatalý pin 1 den fazlaysa yan-sön þeklinde yazdýr
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
       else if (sayac==1){  // tek pin sorunluysa yak geç
          for(i=0;i<10;i++){
             portc=numara[i];
          }
       }
       else if (sayac==0) // hatalý pin yoksa ledleri kapat
       {portc=0;}
}

// PIC INPUT MODUNDA ÇALIÞTIRMA FONKSÝYONU
void input_mode(){
   trisb=1;
   trisa.RA1=1;
   trisa.RA5=1;

      for(i=0;i<10;i++){  //tüm elemanlarý baþta sýfýrla
       kontrol[i]=0;
       }
    while(butonb==0 && butonc==0 ){  //1.BÖLGE

       //ÇALIÞMASI GEREKEN PÝNLERÝ KONTROL ET HATA OLANA 1 ATA
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

      yazdir(); // displaye yazdýr
      if(butona==0)
      {break;}
    }
      for(i=0;i<10;i++){  //tüm elemanlarý baþta sýfýrla
       kontrol[i]=0;
      }

    while(butonb==0 && butonc==1){  //2.BÖLGE

       //ÇALIÞMASI GEREKEN PÝNLERÝ KONTROL ET HATA OLANA 1 ATA
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
      yazdir(); // displaye yazdýr

    }
      for(i=0;i<10;i++){  //tüm elemanlarý baþta sýfýrla
       kontrol[i]=0;
      }
    while(butonb==1 && butonc==0){  //3.BÖLGE

       //ÇALIÞMASI GEREKEN PÝNLERÝ KONTROL ET HATA OLANA 1 ATA

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
      yazdir(); // displaye yazdýr

    }
      for(i=0;i<10;i++){  //tüm elemanlarý baþta sýfýrla
       kontrol[i]=0;
      }
    while(butonb==1 && butonc==1){  //4.BÖLGE

       //ÇALIÞMASI GEREKEN PÝNLERÝ KONTROL ET HATA OLANA 1 ATA
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
      yazdir(); // displaye yazdýr

    }


}

void main() {
    ADCON1 = 0B00001110; //analog-digital converter kapatmak için
    CMCON = 0x07;   // comparator kapat
    trisa.RA2=1;
    trisa.RA3=1;
    trisa.RA4=1;
    trisc=0;
    PORTB=0;
    PORTC=0;
    
    // 7 SEGMENT DÝSPLAY ÝÇÝN GEREKLÝ SAYILAR
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
             input_mode();    // input fonksiyonunu çaðýr
             }
             if(butona==0){
             output_mode();   // output fonksiyonunu çaðýr
             }
    }






}