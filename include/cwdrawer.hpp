#ifndef CWDRAWER
#define CWDRAWER
#include <stdlib.h>
#include <math.h>
namespace cwdrawer{
    struct color{
        int r,g,b;
        color(){
            r=0;
            g=0;
            b=0;
        }
        color(const color & c){
            r=c.r;
            g=c.g;
            b=c.b;
        }
        color & operator=(const color & c){
            r=c.r;
            g=c.g;
            b=c.b;
            return *this;
        }
    };
    class base{
      public:
        int x,y;
        int lightmode,backgroundmode;
        int deflight,colorplus;
      public:
        virtual bool getUsual(int x,int y){
            return rand()%2;
        }
        virtual bool getUnusual(int x,int y)=0;
        virtual void draw(int x,int y,int r,int g,int b)=0;
        
      public:
        base(int x,int y){
            this->x=x;
            this->y=y;
            this->deflight=8;
            this->colorplus=64;
        }
        ~base(){}
        virtual void render(){
            color c;
            bool    usu;
            bool    unu;
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    usu=getUsual    (i,j);
                    unu=getUnusual  (i,j);
                    getNormalColor  (usu,backgroundmode ,c);
                    addLight        (unu,lightmode      ,c);
                    draw(i,j,c.r,c.g,c.b);
                }
            }
        }
      private:
        base();
        void getNormalColor(bool v,int mode,color & c){
            bool val=v;
            int light   =rand()%64;
            int col     =(rand()%32)+this->colorplus;
            c.r=light;
            c.g=light;
            c.b=light;
            if(mode==1)
                val=!val;
            if(val){
                if(rand()%2==1)
                    c.r+=col;
                else{
                    c.r+=col;
                    c.g+=col;
                }
            }else{
                if(rand()%2==1)
                    c.g+=col;
                else
                    c.b+=col;
            }
        }
        void addLight(bool v,int mode,color & c){
            bool val=v;
            if(mode==1)
                val=!val;
            if(val){
                int light=(rand()%64)+this->deflight;
                c.r+=light;
                c.g+=light;
                c.b+=light;
            }
        }
    };
}
#endif