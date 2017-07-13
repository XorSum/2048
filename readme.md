基于SDL2库的c语言2048游戏。

安装SDL2库

``` bash
sudo apt-get install libsdl2-dev libsdl2-image-dev
``` 
编译
``` bash
gcc 2048.c -o 2048 -lSDL2 -lSDL2_image 
```

运行
``` bash
./2048
```

按四个方向键使小块向四个方向移动，两个相同的小块碰撞会相加，直到出现
2048即可胜利。如果玩到一半想退出，请按BACKSPACE键再按任意键。
胜利或失败后也是按任意键退出。
    
