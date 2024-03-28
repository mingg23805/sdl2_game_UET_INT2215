#include"game.h"


Map demomap;
std:: vector <std:: pair<int ,int >>EnemyPath;
std:: vector <std:: pair<int ,int >>TowerLocation;
 void makePathandLocation()
 {
      for(int i=0;i<=480/120;i++)
   EnemyPath.push_back(std::make_pair( 120*i , 600+60 )) ;

   EnemyPath.push_back(std::make_pair(  480, 120*4+60 ) );
   EnemyPath.push_back(std::make_pair( 480 , 120*3+30 ) );
   EnemyPath.push_back(std::make_pair( 600 +90 , 120*3+30 ) );
   EnemyPath.push_back(std::make_pair( 600+90 , 120*2+60 ) );
   EnemyPath.push_back(std::make_pair( 600+90 , 120+30 ) );

   for(int i=6;i<=1700/120;i++)
 EnemyPath.push_back(std::make_pair( 120*i+60, 120+30 ) );


 TowerLocation.push_back(std::make_pair( 300 , 500 )) ;
 TowerLocation.push_back(std::make_pair( 300 , 820 )) ;
 TowerLocation.push_back(std::make_pair( 820 , 360 )) ;
 TowerLocation.push_back(std::make_pair( 500 , 250 )) ;
 TowerLocation.push_back(std::make_pair( 1200 , 340 )) ;
 TowerLocation.push_back(std::make_pair( 1520 , 340 )) ;

 TowerLocation.push_back(std::make_pair( 1360 , 20 )) ;

 }
 void renderDemoMap(SDL_Renderer* renderer)
{  //map
    demomap.texture= loadTexture("picture/map/map.png", renderer);
    SDL_RenderCopy(renderer ,demomap.texture, NULL, NULL);

    //castle
    SDL_Texture * MainTowerTexture= loadTexture("picture/map/castle.png ",renderer);
    SDL_Rect destinationRect = { 1720, 20, 300, 280 };
    SDL_RenderCopy(renderer, MainTowerTexture, NULL, &destinationRect);

 SDL_DestroyTexture(MainTowerTexture);
    SDL_DestroyTexture(demomap.texture);
    // tower Location

   for(auto x : TowerLocation)
   {
       SDL_Rect rect = {x.first,x.second , 120, 120};
       SDL_Texture * slot = loadTexture("picture/map/slot.png", renderer);
       SDL_RenderCopy(renderer,slot,NULL, &rect);
       SDL_DestroyTexture(slot);
   }





    //button ui hpbar
    SDL_Texture * TowerButton= loadTexture("picture/map/towerbutton.png",renderer);
    SDL_Texture * Archer = loadTexture("picture/tower/archer_tower_button.png",renderer);
    SDL_Texture * Rock = loadTexture("picture/tower/rock_tower_button.png",renderer);

    SDL_Rect ArcherRect= {1920-240,1080-180,240,180};
    SDL_Rect RockRect = { 1920-240*2,1080-180,240,180};



    SDL_RenderCopy(renderer,TowerButton,NULL,&ArcherRect);
    SDL_RenderCopy(renderer,Archer,NULL,&ArcherRect);

    SDL_RenderCopy(renderer,TowerButton,NULL,&RockRect);
    SDL_RenderCopy(renderer,Rock,NULL,&RockRect);


    SDL_DestroyTexture(TowerButton);
    SDL_DestroyTexture(Archer);
    SDL_DestroyTexture(Rock);

    SDL_Texture * Status = loadTexture("picture/map/Status.png",renderer);

    SDL_Rect StatusRect={0,0,360,480};
    SDL_RenderCopy(renderer,Status,NULL,&StatusRect);
    SDL_DestroyTexture(Status);



 }
 void chooseTower(SDL_Event&e,int &choosetower,SDL_Renderer *renderer)
 {  SDL_Texture * selector=loadTexture("picture/map/selector.png",renderer);
    SDL_Rect selectorRect;

     int mouseX = e.button.x;
    int mouseY = e.button.y;
  if (mouseX >= 1920-240 && mouseX <= 1920  &&
        mouseY >= 1080 -180   && mouseY <= 1080 )


       choosetower=1;
 if (mouseX >= 1920-240*2 && mouseX < 1920-240  &&
        mouseY >= 1080 -180   && mouseY <= 1080 )
        choosetower=2;
     if(choosetower==1)
     {
         selectorRect={1920-240,1080-300,240,180};
         SDL_RenderCopy(renderer,selector,NULL,&selectorRect);
     }
    if(choosetower==2)
     {
         selectorRect={1920-240*2,1080-300,240,180};
         SDL_RenderCopy(renderer,selector,NULL,&selectorRect);
     }

}
