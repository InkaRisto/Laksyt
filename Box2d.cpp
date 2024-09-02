#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>
#include <string>

using namespace std;

// This is a simple example of building and running a simulation
// using Box2D. Here we create a large ground box and a small dynamic
// box.
// There are no graphics for this example. Box2D is meant to be used
// with your rendering engine in your game engine.

SDL_Texture* loadTexture(SDL_Renderer* renderer, string path) {
    // Load the image from path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    // Create texture from surface pixels
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

    // Get rid of the loaded surface
    SDL_FreeSurface(loadedSurface);

    return newTexture;
}

int main(int argc, char** argv)
{
    // https://github.com/erincatto/box2d/blob/main/docs/hello.md

    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = { 0.0f, -10.0f };
    b2WorldId worldId = b2CreateWorld(&worldDef);

    b2BodyDef groundBodyDef = b2DefaultBodyDef();
    groundBodyDef.position = { 0.0f, -10.0f };
    b2BodyId groundId = b2CreateBody(worldId, &groundBodyDef);
    b2Polygon groundBox = b2MakeBox(50.0f, 10.0f);
    b2ShapeDef groundShapeDef = b2DefaultShapeDef();
    b2CreatePolygonShape(groundId, &groundShapeDef, &groundBox);

    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = { 0.0f, 4.0f };
    bodyDef.rotation = b2MakeRot(40);
    b2BodyId bodyId = b2CreateBody(worldId, &bodyDef);

    b2Polygon dynamicBox = b2MakeBox(1.0f, 1.0f);
    b2ShapeDef shapeDef = b2DefaultShapeDef();
    shapeDef.density = 1.0f;
    shapeDef.friction = 0.3f;
    b2CreatePolygonShape(bodyId, &shapeDef, &dynamicBox);

    float timeStep = 1.0f / 60.0f;
    int subStepCount = 4;

    //Hello World material: 
    /*for (int i = 0; i < 540; ++i)
    {
        b2World_Step(worldId, timeStep, subStepCount);
        b2Vec2 position = b2Body_GetPosition(bodyId);
        b2Rot rotation = b2Body_GetRotation(bodyId);
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, b2Rot_GetAngle(rotation));
    }*/

    //Open GAME window
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    string path = "ball.png";

    //SDL_rendering, base
    SDL_Window* gWindow = win;
    SDL_Renderer* gRenderer = NULL;
    SDL_Texture* gTexture = NULL;

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    gTexture = loadTexture(gRenderer, path);
    
    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    

    while (1) {
        b2World_Step(worldId, timeStep, subStepCount);
        b2Vec2 position = b2Body_GetPosition(bodyId);
        b2Rot rotation = b2Body_GetRotation(bodyId);
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, b2Rot_GetAngle(rotation));

        // Clear the screen
        SDL_RenderClear(gRenderer);

        // Render the texture
        SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

        // Update the screen
        SDL_RenderPresent(gRenderer);
    }

    return 0;
}
