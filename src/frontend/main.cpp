#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include "../backend/libGame/game/game.hpp" //include game.hpp
#include "ftxui/dom/canvas.hpp"  // for Canvas
#include "ftxui/dom/node.hpp"    // for Render
#include "ftxui/screen/color.hpp"  // for Color, Color::Red, Color::Blue, Color::Green, ftxui
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/component_options.hpp"   // for ButtonOption
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive

int main(){
    //tentar novamente nao funciona
    //armas no stage (explicar)
    //status das weapons //rings!!!
    //
    using namespace ftxui;

    Game* g = new Game("Hero");
    Sword* weapon_monster = new Sword(3, 5, "Basic Sword");
    int hptot = (int)g->get_hero()->getLife();
    int hpetot = (int)g->get_stage()->get_enemy()->getLife();
    int vivo = 1;
    bool sair = 0;
    int entrou = 0;
    int sizeEnemy = 35;
    //sai do stage 0 pro 1 mudando arma do heroi
    g->get_stage()->update_level(g->get_hero());
    std::string nome = ""; //ajuda com nome
    std::string tp;
    std::string tp2;
    auto screen = ScreenInteractive::Fullscreen();
    for(int i = 0; i < 50; i++) std::cout << "\n";


/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Tela Inicial

    Component input_nome = Input(&nome, "nome"); //ajuda em como settar nome do heroi
    Component butao = Button("comecar", [&] { screen.ExitLoopClosure()(); }, ButtonOption::Animated(Color::Blue));
    auto botao = Container::Vertical({
            input_nome,
            butao,
    });


    auto telaInicial = Renderer(botao, [&] {
        return vbox({
            vbox({

            text("\n"),           
            text("███████╗██╗     ██╗██████╗ ███████╗███████╗    ██╗   ██╗███████╗        ██████╗██╗██████╗  ██████╗██╗   ██╗██╗      ██████╗ ███████╗"),
            text("██╔════╝██║     ██║██╔══██╗██╔════╝██╔════╝    ██║   ██║██╔════╝       ██╔════╝██║██╔══██╗██╔════╝██║   ██║██║     ██╔═══██╗██╔════╝"),
            text("█████╗  ██║     ██║██████╔╝███████╗█████╗      ██║   ██║███████╗       ██║     ██║██████╔╝██║     ██║   ██║██║     ██║   ██║███████╗"),
            text("██╔══╝  ██║     ██║██╔═══╝ ╚════██║██╔══╝      ╚██╗ ██╔╝╚════██║       ██║     ██║██╔══██╗██║     ██║   ██║██║     ██║   ██║╚════██║"),
            text("███████╗███████╗██║██║     ███████║███████╗     ╚████╔╝ ███████║██╗    ╚██████╗██║██║  ██║╚██████╗╚██████╔╝███████╗╚██████╔╝███████║"),
            text("╚══════╝╚══════╝╚═╝╚═╝     ╚══════╝╚══════╝      ╚═══╝  ╚══════╝╚═╝     ╚═════╝╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚══════╝  ")
            }) | center,
            filler(),
            hbox({
                filler(),
                vbox({
                    hbox({
                        text("Digite seu nome:  "),
                        input_nome->Render() | flex | center
                    }),
                    filler(),
                    butao->Render() | flex | center,
                    filler(),
                })| border,
                filler(),
                }),
                filler(),
            });
        });


    
/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Tela gameplay
    
    auto cenario = Canvas(500, 100);  
    cenario.DrawBlockEllipseFilled(55, 50, 50,30, Color::Blue);
    cenario.DrawBlockCircleFilled(250, 50, sizeEnemy, Color::Red);

    Component ataque = Button("Ataque", [&] {g->get_hero()->attack(g->get_stage()->get_enemy(), g->get_hero()->getWeapon()); g->get_stage()->get_enemy()->attack(g->get_hero(), weapon_monster);}, ButtonOption::Animated(Color::Green3));
    Component quit = Button("Sair", [&]  {sair=1; screen.ExitLoopClosure()();}, ButtonOption::Animated(Color::Red3));
    Component test = Button("test", [&]  {}, ButtonOption::Animated(Color::Red));

    auto gameplay = Container::Horizontal({        ataque,
        test,
        quit
    });

    auto renderer = Renderer(gameplay, [&] {
        return vbox({
            hbox({
                vbox({
                    text("Estágio") | center,
                    text(std::to_string(g->get_stage()->get_level())) | center | bold
                })| border ,
                vbox({
                    text(" ______ _ _                                 _____  _               _           "),
                    text("|  ____| (_)                               / ____ /_/             | |          "),
                    text("| |__  | |_ _ __  ___  ___  __   _____    | |     _ _ __ ___ _   _| | ___  ___ "),
                    text("|  __| | | | '_ \\/ __|/ _ \\ \\ \\ / / __|   | |    | | '__/ __| | | | |/ _ \\/ __|"),
                    text("| |____| | | |_) \\__ \\  __/  \\ V /\\__ \\_  | |____| | | | (__| |_| | | (_) \\__ \\"),
                    text("|______|_|_| .__/|___/\\___|   \\_/ |___(_)  \\_____|_|_|  \\___|\\__,_|_|\\___/|___/"),
                    text("           |_|                                                                 "),
                }) | center| flex,
                //filler() | flex,
                quit->Render() | border
            }),
            filler(),
            hbox({
                canvas(&cenario) | border
            }),
            filler(),
            hbox({
                vbox({text(nome)| center | bold, //colocar getName
                hbox({
                    text(std::to_string((int)g->get_hero()->getLife())),
                    text("/"),
                    text(std::to_string(hptot))
                }) | center, 
                gauge((int)g->get_hero()->getLife()* 0.01f)| border})|flex,
                ataque->Render(),
                filler(),
                test->Render(),
                vbox({
                    text(g->get_stage()->get_enemy()->getName()) | center | bold, 
                    hbox({text(std::to_string((int)g->get_stage()->get_enemy()->getLife())),
                    text("/"),
                    text(std::to_string(hpetot))}) | center,
                    gauge((int)g->get_stage()->get_enemy()->getLife() * 0.1)| border
                })|flex
            })
        }) | border;
    });

    auto component = CatchEvent(renderer, [&](Event event){
            if((int)g->get_hero()->getLife() <= 0){
                screen.ExitLoopClosure()();
                vivo = 0;
                return true;
            }
            if(g->get_stage()->get_enemy()->getLife()<= 0){
                screen.ExitLoopClosure()();
                return true;
            }
            return false;
        });
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Tela matarMonstro
    Component botaoAceitar = Button("Continuar", [&] {
        sizeEnemy+=1;
        cenario.DrawBlockCircleFilled(250, 50, sizeEnemy, Color::Red);
        screen.ExitLoopClosure()();
        //att stage
        g->get_stage()->update_level(g->get_hero());
        //healing nao funciona
        //g->get_hero()->healing(g->get_hero());
        }, 
        ButtonOption::Animated(Color::Green));
    auto aceitar = Container::Vertical({
        botaoAceitar,   
    });

    auto telaMata = Renderer(aceitar, [&] {
        return vbox({
                filler(),
                hbox({
                    filler(),
                    vbox({
                        filler(),
                        text("Voce ganhou: "),
                        aceitar->Render(),
                        filler(),
                    }),
                    filler(),
                }),
                filler(),
        });
    });
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Tela morte
    Component quit1 = Button("Sair", [&]  {sair=1; screen.ExitLoopClosure()(); }, ButtonOption::Animated(Color::Red3));
    Component botaoMorte = Button("Tentar Novamente", [&] {
            //cria novo jogo
            g->~Game();
            Game* g = new Game("Hero");
            //g->get_hero()->setWeapon(weapon_hero);
            hptot = g->get_hero()->getLife();
            sair = 0;
            vivo = 1;
            screen.ExitLoopClosure()();
            }, 
    ButtonOption::Animated(Color::Green));

    auto bMorte = Container::Vertical({
        botaoMorte,
        quit1
    });


    auto telaMorte = Renderer(bMorte, [&] {
        return vbox({
                filler(),
                hbox({
                    filler(),
                    vbox({
                        filler(),
                        text("GAME OVER") | center,
                        hbox({
                            text("VOCÊ SOBREVIVEU "),
                            text(std::to_string(g->get_stage()->get_level())),
                            text(" ESTÁGIO(S)")
                        }),
                        hbox({
                            botaoMorte->Render(),
                            filler(),
                            quit1->Render(),
                        }),
                    }),
                    filler(),
                }),
            filler(),
        });
    });

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Loop

    screen.Loop(telaInicial);
    for(int i = 0; i < 50; i++) std::cout << "\n";

    while(!sair){
        screen.Loop(component);
        if(vivo && !sair){
            screen.Loop(telaMata);
        }
        else if(!vivo)  {
            screen.Loop(telaMorte);
        }
    }

    for(int i = 0; i < 50; i++) std::cout << "\n";
 

/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    return 0;
}
