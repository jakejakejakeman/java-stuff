#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cstdlib>
using namespace std;

struct Header
{
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
};
struct Pixel
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
    Pixel(unsigned char a, unsigned char b, unsigned char c)
    {
        blue=a;
        green=b;
        red=c;
    }

};



int main()
{
    /*cout << "1. car.tga" << endl;
    cout << "2. circles.tga" <<endl;
    cout << "3. layer_blue.tga" <<endl;
    cout << "4. layer_green.tga" << endl;
    cout << "5. layer_red.tga" <<endl;
    cout << "6. layer1.tga" <<endl;
    cout << "7. layer2.tga" << endl;
    cout << "8. pattern1.tga" <<endl;
    cout << "9. pattern2.tga" <<endl;
    cout << "10. text.tga" << endl;
    cout << "11. text2.tga" <<endl;
    cout << "Which file(s) to open first?\n";*/
    for (int j=1; j<12; j++)
    {
        vector <Pixel> fi1;
        vector <Pixel> fi2;
        vector <Pixel> fi3;
        vector <Pixel> fi4;
        vector <Pixel> fi5;
        vector <Pixel> fi6;
        vector <Pixel> fi7;
        vector <Pixel> fi8;
        vector <Pixel> fi9;
        vector <Pixel> fi10;
        vector <Pixel> fi11;
        vector <Pixel> fi12;
        vector <Pixel> fi13;
        vector <Pixel> fi14;
        vector <Pixel> fi15;
        Header headerObject, headerObject2, headerObject3, headerObject4;
        int count, count2=0, temp1, temp2, temp3, temp4;
        ifstream file;
        if (j==1)
            file.open("input/layer1.tga", ios_base::binary);
        else if (j==2)
            file.open("input/layer2.tga", ios_base::binary);
        else if (j==3)
            file.open("input/layer1.tga", ios_base::binary);
        else if (j==4)
            file.open("input/layer2.tga", ios_base::binary);
        else if (j==5)
            file.open("input/layer1.tga", ios_base::binary);
        else if (j==6)
            file.open("input/car.tga", ios_base::binary);
        else if (j==7)
            file.open("input/car.tga", ios_base::binary);
        else if (j==8)
            file.open("input/car.tga", ios_base::binary);
        else if (j==9)
            file.open("input/layer_blue.tga", ios_base::binary);
        else if (j==10)
            file.open("input/text2.tga", ios_base::binary);
        else
            file.open("input/text.tga", ios_base::binary);
        if (file.is_open())
        {
            file.read (&headerObject.idLength, sizeof(headerObject.idLength) );
            file.read (&headerObject.colorMapType, sizeof(headerObject.colorMapType) );
            file.read (&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode) );
            file.read ((char*)&headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin) );
            file.read ((char*)&headerObject.colorMapLength, sizeof(headerObject.colorMapLength) );
            file.read (&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth) );
            file.read ((char*)&headerObject.xOrigin, sizeof(headerObject.xOrigin) );
            file.read ((char*)&headerObject.yOrigin, sizeof(headerObject.yOrigin) );
            file.read ((char*)&headerObject.width, sizeof(headerObject.width) );
            file.read ((char*)&headerObject.height, sizeof(headerObject.height) );
            file.read (&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel) );
            file.read (&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor) );
            count=headerObject.width*headerObject.height;
            for (int i=0; i<count; i++)
            {
                unsigned char blu, gree, re;
                file.read ((char*)&blu, 1);
                file.read ((char*)&gree, 1);
                file.read ((char*)&re, 1);
                fi1.push_back(Pixel (blu, gree, re));
                if (j==6) {
                    if ((int) fi1[i].green < 55)
                        temp2 = (int) fi1[i].green + 200;
                    else
                        temp2 = 255;
                    fi9.push_back(Pixel(blu, temp2, re));
                }
                if (j==7) {
                    if ((int) fi1[i].red < 64)
                        temp3 = fi1[i].red * 4;
                    else
                        temp3 = 255;
                    fi10.push_back(Pixel(0, gree, temp3));
                }
                if (j==8) {
                    fi11.push_back(Pixel(blu, blu, blu));
                    fi12.push_back(Pixel(gree, gree, gree));
                    fi13.push_back(Pixel(re, re, re));
                }
            }
        }
        file.close();
        ifstream file2;
        if (j==1)
            file2.open("input/pattern1.tga", ios_base::binary);
        else if (j==2)
            file2.open("input/car.tga", ios_base::binary);
        else if (j==3)
            file2.open("input/pattern2.tga", ios_base::binary);
        else if (j==4)
            file2.open("input/circles.tga", ios_base::binary);
        else if (j==5)
            file2.open("input/pattern1.tga", ios_base::binary);
        else if (j==6){}
        else if (j==7){}
        else if (j==8){}
        else if (j==9)
            file2.open("input/layer_green.tga", ios_base::binary);
        else if (j==10){}
        else
            file2.open("input/pattern1.tga", ios_base::binary);
        if (file2.is_open())
        {
            file2.read (&headerObject2.idLength, sizeof(headerObject2.idLength) );
            file2.read (&headerObject2.colorMapType, sizeof(headerObject2.colorMapType) );
            file2.read (&headerObject2.dataTypeCode, sizeof(headerObject2.dataTypeCode) );
            file2.read ((char*)&headerObject2.colorMapOrigin, sizeof(headerObject2.colorMapOrigin) );
            file2.read ((char*)&headerObject2.colorMapLength, sizeof(headerObject2.colorMapLength) );
            file2.read (&headerObject2.colorMapDepth, sizeof(headerObject2.colorMapDepth) );
            file2.read ((char*)&headerObject2.xOrigin, sizeof(headerObject2.xOrigin) );
            file2.read ((char*)&headerObject2.yOrigin, sizeof(headerObject2.yOrigin) );
            file2.read ((char*)&headerObject2.width, sizeof(headerObject2.width) );
            file2.read ((char*)&headerObject2.height, sizeof(headerObject2.height) );
            file2.read (&headerObject2.bitsPerPixel, sizeof(headerObject2.bitsPerPixel) );
            file2.read (&headerObject2.imageDescriptor, sizeof(headerObject2.imageDescriptor) );
            for (int i=0; i<count; i++)
            {
                unsigned char blu, gree, re;
                file2.read ((char*)&blu, 1);
                file2.read ((char*)&gree, 1);
                file2.read ((char*)&re, 1);
                fi2.push_back(Pixel(blu, gree, re));
                temp1=(int)(((float)fi1[i].blue*(float)fi2[i].blue/255)+0.5);
                temp2=(int)(((float)fi1[i].green*(float)fi2[i].green/255)+0.5);
                temp3=(int)(((float)fi1[i].red*(float)fi2[i].red/255)+0.5);
                fi3.push_back(Pixel (temp1, temp2, temp3));
                if (j==2) {
                    temp1 = (int) fi2[i].blue - (int) fi1[i].blue;
                    temp2 = (int) fi2[i].green - (int) fi1[i].green;
                    temp3 = (int) fi2[i].red - (int) fi1[i].red;
                    if (temp1 < 0)
                        temp1 = 0;
                    if (temp2 < 0)
                        temp2 = 0;
                    if (temp3 < 0)
                        temp3 = 0;
                    fi4.push_back(Pixel(temp1, temp2, temp3));
                }
                if (j==5) {
                    if (((float) (fi2[i].blue) / 255) > 0.5)
                        temp1 = (int) ((
                                (1 - (1 - (float) fi1[i].blue / 255) * (1 - (float) fi2[i].blue / 255) * 2) * 255 +
                                0.5));
                    else
                        temp1 = (int) ((2 * (float) fi1[i].blue * (float) fi2[i].blue / 255) + 0.5);
                    if (((float) (fi2[i].green) / 255) > 0.5)
                        temp2 = (int) ((
                                (1 - (1 - (float) fi1[i].green / 255) * (1 - (float) fi2[i].green / 255) * 2) * 255 +
                                0.5));
                    else
                        temp2 = (int) ((2 * (float) fi1[i].green * (float) fi2[i].green / 255) + 0.5);
                    if (((float) (fi2[i].red) / 255) > 0.5)
                        temp3 = (int) ((
                                (1 - (1 - (float) fi1[i].red / 255) * (1 - (float) fi2[i].red / 255) * 2) * 255 + 0.5));
                    else
                        temp3 = (int) ((2 * (float) fi1[i].red * (float) fi2[i].red / 255) + 0.5);
                    fi8.push_back(Pixel(temp1,temp2,temp3));
                }
            }
        }
        file2.close();
        ifstream file3;
        if (j==1){}
        else if (j==2){}
        else if (j==3)
            file3.open("input/text.tga", ios_base::binary);
        else if (j==4)
            file3.open("input/pattern2.tga", ios_base::binary);
        else if (j==5){}
        else if (j==6){}
        else if (j==7){}
        else if (j==8){}
        else if (j==9)
            file3.open("input/layer_red.tga", ios_base::binary);
        else if (j==10){}
        else
            file3.open("input/car.tga", ios_base::binary);
        if (file3.is_open())
        {
            file3.read (&headerObject3.idLength, sizeof(headerObject3.idLength) );
            file3.read (&headerObject3.colorMapType, sizeof(headerObject3.colorMapType) );
            file3.read (&headerObject3.dataTypeCode, sizeof(headerObject3.dataTypeCode) );
            file3.read ((char*)&headerObject3.colorMapOrigin, sizeof(headerObject3.colorMapOrigin) );
            file3.read ((char*)&headerObject3.colorMapLength, sizeof(headerObject3.colorMapLength) );
            file3.read (&headerObject3.colorMapDepth, sizeof(headerObject3.colorMapDepth) );
            file3.read ((char*)&headerObject3.xOrigin, sizeof(headerObject3.xOrigin) );
            file3.read ((char*)&headerObject3.yOrigin, sizeof(headerObject3.yOrigin) );
            file3.read ((char*)&headerObject3.width, sizeof(headerObject3.width) );
            file3.read ((char*)&headerObject3.height, sizeof(headerObject3.height) );
            file3.read (&headerObject3.bitsPerPixel, sizeof(headerObject3.bitsPerPixel) );
            file3.read (&headerObject3.imageDescriptor, sizeof(headerObject3.imageDescriptor) );
            for (int i=0; i<count; i++)
            {
                unsigned char blu, gree, re;
                file3.read ((char*)&blu, 1);
                file3.read ((char*)&gree, 1);
                file3.read ((char*)&re, 1);
                fi5.push_back(Pixel (blu, gree, re));
                if (j==3) {
                    temp1 = (int) (((1 - (1 - (float) fi3[i].blue / 255) * (1 - (float) fi5[i].blue / 255)) * 255 +
                                    0.5));
                    temp2 = (int) (((1 - (1 - (float) fi3[i].green / 255) * (1 - (float) fi5[i].green / 255)) * 255 +
                                    0.5));
                    temp3 = (int) (((1 - (1 - (float) fi3[i].red / 255) * (1 - (float) fi5[i].red / 255)) * 255 + 0.5));
                    fi6.push_back(Pixel(temp1, temp2, temp3));
                }
                if (j==4) {
                    temp1 = (int) fi3[i].blue - (int) fi5[i].blue;
                    temp2 = (int) fi3[i].green - (int) fi5[i].green;
                    temp3 = (int) fi3[i].red - (int) fi5[i].red;
                    if (temp1 < 0)
                        temp1 = 0;
                    if (temp2 < 0)
                        temp2 = 0;
                    if (temp3 < 0)
                        temp3 = 0;
                    fi7.push_back(Pixel(temp1, temp2, temp3));
                }
                if (j==9)
                    fi14.push_back(Pixel (blu, gree, re));
            }
        }
        file3.close();
        if (j==11) {
            ifstream file7("input/circles.tga", ios_base::binary);
            if (file7.is_open()) {
                file7.read(&headerObject4.idLength, sizeof(headerObject4.idLength));
                file7.read(&headerObject4.colorMapType, sizeof(headerObject4.colorMapType));
                file7.read(&headerObject4.dataTypeCode, sizeof(headerObject4.dataTypeCode));
                file7.read((char *) &headerObject4.colorMapOrigin, sizeof(headerObject4.colorMapOrigin));
                file7.read((char *) &headerObject4.colorMapLength, sizeof(headerObject4.colorMapLength));
                file7.read(&headerObject4.colorMapDepth, sizeof(headerObject4.colorMapDepth));
                file7.read((char *) &headerObject4.xOrigin, sizeof(headerObject4.xOrigin));
                file7.read((char *) &headerObject4.yOrigin, sizeof(headerObject4.yOrigin));
                file7.read((char *) &headerObject4.width, sizeof(headerObject4.width));
                file7.read((char *) &headerObject4.height, sizeof(headerObject4.height));
                file7.read(&headerObject4.bitsPerPixel, sizeof(headerObject4.bitsPerPixel));
                file7.read(&headerObject4.imageDescriptor, sizeof(headerObject4.imageDescriptor));
                for (int i = 0; i < count; i++) {
                    unsigned char blu, gree, re;
                    file7.read((char *) &blu, 1);
                    file7.read((char *) &gree, 1);
                    file7.read((char *) &re, 1);
                    fi15.push_back(Pixel(blu, gree, re));
                }
            }
            file7.close();
        }
        /*cout << "1. Multiply" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply and Screen" << endl;
        cout << "4. Multiply and Subtract" << endl;
        cout << "5. Overlay" << endl;
        cout << "6. Add Green" <<endl;
        cout << "7. Add Red, Kill Blue"<<endl;
        cout << "8. Red, Blue, and Green files"<<endl;
        cout << "9. Combined File"<<endl;*/
        if (j==11) {
            headerObject4.width = headerObject.width * 2;
            headerObject4.height = headerObject.height * 2;
        }
        ofstream file4;
        if (j==1)
            file4.open("output/part1.tga", ios_base::binary);
        else if (j==2)
            file4.open("output/part2.tga", ios_base::binary);
        else if (j==3)
            file4.open("output/part3.tga", ios_base::binary);
        else if (j==4)
            file4.open("output/part4.tga", ios_base::binary);
        else if (j==5)
            file4.open("output/part5.tga", ios_base::binary);
        else if (j==6)
            file4.open("output/part6.tga", ios_base::binary);
        else if (j==7)
            file4.open("output/part7.tga", ios_base::binary);
        else if (j==8)
            file4.open("output/part8_b.tga", ios_base::binary);
        else if (j==9)
            file4.open("output/part9.tga", ios_base::binary);
        else if (j==10)
            file4.open("output/part10.tga", ios_base::binary);
        else
            file4.open("output/extracredit.tga", ios_base::binary);
        if (file4.is_open()) {
            file4.write(&headerObject.idLength, sizeof(headerObject.idLength));
            file4.write(&headerObject.colorMapType, sizeof(headerObject.colorMapType));
            file4.write(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));
            file4.write((char *) &headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
            file4.write((char *) &headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
            file4.write(&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));
            file4.write((char *) &headerObject.xOrigin, sizeof(headerObject.xOrigin));
            file4.write((char *) &headerObject.yOrigin, sizeof(headerObject.yOrigin));
            if (j==11)
            {
                file4.write((char *) &headerObject4.width, sizeof(headerObject4.width));
                file4.write((char *) &headerObject4.height, sizeof(headerObject4.height));
            }
            else{
                file4.write((char *) &headerObject.width, sizeof(headerObject.width));
                file4.write((char *) &headerObject.height, sizeof(headerObject.height));
            }
            file4.write(&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel));
            file4.write(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));
            if (j == 1) {
                for (int i = 0; i < count; i++) {
                    file4.write((char *) &fi3[i].blue, 1);
                    file4.write((char *) &fi3[i].green, 1);
                    file4.write((char *) &fi3[i].red, 1);
                }
            } else if (j == 2) {
                for (int i = 0; i < count; i++) {
                    file4.write((char *) &fi4[i].blue, 1);
                    file4.write((char *) &fi4[i].green, 1);
                    file4.write((char *) &fi4[i].red, 1);
                }
            } else if (j == 3) {
                for (int i = 0; i < count; i++) {
                    file4.write((char *) &fi6[i].blue, 1);
                    file4.write((char *) &fi6[i].green, 1);
                    file4.write((char *) &fi6[i].red, 1);
                }
            } else if (j == 4) {
                for (int i = 0; i < count; i++) {
                    file4.write((char *) &fi7[i].blue, 1);
                    file4.write((char *) &fi7[i].green, 1);
                    file4.write((char *) &fi7[i].red, 1);
                }
            } else if (j == 5) {
                for (int i = 0; i < count; i++) {
                    file4.write((char *) &fi8[i].blue, 1);
                    file4.write((char *) &fi8[i].green, 1);
                    file4.write((char *) &fi8[i].red, 1);
                }
            } else if (j == 6) {
                for (int i = 0; i < count; i++) {
                    file4.write((char *) &fi9[i].blue, 1);
                    file4.write((char *) &fi9[i].green, 1);
                    file4.write((char *) &fi9[i].red, 1);
                }
            } else if (j == 7) {
                for (int i = 0; i < count; i++) {
                    file4.write((char *) &fi10[i].blue, 1);
                    file4.write((char *) &fi10[i].green, 1);
                    file4.write((char *) &fi10[i].red, 1);
                }
            } else if (j == 8) {
                for (int i = 0; i < count; i++) {
                    file4.write((char *) &fi11[i].blue, 1);
                    file4.write((char *) &fi11[i].green, 1);
                    file4.write((char *) &fi11[i].red, 1);
                }
                ofstream file5("output/part8_g.tga", ios_base::binary);
                if (file5.is_open()) {
                    file5.write(&headerObject.idLength, sizeof(headerObject.idLength));
                    file5.write(&headerObject.colorMapType, sizeof(headerObject.colorMapType));
                    file5.write(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));
                    file5.write((char *) &headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
                    file5.write((char *) &headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
                    file5.write(&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));
                    file5.write((char *) &headerObject.xOrigin, sizeof(headerObject.xOrigin));
                    file5.write((char *) &headerObject.yOrigin, sizeof(headerObject.yOrigin));
                    file5.write((char *) &headerObject.width, sizeof(headerObject.width));
                    file5.write((char *) &headerObject.height, sizeof(headerObject.height));
                    file5.write(&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel));
                    file5.write(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));
                    for (int i = 0; i < count; i++) {
                        file5.write((char *) &fi12[i].blue, 1);
                        file5.write((char *) &fi12[i].green, 1);
                        file5.write((char *) &fi12[i].red, 1);
                    }
                }
                file5.close();
                ofstream file6("output/part8_r.tga", ios_base::binary);
                if (file6.is_open()) {
                    file6.write(&headerObject.idLength, sizeof(headerObject.idLength));
                    file6.write(&headerObject.colorMapType, sizeof(headerObject.colorMapType));
                    file6.write(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));
                    file6.write((char *) &headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
                    file6.write((char *) &headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
                    file6.write(&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));
                    file6.write((char *) &headerObject.xOrigin, sizeof(headerObject.xOrigin));
                    file6.write((char *) &headerObject.yOrigin, sizeof(headerObject.yOrigin));
                    file6.write((char *) &headerObject.width, sizeof(headerObject.width));
                    file6.write((char *) &headerObject.height, sizeof(headerObject.height));
                    file6.write(&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel));
                    file6.write(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));
                    for (int i = 0; i < count; i++) {
                        file6.write((char *) &fi13[i].blue, 1);
                        file6.write((char *) &fi13[i].green, 1);
                        file6.write((char *) &fi13[i].red, 1);
                    }
                }
                file6.close();
            } else if (j == 9) {
                for (int i = 0; i < count; i++) {
                    file4.write((char *) &fi1[i].blue, 1);
                    file4.write((char *) &fi2[i].green, 1);
                    file4.write((char *) &fi14[i].red, 1);
                }
            } else if (j==10){
                for (int i = count - 1; i >= 0; i--) {
                    file4.write((char *) &fi1[i].blue, 1);
                    file4.write((char *) &fi1[i].green, 1);
                    file4.write((char *) &fi1[i].red, 1);
                }
            } else{
                for (int k=0; k < headerObject.height; k++) {
                    for (temp4=count2; temp4 < (headerObject.width*(k+1)); temp4++) {
                        file4.write((char *) &fi1[temp4].blue, 1);
                        file4.write((char *) &fi1[temp4].green, 1);
                        file4.write((char *) &fi1[temp4].red, 1);
                    }
                    for (temp4=count2; temp4 < (headerObject.width*(k+1)); temp4++) {
                        file4.write((char *) &fi2[temp4].blue, 1);
                        file4.write((char *) &fi2[temp4].green, 1);
                        file4.write((char *) &fi2[temp4].red, 1);
                    }
                    count2=temp4;
                }
                count2=0;
                for (int k=0; k < headerObject.height; k++) {
                    for (temp4=count2; temp4 < (headerObject.width*(k+1)); temp4++) {
                        file4.write((char *) &fi5[temp4].blue, 1);
                        file4.write((char *) &fi5[temp4].green, 1);
                        file4.write((char *) &fi5[temp4].red, 1);
                    }
                    for (temp4=count2; temp4 < (headerObject.width*(k+1)); temp4++) {
                        file4.write((char *) &fi15[temp4].blue, 1);
                        file4.write((char *) &fi15[temp4].green, 1);
                        file4.write((char *) &fi15[temp4].red, 1);
                    }
                    count2=temp4;
                }
            }
        }
        file4.close();
    }


    return 0;
}