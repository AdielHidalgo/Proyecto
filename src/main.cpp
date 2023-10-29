#include <Ventana.hpp>
#include <Dibujo.hpp>
#include <curses.h>
#include <unistd.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // cout<<"Press 'd' to --> ,  Press 'a' to <-- , Press 'q' to quit "<<endl;
    // Tamaño de pagina recomendado 33%
    Ventana v;

    Dibujo d1(1, 15, "campo");
    Dibujo d2(1, 5, "mario");
    Dibujo d3(55,15, "campo2");
    bool ejecucion = true;
    while (ejecucion)
    {
        // ciclo de actualización
        v.Actualizar();
        if (getch() == 'q')
        {
            ejecucion = false;
        }
        if (getch() == 'd')
        {
            d2.AvanzarX(4);
        }
        if (getch() == 'a')
        {
            d2.RetrocederX(4);
        }
        if (getch() == 's')
        {
            d2.BajarY(3);
        }
        if (getch() == 'w')
        {
            d2.SubirY(3);
        }
        // ciclo de dibujo
        clear();
        // v.Dibujar();
        d1.Dibujar();
        d2.Dibujar();
        d3.Dibujar();
        refresh();
        usleep(41000);
    }

    return 0;
}