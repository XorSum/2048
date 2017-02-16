#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
int a[4][4]={{0,0,0,0},{0,0,2,0},{0,0,0,0},{0,0,0,0}};
int b[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
  SDL_Event event;
  SDL_Window*win=NULL;
  SDL_Renderer*renderer=NULL;
  SDL_Texture*tex2=NULL;
  SDL_Texture*tex4=NULL;
  SDL_Texture*tex8=NULL;
  SDL_Texture*tex16=NULL;
  SDL_Texture*tex32=NULL;
  SDL_Texture*tex64=NULL;
  SDL_Texture*tex128=NULL;
  SDL_Texture*tex256=NULL;
  SDL_Texture*tex512=NULL;
  SDL_Texture*tex1024=NULL;
  SDL_Texture*tex2048=NULL;
  SDL_Texture*tex0=NULL;
  SDL_Texture*texwin=NULL;
  SDL_Texture*texfail=NULL;
  SDL_Surface*surface=NULL;

int init(){
  win=SDL_CreateWindow("hello",0,0,400,400,0);
  renderer=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
  surface=IMG_Load("./pictures/2.png");
  tex2=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/4.png");
  tex4=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/8.png");
  tex8=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/16.png");
  tex16=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/32.png");
  tex32=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/64.png");
  tex64=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/128.png");
  tex128=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/256.png");
  tex256=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/512.png");
  tex512=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/1024.png");
  tex1024=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/2048.png");
  tex2048=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/background.png");
  tex0=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/win.png");
  texwin=SDL_CreateTextureFromSurface(renderer,surface);
  surface=IMG_Load("./pictures/fail.png");
  texfail=SDL_CreateTextureFromSurface(renderer,surface);
  SDL_FreeSurface(surface);
  return 0;
}

int present(){
  int i,j;
  SDL_Rect rect;
  SDL_RenderClear(renderer);
  for (j=0;j<4;j++){
    for (i=0;i<4;i++){
      rect.x=j*100;
      rect.y=i*100;
      rect.w=100;
      rect.h=100;
      switch (a[i][j]){
        case 0:SDL_RenderCopy(renderer,tex0,0,&rect);break;
        case 2:SDL_RenderCopy(renderer,tex2,0,&rect);break;
        case 4:SDL_RenderCopy(renderer,tex4,0,&rect);break;
        case 8:SDL_RenderCopy(renderer,tex8,0,&rect);break;
        case 16:SDL_RenderCopy(renderer,tex16,0,&rect);break;
        case 32:SDL_RenderCopy(renderer,tex32,0,&rect);break;
        case 64:SDL_RenderCopy(renderer,tex64,0,&rect);break;
        case 128:SDL_RenderCopy(renderer,tex128,0,&rect);break;
        case 256:SDL_RenderCopy(renderer,tex256,0,&rect);break;
        case 512:SDL_RenderCopy(renderer,tex512,0,&rect);break;
        case 1024:SDL_RenderCopy(renderer,tex1024,0,&rect);break;
        case 2048:SDL_RenderCopy(renderer,tex2048,0,&rect);break;
        default :return 1;break;
      }
    }
  }
  SDL_RenderPresent(renderer);
  return 0;
}

int quit(){
  SDL_DestroyTexture(tex0);
  SDL_DestroyTexture(tex2);
  SDL_DestroyTexture(tex4);
  SDL_DestroyTexture(tex8);
  SDL_DestroyTexture(tex16);
  SDL_DestroyTexture(tex32);
  SDL_DestroyTexture(tex64);
  SDL_DestroyTexture(tex128);
  SDL_DestroyTexture(tex256);
  SDL_DestroyTexture(tex512);
  SDL_DestroyTexture(tex1024);
  SDL_DestroyTexture(tex2048);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  IMG_Quit();
  SDL_Quit();
  return 0;
}



int zhuan(){
  /*顺时针旋转90度*/
  int i,j,c[4][4];
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      c[i][j]=a[3-j][i];
    }
  }
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      a[i][j]=c[i][j];
    }
  }
  return 0;
}
int left(){
  int i,j,k;
  for (i=0;i<4;i++){
    for (j=0;j<3;j++){
      if (a[i][j]==0){
        for (k=j+1;k<4;k++) if (a[i][k]!=0) {a[i][j]=a[i][k];a[i][k]=0;break;}
      }
    }
    for (j=0;j<3;j++) if (a[i][j]==a[i][j+1]) {a[i][j]=a[i][j]*2;a[i][j+1]=0;}
    for (j=0;j<3;j++){
      if (a[i][j]==0){
        for (k=j+1;k<4;k++) if (a[i][k]!=0) {a[i][j]=a[i][k];a[i][k]=0;break;}
      }
    }
  }
  return 0;
}
int right(){
  zhuan();
  zhuan();
  left();
  zhuan();
  zhuan();
  return 0;
}
int up(){
  zhuan();
  zhuan();
  zhuan();
  left();
  zhuan();
  return 0;
}
int down(){
  zhuan();
  left();
  zhuan();
  zhuan();
  zhuan();
  return 0;
}
int save(){
/*为a做一个备份b*/
  int i,j;
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      b[i][j]=a[i][j];
    }
  }
  return 0;
}
int text1(){
/*检测a是否改变，改变返回0，不改变返回1*/
  int i,j,d=1;
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      if (a[i][j]!=b[i][j]){
	d=0;
	break;
	break;
      }
    }
  }
  return d;
}
int text2(){
/*检测是否输，输返回1，否则返回0*/
  int i,j,t=0;
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      if (a[i][j]!=0) t++;
    }
  }
  if (t==16) return 1;
  else return 0;
}
int text3(){
/*检测是否赢，赢1否则0*/
  int i,j,t=0;
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      if (a[i][j]==2048) {t=1;break;break;}
    }
  }
  return t;
}
int add(){
/*向a中随机放一个2*/
  int i,j;
  srand((unsigned)time(NULL));
  while (1==1){
    i=((unsigned)rand())%4;
    j=((unsigned)rand())%4;
    if (a[i][j]==0){
      a[i][j]=2;
      break;
    }
  }
  return 0;
}
int at(){
  a[0][0]=2;
  return 0;
}
int play(char q){
  /*赢2，输退1，其它0*/
  save();
  switch (q){
    case 'w':up();break;
    case 'a':left();break;
    case 's':down();break;
    case 'd':right();break;
    case 't':return 1;
  }
  if (text3()==1) return 2;
  if (text2()==1) return 1;
  if (text1()==0) add();
  return 0;
}

int main(){
  int f=0;
  init();
  present();
  while (f==0){
    SDL_PollEvent(&event);
    if (event.type==SDL_KEYDOWN){
      switch (event.key.keysym.sym){
        case SDLK_UP:f=play('w');present();break;
        case SDLK_LEFT:f=play('a');present();break;
        case SDLK_DOWN:f=play('s');present();break;
        case SDLK_RIGHT:f=play('d');present();break;
        case SDLK_BACKSPACE:f=1;break;
      }
    }
  SDL_Delay(200);
  }
  while (f==2) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,texwin,0,0);
    SDL_RenderPresent(renderer);
    SDL_PollEvent(&event);
    if (event.type==SDL_KEYDOWN) break;
    SDL_Delay(200);
  }
  while (f==1) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,texfail,0,0);
    SDL_RenderPresent(renderer);
    SDL_PollEvent(&event);
    if (event.type==SDL_KEYDOWN) break;
    SDL_Delay(200);
  }
  quit();
  return 0;
}
