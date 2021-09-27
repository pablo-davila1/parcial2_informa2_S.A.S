#include <iostream>
#include <QImage>

using namespace std;

int main()
{
    string filename="../parcial02/images/pru3.jpg";
    QImage img( filename.c_str());

    unsigned int pixelX = 515;
    unsigned int pixelY = 680;
    
    unsigned int imgX = img.height(); //Tamaños de la imagen original
    unsigned int imgY = img.height();

    unsigned int img2X = 12 ; //tamaños de la imagen a crear
    unsigned int img2Y = 12;

//    cout<<"intensidad del rojo del pixel: "<< img.pixelColor(pixelX,pixelY).red()<<endl;
//    cout<<"intensidad del rojo del pixel: "<< img.pixelColor(pixelX,pixelY).blue()<<endl;
//    cout<<"intensidad del rojo del pixel: "<< img.pixelColor(pixelX,pixelY).green()<<endl;

    cout<<"Las dimensiones de la imagen son: "<<imgX<<" X "<<imgY<<endl;

    //nuevas dimensiondes de la imagen original:
    //hacer que las dimensiones de img sean multiplos de img2
    unsigned int new_sizeimgX=0;
    unsigned int new_sizeimgY=0;

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

    for (int y = 0; y<new_sizeimgX-3090 ; ++y){
        for(int x = 0; x<new_sizeimgY-3090 ; ++x){
            cout<<" "<<"["<<x<<"]"<<"["<<y<<"]"<<" = "<< img.pixelColor(x,y).red();
        }
        cout<<endl;

    }






    return 0;
}
