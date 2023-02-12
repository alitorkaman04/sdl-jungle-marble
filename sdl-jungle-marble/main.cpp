#include <iostream>
#include <iostream>
#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include <vector>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

bool init();
void kill();
bool loop(string &input);
void bozorg(int a[], int b[]);

int record[100];
int shomare[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

SDL_Renderer * m_renderer;
SDL_Texture *texture, *text, *text2;
TTF_Font* font;
SDL_Event *e = new SDL_Event();
SDL_Window * m_window;

int img_w, img_h,img2_w, img2_h,img3_w, img3_h,img4_w, img4_h, img5_w, img5_h, img6_w, img6_h, img7_w, img7_h,img8_w, img8_h;

SDL_Rect img_rect;
SDL_Rect img2_rect;
SDL_Rect img3_rect;
SDL_Rect img4_rect;
SDL_Rect img5_rect;
SDL_Rect img6_rect;
SDL_Rect img7_rect;
SDL_Rect img8_rect;

SDL_Texture* m_img = NULL;
SDL_Texture* m2_img2 = NULL;
SDL_Texture* m3_img = NULL;
SDL_Texture* m4_img = NULL;
SDL_Texture* m5_img = NULL;
SDL_Texture* m6_img = NULL;
SDL_Texture* m7_img = NULL;
SDL_Texture* m8_img = NULL;
SDL_Texture* m9_img = NULL;
SDL_Texture* m10_img = NULL;
SDL_Texture* m11_img = NULL;
SDL_Texture* m8p_img = NULL;
SDL_Texture* m9p_img = NULL;
SDL_Texture* m10p_img = NULL;
SDL_Texture* m11p_img = NULL;
SDL_Texture* m12_img = NULL;
SDL_Texture* m13_img = NULL;
SDL_Texture* m20_img = NULL;
SDL_Texture* m21_img = NULL;
SDL_Texture* m22_img = NULL;
SDL_Texture* m23_img = NULL;
SDL_Texture* m24_img = NULL;
SDL_Texture* m25_img = NULL;
SDL_Texture* m26_img = NULL;
SDL_Texture* m30_img = NULL;
SDL_Texture* m31_img = NULL;

SDL_Texture* e1_img = NULL;
SDL_Texture* e2_img = NULL;
SDL_Texture* e3_img = NULL;
SDL_Texture* e4_img = NULL;

SDL_Texture* f_img = NULL;
SDL_Texture* help_img = NULL;

bool signin_u = 1, login_u = 1, signin, login, menu;
string input1, input2, signin_uu, login_uu, signin_pp, login_pp;

void textRGBA2(SDL_Renderer*m_renderer, int x, int y, const char* text,int f_size,int r, int g, int b, int a);
void img(int x, int y, int w, int h, SDL_Texture* m_img);
void img2(int x, int y, double alfa, int w, int h, SDL_Texture* m_img);

vector <int> red;
vector <int> grean;
vector <int> blue;
vector <double> teta;
vector <int> power;

int main( int argc, char * argv[] )
{

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music *background_sound1 = Mix_LoadMUS("1.mp3");
    Mix_Music *background_sound2 = Mix_LoadMUS("2.mp3");
    Mix_Music *background_sound3 = Mix_LoadMUS("3.mp3");
    Mix_Music *background_sound4 = Mix_LoadMUS("4.mp3");
    Mix_Chunk *shelik_efect = Mix_LoadWAV("shelik3.wav");
    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;

    SDL_Point img3_point;

    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1000, 480, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = DM.w;
    int H = DM.h;
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    m20_img = IMG_LoadTexture(m_renderer, "snow.png");
    m21_img = IMG_LoadTexture(m_renderer, "pause.png");
    m22_img = IMG_LoadTexture(m_renderer, "cycle.png");
    m23_img = IMG_LoadTexture(m_renderer, "fire_ball.png");
    m24_img = IMG_LoadTexture(m_renderer, "rainbowball.png");
    m25_img = IMG_LoadTexture(m_renderer, "bombball.png");
    m26_img = IMG_LoadTexture(m_renderer, "meteorite.png");
    m30_img = IMG_LoadTexture(m_renderer, "victory.png");
    m31_img = IMG_LoadTexture(m_renderer, "defeat.png");
    e1_img = IMG_LoadTexture(m_renderer, "e1.png");
    e2_img = IMG_LoadTexture(m_renderer, "e2.png");
    e3_img = IMG_LoadTexture(m_renderer, "e3.png");
    e4_img = IMG_LoadTexture(m_renderer, "e4.png");
    f_img = IMG_LoadTexture(m_renderer, "f.png");
    help_img = IMG_LoadTexture(m_renderer, "help.png");
    // Show the window

    SDL_RenderPresent( m_renderer );

    while(e->type != SDL_KEYDOWN)
        SDL_PollEvent(e);

    m_img = IMG_LoadTexture(m_renderer, "menu1.jpg");
    //Get the width and height of the texture
    SDL_QueryTexture(m_img, NULL, NULL, &img_w, &img_h);
    img_rect.x = 50;
    img_rect.y = 50;
    img_rect.w = W-100;
    img_rect.h = H-100;

    m4_img = IMG_LoadTexture(m_renderer, "menu2.jpg");
    //Get the width and height of the texture
    SDL_QueryTexture(m4_img, NULL, NULL, &img4_w, &img4_h);
    img4_rect.x = 50;
    img4_rect.y = 50;
    img4_rect.w = W-100;
    img4_rect.h = H-100;

    m5_img = IMG_LoadTexture(m_renderer, "back.jpg");
    //Get the width and height of the texture
    SDL_QueryTexture(m5_img, NULL, NULL, &img5_w, &img5_h);
    img5_rect.x = 0;
    img5_rect.y = 0;
    img5_rect.w = W;
    img5_rect.h = H;

    m6_img = IMG_LoadTexture(m_renderer, "map.jpg");
    //Get the width and height of the texture
    SDL_QueryTexture(m6_img, NULL, NULL, &img6_w, &img6_h);
    img6_rect.x = 50;
    img6_rect.y = 50;
    img6_rect.w = W - 100;
    img6_rect.h = H - 100;

    m7_img = IMG_LoadTexture(m_renderer, "map2.jpg");
    //Get the width and height of the texture
    SDL_QueryTexture(m6_img, NULL, NULL, &img6_w, &img6_h);
    img6_rect.x = 0;
    img6_rect.y = 0;
    img6_rect.w = W;
    img6_rect.h = H;

    m8_img = IMG_LoadTexture(m_renderer, "setting.png");
    //Get the width and height of the texture
    SDL_QueryTexture(m8_img, NULL, NULL, &img8_w, &img8_h);
    img8_rect.x = W/2 - 234;
    img8_rect.y = H/2 - 174;
    img8_rect.w = 234 * 2;
    img8_rect.h = 174 * 2;

    m9_img = IMG_LoadTexture(m_renderer, "music.png");
    //Get the width and height of the texture
    SDL_QueryTexture(m9_img, NULL, NULL, &img8_w, &img8_h);


    m10_img = IMG_LoadTexture(m_renderer, "sound.png");
    //Get the width and height of the texture
    SDL_QueryTexture(m10_img, NULL, NULL, &img8_w, &img8_h);


    m11_img = IMG_LoadTexture(m_renderer, "sound & music.png");
    //Get the width and height of the texture
    SDL_QueryTexture(m11_img, NULL, NULL, &img8_w, &img8_h);


    m8p_img = IMG_LoadTexture(m_renderer, "setting2.png");
    //Get the width and height of the texture
    SDL_QueryTexture(m8_img, NULL, NULL, &img8_w, &img8_h);


    m9p_img = IMG_LoadTexture(m_renderer, "music2.png");
    //Get the width and height of the texture
    SDL_QueryTexture(m9_img, NULL, NULL, &img8_w, &img8_h);


    m10p_img = IMG_LoadTexture(m_renderer, "sound2.png");
    //Get the width and height of the texture
    SDL_QueryTexture(m10_img, NULL, NULL, &img8_w, &img8_h);


    m11p_img = IMG_LoadTexture(m_renderer, "sound & music2.png");
    //Get the width and height of the texture
    SDL_QueryTexture(m11_img, NULL, NULL, &img8_w, &img8_h);


    m12_img = IMG_LoadTexture(m_renderer, "mode.jpg");
    //Get the width and height of the texture
    SDL_QueryTexture(m6_img, NULL, NULL, &img6_w, &img6_h);

    m13_img = IMG_LoadTexture(m_renderer, "leaderboard.jpg");
    //Get the width and height of the texture
    SDL_QueryTexture(m13_img, NULL, NULL, &img6_w, &img6_h);


    int x, y;
    bool menu1 = 0, help = 0;
    int music = 0, sound = 0, ahang = 0;

    Mix_PlayMusic(background_sound1, 0);
    double T1 = 0, T2 = SDL_GetPerformanceCounter();
    float elapsedMS;


    while(menu == 0)
    {

        while(menu1 == 0)
        {
            SDL_PollEvent(e);

            SDL_ShowCursor(SDL_ENABLE);
            x=e->button.x;
            y=e->button.y;

            SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);
            SDL_RenderPresent( m_renderer );


            if(x >=520 && x<=760 && y>=330 && y<=415 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
            {
                menu1 = 1;
                signin = 1;
            }

            else if(x >=520 && x<=760 && y>=440 && y<=520 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
            {
                menu1 = 1;
                login = 1;
            }


        }


        if(signin == 1 || login == 1)
            init();

        while(signin == 1)
        {

            while ( loop(input1) && signin_u == 1)
            {
                SDL_PollEvent(e);
                SDL_ShowCursor(SDL_ENABLE);
                x=e->button.x;
                y=e->button.y;
                signin_uu = input1;
                if(x >=610 && x<=800 && y>=420 && y<=460 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    signin_u = 0;
                    e->type = 0;
                }
                if(x >=640 && x<=765 && y>=500 && y<=555 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    login_uu = signin_uu;
                    ofstream f("user.txt",ios::app);
                    f << signin_uu << endl << signin_pp << endl;
                    f.close();
                    ofstream ff("emtiaz.txt",ios::app);
                    ff << endl << signin_uu << endl << "0" << endl << "/...";;
                    ff.close();
                    e->type = 0;
                    signin = 0;
                    menu = 1;
                    break;
                }
                if(x >=510 && x<=630 && y>=500 && y<=555 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    signin = 0;
                    menu1 = 0;
                    input1 = "";
                    input2 = "";
                    break;
                }

                //cout << signin_uu << " " << signin_pp << " " << endl;
                SDL_Delay(10);
            }
            while ( loop(input2) && signin_u == 0)
            {
                SDL_PollEvent(e);
                SDL_ShowCursor(SDL_ENABLE);
                x=e->button.x;
                y=e->button.y;
                signin_pp = input2;
                if(x >=610 && x<=800 && y>=310 && y<=360 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    signin_u = 1;
                    e->type = 0;
                }
                if(x >=640 && x<=765 && y>=500 && y<=555 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    login_uu = signin_uu;
                    ofstream f("user.txt",ios::app);
                    f << signin_uu << endl << signin_pp << endl;
                    f.close();
                    ofstream ff("emtiaz.txt",ios::app);
                    ff << endl << signin_uu << endl << "0" << endl << "/...";
                    ff.close();
                    e->type = 0;
                    signin = 0;
                    menu = 1;
                    break;
                }
                if(x >=510 && x<=630 && y>=500 && y<=555 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    signin = 0;
                    menu1 = 0;
                    input1 = "";
                    input2 = "";
                    break;
                }
                //cout << signin_uu << " " << signin_pp << " " << endl;
                SDL_Delay(10);
            }

            //kill();
        }
        while(login == 1)
        {
            while ( loop(input1) && login_u == 1)
            {
                SDL_PollEvent(e);
                SDL_ShowCursor(SDL_ENABLE);
                x=e->button.x;
                y=e->button.y;
                login_uu = input1;
                if(x >=610 && x<=800 && y>=420 && y<=460 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    login_u = 0;
                    e->type = 0;
                }
                if(x >=640 && x<=765 && y>=500 && y<=555 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    string s;
                    bool check = 0;
                    ifstream f;
                    f.open("user.txt", ios_base::in);
                    while(!f.eof())
                    {
                        getline(f, s, '\n');
                        if (s.compare(login_uu) == 0)
                        {
                            getline(f, s, '\n');
                            if (s.compare(login_pp) == 0)
                            {
                                check = 1;
                                break;
                            }
                        }
                    }

                    if(check == 1)
                    {
                        textRGBA2(m_renderer, W/2 - 100, H/2 + 200, "Welcome", 50, 0, 255, 0, 255);
                        SDL_RenderPresent(m_renderer);
                        SDL_Delay(1000);
                        login = 0;
                        menu = 1;
                        break;
                    }

                    else
                    {
                        textRGBA2(m_renderer, W/2, H/2 + 200, "wrong user or pass", 50, 255, 0, 0, 255);
                        SDL_Delay(1000);
                    }

                    f.close();
                    e->type = 0;
                }
                if(x >=510 && x<=630 && y>=500 && y<=555 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    login = 0;
                    menu1 = 0;
                    input1 = "";
                    input2 = "";
                    break;
                }
                SDL_Delay(10);
            }
            while ( loop(input2) && login_u == 0)
            {
                SDL_PollEvent(e);
                SDL_ShowCursor(SDL_ENABLE);
                x=e->button.x;
                y=e->button.y;
                login_pp = input2;
                if(x >=610 && x<=800 && y>=310 && y<=360 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    login_u = 1;
                    e->type = 0;
                }
                if(x >=640 && x<=765 && y>=500 && y<=555 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    string s;
                    bool check = 0;
                    ifstream f;
                    f.open("user.txt", ios_base::in);
                    while(!f.eof())
                    {
                        getline(f, s, '\n');
                        if (s.compare(login_uu) == 0)
                        {
                            getline(f, s, '\n');
                            if (s.compare(login_pp) == 0)
                            {
                                check = 1;
                                break;
                            }
                        }
                    }

                    if(check == 1)
                    {
                        textRGBA2(m_renderer, W/2 - 100, H/2 + 200, "Welcome", 50, 0, 255, 0, 255);
                        SDL_RenderPresent(m_renderer);
                        SDL_Delay(1000);
                        login = 0;
                        menu = 1;
                        break;
                    }

                    else
                    {
                        textRGBA2(m_renderer, W/2 - 200, H/2 + 200, "wrong user or pass", 50, 255, 0, 0, 255);
                        SDL_RenderPresent(m_renderer);
                        SDL_Delay(1000);
                    }

                    f.close();
                    e->type = 0;

                }
                if(x >=510 && x<=630 && y>=500 && y<=555 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    login = 0;
                    menu1 = 0;
                    input1 = "";
                    input2 = "";
                    break;
                }
                SDL_Delay(10);
            }
        }

    }


    //Loading image
    m_img = IMG_LoadTexture(m_renderer, "menu.jpg");
    //Get the width and height of the texture
    SDL_QueryTexture(m_img, NULL, NULL, &img_w, &img_h);
    img_rect.x = 50;
    img_rect.y = 50;
    img_rect.w = W-100;
    img_rect.h = H-100;

    string ss, id;
    string name[100];
    ifstream file;
    file.open("emtiaz.txt", ios_base::in);
    int k = 0, khat = 0;
    int player = 0;
    int ran = 0;
    while(!file.eof())
    {
        getline(file, ss);
        name[player] = ss;
        getline(file, ss);
        record[player] = stoi(ss);
        while(ss != "/...")
        {
            getline(file, ss);
            if(ss != "/...")
                if(stoi(ss) > record[player])
                    record[player] = stoi(ss);
        }
        player++;
    }

    bozorg(record, shomare);

    file.close();
    // copy the texture to the rendering context
    SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);
    SDL_RenderPresent( m_renderer );

    img3_point.x = 25;
    img3_point.y = 30;

    e->type = 0;
    int i = 0, ii = 0,xE[2],xC,yC,yE[2],xB,yB,xo=W/2,yo=H/2,r=0,g=0,b=0,r2[2],g2[2],b2[2],s=0,z=0,atrafr,atrafl;
    double T =0, t = 0, TT = 0, alfa = 0, alfa_shelik, R1=320, R2=320, fi=0, xs, ys, R_shelik , rrr, drrr, p, q, delta, gama;
    bool flag = 0, setting, leader_board, namayesh, flag2 = 0,toBeDrawn=0, shelik = 0, residan = 0, change_color = 0, map1 = 0, map2 = 0, map3 = 0, map_menu = 0,  next = 0;
    bool power_bomb = 0, bombball = 0, rainbowball = 0, power_rainbow = 0, fireball = 0, power_fire = 0, meteoriteball = 0, power_meteorite = 0, power_freeze = 0, freezeball = 0, power_pause = 0, pauseball = 0, power_backward = 0, backwardball = 0;
    bool rock_vrood = 0;
    long long start = time(NULL) , pause = 0 , corno;
    int f = 1;
    int emtiaz = 0, zarib = 1;
    int mode = 0, Rock = 0, freeze = 0;
    int t1_efect = 0, t2_efect = 0, t3_efect = 0;

    srand(start + s);
    r2[0] = rand()%255;
    if(r2[0] % 4 == 0)
    {
        r2[0]=255;
        g2[0]=0;
        b2[0]=0;
    }
    else if(r2[0] % 4 == 1)
    {
        r2[0]=0;
        g2[0]=255;
        b2[0]=0;
    }
    else if(r2[0] % 4 == 2)
    {
        r2[0]=0;
        g2[0]=0;
        b2[0]=255;
    }
    else if(r2[0] % 4 == 3)
    {
        r2[0]=255;
        g2[0]=255;
        b2[0]=0;
    }


    r2[1] = rand()%255;
    if(r2[1] % 4 == 0)
    {
        r2[1]=255;
        g2[1]=0;
        b2[1]=0;
    }
    else if(r2[1] % 4 == 1)
    {
        r2[1]=0;
        g2[1]=255;
        b2[1]=0;
    }
    else if(r2[1] % 4 == 2)
    {
        r2[1]=0;
        g2[1]=0;
        b2[1]=255;
    }
    else if(r2[1] % 4 == 3)
    {
        r2[1]=255;
        g2[1]=255;
        b2[1]=0;
    }


    while(1)
    {
        SDL_PollEvent(e);

        SDL_ShowCursor(SDL_ENABLE);
        x=e->button.x;
        y=e->button.y;
        if(toBeDrawn == 0)
        {
            SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
            SDL_RenderClear( m_renderer );
            SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);
            SDL_RenderPresent( m_renderer );
        }


        setting = 0;
        leader_board = 0;
        namayesh = 0;
        mode = 0;
        Rock = 0;

        if(x >=520 && x<=760 && y>=335 && y<=400 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
        {
            flag = 1;
            red.clear();
            grean.clear();
            blue.clear();
            teta.clear();
            power.clear();
        }


        if(x >=520 && x<=760 && y>=440 && y<=510 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
            setting = 1;

        if(x >=520 && x<=760 && y>=530 && y<=600 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
            leader_board = 1;

        if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
        {
            e->type = 0;
            kill();
        }

        if(flag == 1)
        {
            i = 0;
            ii = 0;
            T = 0;
            emtiaz = 0;
            SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
            SDL_RenderClear( m_renderer );
            toBeDrawn = true;
            start = SDL_GetTicks();
            m3_img = IMG_LoadTexture(m_renderer, "cannon3.png");
            m2_img2 = IMG_LoadTexture(m_renderer, "vrood.jpg");
            //new_IMG  = SDL_RenderCopyEx(m_renderer,m_img,NULL,NULL,)
            //Get the width and height of the texture
            SDL_QueryTexture(m3_img, NULL, NULL, &img3_w, &img3_h);

            img3_rect.x = xo-25;
            img3_rect.y = H/2-30;
            img3_rect.w = 50;
            img3_rect.h = 60;
            SDL_QueryTexture(m2_img2, NULL, NULL, &img2_w, &img2_h);

            img2_rect.x = xo+260;
            img2_rect.y = H/2-30;
            img2_rect.w = 50;
            img2_rect.h = 60;
            flag = 0;
            SDL_RenderCopy(m_renderer, m6_img, NULL, &img_rect);
            SDL_RenderPresent(m_renderer);
            e->type = 0;

        }

        while(leader_board)
        {
            if(Mix_PlayingMusic() == 0)
            {
                next = 1;
                ahang++;
            }
            if(ahang % 4 == 0 && next == 1)
            {
                Mix_PlayMusic(background_sound1, 0);
                next = 0;
            }
            else if(ahang % 4 == 1 && next == 1)
            {
                Mix_PlayMusic(background_sound2, 0);
                next = 0;
            }
            else if(ahang % 4 == 2 && next == 1)
            {
                Mix_PlayMusic(background_sound3, 0);
                next = 0;
            }
            else if(ahang % 4 == 3 && next == 1)
            {
                Mix_PlayMusic(background_sound4, 0);
                next = 0;
            }
            SDL_RenderCopy(m_renderer, m13_img, NULL, &img_rect);

            SDL_PollEvent(e);

            SDL_ShowCursor(SDL_ENABLE);
            x=e->button.x;
            y=e->button.y;

            if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
            {
                e->type = 0;
                leader_board = 0;
            }
            for(int i=0; i<player; i++)
            {
                textRGBA2(m_renderer,W/2 - 180,H/2 - 100 + 50 * i,name[shomare[i]].c_str(),20,255,255,0,255);
                textRGBA2(m_renderer,W/2 + 100,H/2 - 100 + 50 * i,to_string(record[i]).c_str(),20,255,255,0,255);
            }
            if(namayesh == 0)
                SDL_RenderPresent(m_renderer);

            namayesh = 1;
            e->type = 0;

        }
        while(setting)
        {
            help = 0;
            if(Mix_PlayingMusic() == 0)
            {
                next = 1;
                ahang++;
            }
            if(ahang % 4 == 0 && next == 1)
            {
                Mix_PlayMusic(background_sound1, 0);
                next = 0;
            }
            else if(ahang % 4 == 1 && next == 1)
            {
                Mix_PlayMusic(background_sound2, 0);
                next = 0;
            }
            else if(ahang % 4 == 2 && next == 1)
            {
                Mix_PlayMusic(background_sound3, 0);
                next = 0;
            }
            else if(ahang % 4 == 3 && next == 1)
            {
                Mix_PlayMusic(background_sound4, 0);
                next = 0;
            }
            SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);
            SDL_RenderCopy(m_renderer, m8_img, NULL, &img8_rect);

            SDL_PollEvent(e);

            SDL_ShowCursor(SDL_ENABLE);
            x=e->button.x;
            y=e->button.y;
            if(x >=635 && x<=825 && y>=310 && y<=355  && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
            {
                music++;
                music %= 2;
            }

            if(x >=430 && x<=620 && y>=310 && y<=355  && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
            {
                sound++;
                sound %= 2;
            }

            if((x >=840 && x<=873 && y>=193 && y<=220  && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT)) || (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE))
            {
                setting = 0;
            }
            if(x >=435 && x<=620 && y>=368 && y<=410  && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
            {
                help = 1;
                img(W/2,H/2,300,400,help_img);
                SDL_RenderPresent(m_renderer);
            }
            while(help)
            {
                SDL_PollEvent(e);
                if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
                    help = 0;
                e->type = 0;
            }

            if(sound %2 == 0 && music %2 ==0)
            {
                SDL_RenderCopy(m_renderer, m8_img, NULL, &img8_rect);
                textRGBA2(m_renderer,W/2 - 140,H/2 - 120,login_uu.c_str(),50,0,0,255,255);
                Mix_VolumeMusic(128);
                Mix_VolumeChunk(shelik_efect,128);
            }

            else if(sound %2 == 0 && music %2 ==1)
            {
                SDL_RenderCopy(m_renderer, m9_img, NULL, &img8_rect);
                textRGBA2(m_renderer,W/2 - 140,H/2 - 120,login_uu.c_str(),50,0,0,255,255);
                Mix_VolumeMusic(0);
                Mix_VolumeChunk(shelik_efect,128);
            }

            else if(sound %2 == 1 && music %2 ==0)
            {
                SDL_RenderCopy(m_renderer, m10_img, NULL, &img8_rect);
                textRGBA2(m_renderer,W/2 - 140,H/2 - 120,login_uu.c_str(),50,0,0,255,255);
                Mix_VolumeMusic(128);
                Mix_VolumeChunk(shelik_efect,0);

            }
            else if(sound %2 == 1 && music %2 ==1)
            {
                SDL_RenderCopy(m_renderer, m11_img, NULL, &img8_rect);
                textRGBA2(m_renderer,W/2 - 140,H/2 - 120,login_uu.c_str(),50,0,0,255,255);
                Mix_VolumeMusic(0);
                Mix_VolumeChunk(shelik_efect,0);
            }

            SDL_RenderPresent( m_renderer );


            e->type = 0;
        }

        while(toBeDrawn)
        {

            if(Mix_PlayingMusic() == 0)
            {
                next = 1;
                ahang++;
            }
            if(ahang % 4 == 0 && next == 1)
            {
                Mix_PlayMusic(background_sound1, 0);
                next = 0;
            }
            else if(ahang % 4 == 1 && next == 1)
            {
                Mix_PlayMusic(background_sound2, 0);
                next = 0;
            }
            else if(ahang % 4 == 2 && next == 1)
            {
                Mix_PlayMusic(background_sound3, 0);
                next = 0;
            }
            else if(ahang % 4 == 3 && next == 1)
            {
                Mix_PlayMusic(background_sound4, 0);
                next = 0;
            }
            SDL_PollEvent(e);

            SDL_ShowCursor(SDL_ENABLE);
            x=e->button.x;
            y=e->button.y;

            SDL_RenderCopy(m_renderer, m12_img, NULL, &img_rect);
            if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
            {
                e->type = 0;
                toBeDrawn = 0;
            }

            mode = 0;
            Rock = 0;
            power_rainbow = 0;
            rainbowball = 0;
            power_bomb = 0;
            bombball = 0;
            power_meteorite = 0;
            meteoriteball = 0;
            power_fire = 0;
            fireball = 0;
            power_freeze = 0;
            freezeball = 0;
            power_pause = 0;
            pauseball = 0;
            power_backward = 0;
            backwardball = 0;

            if(x >=492 && x<=788 && y>=283 && y<=370 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
            {
                map_menu = 1;
                mode = 1;
            }

            if(x >=492 && x<=788 && y>=374 && y<=458 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
            {
                map_menu = 1;
                mode = 2;
            }

            if(x >=492 && x<=788 && y>=464 && y<=549 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
            {
                map_menu = 1;
                mode = 3;
            }
            e->type = 0;
            SDL_RenderPresent(m_renderer);

            while(map_menu)
            {
                if(Mix_PlayingMusic() == 0)
                {
                    next = 1;
                    ahang++;
                }
                if(ahang % 4 == 0 && next == 1)
                {
                    Mix_PlayMusic(background_sound1, 0);
                    next = 0;
                }
                else if(ahang % 4 == 1 && next == 1)
                {
                    Mix_PlayMusic(background_sound2, 0);
                    next = 0;
                }
                else if(ahang % 4 == 2 && next == 1)
                {
                    Mix_PlayMusic(background_sound3, 0);
                    next = 0;
                }
                else if(ahang % 4 == 3 && next == 1)
                {
                    Mix_PlayMusic(background_sound4, 0);
                    next = 0;
                }
                SDL_PollEvent(e);

                SDL_ShowCursor(SDL_ENABLE);
                x=e->button.x;
                y=e->button.y;
                map1 = 0;
                map2 = 0;
                map3 = 0;

                SDL_RenderCopy(m_renderer, m6_img, NULL, &img_rect);

                if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
                {
                    e->type = 0;
                    map_menu = 0;
                }


                if(x >=345 && x<=480 && y>=320 && y<=460 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    start = time(NULL);
                    map1 = 1;
                    map_menu = 0;
                    pause = 0;
                }


                if(x >=575 && x<=710 && y>=320 && y<=460 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    start = time(NULL);
                    map2 = 1;
                    map_menu = 0;
                    pause = 0;
                }

                if(x >=805 && x<=940 && y>=320 && y<=460 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                {
                    start = time(NULL);
                    map3 = 1;
                    map_menu = 0;
                    pause = 0;
                }
                SDL_RenderPresent(m_renderer);

            }

            while(map1)
            {
                SDL_PollEvent(e);

                SDL_ShowCursor(SDL_ENABLE);
                xC=e->button.x;
                yC=e->button.y;
                if(Mix_PlayingMusic() == 0)
                {
                    next = 1;
                    ahang++;
                }
                if(ahang % 4 == 0 && next == 1)
                {
                    Mix_PlayMusic(background_sound1, 0);
                    next = 0;
                }
                else if(ahang % 4 == 1 && next == 1)
                {
                    Mix_PlayMusic(background_sound2, 0);
                    next = 0;
                }
                else if(ahang % 4 == 2 && next == 1)
                {
                    Mix_PlayMusic(background_sound3, 0);
                    next = 0;
                }
                else if(ahang % 4 == 3 && next == 1)
                {
                    Mix_PlayMusic(background_sound4, 0);
                    next = 0;
                }

                if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
                {
                    e->type = 0;
                    corno = time(NULL);
                    while(1)
                    {

                        e->type = 0;
                        SDL_PollEvent(e);

                        SDL_ShowCursor(SDL_ENABLE);
                        x=e->button.x;
                        y=e->button.y;
                        if(x >=635 && x<=825 && y>=310 && y<=355  && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                        {
                            music++;
                            music %= 2;
                        }

                        if(x >=430 && x<=620 && y>=310 && y<=355  && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                        {
                            sound++;
                            sound %= 2;
                        }

                        if((x >=840 && x<=873 && y>=193 && y<=220  && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT)) || (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE))
                        {
                            e->type = 0;
                            break;
                        }

                        if(x >=435 && x<=620 && y>=368 && y<=410 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                        {
                            map1 = 0;
                            toBeDrawn = 0;
                            e->type = 0;
                            break;
                        }
                        if(x >=635 && x<=825 && y>=368 && y<=410  && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                        {
                            ahang++;
                            ahang %= 4;
                            next = 1;
                        }

                        if(ahang % 4 == 0 && next == 1)
                        {
                            Mix_PlayMusic(background_sound1, 0);
                            next = 0;
                        }
                        else if(ahang % 4 == 1 && next == 1)
                        {
                            Mix_PlayMusic(background_sound2, 0);
                            next = 0;
                        }
                        else if(ahang % 4 == 2 && next == 1)
                        {
                            Mix_PlayMusic(background_sound3, 0);
                            next = 0;
                        }
                        else if(ahang % 4 == 3 && next == 1)
                        {
                            Mix_PlayMusic(background_sound4, 0);
                            next = 0;
                        }

                        if(sound %2 == 0 && music %2 ==0)
                        {
                            SDL_RenderCopy(m_renderer, m8p_img, NULL, &img8_rect);
                            textRGBA2(m_renderer,W/2 - 140,H/2 - 120,login_uu.c_str(),50,0,0,255,255);
                            Mix_VolumeMusic(128);
                            Mix_VolumeChunk(shelik_efect,128);
                        }

                        else if(sound %2 == 0 && music %2 ==1)
                        {
                            SDL_RenderCopy(m_renderer, m9p_img, NULL, &img8_rect);
                            textRGBA2(m_renderer,W/2 - 140,H/2 - 120,login_uu.c_str(),50,0,0,255,255);
                            Mix_VolumeMusic(0);
                            Mix_VolumeChunk(shelik_efect,128);
                        }

                        else if(sound %2 == 1 && music %2 ==0)
                        {
                            SDL_RenderCopy(m_renderer, m10p_img, NULL, &img8_rect);
                            textRGBA2(m_renderer,W/2 - 140,H/2 - 120,login_uu.c_str(),50,0,0,255,255);
                            Mix_VolumeMusic(128);
                            Mix_VolumeChunk(shelik_efect,0);

                        }
                        else if(sound %2 == 1 && music %2 ==1)
                        {
                            SDL_RenderCopy(m_renderer, m11p_img, NULL, &img8_rect);
                            textRGBA2(m_renderer,W/2 - 140,H/2 - 120,login_uu.c_str(),50,0,0,255,255);
                            Mix_VolumeMusic(0);
                            Mix_VolumeChunk(shelik_efect,0);
                        }

                        SDL_RenderPresent( m_renderer );

                    }
                    corno = time(NULL) - corno;
                    pause += corno;
                    e->type = 0;

                }

                if(t > 320/(320 * pow(2.7,-1*T/15))*0.13 && ii < 80)
                {
                    rock_vrood = 0;
                    srand(start + i);
                    r = rand()%255;

                    if(r % 9 != 0)
                    {
                        if(rand() % 10 == 0)
                            power.push_back(1);
                        else if(rand() % 10 == 1)
                            power.push_back(2);
                        else if(rand() % 10 == 2)
                            power.push_back(3);
                        else
                            power.push_back(0);
                    }
                    else
                    {
                        power.push_back(0);
                        if(mode == 2)
                        {
                            r=0;
                            g=0;
                            b=0;
                            Rock++;
                            rock_vrood = 1;
                        }
                    }


                    if(r % 4 == 0 && rock_vrood == 0)
                    {
                        r=255;
                        g=0;
                        b=0;
                    }
                    else if(r % 4 == 1 && rock_vrood == 0)
                    {
                        r=0;
                        g=255;
                        b=0;
                    }
                    else if(r % 4 == 2 && rock_vrood == 0)
                    {
                        r=0;
                        g=0;
                        b=255;
                    }
                    else if(r % 4 == 3 && rock_vrood == 0)
                    {
                        r=255;
                        g=255;
                        b=0;
                    }


                    red.push_back(r);
                    grean.push_back(g);
                    blue.push_back(b);
                    teta.push_back(T);


                    t = 0;
                    i++;
                    ii++;
                }

                xE[0] = xo + 50*cos(alfa);
                yE[0] = yo - 50*sin(alfa);
                xE[1] = xo - 20*cos(alfa);
                yE[1] = yo + 20*sin(alfa);
                T += 0.002;
                t += 0.002;
                if(mode == 2 && ii == 80 && i == Rock)
                {
                    T += 0.02;
                    t += 0.02;
                }

                if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_SPACE)
                {
                    change_color = 1;
                    e->type = 0;
                }

                if(change_color == 1)
                {
                    r2[0] -= r2[1];
                    r2[1] += r2[0];
                    r2[0] = r2[1] - r2[0];
                    g2[0] -= g2[1];
                    g2[1] += g2[0];
                    g2[0] = g2[1] - g2[0];
                    b2[0] -= b2[1];
                    b2[1] += b2[0];
                    b2[0] = b2[1] - b2[0];
                    change_color = 0;
                }

                SDL_RenderCopy(m_renderer, m5_img, NULL, &img5_rect);

                if(xC >=32 && xC<=80 && yC>=122 && yC<=168 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT) && power_rainbow == 0)//rainbowball
                {
                    rainbowball = 1;
                    power_rainbow = 1;
                    e->type = 0;
                }
                if(xC >=32 && xC<=80 && yC>=190 && yC<=245 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT) && power_bomb == 0)//bombball
                {
                    bombball = 1;
                    power_bomb = 1;
                    e->type = 0;
                }

                if(xC >=32 && xC<=80 && yC>=275 && yC<=320 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT) && power_meteorite == 0)//meteoriteball
                {
                    meteoriteball = 1;
                    power_meteorite = 1;
                    e->type = 0;
                }

                if(xC >=32 && xC<=80 && yC>=345 && yC<=395 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT) && power_fire == 0)//fireball
                {
                    fireball = 1;
                    power_fire = 1;
                    e->type = 0;
                }

                for(int j =0; j<i; j++)
                {
                    R1 = 320;
                    R2 = 320;
                    R1 *=  pow(2.7,-1*teta.operator[](j)/15);
                    R2 *=  pow(2.7,-1*teta.operator[](j)/15);

                    alfa = acos((xC - xo)/sqrt((xC - xo)*(xC - xo) + (yC-yo)*(yC-yo)));

                    if(yC > yo)
                        alfa = 2 * M_PI - alfa;
                    if(T > 2 * M_PI)
                        if(alfa < T - 2* M_PI && alfa > 0)
                            alfa += 2 * M_PI;


                    double m = 0;
                    for(int k=0; k<=j; k++)
                        m += 320/(320 * pow(2.7,-1*teta.operator[](k)/15))*0.13;
                    teta.operator[](j) = T - m;

                    if(e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT && ((mode == 1 || mode == 3) || (mode == 2  && (ii < 80 || i > Rock))))
                    {
                        Mix_PlayChannel(-1,shelik_efect,0);
                        shelik = 1;
                        residan = 0;
                        R_shelik = 320 * pow(2.7,-1*alfa/15) - 20;
                        alfa_shelik = alfa;
                        e->type = 0;
                    }


                    if(residan == 1)
                    {
                        power_freeze = 0;
                        power_pause = 0;
                        power_backward = 0;

                        alfa = alfa_shelik;
                        double beta = alfa;
                        double aaalfa = abs(T - beta);
                        z = 0;
                        for(int k = 1; k<i; k++)
                            if(abs(beta - teta.operator[](k)) < aaalfa)
                            {
                                z = k;
                                aaalfa = abs(beta - teta.operator[](k));

                            }

                        if(rainbowball == 1)
                        {
                            int qq = 0;
                            r = red.operator[](z);
                            g = grean.operator[](z);
                            b = blue.operator[](z);
                            if(r != 0 || g != 0 || b != 0)
                                for(int k=0; k<i; k++)
                                    if(r == red.operator[](k - qq) && g == grean.operator[](k - qq) && b == blue.operator[](k - qq))
                                    {
//                                        if(power.operator[](k - qq) == 1)
//                                            power_freeze = 1;
//                                        if(power.operator[](k - qq) == 2)
//                                            power_pause = 1;
//                                        if(power.operator[](k - qq) == 3)
//                                            power_backward = 1;

                                        red.erase(red.begin() + k - qq);
                                        grean.erase(grean.begin() + k - qq);
                                        blue.erase(blue.begin() + k - qq);
                                        T -= 320/(320 * pow(2.7,-1*teta.operator[](k - qq)/15))*0.13;
                                        teta.erase(teta.begin() + k - qq);
                                        power.erase(power.begin() + k - qq);
                                        qq++;

                                    }
                            rainbowball = 0;
                            i -= qq;
                            emtiaz += qq;
                        }

                        else if(bombball == 1 && z > 3)
                        {
//                            for(int k=z-4; k<z+4; k++)
//                            {
//                                if(power.operator[](k) == 1)
//                                    power_freeze = 1;
//                                if(power.operator[](k) == 2)
//                                    power_pause = 1;
//                                if(power.operator[](k) == 3)
//                                    power_backward = 1;
//                            }
                            double x = xo + 320*pow(2.7,-1*teta.operator[](z)/15)*cos(teta.operator[](z));
                            double y = yo - 320*pow(2.7,-1*teta.operator[](z)/15)*sin(teta.operator[](z));

                            img(x,y,200,200,e1_img);
                            SDL_RenderPresent( m_renderer );
                            SDL_Delay(100);
                            img(x,y,200,200,e2_img);
                            SDL_RenderPresent( m_renderer );
                            SDL_Delay(100);
                            img(x,y,200,200,e3_img);
                            SDL_RenderPresent( m_renderer );
                            SDL_Delay(100);
                            img(x,y,200,200,e4_img);
                            SDL_RenderPresent( m_renderer );
                            SDL_Delay(100);

                            if(mode == 2)
                                for(int k=z-4; k<z+4; k++)
                                    if(red.operator[](k) == 0 && grean.operator[](k) == 0 && blue.operator[](k) == 0)
                                        Rock--;
                            red.erase(red.begin() + z - 4,red.begin() + z + 4);
                            grean.erase(grean.begin() + z - 4, grean.begin() + z + 4);
                            blue.erase(blue.begin() + z - 4, blue.begin() + z + 4);
                            m = 0;
                            for(int k=z-4; k<z+4; k++)
                                m += 320/(320 * pow(2.7,-1*teta.operator[](k)/15))*0.13;
                            T -= m;
                            teta.erase(teta.begin() + z - 4, teta.begin() + z + 4);
                            power.erase(power.begin() + z - 4, power.begin() + z + 4);
                            bombball = 0;
                            i -= 8;
                            emtiaz += 64;
                        }

                        else if(meteoriteball == 1 && i > 0)
                        {
                            if(mode == 2)
                                for(int k=0; k<i; k++)
                                    if(red.operator[](k) == 0 && grean.operator[](k) == 0 && blue.operator[](k) == 0)
                                        Rock--;
                            red.erase(red.begin(),red.begin() + i);
                            grean.erase(grean.begin(), grean.begin() + i);
                            blue.erase(blue.begin(), blue.begin() + i);
                            m = 0;
                            for(int k=0; k<i; k++)
                                m += 320/(320 * pow(2.7,-1*teta.operator[](k)/15))*0.13;
                            T -= m;
                            teta.erase(teta.begin(), teta.begin() + i);
                            power.erase(power.begin(), power.begin() + i);
                            meteoriteball = 0;
                            emtiaz += i;
                            i = 0;
                        }

                        else if(fireball == 1)
                        {
                            if(power.operator[](z) == 1)
                                power_freeze = 1;
                            if(power.operator[](z) == 2)
                                power_pause = 1;
                            if(power.operator[](z) == 3)
                                power_backward = 1;
                            if(red.operator[](z) == 0 && grean.operator[](z) == 0 && blue.operator[](z) == 0)
                                Rock--;
                            red.erase(red.begin() + z);
                            grean.erase(grean.begin() + z);
                            blue.erase(blue.begin() + z);
                            T -= 320/(320 * pow(2.7,-1*teta.operator[](z)/15))*0.13;
                            teta.erase(teta.begin() + z);
                            power.erase(power.begin() + z);
                            emtiaz++;
                            i--;
                            fireball = 0;
                        }

                        else
                        {
                            if(beta < teta.operator[](z))
                                z++;

                            red.insert(red.begin() + z,r2[0]);
                            grean.insert(grean.begin() + z,g2[0]);
                            blue.insert(blue.begin() + z,b2[0]);
                            teta.insert(teta.begin() + z,alfa);
                            power.insert(power.begin() + z,0);
                            i++;
                            s++;
                            T += 320/(320 * pow(2.7,-1*teta.operator[](z)/15))*0.13;

                            atrafr = 0;
                            atrafl = 0;

                            if(i> 3)
                            {
                                while(red.operator[](z+atrafr) == r2[0] && grean.operator[](z+atrafr) == g2[0] && blue.operator[](z+atrafr) == b2[0] && red.size() > z + atrafr)
                                    atrafr++;

                                while(red.operator[](z-atrafl) == r2[0] && grean.operator[](z-atrafl) == g2[0] && blue.operator[](z-atrafl) == b2[0] && z - atrafl >= 0)
                                    atrafl++;

                                //atrafr--;
                                //atrafl--;
                            }
                            //cout << z << " l: " << atrafl << " r: " << atrafr <<endl;
                            if((atrafr + atrafl) > 3)
                            {
                                zarib = 0;
                                if(atrafl == 1)
                                {
                                    for(int q=0; q < atrafr; q++)
                                    {
                                        if(power.operator[](z) == 1)
                                            power_freeze = 1;
                                        if(power.operator[](z) == 2)
                                            power_pause = 1;
                                        if(power.operator[](z) == 3)
                                            power_backward = 1;
                                        red.erase(red.begin() + z);
                                        grean.erase(grean.begin() +z);
                                        blue.erase(blue.begin() + z);
                                        i--;
                                        T -= 320/(320 * pow(2.7,-1*teta.operator[](z)/15))*0.13;
                                        teta.erase(teta.begin() + z);
                                        power.erase(power.begin() + z);
                                        zarib++;
                                    }
                                }

                                else if(atrafr == 1)
                                {
                                    for(int q=0; q < atrafl; q++)
                                    {
                                        if(power.operator[](z) == 1)
                                            power_freeze = 1;
                                        if(power.operator[](z) == 2)
                                            power_pause = 1;
                                        if(power.operator[](z) == 3)
                                            power_backward = 1;
                                        red.erase(red.begin() + z);
                                        grean.erase(grean.begin() + z);
                                        blue.erase(blue.begin() + z);
                                        i--;
                                        T -= 320/(320 * pow(2.7,-1*teta.operator[](z)/15))*0.13;
                                        teta.erase(teta.begin() + z);
                                        power.erase(power.begin() + z);
                                        z--;
                                        zarib++;
                                    }
                                }
                                else
                                {
                                    if(power.operator[](z) == 1)
                                        power_freeze = 1;
                                    if(power.operator[](z) == 2)
                                        power_pause = 1;
                                    if(power.operator[](z) == 3)
                                        power_backward = 1;
                                    red.erase(red.begin() + z);
                                    grean.erase(grean.begin() +z);
                                    blue.erase(blue.begin() + z);
                                    i--;
                                    T -= 320/(320 * pow(2.7,-1*teta.operator[](j)/15))*0.13;
                                    teta.erase(teta.begin() + z);
                                    power.erase(power.begin() + z);
                                    zarib++;
                                    for(int q=0; q < atrafr - 1; q++)
                                    {
                                        if(power.operator[](z) == 1)
                                            power_freeze = 1;
                                        if(power.operator[](z) == 2)
                                            power_pause = 1;
                                        if(power.operator[](z) == 3)
                                            power_backward = 1;
                                        red.erase(red.begin() + z);
                                        grean.erase(grean.begin() +z);
                                        blue.erase(blue.begin() + z);
                                        i--;
                                        T -= 320/(320 * pow(2.7,-1*teta.operator[](j)/15))*0.13;
                                        teta.erase(teta.begin() + z);
                                        power.erase(power.begin() + z);
                                        zarib++;
                                    }
                                    for(int q=0; q < atrafl - 1; q++)
                                    {
                                        if(power.operator[](z - 1 - q) == 1)
                                            power_freeze = 1;
                                        if(power.operator[](z - 1 - q) == 2)
                                            power_pause = 1;
                                        if(power.operator[](z - 1 - q) == 3)
                                            power_backward = 1;
                                        red.erase(red.begin() + z - 1 - q);
                                        grean.erase(grean.begin() + z - 1 - q);
                                        blue.erase(blue.begin() + z - 1 - q);
                                        i--;
                                        T -= 320/(320 * pow(2.7,-1*teta.operator[](j)/15))*0.13;
                                        teta.erase(teta.begin() + z - 1 - q);
                                        power.erase(power.begin() + z - 1 - q);
                                        zarib++;
                                    }
                                }

                                emtiaz += (zarib - 1) * (zarib - 1);
                            }

                            int hazer = red.size();


                            if(ii < 80)
                            {
                                r2[0] = r2[1];
                                g2[0] = g2[1];
                                b2[0] = b2[1];
                            }

                            bool rr = 0;
                            bool bb = 0;
                            bool zz = 0;
                            bool gg = 0;

                            for(int k=0; k<hazer; k++)
                            {
                                if(rr == 0)
                                    if(red.operator[](k) == 255 && grean.operator[](k) == 0)
                                        rr = 1;
                                if(zz == 0)
                                    if(red.operator[](k) == 255 && grean.operator[](k) == 255)
                                        zz = 1;
                                if(bb == 0)
                                    if(blue.operator[](k) == 255)
                                        bb = 1;
                                if(gg == 0)
                                    if(grean.operator[](k) == 255 && red.operator[](k) == 0)
                                        gg = 1;
                            }

                            srand(start + s);
                            if(rr == 1 && zz == 0 && bb == 0 && gg == 0)
                            {
                                r2[1]=255;
                                g2[1]=0;
                                b2[1]=0;
                            }
                            else if(rr == 0 && zz == 1 && bb == 0 && gg == 0)
                            {
                                r2[1]=255;
                                g2[1]=255;
                                b2[1]=0;
                            }
                            else if(rr == 0 && zz == 0 && bb == 1 && gg == 0)
                            {
                                r2[1]=0;
                                g2[1]=0;
                                b2[1]=255;
                            }
                            else if(rr == 0 && zz == 0 && bb == 0 && gg == 1)
                            {
                                r2[1]=0;
                                g2[1]=255;
                                b2[1]=0;
                            }
                            else if(rr == 1 && zz == 1 && bb == 0 && gg == 0)
                            {

                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 1 && zz == 0 && bb == 1 && gg == 0)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                            }
                            else if(rr == 1 && zz == 0 && bb == 0 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 0 && zz == 1 && bb == 1 && gg == 0)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                            }
                            else if(rr == 0 && zz == 1 && bb == 0 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 0 && zz == 0 && bb == 1 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 1 && zz == 1 && bb == 1 && gg == 0)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 3 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 1)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 2)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                            }
                            else if(rr == 1 && zz == 1 && bb == 0 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 3 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 1)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 2)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 0 && zz == 1 && bb == 1 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 3 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                                else if(r2[1] % 3 == 2)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 1 && zz == 0 && bb == 1 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 3 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                                else if(r2[1] % 3 == 2)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 4 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 4 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 4 == 2)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                                else if(r2[1] % 4 == 3)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }


                            if(ii == 80)
                            {
                                r2[0] = r2[1];
                                g2[0] = g2[1];
                                b2[0] = b2[1];
                            }

                        }

                        if(power_freeze == 1)
                        {
                            t1_efect = time(NULL);
                            freezeball = 1;
                            power_freeze = 0;
                        }
                        if(power_pause == 1)
                        {
                            t2_efect = time(NULL);
                            pauseball = 1;
                            power_pause = 0;
                        }
                        if(power_backward == 1)
                        {
                            t3_efect = time(NULL);
                            backwardball = 1;
                            power_backward = 0;
                        }


                        residan = 0;
                    }

                    if((ii == 80 && i == Rock && mode == 2 && ((i > 0 && T > 4*M_PI - .1) || (i == 0 && T < 4*M_PI - .1))) || (ii == 80 && i == Rock && (mode == 1 || mode == 3)))
                    {
                        emtiaz += 140 - (time(NULL) - start - pause);
                        toBeDrawn = 0;
                        map1 = 0;
                        SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
                        SDL_RenderClear(m_renderer);
                        img(640,200,1280,400,m30_img);
                        textRGBA2(m_renderer, W/2 - 190, H/2 - 100, "you win", 100, 0, 255, 0, 255);
                        textRGBA2(m_renderer, W/2 - 50, H/2 + 50, to_string(emtiaz).c_str(), 60, 0, 255, 255, 255);
                        SDL_RenderPresent(m_renderer);
                        string s;
                        string name[100];
                        bool check = 0;
                        ifstream f;
                        f.open("emtiaz.txt", ios_base::in);
                        int k = 0, khat;
                        while(!f.eof())
                        {
                            getline(f, s);
                            name[k] = s;
                            k++;
                            if (s.compare(login_uu) == 0)
                            {
                                while(s != "/...")
                                {
                                    getline(f, s);
                                    name[k] = s;
                                    k++;
                                }
                                check = 1;
                                khat = k;
                                break;
                            }
                        }
                        if(check == 1)
                        {
                            while(!f.eof())
                            {
                                getline(f, s);
                                name[k] = s;
                                k++;
                            }
                            f.close();
                            ofstream ff("emtiaz.txt",ios::out);
                            ff << name[0] << endl;
                            ff.close();
                            ofstream fff("emtiaz.txt",ios::app);
                            for(int i = 1; i < khat-1; i++)
                            {
                                fff << name[i] << endl;
                            }
                            fff << emtiaz << endl << "/...";
                            for(int i = khat; i < k; i++)
                            {
                                fff << endl << name[i];
                            }
                            fff.close();
                        }
                        else
                        {
                            ofstream fff("emtiaz.txt",ios::app);
                            fff << endl << login_uu << endl << emtiaz << endl << "/...";
                            fff.close();
                        }
                        SDL_Delay(4000);
                        break;
                    }

                    m = 0;
                    for(int k=0; k<=j; k++)
                        m += 320/(320 * pow(2.7,-1*teta.operator[](k)/15))*0.13;
                    teta.operator[](j) = T - m;

                    filledEllipseRGBA(m_renderer, xo + R1*cos(teta.operator[](j)), yo - R2*sin(teta.operator[](j)), 20, 20, red.operator[](j), grean.operator[](j), blue.operator[](j), 255);
                    if(power.operator[](j) == 1)
                        img(xo + R1*cos(teta.operator[](j)),yo - R2*sin(teta.operator[](j)),100,100,m20_img);
                    if(power.operator[](j) == 2)
                        img(xo + R1*cos(teta.operator[](j)),yo - R2*sin(teta.operator[](j)),30,30,m21_img);
                    if(power.operator[](j) == 3)
                        img(xo + R1*cos(teta.operator[](j)),yo - R2*sin(teta.operator[](j)),30,30,m22_img);

                }

                aalineRGBA(m_renderer,xo,H/2,xC,yC,255,255,255,255);
                if(ii < 80 || (ii == 80 && i > Rock))
                    filledEllipseRGBA(m_renderer,xE[0],yE[0],20,20,r2[0],g2[0],b2[0],255);
                if(rainbowball == 1)
                {
                    img(xE[0],yE[0],80,80,m24_img);
                }
                if(bombball == 1)
                {
                    img(xE[0],yE[0],80,80,m25_img);
                }
                if(meteoriteball == 1)
                {
                    img(xE[0],yE[0],80,80,m26_img);
                }
                if(fireball == 1)
                {
                    img(xE[0],yE[0],50,50,m23_img);
                }

                if(freezeball == 1)
                {
                    T -= .001;
                    t -= .001;
                    if(time(NULL) - t1_efect > 3)
                        freezeball = 0;
                }
                if(pauseball == 1)
                {
                    T -= .002;
                    t -= .002;
                    if(time(NULL) - t2_efect > 3)
                        pauseball = 0;
                }
                if(backwardball == 1)
                {
                    T -= .003;
                    t -= .003;
                    if(time(NULL) - t3_efect > 3)
                        backwardball = 0;
                }

                SDL_RenderCopyEx(m_renderer, m3_img, NULL, &img3_rect, -1 * (alfa * 180 / M_PI - 90), &img3_point, SDL_FLIP_NONE);

                if(ii < 80)
                    filledEllipseRGBA(m_renderer,xE[1],yE[1],10,10,r2[1],g2[1],b2[1],255);


                if(shelik == 1)
                {
                    residan = 0;
                    TT += 20;
                    xs = xo + (50+TT)*cos(alfa_shelik);
                    ys = yo - (50+TT)*sin(alfa_shelik);

                    if(rainbowball == 1)
                    {
                        img(xs,ys,80,80,m24_img);
                    }
                    else if(bombball == 1)
                    {
                        img(xs,ys,80,80,m25_img);
                    }
                    else if(meteoriteball == 1)
                    {
                        img(xs,ys,80,80,m26_img);
                    }
                    else if(fireball == 1)
                    {
                        img2(xs,ys,alfa_shelik,120,60,f_img);
                    }

                    else
                        filledEllipseRGBA(m_renderer,xs,ys,20,20,r2[0],g2[0],b2[0],255);

                    if((xs - xo) * (xs - xo) + (ys - yo) * (ys - yo) > R_shelik * R_shelik)
                    {
                        if(alfa_shelik < T + 0.26 && alfa_shelik > teta.operator[](i-1) - .26)
                        {
                            residan = 1;
                            shelik = 0;
                            TT = 0;
                        }
                        else
                        {
                            residan = 0;
                            shelik = 0;
                            TT = 0;
                        }

                    }

                }

                textRGBA2(m_renderer,100,50,to_string(emtiaz).c_str(),20,255,255,0,255);

                if(mode == 3)
                    textRGBA2(m_renderer,100,100,to_string(140 + pause - time(NULL) + start).c_str(),20,255,255,0,255);

                if(mode == 1 || mode == 2)
                    textRGBA2(m_renderer,100,100,to_string(time(NULL) - pause - start).c_str(),20,255,255,0,255);

                if(T > 4*M_PI - .1 && (mode == 1 || mode == 2) && i > Rock)
                {
                    toBeDrawn = 0;
                    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
                    SDL_RenderClear(m_renderer);
                    img(630,350,860,700,m31_img);
                    SDL_RenderPresent( m_renderer );
                    string s;
                    string name[100];
                    bool check = 0;
                    ifstream f;
                    f.open("emtiaz.txt", ios_base::in);
                    int k = 0, khat;
                    while(!f.eof())
                    {
                        getline(f, s);
                        name[k] = s;
                        k++;
                        if (s.compare(login_uu) == 0)
                        {
                            while(s != "/...")
                            {
                                getline(f, s);
                                name[k] = s;
                                k++;
                            }
                            check = 1;
                            khat = k;
                            break;
                        }
                    }
                    if(check == 1)
                    {
                        while(!f.eof())
                        {
                            getline(f, s);
                            name[k] = s;
                            k++;
                        }
                        f.close();
                        ofstream ff("emtiaz.txt",ios::out);
                        ff << name[0] << endl;
                        ff.close();
                        ofstream fff("emtiaz.txt",ios::app);
                        for(int i = 1; i < khat-1; i++)
                        {
                            fff << name[i] << endl;
                        }
                        fff << emtiaz << endl << "/...";
                        for(int i = khat; i < k; i++)
                        {
                            fff << endl << name[i];
                        }
                        fff.close();
                    }
                    else
                    {
                        ofstream fff("emtiaz.txt",ios::app);
                        fff << endl << login_uu << endl << emtiaz << endl << "/...";
                        fff.close();
                    }
                    SDL_Delay(4000);
                    map1 = 0;
                }

                else if((time(NULL) - start - pause > 140 || T > 4*M_PI - .1) && mode == 3)
                {
                    toBeDrawn = 0;
                    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
                    SDL_RenderClear(m_renderer);
                    img(630,350,860,700,m31_img);
                    SDL_RenderPresent( m_renderer );
                    string s;
                    string name[100];
                    bool check = 0;
                    ifstream f;
                    f.open("emtiaz.txt", ios_base::in);
                    int k = 0, khat;
                    while(!f.eof())
                    {
                        getline(f, s);
                        name[k] = s;
                        k++;
                        if (s.compare(login_uu) == 0)
                        {
                            while(s != "/...")
                            {
                                getline(f, s);
                                name[k] = s;
                                k++;
                            }
                            check = 1;
                            khat = k;
                            break;
                        }
                    }
                    if(check == 1)
                    {
                        while(!f.eof())
                        {
                            getline(f, s);
                            name[k] = s;
                            k++;
                        }
                        f.close();
                        ofstream ff("emtiaz.txt",ios::out);
                        ff << name[0] << endl;
                        ff.close();
                        ofstream fff("emtiaz.txt",ios::app);
                        for(int i = 1; i < khat-1; i++)
                        {
                            fff << name[i] << endl;
                        }
                        fff << emtiaz << endl << "/...";
                        for(int i = khat; i < k; i++)
                        {
                            fff << endl << name[i];
                        }
                        fff.close();
                    }
                    else
                    {
                        ofstream fff("emtiaz.txt",ios::app);
                        fff << endl << login_uu << endl << emtiaz << endl << "/...";
                        fff.close();
                    }
                    SDL_Delay(4000);
                    map1 = 0;
                }


                SDL_RenderPresent(m_renderer);
                SDL_Delay(0);
            }

            while(map2)
            {

                if(Mix_PlayingMusic() == 0)
                {
                    next = 1;
                    ahang++;
                }
                if(ahang % 4 == 0 && next == 1)
                {
                    Mix_PlayMusic(background_sound1, 0);
                    next = 0;
                }
                else if(ahang % 4 == 1 && next == 1)
                {
                    Mix_PlayMusic(background_sound2, 0);
                    next = 0;
                }
                else if(ahang % 4 == 2 && next == 1)
                {
                    Mix_PlayMusic(background_sound3, 0);
                    next = 0;
                }
                else if(ahang % 4 == 3 && next == 1)
                {
                    Mix_PlayMusic(background_sound4, 0);
                    next = 0;
                }
                SDL_PollEvent(e);


//                T1 =  SDL_GetPerformanceCounter();
//                elapsedMS = (T2 - T1) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
//                SDL_Delay(floor(16.666f - elapsedMS));

                SDL_ShowCursor(SDL_ENABLE);
                xC=e->button.x;
                yC=e->button.y;

                if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
                {
                    e->type = 0;
                    corno = time(NULL);
                    while(1)
                    {

                        e->type = 0;
                        SDL_PollEvent(e);

                        SDL_ShowCursor(SDL_ENABLE);
                        x=e->button.x;
                        y=e->button.y;
                        if(x >=635 && x<=825 && y>=310 && y<=355  && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))//x >=430 && x<=620 && y>=310 && y<=355 //help:  x >=435 && x<=620 && y>=368 && y<=410
                        {
                            music++;
                            music %= 2;
                        }

                        if(x >=430 && x<=620 && y>=310 && y<=355  && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))//x >=430 && x<=620 && y>=310 && y<=355 //help:  x >=435 && x<=620 && y>=368 && y<=410
                        {
                            sound++;
                            sound %= 2;
                        }

                        if((x >=840 && x<=873 && y>=193 && y<=220  && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT)) || (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE))//x >=430 && x<=620 && y>=310 && y<=355 //help:  x >=435 && x<=620 && y>=368 && y<=410
                        {
                            e->type = 0;
                            break;
                        }

                        if(x >=435 && x<=620 && y>=368 && y<=410 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                        {
                            map2 = 0;
                            toBeDrawn = 0;
                            e->type = 0;
                            break;
                        }

                        if(x >=635 && x<=825 && y>=368 && y<=410  && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT))
                        {
                            ahang++;
                            ahang %= 4;
                            next = 1;
                        }

                        if(ahang % 4 == 0 && next == 1)
                        {
                            Mix_PlayMusic(background_sound1, -1);
                            next = 0;
                        }
                        else if(ahang % 4 == 1 && next == 1)
                        {
                            Mix_PlayMusic(background_sound2, -1);
                            next = 0;
                        }
                        else if(ahang % 4 == 2 && next == 1)
                        {
                            Mix_PlayMusic(background_sound3, -1);
                            next = 0;
                        }
                        else if(ahang % 4 == 3 && next == 1)
                        {
                            Mix_PlayMusic(background_sound4, -1);
                            next = 0;
                        }

                        if(sound %2 == 0 && music %2 ==0)
                        {
                            SDL_RenderCopy(m_renderer, m8p_img, NULL, &img8_rect);
                            textRGBA2(m_renderer,W/2 - 140,H/2 - 120,login_uu.c_str(),50,0,0,255,255);
                            Mix_VolumeMusic(128);
                            Mix_VolumeChunk(shelik_efect,128);
                        }

                        else if(sound %2 == 0 && music %2 ==1)
                        {
                            SDL_RenderCopy(m_renderer, m9p_img, NULL, &img8_rect);
                            textRGBA2(m_renderer,W/2 - 140,H/2 - 120,login_uu.c_str(),50,0,0,255,255);
                            Mix_VolumeMusic(0);
                            Mix_VolumeChunk(shelik_efect,128);
                        }

                        else if(sound %2 == 1 && music %2 ==0)
                        {
                            SDL_RenderCopy(m_renderer, m10p_img, NULL, &img8_rect);
                            textRGBA2(m_renderer,W/2 - 140,H/2 - 120,login_uu.c_str(),50,0,0,255,255);
                            Mix_VolumeMusic(128);
                            Mix_VolumeChunk(shelik_efect,0);

                        }
                        else if(sound %2 == 1 && music %2 ==1)
                        {
                            SDL_RenderCopy(m_renderer, m11p_img, NULL, &img8_rect);
                            textRGBA2(m_renderer,W/2 - 140,H/2 - 120,login_uu.c_str(),50,0,0,255,255);
                            Mix_VolumeMusic(0);
                            Mix_VolumeChunk(shelik_efect,0);
                        }

                        SDL_RenderPresent( m_renderer );

                    }
                    corno = time(NULL) - corno;
                    pause += corno;
                    e->type = 0;

                }

                rrr = (H/2 * W/2 / sqrt((H/2*cos(T)) * (H/2*cos(T)) + (W/2*sin(T)) * (W/2*sin(T)))) * pow(2.7,-1*T/15);
                drrr = 0.001;

                if(t > acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  ) && ii < 80)
                {
                    rock_vrood = 0;
                    srand(start + i);
                    r = rand()%255;

                    if(r % 9 != 0)
                    {
                        if(rand() % 10 == 0)
                            power.push_back(1);
                        else if(rand() % 10 == 1)
                            power.push_back(2);
                        else if(rand() % 10 == 2)
                            power.push_back(3);
                        else
                            power.push_back(0);
                    }

                    else
                    {
                        power.push_back(0);
                        if(mode == 2)
                        {
                            r=0;
                            g=0;
                            b=0;
                            Rock++;
                            rock_vrood = 1;
                        }
                    }


                    if(r % 4 == 0 && rock_vrood == 0)
                    {
                        r=255;
                        g=0;
                        b=0;
                    }
                    else if(r % 4 == 1 && rock_vrood == 0)
                    {
                        r=0;
                        g=255;
                        b=0;
                    }
                    else if(r % 4 == 2 && rock_vrood == 0)
                    {
                        r=0;
                        g=0;
                        b=255;
                    }
                    else if(r % 4 == 3 && rock_vrood == 0)
                    {
                        r=255;
                        g=255;
                        b=0;
                    }

                    red.push_back(r);
                    grean.push_back(g);
                    blue.push_back(b);
                    teta.push_back(T);

                    t = 0;
                    i++;
                    ii++;
                }

                xE[0] = xo + 50*cos(alfa);
                yE[0] = yo - 50*sin(alfa);
                xE[1] = xo - 20*cos(alfa);
                yE[1] = yo + 20*sin(alfa);
                T += .002;
                t += .002;

                if(mode == 2 && ii == 80 && i == Rock)
                {
                    T += 0.02;
                    t += 0.02;
                }

                if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_SPACE)
                {
                    change_color = 1;
                    e->type = 0;
                }

                if(change_color == 1)
                {
                    r2[0] -= r2[1];
                    r2[1] += r2[0];
                    r2[0] = r2[1] - r2[0];
                    g2[0] -= g2[1];
                    g2[1] += g2[0];
                    g2[0] = g2[1] - g2[0];
                    b2[0] -= b2[1];
                    b2[1] += b2[0];
                    b2[0] = b2[1] - b2[0];
                    change_color = 0;
                }

                SDL_RenderCopy(m_renderer, m7_img, NULL, &img5_rect);

                if(xC >=32 && xC<=80 && yC>=122 && yC<=168 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT) && power_rainbow == 0)//rainbowball
                {
                    rainbowball = 1;
                    power_rainbow = 1;
                    e->type = 0;
                }
                if(xC >=32 && xC<=80 && yC>=190 && yC<=245 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT) && power_bomb == 0)//bombball
                {
                    bombball = 1;
                    power_bomb = 1;
                    e->type = 0;
                }

                if(xC >=32 && xC<=80 && yC>=275 && yC<=320 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT) && power_meteorite == 0)//meteoriteball
                {
                    meteoriteball = 1;
                    power_meteorite = 1;
                    e->type = 0;
                }

                if(xC >=32 && xC<=80 && yC>=345 && yC<=395 && (e->type == SDL_MOUSEBUTTONDOWN)&&(e->button.button == SDL_BUTTON_LEFT) && power_fire == 0)//fireball
                {
                    fireball = 1;
                    power_fire = 1;
                    e->type = 0;
                }

                for(int j =0; j<i; j++)
                {
                    R1 =  (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](j))) * (H/2*cos(teta.operator[](j))) + (W/2*sin(teta.operator[](j))) * (W/2*sin(teta.operator[](j))))) * pow(2.7,-1*teta.operator[](j)/15);
                    R2 =  (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](j))) * (H/2*cos(teta.operator[](j))) + (W/2*sin(teta.operator[](j))) * (W/2*sin(teta.operator[](j))))) * pow(2.7,-1*teta.operator[](j)/15);

                    alfa = acos((xC - xo)/sqrt((xC - xo)*(xC - xo) + (yC-yo)*(yC-yo)));

                    if(yC > yo)
                        alfa = 2 * M_PI - alfa;
                    if(T > 2 * M_PI)
                        if(alfa < T - 2* M_PI && alfa > 0)
                            alfa += 2 * M_PI;


                    double m = 0;
                    for(int k=0; k<=j; k++)
                    {
                        rrr = (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](k))) * (H/2*cos(teta.operator[](k))) + (W/2*sin(teta.operator[](k))) * (W/2*sin(teta.operator[](k))))) * pow(2.7,-1*teta.operator[](k)/15);
                        m += acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  );
                    }
                    teta.operator[](j) = T - m;

                    if(e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT && ((mode == 1 || mode == 3) || (mode == 2  && (ii < 80 || i > Rock))))
                    {
                        Mix_PlayChannel(-1,shelik_efect,0);
                        shelik = 1;
                        residan = 0;
                        R_shelik = (H/2 * W/2 / sqrt((H/2*cos(alfa)) * (H/2*cos(alfa)) + (W/2*sin(alfa)) * (W/2*sin(alfa)))) * pow(2.7,-1*alfa/15)- 20;
                        alfa_shelik = alfa;
                        e->type = 0;
                    }


                    if(residan == 1)
                    {
                        power_freeze = 0;
                        power_pause = 0;
                        power_backward = 0;

                        alfa = alfa_shelik;
                        double beta = alfa;
                        double aaalfa = abs(T - beta);
                        z = 0;
                        for(int k = 1; k<i; k++)
                            if(abs(beta - teta.operator[](k)) < aaalfa)
                            {
                                z = k;
                                aaalfa = abs(beta - teta.operator[](k));

                            }


                        if(rainbowball == 1)
                        {
                            int qq = 0;
                            r = red.operator[](z);
                            g = grean.operator[](z);
                            b = blue.operator[](z);
                            if(r != 0 || g != 0 || b != 0)
                                for(int k=0; k<i; k++)
                                    if(r == red.operator[](k - qq) && g == grean.operator[](k - qq) && b == blue.operator[](k - qq))
                                    {

                                        red.erase(red.begin() + k - qq);
                                        grean.erase(grean.begin() + k - qq);
                                        blue.erase(blue.begin() + k - qq);
                                        rrr = (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](k - qq))) * (H/2*cos(teta.operator[](k - qq))) + (W/2*sin(teta.operator[](k - qq))) * (W/2*sin(teta.operator[](k - qq))))) * pow(2.7,-1*teta.operator[](k - qq)/15);
                                        T -= acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  );
                                        teta.erase(teta.begin() + k - qq);
                                        power.erase(power.begin() + k - qq);
                                        qq++;

                                    }
                            rainbowball = 0;
                            i -= qq;
                            emtiaz += qq;
                        }

                        else if(bombball == 1 && z > 3)
                        {
                            double x = xo + (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](z))) * (H/2*cos(teta.operator[](z))) + (W/2*sin(teta.operator[](z))) * (W/2*sin(teta.operator[](z))))) * pow(2.7,-1*teta.operator[](z)/15)*cos(teta.operator[](z));
                            double y = yo - (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](z))) * (H/2*cos(teta.operator[](z))) + (W/2*sin(teta.operator[](z))) * (W/2*sin(teta.operator[](z))))) * pow(2.7,-1*teta.operator[](z)/15)*sin(teta.operator[](z));

                            img(x,y,200,200,e1_img);
                            SDL_RenderPresent( m_renderer );
                            SDL_Delay(100);
                            img(x,y,200,200,e2_img);
                            SDL_RenderPresent( m_renderer );
                            SDL_Delay(100);
                            img(x,y,200,200,e3_img);
                            SDL_RenderPresent( m_renderer );
                            SDL_Delay(100);
                            img(x,y,200,200,e4_img);
                            SDL_RenderPresent( m_renderer );
                            SDL_Delay(100);

                            if(mode == 2)
                                for(int k=z-4; k<z+4; k++)
                                    if(red.operator[](k) == 0 && grean.operator[](k) == 0 && blue.operator[](k) == 0)
                                        Rock--;
                            red.erase(red.begin() + z - 4,red.begin() + z + 4);
                            grean.erase(grean.begin() + z - 4, grean.begin() + z + 4);
                            blue.erase(blue.begin() + z - 4, blue.begin() + z + 4);
                            m = 0;
                            for(int k=z-4; k<z+4; k++)
                            {
                                rrr = (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](k))) * (H/2*cos(teta.operator[](k))) + (W/2*sin(teta.operator[](k))) * (W/2*sin(teta.operator[](k))))) * pow(2.7,-1*teta.operator[](k)/15);
                                m += acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  );
                            }
                            T -= m;
                            teta.erase(teta.begin() + z - 4, teta.begin() + z + 4);
                            power.erase(power.begin() + z - 4, power.begin() + z + 4);
                            bombball = 0;
                            i -= 8;
                            emtiaz += 64;
                        }

                        else if(meteoriteball == 1 && i > 0)
                        {
                            if(mode == 2)
                                for(int k=0; k<i; k++)
                                    if(red.operator[](k) == 0 && grean.operator[](k) == 0 && blue.operator[](k) == 0)
                                        Rock--;
                            red.erase(red.begin(),red.begin() + i);
                            grean.erase(grean.begin(), grean.begin() + i);
                            blue.erase(blue.begin(), blue.begin() + i);
                            m = 0;
                            for(int k=0; k<i; k++)
                            {
                                rrr = (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](k))) * (H/2*cos(teta.operator[](k))) + (W/2*sin(teta.operator[](k))) * (W/2*sin(teta.operator[](k))))) * pow(2.7,-1*teta.operator[](k)/15);
                                m += acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  );
                            }
                            T -= m;
                            teta.erase(teta.begin(), teta.begin() + i);
                            power.erase(power.begin(), power.begin() + i);
                            meteoriteball = 0;
                            emtiaz += i;
                            i = 0;
                        }

                        else if(fireball == 1)
                        {
                            if(power.operator[](z) == 1)
                                power_freeze = 1;
                            if(power.operator[](z) == 2)
                                power_pause = 1;
                            if(power.operator[](z) == 3)
                                power_backward = 1;

                            if(red.operator[](z) == 0 && grean.operator[](z) == 0 && blue.operator[](z) == 0)
                                Rock--;
                            red.erase(red.begin() + z);
                            grean.erase(grean.begin() + z);
                            blue.erase(blue.begin() + z);
                            rrr = (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](z))) * (H/2*cos(teta.operator[](z))) + (W/2*sin(teta.operator[](z))) * (W/2*sin(teta.operator[](z))))) * pow(2.7,-1*teta.operator[](z)/15);
                            T -= acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  );
                            teta.erase(teta.begin() + z);
                            power.erase(power.begin() + z);
                            emtiaz++;
                            i--;
                            fireball = 0;
                        }

                        else
                        {
                            if(beta < teta.operator[](z))
                                z++;

                            atrafr = 0;
                            atrafl = 0;

                            red.insert(red.begin() + z,r2[0]);
                            grean.insert(grean.begin() + z,g2[0]);
                            blue.insert(blue.begin() + z,b2[0]);
                            teta.insert(teta.begin() + z,alfa);
                            power.insert(power.begin() + z,0);
                            i++;
                            s++;
                            rrr = (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](z))) * (H/2*cos(teta.operator[](z))) + (W/2*sin(teta.operator[](z))) * (W/2*sin(teta.operator[](z))))) * pow(2.7,-1*teta.operator[](z)/15);
                            T += acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  );

                            if(i> 3)
                            {
                                while(red.operator[](z+atrafr) == r2[0] && grean.operator[](z+atrafr) == g2[0] && blue.operator[](z+atrafr) == b2[0] && red.size() > z + atrafr)
                                    atrafr++;

                                while(red.operator[](z-atrafl) == r2[0] && grean.operator[](z-atrafl) == g2[0] && blue.operator[](z-atrafl) == b2[0] && z - atrafl >= 0)
                                    atrafl++;

                                //atrafr--;
                                //atrafl--;
                            }
                            //cout << z << " l: " << atrafl << " r: " << atrafr <<endl;
                            if((atrafr + atrafl) > 3)
                            {
                                zarib = 0;
                                if(atrafl == 1)
                                {
                                    for(int q=0; q < atrafr; q++)
                                    {
                                        if(power.operator[](z) == 1)
                                            power_freeze = 1;
                                        if(power.operator[](z) == 2)
                                            power_pause = 1;
                                        if(power.operator[](z) == 3)
                                            power_backward = 1;
                                        red.erase(red.begin() + z);
                                        grean.erase(grean.begin() +z);
                                        blue.erase(blue.begin() + z);
                                        i--;
                                        rrr = (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](z))) * (H/2*cos(teta.operator[](z))) + (W/2*sin(teta.operator[](z))) * (W/2*sin(teta.operator[](z))))) * pow(2.7,-1*teta.operator[](z)/15);
                                        T -= acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  );
                                        teta.erase(teta.begin() + z);
                                        power.erase(power.begin() + z);
                                        zarib++;
                                    }
                                }

                                else if(atrafr == 1)
                                {
                                    for(int q=0; q < atrafl; q++)
                                    {
                                        if(power.operator[](z) == 1)
                                            power_freeze = 1;
                                        if(power.operator[](z) == 2)
                                            power_pause = 1;
                                        if(power.operator[](z) == 3)
                                            power_backward = 1;
                                        red.erase(red.begin() + z);
                                        grean.erase(grean.begin() + z);
                                        blue.erase(blue.begin() + z);
                                        i--;
                                        rrr = (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](z))) * (H/2*cos(teta.operator[](z))) + (W/2*sin(teta.operator[](z))) * (W/2*sin(teta.operator[](z))))) * pow(2.7,-1*teta.operator[](z)/15);
                                        T -= acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  );
                                        teta.erase(teta.begin() + z);
                                        power.erase(power.begin() + z);
                                        z--;
                                        zarib++;
                                    }
                                }
                                else
                                {
                                    if(power.operator[](z) == 1)
                                        power_freeze = 1;
                                    if(power.operator[](z) == 2)
                                        power_pause = 1;
                                    if(power.operator[](z) == 3)
                                        power_backward = 1;
                                    red.erase(red.begin() + z);
                                    grean.erase(grean.begin() +z);
                                    blue.erase(blue.begin() + z);
                                    i--;
                                    rrr = (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](j))) * (H/2*cos(teta.operator[](j))) + (W/2*sin(teta.operator[](j))) * (W/2*sin(teta.operator[](j))))) * pow(2.7,-1*teta.operator[](j)/15);
                                    T -= acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  );
                                    teta.erase(teta.begin() + z);
                                    power.erase(power.begin() + z);
                                    zarib++;
                                    for(int q=0; q < atrafr - 1; q++)
                                    {
                                        if(power.operator[](z) == 1)
                                            power_freeze = 1;
                                        if(power.operator[](z) == 2)
                                            power_pause = 1;
                                        if(power.operator[](z) == 3)
                                            power_backward = 1;
                                        red.erase(red.begin() + z);
                                        grean.erase(grean.begin() +z);
                                        blue.erase(blue.begin() + z);
                                        i--;
                                        rrr = (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](j))) * (H/2*cos(teta.operator[](j))) + (W/2*sin(teta.operator[](j))) * (W/2*sin(teta.operator[](j))))) * pow(2.7,-1*teta.operator[](j)/15);
                                        T -= acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  );
                                        teta.erase(teta.begin() + z);
                                        power.erase(power.begin() + z);
                                        zarib++;
                                    }
                                    for(int q=0; q < atrafl - 1; q++)
                                    {
                                        if(power.operator[](z - 1 - q) == 1)
                                            power_freeze = 1;
                                        if(power.operator[](z - 1 - q) == 2)
                                            power_pause = 1;
                                        if(power.operator[](z - 1 - q) == 3)
                                            power_backward = 1;
                                        red.erase(red.begin() + z - 1 - q);
                                        grean.erase(grean.begin() + z - 1 - q);
                                        blue.erase(blue.begin() + z - 1 - q);
                                        i--;
                                        rrr = (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](j))) * (H/2*cos(teta.operator[](j))) + (W/2*sin(teta.operator[](j))) * (W/2*sin(teta.operator[](j))))) * pow(2.7,-1*teta.operator[](j)/15);
                                        T -= acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  );
                                        teta.erase(teta.begin() + z - 1 - q);
                                        power.erase(power.begin() + z - 1 - q);
                                        zarib++;
                                    }
                                }

                                emtiaz += (zarib - 1) * (zarib - 1);

                            }

                            int hazer = red.size();


                            if(ii < 80)
                            {
                                r2[0] = r2[1];
                                g2[0] = g2[1];
                                b2[0] = b2[1];
                            }

                            bool rr = 0;
                            bool bb = 0;
                            bool zz = 0;
                            bool gg = 0;

                            for(int k=0; k<hazer; k++)
                            {
                                if(rr == 0)
                                    if(red.operator[](k) == 255 && grean.operator[](k) == 0)
                                        rr = 1;
                                if(zz == 0)
                                    if(red.operator[](k) == 255 && grean.operator[](k) == 255)
                                        zz = 1;
                                if(bb == 0)
                                    if(blue.operator[](k) == 255)
                                        bb = 1;
                                if(gg == 0)
                                    if(grean.operator[](k) == 255 && red.operator[](k) == 0)
                                        gg = 1;
                            }

                            srand(start + s);
                            if(rr == 1 && zz == 0 && bb == 0 && gg == 0)
                            {
                                r2[1]=255;
                                g2[1]=0;
                                b2[1]=0;
                            }
                            else if(rr == 0 && zz == 1 && bb == 0 && gg == 0)
                            {
                                r2[1]=255;
                                g2[1]=255;
                                b2[1]=0;
                            }
                            else if(rr == 0 && zz == 0 && bb == 1 && gg == 0)
                            {
                                r2[1]=0;
                                g2[1]=0;
                                b2[1]=255;
                            }
                            else if(rr == 0 && zz == 0 && bb == 0 && gg == 1)
                            {
                                r2[1]=0;
                                g2[1]=255;
                                b2[1]=0;
                            }
                            else if(rr == 1 && zz == 1 && bb == 0 && gg == 0)
                            {

                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 1 && zz == 0 && bb == 1 && gg == 0)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                            }
                            else if(rr == 1 && zz == 0 && bb == 0 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 0 && zz == 1 && bb == 1 && gg == 0)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                            }
                            else if(rr == 0 && zz == 1 && bb == 0 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 0 && zz == 0 && bb == 1 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 1 && zz == 1 && bb == 1 && gg == 0)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 3 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 1)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 2)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                            }
                            else if(rr == 1 && zz == 1 && bb == 0 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 3 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 1)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 2)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 0 && zz == 1 && bb == 1 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 3 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                                else if(r2[1] % 3 == 2)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 1 && zz == 0 && bb == 1 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 3 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                                else if(r2[1] % 3 == 2)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 4 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 4 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 4 == 2)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                                else if(r2[1] % 4 == 3)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }


                            if(ii == 80)
                            {

                                r2[0] = r2[1];
                                g2[0] = g2[1];
                                b2[0] = b2[1];
                            }

                        }

                        if(power_freeze == 1)
                        {
                            t1_efect = time(NULL);
                            freezeball = 1;
                            power_freeze = 0;
                        }
                        if(power_pause == 1)
                        {
                            t2_efect = time(NULL);
                            pauseball = 1;
                            power_pause = 0;
                        }
                        if(power_backward == 1)
                        {
                            t3_efect = time(NULL);
                            backwardball = 1;
                            power_backward = 0;
                        }
                        residan = 0;
                    }

                    if((ii == 80 && i == Rock && mode == 2 && ((i > 0 && T > 4*M_PI - .1) || (i == 0 && T < 4*M_PI - .1))) || (ii == 80 && i == Rock && (mode == 1 || mode == 3)))
                    {
                        emtiaz += 140 - (time(NULL) - start - pause);
                        toBeDrawn = 0;
                        map2 = 0;
                        SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
                        SDL_RenderClear(m_renderer);
                        img(640,200,1280,400,m30_img);
                        textRGBA2(m_renderer, W/2 - 190, H/2 - 100, "you win", 100, 0, 255, 0, 255);
                        textRGBA2(m_renderer, W/2 - 50, H/2 + 50, to_string(emtiaz).c_str(), 60, 0, 255, 255, 255);
                        SDL_RenderPresent(m_renderer);
                        string s;
                        string name[100];
                        bool check = 0;
                        ifstream f;
                        f.open("emtiaz.txt", ios_base::in);
                        int k = 0, khat;
                        while(!f.eof())
                        {
                            getline(f, s);
                            name[k] = s;
                            k++;
                            if (s.compare(login_uu) == 0)
                            {
                                while(s != "/...")
                                {
                                    getline(f, s);
                                    name[k] = s;
                                    k++;
                                }
                                check = 1;
                                khat = k;
                                break;
                            }
                        }
                        if(check == 1)
                        {
                            while(!f.eof())
                            {
                                getline(f, s);
                                name[k] = s;
                                k++;
                            }
                            f.close();
                            ofstream ff("emtiaz.txt",ios::out);
                            ff << name[0] << endl;
                            ff.close();
                            ofstream fff("emtiaz.txt",ios::app);
                            for(int i = 1; i < khat-1; i++)
                            {
                                fff << name[i] << endl;
                            }
                            fff << emtiaz << endl << "/...";
                            for(int i = khat; i < k; i++)
                            {
                                fff << endl << name[i];
                            }
                            fff.close();
                        }
                        else
                        {
                            ofstream fff("emtiaz.txt",ios::app);
                            fff << endl << login_uu << endl << emtiaz << endl << "/...";
                            fff.close();
                        }
                        SDL_Delay(4000);
                        break;

                    }

                    m = 0;
                    for(int k=0; k<=j; k++)
                    {
                        rrr = (H/2 * W/2 / sqrt((H/2*cos(teta.operator[](k))) * (H/2*cos(teta.operator[](k))) + (W/2*sin(teta.operator[](k))) * (W/2*sin(teta.operator[](k))))) * pow(2.7,-1*teta.operator[](k)/15);
                        m += acos(  (rrr*rrr + (rrr + drrr)*(rrr + drrr) - 1500)/(2*rrr*(rrr + drrr))  );
                    }
                    teta.operator[](j) = T - m;

                    filledEllipseRGBA(m_renderer,xo + R1*cos(teta.operator[](j)),yo - R2*sin(teta.operator[](j)),20,20,red.operator[](j),grean.operator[](j),blue.operator[](j),255);
                    if(power.operator[](j) == 1)
                        img(xo + R1*cos(teta.operator[](j)),yo - R2*sin(teta.operator[](j)),100,100,m20_img);
                    if(power.operator[](j) == 2)
                        img(xo + R1*cos(teta.operator[](j)),yo - R2*sin(teta.operator[](j)),30,30,m21_img);
                    if(power.operator[](j) == 3)
                        img(xo + R1*cos(teta.operator[](j)),yo - R2*sin(teta.operator[](j)),30,30,m22_img);


                }

                aalineRGBA(m_renderer,xo,H/2,xC,yC,255,255,255,255);
                if(ii < 80 || (ii == 80 && i > Rock))
                    filledEllipseRGBA(m_renderer,xE[0],yE[0],20,20,r2[0],g2[0],b2[0],255);

                if(rainbowball == 1)
                {
                    img(xE[0],yE[0],80,80,m24_img);
                }
                if(bombball == 1)
                {
                    img(xE[0],yE[0],80,80,m25_img);
                }
                if(meteoriteball == 1)
                {
                    img(xE[0],yE[0],80,80,m26_img);
                }
                if(fireball == 1)
                {
                    img(xE[0],yE[0],50,50,m23_img);
                }

                if(freezeball == 1)
                {
                    T -= .001;
                    t -= .001;
                    if(time(NULL) - t1_efect > 3)
                        freezeball = 0;
                }
                if(pauseball == 1)
                {
                    T -= .002;
                    t -= .002;
                    if(time(NULL) - t2_efect > 3)
                        pauseball = 0;
                }
                if(backwardball == 1)
                {
                    T -= .003;
                    t -= .003;
                    if(time(NULL) - t3_efect > 3)
                        backwardball = 0;
                }
                SDL_RenderCopyEx(m_renderer, m3_img, NULL, &img3_rect, -1 * (alfa * 180 / M_PI - 90), &img3_point, SDL_FLIP_NONE);

                if(ii < 80)
                    filledEllipseRGBA(m_renderer,xE[1],yE[1],10,10,r2[1],g2[1],b2[1],255);

                if(shelik == 1)
                {
                    residan = 0;
                    TT += 40;
                    xs = xo + (50+TT)*cos(alfa_shelik);
                    ys = yo - (50+TT)*sin(alfa_shelik);

                    if(rainbowball == 1)
                    {
                        img(xs,ys,80,80,m24_img);
                    }
                    else if(bombball == 1)
                    {
                        img(xs,ys,80,80,m25_img);
                    }
                    else if(meteoriteball == 1)
                    {
                        img(xs,ys,80,80,m26_img);
                    }
                    else if(fireball == 1)
                    {
                        img2(xs,ys,alfa_shelik,120,60,f_img);
                    }
                    else
                        filledEllipseRGBA(m_renderer,xs,ys,20,20,r2[0],g2[0],b2[0],255);

                    if((xs - xo) * (xs - xo) + (ys - yo) * (ys - yo) > R_shelik * R_shelik)
                    {
                        if(alfa_shelik < T + 0.26 && alfa_shelik > teta.operator[](i-1) - .26)
                        {
                            residan = 1;
                            shelik = 0;
                            TT = 0;
                        }
                        else
                        {
                            residan = 0;
                            shelik = 0;
                            TT = 0;
                        }
                    }

                }

                textRGBA2(m_renderer,100,50,to_string(emtiaz).c_str(),20,255,255,0,255);

                if(mode == 3)
                    textRGBA2(m_renderer,100,100,to_string(140 + pause - time(NULL) + start).c_str(),20,255,255,0,255);

                if(mode == 1 || mode == 2)
                    textRGBA2(m_renderer,100,100,to_string(time(NULL) - pause - start).c_str(),20,255,255,0,255);


                if(T > 4*M_PI - .1 && (mode == 1 || mode == 2) && i > Rock)
                {
                    toBeDrawn = 0;
                    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
                    SDL_RenderClear(m_renderer);
                    img(630,350,860,700,m31_img);
                    SDL_RenderPresent( m_renderer );
                    string s;
                    string name[100];
                    bool check = 0;
                    ifstream f;
                    f.open("emtiaz.txt", ios_base::in);
                    int k = 0, khat;
                    while(!f.eof())
                    {
                        getline(f, s);
                        name[k] = s;
                        k++;
                        if (s.compare(login_uu) == 0)
                        {
                            while(s != "/...")
                            {
                                getline(f, s);
                                name[k] = s;
                                k++;
                            }
                            check = 1;
                            khat = k;
                            break;
                        }
                    }
                    if(check == 1)
                    {
                        while(!f.eof())
                        {
                            getline(f, s);
                            name[k] = s;
                            k++;
                        }
                        f.close();
                        ofstream ff("emtiaz.txt",ios::out);
                        ff << name[0] << endl;
                        ff.close();
                        ofstream fff("emtiaz.txt",ios::app);
                        for(int i = 1; i < khat-1; i++)
                        {
                            fff << name[i] << endl;
                        }
                        fff << emtiaz << endl << "/...";
                        for(int i = khat; i < k; i++)
                        {
                            fff << endl << name[i];
                        }
                        fff.close();
                    }
                    else
                    {
                        ofstream fff("emtiaz.txt",ios::app);
                        fff << endl << login_uu << endl << emtiaz << endl << "/...";
                        fff.close();
                    }
                    SDL_Delay(4000);
                    map2 = 0;
                }

                else if((time(NULL) - start - pause > 140 || T > 4*M_PI - .1) && mode == 3)
                {
                    toBeDrawn = 0;
                    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
                    SDL_RenderClear(m_renderer);
                    img(630,350,860,700,m31_img);
                    SDL_RenderPresent( m_renderer );
                    string s;
                    string name[100];
                    bool check = 0;
                    ifstream f;
                    f.open("emtiaz.txt", ios_base::in);
                    int k = 0, khat;
                    while(!f.eof())
                    {
                        getline(f, s);
                        name[k] = s;
                        k++;
                        if (s.compare(login_uu) == 0)
                        {
                            while(s != "/...")
                            {
                                getline(f, s);
                                name[k] = s;
                                k++;
                            }
                            check = 1;
                            khat = k;
                            break;
                        }
                    }
                    if(check == 1)
                    {
                        while(!f.eof())
                        {
                            getline(f, s);
                            name[k] = s;
                            k++;
                        }
                        f.close();
                        ofstream ff("emtiaz.txt",ios::out);
                        ff << name[0] << endl;
                        ff.close();
                        ofstream fff("emtiaz.txt",ios::app);
                        for(int i = 1; i < khat-1; i++)
                        {
                            fff << name[i] << endl;
                        }
                        fff << emtiaz << endl << "/...";
                        for(int i = khat; i < k; i++)
                        {
                            fff << endl << name[i];
                        }
                        fff.close();
                    }
                    else
                    {
                        ofstream fff("emtiaz.txt",ios::app);
                        fff << endl << login_uu << endl << emtiaz << endl << "/...";
                        fff.close();
                    }
                    SDL_Delay(4000);
                    map2 = 0;
                }



                SDL_RenderPresent(m_renderer);
                SDL_Delay(0);
                T2 = SDL_GetPerformanceCounter();

            }

            while(map3)
            {
                SDL_PollEvent(e);


                SDL_ShowCursor(SDL_ENABLE);
                xC=e->button.x;
                yC=e->button.y;


                if(t > 0.2 && ii < 25)
                {
                    srand(start + i);
                    r = rand()%255;
                    if(r % 4 == 0)
                    {
                        r=255;
                        g=0;
                        b=0;
                    }
                    else if(r % 4 == 1)
                    {
                        r=0;
                        g=255;
                        b=0;
                    }
                    else if(r % 4 == 2)
                    {
                        r=0;
                        g=0;
                        b=255;
                    }
                    else if(r % 4 == 3)
                    {
                        r=255;
                        g=255;
                        b=0;
                    }

                    red.push_back(r);
                    grean.push_back(g);
                    blue.push_back(b);
                    teta.push_back(T);

                    t = 0;
                    i++;
                    ii++;
                }

                xE[0] = xo + 50*cos(alfa);
                yE[0] = yo - 50*sin(alfa);
                xE[1] = xo - 20*cos(alfa);
                yE[1] = yo + 20*sin(alfa);
                T += 0.005;
                t += 0.005;

                SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
                SDL_RenderClear(m_renderer);

                if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_SPACE)
                {
                    change_color = 1;
                    e->type = 0;
                }

                if(change_color == 1)
                {
                    r2[0] -= r2[1];
                    r2[1] += r2[0];
                    r2[0] = r2[1] - r2[0];
                    g2[0] -= g2[1];
                    g2[1] += g2[0];
                    g2[0] = g2[1] - g2[0];
                    b2[0] -= b2[1];
                    b2[1] += b2[0];
                    b2[0] = b2[1] - b2[0];
                    change_color = 0;
                }

                SDL_RenderCopy(m_renderer, m5_img, NULL, &img5_rect);
                for(int j =0; j<i; j++)
                {
                    R1 = 320;
                    R2 = 320;
                    R1 *=  pow(2.7,-1*teta.operator[](j)/15);
                    R2 *=  pow(2.7,-1*teta.operator[](j)/15);

                    alfa = acos((xC - xo)/sqrt((xC - xo)*(xC - xo) + (yC-yo)*(yC-yo)));

                    if(yC > yo)
                        alfa = 2 * M_PI - alfa;
                    if(T > 2 * M_PI)
                        if(alfa < T - 2* M_PI && alfa > 0)
                            alfa += 2 * M_PI;



                    double m = 0;
                    for(int k=0; k<j; k++)
                        m += 320/(320 * pow(2.7,-1*teta.operator[](k)/15))*0.13;
                    teta.operator[](j) = T - m;

                    if(e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
                    {
                        shelik = 1;
                        residan = 0;
                        R_shelik = R1;
                        alfa_shelik = alfa;
                        e->type = 0;
                    }


                    if(residan == 1)
                    {

                        alfa = alfa_shelik;
                        double beta = alfa;
                        double aaalfa = abs(T - beta);
                        z = 0;
                        for(int k = 1; k<i; k++)
                            if(abs(beta - teta.operator[](k)) < aaalfa)
                            {
                                z = k;
                                aaalfa = abs(beta - teta.operator[](k));

                            }

                        if(beta < teta.operator[](z))
                            z++;

                        atrafr = 0;
                        atrafl = 0;

                        red.insert(red.begin() + z,r2[0]);
                        grean.insert(grean.begin() + z,g2[0]);
                        blue.insert(blue.begin() + z,b2[0]);
                        teta.insert(teta.begin() + z,alfa);
                        i++;
                        s++;
                        T += 320/(320 * pow(2.7,-1*teta.operator[](j)/15))*0.13;

                        if(i> 3)
                        {
                            while(red.operator[](z+atrafr) == r2[0] && grean.operator[](z+atrafr) == g2[0] && blue.operator[](z+atrafr) == b2[0] && red.size() > z + atrafr)
                                atrafr++;

                            while(red.operator[](z-atrafl) == r2[0] && grean.operator[](z-atrafl) == g2[0] && blue.operator[](z-atrafl) == b2[0] && z - atrafl >= 0)
                                atrafl++;

                            //atrafr--;
                            //atrafl--;
                        }
                        //cout << z << " l: " << atrafl << " r: " << atrafr <<endl;
                        if((atrafr + atrafl) > 3)
                        {

                            if(atrafl == 1)
                            {
                                for(int q=0; q < atrafr; q++)
                                {
                                    red.erase(red.begin() + z);
                                    grean.erase(grean.begin() +z);
                                    blue.erase(blue.begin() + z);
                                    teta.erase(teta.begin() + z);
                                    i--;
                                    T -= 320/(320 * pow(2.7,-1*teta.operator[](j)/15))*0.13;
                                    emtiaz++;
                                }
                            }

                            else if(atrafr == 1)
                            {
                                for(int q=0; q < atrafl; q++)
                                {

                                    red.erase(red.begin() + z);
                                    grean.erase(grean.begin() + z);
                                    blue.erase(blue.begin() + z);
                                    teta.erase(teta.begin() + z);
                                    i--;
                                    T -= 320/(320 * pow(2.7,-1*teta.operator[](j)/15))*0.13;
                                    z--;
                                    emtiaz++;

                                }
                            }
                            else
                            {
                                red.erase(red.begin() + z);
                                grean.erase(grean.begin() +z);
                                blue.erase(blue.begin() + z);
                                teta.erase(teta.begin() + z);
                                i--;
                                T -= 320/(320 * pow(2.7,-1*teta.operator[](j)/15))*0.13;

                                for(int q=0; q < atrafr - 1; q++)
                                {
                                    red.erase(red.begin() + z);
                                    grean.erase(grean.begin() +z);
                                    blue.erase(blue.begin() + z);
                                    teta.erase(teta.begin() + z);
                                    i--;
                                    T -= 320/(320 * pow(2.7,-1*teta.operator[](j)/15))*0.13;
                                    emtiaz++;
                                }
                                for(int q=0; q < atrafl - 1; q++)
                                {
                                    red.erase(red.begin() + z - 1 - q);
                                    grean.erase(grean.begin() + z - 1 - q);
                                    blue.erase(blue.begin() + z - 1 - q);
                                    teta.erase(teta.begin() + z - 1 - q);
                                    i--;
                                    T -= 320/(320 * pow(2.7,-1*teta.operator[](j)/15))*0.13;
                                    emtiaz++;
                                }
                            }


                        }


                        if(i == 0)
                        {
                            toBeDrawn = 0;
                            map1 = 0;
                            SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
                            SDL_RenderClear(m_renderer);
                            textRGBA2(m_renderer, W/2 - 190, H/2 - 100, "you win", 100, 0, 255, 0, 255);
                            textRGBA2(m_renderer, W/2 - 50, H/2 + 50, to_string(emtiaz).c_str(), 60, 0, 255, 255, 255);
                            SDL_RenderPresent(m_renderer);
                            string s;
                            string name[100];
                            bool check = 0;
                            ifstream f;
                            f.open("emtiaz.txt", ios_base::in);
                            int k = 0, khat;
                            while(!f.eof())
                            {
                                getline(f, s);
                                name[k] = s;
                                k++;
                                if (s.compare(login_uu) == 0)
                                {
                                    check = 1;
                                    khat = k;
                                    break;
                                }
                            }
                            if(check == 1)
                            {
                                while(!f.eof())
                                {
                                    getline(f, s);
                                    name[k] = s;
                                    k++;
                                }
                                f.close();
                                ofstream ff("emtiaz.txt",ios::out);
                                ff << name[0] << endl;
                                ff.close();
                                ofstream fff("emtiaz.txt",ios::app);
                                for(int i = 1; i < khat; i++)
                                {
                                    fff << name[i] << endl;
                                }
                                fff << name[khat] << "\t";
                                fff << emtiaz << endl;
                                for(int i = khat + 1; i < k; i++)
                                {
                                    fff << name[i] << endl;
                                }
                                fff.close();
                            }
                            else
                            {
                                ofstream fff("emtiaz.txt",ios::app);
                                fff << login_uu << endl << emtiaz << endl;
                            }
                            SDL_Delay(4000);

                        }
                        int hazer = red.size();
                        if(ii == 20)
                        {
                            bool rr = 0;
                            bool bb = 0;
                            bool zz = 0;
                            bool gg = 0;

                            for(int k=0; k<hazer; k++)
                            {
                                if(rr == 0)
                                    if(red.operator[](k) == 255 && grean.operator[](k) == 0)
                                        rr = 1;
                                if(zz == 0)
                                    if(red.operator[](k) == 255 && grean.operator[](k) == 255)
                                        zz = 1;
                                if(bb == 0)
                                    if(blue.operator[](k) == 255)
                                        bb = 1;
                                if(gg == 0)
                                    if(grean.operator[](k) == 255 && red.operator[](k) == 0)
                                        gg = 1;
                            }

                            srand(start + s);
                            if(rr == 1 && zz == 0 && bb == 0 && gg == 0)
                            {
                                r2[1]=255;
                                g2[1]=0;
                                b2[1]=0;
                            }
                            else if(rr == 0 && zz == 1 && bb == 0 && gg == 0)
                            {
                                r2[1]=255;
                                g2[1]=255;
                                b2[1]=0;
                            }
                            else if(rr == 0 && zz == 0 && bb == 1 && gg == 0)
                            {
                                r2[1]=0;
                                g2[1]=0;
                                b2[1]=255;
                            }
                            else if(rr == 0 && zz == 0 && bb == 0 && gg == 1)
                            {
                                r2[1]=0;
                                g2[1]=255;
                                b2[1]=0;
                            }
                            else if(rr == 1 && zz == 1 && bb == 0 && gg == 0)
                            {

                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 1 && zz == 0 && bb == 1 && gg == 0)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                            }
                            else if(rr == 1 && zz == 0 && bb == 0 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 0 && zz == 1 && bb == 1 && gg == 0)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                            }
                            else if(rr == 0 && zz == 1 && bb == 0 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 0 && zz == 0 && bb == 1 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 2 == 0)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                                else if(r2[1] % 2 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 1 && zz == 1 && bb == 1 && gg == 0)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 3 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 1)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 2)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                            }
                            else if(rr == 1 && zz == 1 && bb == 0 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 3 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 1)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 2)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 0 && zz == 1 && bb == 1 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 3 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                                else if(r2[1] % 3 == 2)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else if(rr == 1 && zz == 0 && bb == 1 && gg == 1)
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 3 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 3 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                                else if(r2[1] % 3 == 2)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            else
                            {
                                r2[1] = rand()%255;
                                if(r2[1] % 4 == 0)
                                {
                                    r2[1]=255;
                                    g2[1]=0;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 4 == 1)
                                {
                                    r2[1]=0;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                                else if(r2[1] % 4 == 2)
                                {
                                    r2[1]=0;
                                    g2[1]=0;
                                    b2[1]=255;
                                }
                                else if(r2[1] % 4 == 3)
                                {
                                    r2[1]=255;
                                    g2[1]=255;
                                    b2[1]=0;
                                }
                            }
                            r2[0] = r2[1];
                            g2[0] = g2[1];
                            b2[0] = b2[1];
                        }

                        else
                        {
                            r2[0] = r2[1];
                            g2[0] = g2[1];
                            b2[0] = b2[1];
                            srand(start + s);
                            r2[1] = rand()%255;
                            if(r2[1] % 4 == 0)
                            {
                                r2[1]=255;
                                g2[1]=0;
                                b2[1]=0;
                            }
                            else if(r2[1] % 4 == 1)
                            {
                                r2[1]=0;
                                g2[1]=255;
                                b2[1]=0;
                            }
                            else if(r2[1] % 4 == 2)
                            {
                                r2[1]=0;
                                g2[1]=0;
                                b2[1]=255;
                            }
                            else if(r2[1] % 4 == 3)
                            {
                                r2[1]=255;
                                g2[1]=255;
                                b2[1]=0;
                            }
                        }

                        residan = 0;
                    }

                    m = 0;
                    if(teta.operator[](j) > M_PI - .5)
                        m -= .5;

                    for(int k=0; k<j; k++)
                        m += 320/(320 * pow(2.7,-1*teta.operator[](k)/15))*0.13;
                    teta.operator[](j) = T - m;

                    filledEllipseRGBA(m_renderer,xo + 200*pow(sin(teta.operator[](j)),3),yo - 12.5*(13*cos(teta.operator[](j)) -5*cos(2*teta.operator[](j)) -2*cos(3*teta.operator[](j)) -1*cos(4*teta.operator[](j))),20,20,red.operator[](j),grean.operator[](j),blue.operator[](j),255);


                }

                aalineRGBA(m_renderer,xo,H/2,xC,yC,255,255,255,255);
                filledEllipseRGBA(m_renderer,xE[0],yE[0],20,20,r2[0],g2[0],b2[0],255);
                SDL_RenderCopyEx(m_renderer, m3_img, NULL, &img3_rect, -1 * (alfa * 180 / M_PI - 90), &img3_point, SDL_FLIP_NONE);

                if(ii < 20)
                    filledEllipseRGBA(m_renderer,xE[1],yE[1],10,10,r2[1],g2[1],b2[1],255);

                if(shelik == 1)
                {
                    residan = 0;
                    TT += 20;
                    xs = xo + (50+TT)*cos(alfa_shelik);
                    ys = yo - (50+TT)*sin(alfa_shelik);
                    filledEllipseRGBA(m_renderer,xs,ys,20,20,r2[0],g2[0],b2[0],255);
                    if((xs - xo) * (xs - xo) + (ys - yo) * (ys - yo) > R_shelik * R_shelik)
                    {
                        residan = 1;
                        shelik = 0;
                        TT = 0;
                    }

                }

                textRGBA2(m_renderer,100,50,to_string(emtiaz).c_str(),20,255,255,0,255);
                textRGBA2(m_renderer,100,100,to_string(time(NULL) - start).c_str(),20,255,255,0,255);

                //textRGBA2(m_renderer, 100,100,to_string(260/(260 + (1.2 * i))*0.16).c_str(),40,255,0,0,255);
                if(T > 4*M_PI - .1)
                {
                    toBeDrawn = 0;
                    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
                    SDL_RenderClear(m_renderer);
                    stringRGBA(m_renderer, W/2, H/2, "Failed", 255, 0, 0, 255);
                    SDL_RenderPresent( m_renderer );
                    SDL_Delay(4000);
                    map1 = 0;
                }

                SDL_RenderPresent(m_renderer);
                SDL_Delay(0);
            }

        }

        e->type = 0;
    }
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent( m_renderer );
    //Wait for a key to be pressed
    while(e->type != SDL_KEYDOWN)
        SDL_PollEvent(e);

    //Finalize and free resources
    SDL_DestroyTexture(m_img);
    SDL_DestroyTexture(m2_img2);
    SDL_DestroyTexture(m3_img);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    IMG_Quit();
    SDL_Quit();
    kill();
    return 0;

}


