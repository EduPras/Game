#include<iostream>
#include<string>
#include<memory>
#include<ftxui/dom/elements.hpp>
#include<ftxui/screen/screen.hpp>
#include<ftxui/component/component.hpp>

#include "ftxui/dom/canvas.hpp"  // for Canvas
#include "ftxui/dom/node.hpp"    // for Render
#include "ftxui/screen/color.hpp"  // for Color, Color::Red, Color::Blue, Color::Green, ftxui
                                   //
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/component_options.hpp"   // for ButtonOption
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive

#include "../backend/libGame/item/items.hpp"
#include "../backend/libGame/item/item.hpp"
#include "../backend/libGame/character/characters.hpp"
#include "../backend/libGame/stage/stage.hpp"
#include "../backend/libGame/game/game.hpp"

vector<Item*> Item::all_items_ = {};

vector<Item*> create_items(){
  vector<Item*> items = {
    new Sword(10, 0.9, "Ice"),
    new Sword(108, 0.8, "Leaf"),
    new Rod(10, 0.9, "Fireblood"),
    new Shadow(10, 7, "Ring of power"),
    new Rod(10, 0.7, "Colossus"),
    new Rock(10, 97, "Ring of defense")
  };
  system("clear");
  return items;
}


int main(){

    using namespace ftxui;
    Game *g;
    int entrou = 0;
    int hp = 100;
    int hptot = 100;
    int hpe = 10;
    int dano = 1;
    int vivo = 1;
    std::string nome = "";
    std::string vida = std::to_string(hp) + "/" + std::to_string(hptot);

    auto screen = ScreenInteractive::FitComponent();
    auto screen1 = ScreenInteractive::Fullscreen();
    for(int i = 0; i < 50; i++)
            std::cout << "\n";


/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Tela Inicial
    Component input_nome = Input(&nome, "nome");
    Component butao = Button("comecar", [&] { screen1.ExitLoopClosure()(); }, ButtonOption::Animated(Color::Blue));
    auto botao = Container::Vertical({
            input_nome,
            butao,
    });

    auto telaInicial = Renderer(botao, [&] {
        return vbox({
                hbox({
                    filler(),
                }),
                filler(),
                hbox({
                        filler(),
                        vbox({
                        filler(),
                        input_nome->Render() | flex,
                        butao->Render() | flex,
                        filler(),
                        }),
                        filler(),
                    }),
                filler(),
                hbox({
                        filler(),
                })
        });
        });

        screen1.Loop(telaInicial);
        for(int i = 0; i < 50; i++)
            std::cout << "\n";
    g = new Game(nome);
/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Tela matarMonstro
Component botaoAceitar = Button("Continuar", [&] {screen1.ExitLoopClosure()();}, ButtonOption::Animated(Color::Green));
auto aceitar = Container::Vertical({
    botaoAceitar,
});

auto telaMata = Renderer(aceitar, [&] {
    return vbox({
        hbox({
            filler(),
        }),
            filler(),
            hbox({
                filler(),
                vbox({
                    filler(),
                    text("Voce ganhou: item (+10ad)"),
                    aceitar->Render(),
                    filler(),
                }),
                filler(),
            }),
            filler(),
            hbox({
                filler(),
            })
    });
});


/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 
    
    auto cenario = Canvas(500, 100);  
    cenario.DrawBlockCircleFilled(55, 50, 35, Color::Blue);
    cenario.DrawBlockCircleFilled(305, 50, 35, Color::Red);
    Component ataque = Button("Ataque", [&] {hpe-=dano;}, ButtonOption::Animated(Color::Red));
    Component quit = Button("Sair", [&]  {vivo = 0; screen1.ExitLoopClosure()(); }, ButtonOption::Animated(Color::Red));
    Component test = Button("test", [&]  {hp-=10; vida = std::to_string(hp) + "/" + std::to_string(hptot);}, ButtonOption::Animated(Color::Red));
    

    auto gameplay = Container::Horizontal({
        ataque,
        test,
        quit
    });

    auto renderer = Renderer(gameplay, [&] {
            return vbox({
                hbox({
                    text("Estagio 1") | border
                }),
                filler(),
                hbox({
                    canvas(&cenario) | border
                }),
                filler(),
                hbox({
                    vbox({text(nome)| center, hbox({text(vida)})|center, gauge(hp * 0.01f)| border})|flex,
                    ataque->Render(),
                    filler(),
                    test->Render(),
                    vbox({
                    vbox({text("Dano")}),
                    filler(),
                    vbox({text("Magia")}),
                    filler(),
                    }),
                    quit->Render(),
                    vbox({text("Inimigo"), gauge(hpe * 0.1)| border})|flex
                })
            }) | border;


    });

    auto component = CatchEvent(renderer, [&](Event event){
            if(hp <= 0){
                screen1.ExitLoopClosure()();
                vivo = 0;
                return true;
            }
            if(hpe <= 0){
                hpe = 10;
                screen1.ExitLoopClosure()();
                return true;
            }
            return false;
        });


    while(vivo){
        screen1.Loop(component);
        if(vivo)
        screen1.Loop(telaMata);
    }
    for(int i = 0; i < 50; i++)
            std::cout << "\n";
 

/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    

    return 0;
}
