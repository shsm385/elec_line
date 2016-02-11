#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//関数のプロトタイプ
void electricline(double length);

int main(){

  electricline(5.0);
  electricline(7.0);
  electricline(10.0);
  electricline(15.0);
     
  return 0;
}

void electricline(double length){
  double Er, Eth, x, y, th;
  double a;
  double dx, dy, dth, ds, tempdth;

  //初期設定
  x = length;
  y = 0.0;
  ds = 0.01;
  th = M_PI/2;
  dth = 0.0;
  tempdth = 0.0;
  a = M_PI/2; 
  
  while(1){
    printf("%f\t %f\n", x, -y);
    printf("%f\t %f\n", x, y);
    printf("%f\t %f\n", -x, -y);
    printf("%f\t %f\n", -x, y);
    
    //電場
    Er = cos(th)/(length*length*length);
    Eth = sin(th)/(2*length*length*length);
    
    //座標の微小変化量
    dx = -ds*cos(a -tempdth);
    dy = -ds*sin(a - tempdth);
    
    //座標の微小変化量
    x = x+dx;
    y = y+dy;

    dth = atan(fabs(y)/fabs(x));
    a = atan(fabs(Eth)/fabs(Er));
    
    th = th + dth - tempdth;
    tempdth = dth;
    length = sqrt(x*x + y*y);

    if(x<0){
      break;
    }   
  }    
}
