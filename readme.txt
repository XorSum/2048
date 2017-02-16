    这是一个ubuntu系统上的2048游戏，用到了SDL2库，
其安装命令是：
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev
    这个游戏的编译命令是：
gcc 2048.c -o 2048.out -lSDL2 -lSDL2_image 
    然后“./2048.out”就能运行了。按四个方向键使小块
向四个方向移动，两个相同的小块碰撞会相加，直到出现
2048即可胜利。如果玩到一半想退出，请按BACKSPACE键再按任意键。
胜利或失败后也是按任意键退出。
    
