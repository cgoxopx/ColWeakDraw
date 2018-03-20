# ColWeakDraw  
色觉异常者专用私密窗口  
## 简介  
一个简单的图片生成库，能生成只有“色觉异常”者才能看到的图片（并且还支持动态图片，快速变化会让别人根本没法看）。  
可用于隐藏一些隐私内容。  
截图：  
！[image](https://github.com/cgoxopx/ColWeakDraw/blob/master/image/1.jpg)  
！[image](https://github.com/cgoxopx/ColWeakDraw/blob/master/image/2.jpg)  
！[image](https://github.com/cgoxopx/ColWeakDraw/blob/master/image/3.jpg)  
！[image](https://github.com/cgoxopx/ColWeakDraw/blob/master/image/4.jpg)  
用[动态版](./test/sdl.cpp)效果更佳  
核心代码约100行，只用了math.h和stdlib.h，完美跨平台，甚至能在emscripten上编译，用于web开发  
## 使用方法  
```
        #include "cwdrawer.hpp"
        class myclass:public cwdrawer::base{            //继承cwdrawer::base
          public:
            myclass():  
              base(20,20){                              //设置宽20,高20  
                this->deflight=16;                      //设置明暗变化量  
                virtual bool getUnusual(int x,int y){   //覆盖getUnusual，用于读取要混淆的数据  
                  //……  
                }
                virtual void draw(int x,int y,int r,int g,int b){   //覆盖getUnusual，用于绘图  
                    //这里展示一下SDL2下的操作  
                    SDL_Rect sr;
                    sr.x=x*30;
                    sr.y=y*30;
                    sr.w=30;
                    sr.h=30;
                    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
                    SDL_RenderFillRect(renderer,&sr);
                }
            }
        }myobj;
```  
然后调用` myobj.render() `渲染图片  
## 最后说点别的吧  
owner几天前高考体检，被诊断为色弱（不过我认为应该是明暗认知导致的），于是开发了这个项目，证明色觉和别人不一样并不一定是坏事。  
同时呼吁废除目前国内仍在使用的在国际上已经被淘汰的检测方法，反对歧视色觉异常者。  
2018.3.18  