void textRGBA2(SDL_Renderer*m_renderer, int x, int y, const char* text,int f_size,int r, int g, int b, int a)
{
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("arial.ttf", f_size);
    int textWidth, textHeight;
    TTF_SizeText(font, text, &textWidth, &textHeight);

    SDL_Rect rectText{x, y, 0, 0};
    SDL_Color color{r,g,b,a};

    SDL_Surface *textSur = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *textTex = SDL_CreateTextureFromSurface(m_renderer, textSur);
    SDL_FreeSurface(textSur);
    SDL_QueryTexture(textTex, nullptr, nullptr, &rectText.w, &rectText.h);
    SDL_RenderCopy(m_renderer, textTex, nullptr, &rectText);
    SDL_DestroyTexture(textTex);
    TTF_CloseFont(font);
}

bool loop(string &input)
{

    static const unsigned char* keys = SDL_GetKeyboardState( NULL );

    SDL_Rect dest, dest2;

    // Clear the window to white
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear(m_renderer );

    // Event loop
    while ( SDL_PollEvent(e) != 0 && (signin == 1 || login == 1))
    {
        switch (e->type)
        {
        case SDL_QUIT:
            return false;
        case SDL_TEXTINPUT:
            input += e->text.text;
            break;
        case SDL_KEYDOWN:
            if (e->key.keysym.sym == SDLK_BACKSPACE && input.size())
            {
                input.pop_back();
            }
            break;
        }
    }

    // Render texture
    SDL_RenderCopy(m_renderer, m4_img, NULL, &img4_rect);

    SDL_Color foreground = { 255, 255, 255 };

    if (input1.size() || input2.size())
    {

        if(input1.size())
        {
            SDL_Surface* text_surf = TTF_RenderText_Solid(font, input1.c_str(), foreground);
            text = SDL_CreateTextureFromSurface(m_renderer, text_surf);
            dest.x = 620;
            dest.y = 330;
            dest.w = text_surf->w;
            dest.h = text_surf->h;
            SDL_RenderCopy(m_renderer, text, NULL, &dest);
            SDL_DestroyTexture(text);
            SDL_FreeSurface(text_surf);
        }

        if(input2.size())
        {
            SDL_Surface* text_surf2 = TTF_RenderText_Solid(font, input2.c_str(), foreground);
            text2 = SDL_CreateTextureFromSurface(m_renderer, text_surf2);
            dest2.x = 620;
            dest2.y = 430;
            dest2.w = text_surf2->w;
            dest2.h = text_surf2->h;
            SDL_RenderCopy(m_renderer, text2, NULL, &dest2);
            SDL_DestroyTexture(text2);
            SDL_FreeSurface(text_surf2);
        }

    }

    // Update window
    SDL_RenderPresent( m_renderer );

    return true;
}

