#include <iostream>
#include <QImage>
#include <fstream>
#include <iostream>

using namespace std;

void escribir(string nombre, int red, int blue, int green);

int main()
{
    string filename="../parcial02/images/pru3.jpg";
    QImage img( filename.c_str());
    
    unsigned int imgX = img.height(); //Tamaños de la imagen original
    unsigned int imgY = img.height();

    unsigned int img2X = 8; //tamaños de la imagen a crear
    unsigned int img2Y = 8;

    cout<<"Las dimensiones de la imagen son: "<<imgX<<" X "<<imgY<<endl;

    //nuevas dimensiondes de la imagen original:
    unsigned int new_sizeimgX=0;
    unsigned int new_sizeimgY=0;

    //hacer que las dimensiones de img sean multiplos de img2
    while (true){
        if (imgX%img2X==0){
            new_sizeimgX = imgX;//nuevo ancho de img
            break;
        }
        else{
            imgX--;
        }
    }
    while (true){
        if (imgY%img2Y==0){
            new_sizeimgY = imgY;//nuevo alto de img
            break;
        }
        else
            imgY--;
    }

    cout<<"Las nuevas dimensiones de la imagen son: "<<new_sizeimgX<<" X "<<new_sizeimgY<<endl;


    //dimensiones de prueba (Xn, Yn)
    int Xn = new_sizeimgX;
    int Yn = new_sizeimgY;


    cout<<endl<<endl;

    /*
    "heigth" hace referencia a la cantidad de pixeles de un paquete en Y, similarmente con "whith"
   */
    unsigned int b=0, heigth=new_sizeimgY/img2Y, whith =new_sizeimgX/img2X,copheigth=0, copwhith =0;
    int a=whith,c=0, d = heigth,red=0,blue=0,green=0,h=0;

    string nombre_arch = "colores";

    int Xn2 = Xn/whith;//cantidad de paquetes en x
    int Yn2 = Yn/heigth;//cantidad de paquetes en y

    for (int y = 0; y<Yn2 ; ++y){
        for(int x = 0; x<Xn2 ; ++x){

            while(copheigth<heigth){

                while(copwhith<whith+c){
                    cout<<" "<<"["<<copwhith<<"]"<<"["<<copheigth<<"]";
                    //adquiero los colores
                    red+=img.pixelColor(copwhith,copheigth).red();
                    blue+=img.pixelColor(copwhith,copheigth).blue();
                    green+=img.pixelColor(copwhith,copheigth).green();
                    h++;

                    copwhith++;
                    b++;

                }


                copheigth++;
                copwhith=b-a;
            }
            //ponderando los valores de los colores
            red=red/h;
            blue=blue/h;
            green=green/h;
            escribir(nombre_arch, red, blue, green);

            red=0,blue=0,green=0,h=0;//reiniciando los valores para el siguiente paquete

            cout<<endl;
            copheigth-=d;
            b-=2;
            c+=whith;


        }

        copheigth= heigth;
        heigth+=d;
        copwhith=0;
        b=0;
        c=0;


        cout<<endl<<endl;

    }



    return 0;
}

void escribir(string nombre,int red, int blue, int green){
    ofstream archivo_w;

    archivo_w.open(nombre, ios::out | ios::app);

    if (archivo_w.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        exit(1);
    }
    archivo_w<<"(";
    archivo_w<<red;
    archivo_w<<",";
    archivo_w<<blue;
    archivo_w<<",";
    archivo_w<<green;
    archivo_w<<")";
    archivo_w<<"\n";

    archivo_w.close();

}
