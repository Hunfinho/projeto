#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <SDL2/SDL_image.h>

//gcc -o main2 main2.c `pkg-config --cflags --libs` SDL2_image -lGL
//gcc -o main2 main2.c `sdl2-config --cflags --libs` -lSDL2_image -lGL
//gcc -g -o main2 main2.c `sdl2-config --cflags --libs` -lSDL2_image -lGL



int main(int argc, char* argv[]){

    //Iniciar o SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //Atribuição de cores para economizar memória
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); //Transparencia

    //Atributos do buffer
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //Criando a janela do jogo
    SDL_Window* janela = SDL_CreateWindow("Pokemon da Shopee", //Nome da janela
        300, 20, //Localização de onde a janela irá abrir
        1280, 720, //Resolução da janela
        SDL_WINDOW_OPENGL);
    SDL_GLContext contexto = SDL_GL_CreateContext(janela); //Contexto com OpenGL

    const int FPS = 144; //Contador de FPS
    Uint64 start;

    //Chamando imagens e criando superficies
    SDL_Surface* cenario = IMG_Load("cenario.PNG");
    SDL_Surface* charmander = IMG_Load("4.PNG");

    //Criando texturas
    glEnable(GL_TEXTURE_2D); // Permitir texturas em 2D
    glEnable(GL_BLEND); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Permitir transparência

    //Cenario
    GLuint cenariotextura;
    glGenTextures(1, &cenariotextura);
    glBindTexture(GL_TEXTURE_2D, cenariotextura);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, cenario->w, cenario->h, 0, GL_RGB, GL_UNSIGNED_BYTE, cenario->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    SDL_FreeSurface(cenario);

    //Personagem
    GLuint charmandertextura;
    glGenTextures(1, &charmandertextura);
    glBindTexture(GL_TEXTURE_2D, charmandertextura);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, charmander->w, charmander->h, 0, GL_RGB, GL_UNSIGNED_BYTE, charmander->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    SDL_FreeSurface(charmander);

    GLuint Animacao = charmandertextura;

    //Criando eventos
    SDL_Event Eventos;

    bool moverx = false, moverx1 = false, movery = false, movery1 = false; //Movimento = 0
    float formax = 280, formay = 270, formax1 = 26, formay1 = 35; //Personagem inicia
    float velocidade1 = 0.6, velocidade2 = 0.6; //Velocidade de movimento do personagem
    int con = 5; //Contador de frames

    while(true){
        while(SDL_PollEvent(&Eventos)){
            if(Eventos.type == SDL_QUIT){ //Encerrar o jogo pelo X
                break;
            }
        if(Eventos.type == SDL_KEYDOWN){
            if(Eventos.key.keysym.sym == SDLK_ESCAPE){ //Encerrar jogo com ESC
                break;
            }
            if(Eventos.key.keysym.sym == SDLK_RIGHT){ //Anda para direita
                moverx = true;
            }
            if(Eventos.key.keysym.sym == SDLK_LEFT){ //Anda para esquerda
                moverx1 = true;
            }
            if(Eventos.key.keysym.sym == SDLK_UP){ //Anda para cima
                movery = true;
            }
            if(Eventos.key.keysym.sym == SDLK_DOWN){ //Anda para baixo
                movery1 = true;
            }
        }
        else if(Eventos.type == SDL_KEYUP){
            if(Eventos.key.keysym.sym == SDLK_RIGHT){ //Para de andar para direita
                moverx = false;
            }
            if(Eventos.key.keysym.sym == SDLK_LEFT){ //Para de andar para esquerda
                moverx1 = false;
            }
            if(Eventos.key.keysym.sym == SDLK_UP){ //Para de andar para cima
                movery = false;
            }
            if(Eventos.key.keysym.sym == SDLK_DOWN){ //Para de andar para baixo
                movery1 = false;
            }
        }
    }
    

    //Limitador de FPS
    start = SDL_GetTicks();
    if(1000/FPS > SDL_GetTicks()-start){
        SDL_Delay(1000/FPS-(SDL_GetTicks()-start));


    //Timer de sprites
        if(con >= 0 && con < 60){
            con = con + 1;
        }
        if(con >= 60){
            con = con - 60;
        }

    //Limitar personagem dentro da tela
    if(formax < 1){
        moverx1 = false;
    }
    else if(formax + formax1 > 599){
        moverx = false;
    }
    if(formay < 1){
        movery = false;
    }
    if(formay + formay1 > 541){
        movery1 = false;
    }

    //Mover personagem
    if(moverx == true){
        formax += velocidade1;
    }
    if(moverx1 == true){
        formax -= velocidade1;
    }
    if(movery == true){
        formay += velocidade2;
    }
    if(movery1 == true){
        formay -= velocidade2;
    }

    //Iniciar matriz
    glPushMatrix();
    glOrtho( 0, //Ponto minimo de x
    600,        //Ponto maximo de x
    600,        //Ponto maximo de y
    0,          //Ponto minimo de y
    -1, 
    1);

    glBindTexture(GL_TEXTURE_2D, cenariotextura); //Textura do chão
    glBegin(GL_QUADS);
    {
    glTexCoord2f(0,0); glVertex2f(0,0);
    glTexCoord2f(1,0); glVertex2f(600,0);
    glTexCoord2f(1,1); glVertex2f(600,550);
    glTexCoord2f(0,1); glVertex2f(0,550);
    glEnd();
    }

    glBindTexture(GL_TEXTURE_2D, Animacao); //Textura do personagem
    glBegin(GL_QUADS);
    {
    glTexCoord2f(0,0); glVertex2f(formax,formay);
    glTexCoord2f(1,0); glVertex2f(formax + formax1, formay);
    glTexCoord2f(1,1); glVertex2f(formax + formax1, formay + formay1);
    glTexCoord2f(0,1); glVertex2f(formax,formay + formay1);
    glEnd();
    }

    glPopMatrix(); //Fecha a matriz

    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(janela);

        }
    }
    SDL_Quit();

    return 0;
}