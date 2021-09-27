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

    //dimensiones de prueba (Xn, Yn)
    int Xn = new_sizeimgX-3085;
    int Yn = new_sizeimgY-3085;

    for (int y = 0; y<Yn ; ++y){
        for(int x = 0; x<Xn ; ++x){
            //cout<<" "<<"["<<x<<"]"<<"["<<y<<"]"<<" = "<< img.pixelColor(x,y).red();
            cout<<" "<<"["<<x<<"]"<<"["<<y<<"]";

        }
        cout<<endl;

    }
    cout<<endl<<endl;

    int a=0, b=0, heigth=2, whith =2,copheigth=0, copwhith =0;

    for (int y = 0; y<Yn ; ++y){
        for(int x = 0; x<Xn ; ++x){
            while(copheigth<heigth){
                while(copwhith<whith){
                    cout<<" "<<"["<<copwhith<<"]"<<"["<<copheigth<<"]";
                    copwhith++;

                }
               copheigth++;
            }
            cout<<endl;

        }
        copwhith= whith;
        copheigth=heigth;
        heigth+=heigth;
        whith+=whith;
        cout<<endl;

    }




    return 0;
}
