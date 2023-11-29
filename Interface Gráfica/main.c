#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#define QUANT 3
#define hitboxQuantidade 24

// gcc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

int main(){

    const int screenWidth = 563;
    const int screenHeight = 480;
    const char* mensagens[QUANT] = {"Ola, Bem vindos ao clara em caaaasa :)"};

    InitWindow(screenWidth, screenHeight , "Pokemon da shopee");

    Texture bg1, bg2, bg3, bg4, bgtroca;
    Texture2D frente, esquerda, direita, costas, animacao;
    Texture2D npc1, chatbox;
    //Font chatFont;
    frente = LoadTexture("./frente.png");
    costas = LoadTexture("./costas.png");
    esquerda = LoadTexture("./esquerda.png");
    direita = LoadTexture("./direita.png");
    npc1 = LoadTexture("./npc1.png");
    chatbox = LoadTexture("./chatbox.png");
    //chatFont = LoadFont("./pokemon.ttf");
    unsigned numFrames = 4;
    Rectangle sourceF = {0.0f, 0.0f, (float)frente.width/numFrames, frente.height}; 
    Rectangle sourceC = {0.0f, 0.0f, (float)costas.width/numFrames, costas.height};  
    Rectangle sourceE = {0.0f, 0.0f, (float)esquerda.width/numFrames, esquerda.height}; 
    Rectangle sourceD = {0.0f, 0.0f, (float)direita.width/numFrames, direita.height}; 
    //Rectangle hnpc1 = {screenHeight/2.0, screenWidth/2.0, npc1.width, npc1.height};
    Rectangle chatBoxF = {21, screenHeight - chatbox.height, chatbox.width, chatbox.height};
    animacao = frente;
    Rectangle source = sourceF;

    bg1 = LoadTexture("./cenario.png");
    bg2 = LoadTexture("./cenario2.png");
    bg3 = LoadTexture("./cenario3.png");
    bg4 = LoadTexture("./cenario4.png");
    bgtroca = bg1;

    Vector2 posicao = {screenWidth/2.0, screenHeight/2.0+20};
    //Vector2 chatPosicao = {60, screenHeight - chatbox.height+40};
    Rectangle hitbox = {posicao.x+10, posicao.y+source.height/2.0+5, source.width-20, source.height/2.0-10};
    // //posicao.x+10, posicao.y+source.height/2.0+5, source.width-20, source.height/2.0-10};
    Rectangle colisao1, colisao2;
    //Rectangle areaColisao1 = {-source.width, 100, 1, 45};
    Rectangle areaColisao1 = {-source.width, 110, 1, 45};
    //Rectangle areaColisao2 = {screenWidth+source.width, 100, 1, 45};
    Rectangle areaColisao2 = {screenWidth+source.width, 0, 1, 480};
    Rectangle propHitboxArea1[hitboxQuantidade] = {
        {0 , 0, 196, 113},
        {196, 0, 37, 154},
        {231, 0, 125, 79},
        {357, 0, 63, 107},
        {265, 137, 186, 150},
        {0, 185, 187, 61},
        {0, 161, 168, 24},
        {451, 0, 45, 296},
        {495, 0, 38, 278},
        {533, 0, 29, 261},
        {390, 385, 173, 95},
        {125, 252, 64, 131},
        {0, 251, 47, 230},
        {46, 328, 48, 59},
        {47, 387, 15, 97},
        {63, 436, 122, 47},
        {245, 436, 63, 44},
        {495, 0, 38, 278},
        {248, 337, 319, 48},
        {185, 476, 59, 4},
        {314, 462, 77, 17},
        {248, 176, 17, 96},
        {229, 182, 15, 70},
        {418, 0, 34, 27}
    };

    colisao1 = areaColisao1;
    unsigned areaSt = 1;
    Rectangle colisaoNula = {-200, -200, 0, 0};
    
    unsigned frameDelay = 5;
    unsigned frameDelayCounter = 0;
    unsigned frameIndex = 0;
    bool isInMenu = false, pauseMenu = false;
    bool text = false;

    SetTargetFPS(60);

    while(!WindowShouldClose()){     

        if(pauseMenu){
            if(IsKeyPressed(KEY_P)) pauseMenu = false;
        }        
        else{
            if(IsKeyPressed(KEY_P)) pauseMenu = true;
        }

        if(IsKeyPressed(KEY_KP_0)) text = true;

        if(!pauseMenu && !isInMenu){
            ++frameDelayCounter;
            if(frameDelayCounter >= frameDelay){
                if(IsKeyDown(KEY_RIGHT)){
                    posicao.x += 10.0;
                    hitbox.x += 10.0;
                    if(areaSt == 1){
                        for(int i = 0 ; i < hitboxQuantidade ; i++){
                            if(CheckCollisionRecs(hitbox, propHitboxArea1[i])){
                                posicao.x -= 10.0;
                                hitbox.x -=10.0;
                            }
                        }
                    }
                    if(frameDelayCounter > numFrames){
                        frameDelayCounter = 0;
                        ++frameIndex;
                        frameIndex %= numFrames;
                    }
                    animacao = direita;
                    sourceD.x = (float)frameIndex * (float)direita.width/numFrames;
                    source = sourceD;
                }
                if(IsKeyDown(KEY_LEFT)){ 
                    posicao.x -= 10.0;
                    hitbox.x -= 10.0;
                    if(areaSt == 1){
                        for(int i = 0 ; i < hitboxQuantidade ; i++){
                            if(CheckCollisionRecs(hitbox, propHitboxArea1[i])){
                                posicao.x += 10.0;
                                hitbox.x +=10.0;
                            }
                        }
                    }
                    if(frameDelayCounter > numFrames){
                        frameDelayCounter = 0;
                        ++frameIndex;
                        frameIndex %= numFrames;
                    }
                    animacao = esquerda;
                    sourceE.x = (float)frameIndex * (float)esquerda.width/numFrames;
                    source = sourceE;
                }
                if(IsKeyDown(KEY_UP)){ 
                    posicao.y -= 10.0;
                    hitbox.y -=10.0;
                    if(areaSt == 1){
                        for(int i = 0 ; i < hitboxQuantidade ; i++){
                            if(CheckCollisionRecs(hitbox, propHitboxArea1[i])){
                                posicao.y += 10.0;
                                hitbox.y +=10.0;
                            }
                        }
                    }
                    if(frameDelayCounter > numFrames){
                        frameDelayCounter = 0;
                        ++frameIndex;
                        frameIndex %= numFrames;
                    }
                    animacao = costas;
                    sourceC.x = (float)frameIndex * (float)costas.width/numFrames;
                    source = sourceC;
                }
                if(IsKeyDown(KEY_DOWN)){
                    posicao.y += 10.0;
                    hitbox.y += 10.0;
                    if(areaSt == 1){
                        for(int i = 0 ; i < hitboxQuantidade ; i++){
                            if(CheckCollisionRecs(hitbox, propHitboxArea1[i])){
                                posicao.y -= 10.0;
                                hitbox.y -=10.0;
                            }
                        }
                    }
                    if(frameDelayCounter > numFrames){
                        frameDelayCounter = 0;
                        ++frameIndex;
                        frameIndex %= numFrames;
                    }
                    animacao = frente;
                    sourceF.x = (float)frameIndex * (float)frente.width/numFrames;
                    source = sourceF;
                }
            }
            
            if(CheckCollisionRecs(hitbox, colisao1)){
                colisao1 = colisaoNula;
                colisao2 = areaColisao2;
                bgtroca = bg3;
                posicao.x = screenWidth;
                hitbox.x = posicao.x+10;
                posicao.y = 115;
                hitbox.y = posicao.y+source.height/2.0+5;
                areaSt = 2;
                //posicao.x+10, posicao.y+source.height/2.0+5, source.width-20, source.height/2.0-10};
            }
            if(CheckCollisionRecs(hitbox, colisao2)){
                colisao2 = colisaoNula;
                colisao1 = areaColisao1;
                bgtroca = bg1;
                posicao.x = -source.width;
                hitbox.x = posicao.x+10;
                posicao.y = 95;
                hitbox.y = posicao.y+source.height/2.0+5;
                areaSt = 1;
            }
        }Rectangle areaColisao1 = {-source.width, 100, 1, 45};(RAYWHITE);
        DrawTexture(bgtroca, 0, 0, WHITE);
        //DrawRectangleRec(areaColisao1, BLUE);
        //DrawRectangleRec(areaColisao2, BLACK);
        //DrawRectangleRec(hitbox, BLACK);
        if(areaSt == 1){
            DrawTexture(npc1, screenWidth/2.0, screenHeight/2.0+100, WHITE);
            /*
            for(int i = 0 ; i < hitboxQuantidade ; i++){
                DrawRectangleRec(propHitboxArea1[i], BLUE);
            }
            */
           
        }
        DrawTextureRec(animacao, source, posicao, WHITE);
        if(text){
        DrawRectangleRec(chatBoxF, WHITE);
            DrawTexture(chatbox, 21, screenHeight - chatbox.height, WHITE);
            for(int i = 0 ; i < QUANT ; i++){
            DrawText(TextSubtext(mensagens[i], 0, frameDelayCounter/3), 60, screenHeight - chatbox.height+40, 20, BLACK);
            //DrawTextEx(chatFont, mensagens[i], chatPosicao, 12, 1, BLACK);
            if(IsKeyPressed(KEY_KP_1)) text = false;
            }
        }
        if(pauseMenu){
            ClearBackground(RAYWHITE);
            DrawText("PAUSED", (screenWidth/2)-140, (screenHeight/2)-70, 70, BLACK);
        }
        EndDrawing();
        
    }

    CloseWindow();


    return 0;
}