bool init()
{
    SDL_Init( SDL_INIT_EVERYTHING );
    IMG_Init(IMG_INIT_JPG);

    TTF_Init();

    font = TTF_OpenFont("arial.ttf", 40);

    SDL_StartTextInput();

    return true;
}

void kill()
{
    SDL_StopTextInput();

    TTF_CloseFont( font );
    SDL_DestroyTexture( texture );
    texture = NULL;

    SDL_DestroyRenderer( m_renderer );
    SDL_DestroyWindow( m_window );
    m_window = NULL;
    m_renderer = NULL;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void bozorg(int a[], int b[])
{
    int n = 100;
    for(int i=n-1; i>0; i--)
        for(int j=0; j<i; j++)
            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
                swap(b[j],b[j+1]);
            }

}

void img(int x, int y,int w, int h, SDL_Texture* m_img)
{
    SDL_Rect img_rect;
    int img_w, img_h;
    SDL_QueryTexture(m6_img, NULL, NULL, &img_w, &img_h);
    img_rect.x = x - w/2;
    img_rect.y = y - h/2;
    img_rect.w = w;
    img_rect.h = h;
    SDL_RenderCopy(m_renderer, m_img, NULL, &img_rect);

}

void img2(int x, int y, double alfa, int w, int h, SDL_Texture* m_img)
{
    SDL_Rect img_rect;
    SDL_Point img_point;
    img_point.x = 0;
    img_point.y = h/2;
    int img_w, img_h;
    SDL_QueryTexture(m6_img, NULL, NULL, &img_w, &img_h);
    img_rect.x = x;
    img_rect.y = y - h/2;
    img_rect.w = w;
    img_rect.h = h;
    SDL_RenderCopyEx(m_renderer, m_img, NULL, &img_rect, -1 * (alfa * 180 / M_PI), &img_point, SDL_FLIP_NONE);
}
