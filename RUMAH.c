#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// listening
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE); // close program on ESC key << fungsi buat ginian
}

void setup_viewport(GLFWwindow* window){
    // ngeset view sama perhitungan berapa di windowsnya..
    // setting viewports size, projection etc
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    //ratio = width / (float) height;
    glViewport(0, 0, width, height);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,750, 300, 0, 1.f, -1.f); //(L,R,B,T,)(depan , belakang) ini dari titik tengah sampai ujung kiri jaraknya 10
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void bulat(double titik,int R,int G,int B,double radius2,double posX,double posY){
    double cons=3.14/titik;// setengah lingkaran, kalo mau full, kali 2 aja consnya
    double px,py;
    double radius1=0; //jari-jari dalam
    int i;
    glColor3ub(R,G,B);
    glBegin(GL_TRIANGLE_STRIP);

        for(i=-100;i<=100;i++) // maenin batesan loopingnya buat rotate, coba aja :)
        {
            px=sin(i*cons)*radius1+posX;
            py=cos(i*cons)*radius1+posY;
            glVertex2f(px*10,py*10);
            px=sin(i*cons)*radius2+posX;
            py=cos(i*cons)*radius2+posY;
            glVertex2f(px*10,py*10);
        }

    glEnd();
}
void rumah(){
    glBegin(GL_QUADS);
    glColor3ub(0,104,56);
        glVertex2f(314.28,189.72);
        glVertex2f(319.52,195.08);
        glVertex2f(374.93,138.38);
        glVertex2f(374.93,127.65);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,104,56);
        glVertex2f(430.33,195.08);
        glVertex2f(435.57,189.72);
        glVertex2f(374.93,127.65);
        glVertex2f(374.93,138.38);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(254,229,122);
        glVertex2f(335.92,222.04);
        glVertex2f(335.85,178.38);
        glVertex2f(374.93,138.38);
        glVertex2f(414.01,178.38);
        glVertex2f(413.93,222.04);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(254,229,122);
        glVertex2f(336.27,167.21);
        glVertex2f(348.27,154.93);
        glVertex2f(348.27,140.37);
        glVertex2f(335,140.37);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,104,56);
        glVertex2f(331.67,140.37);
        glVertex2f(351.08,140.37);
        glVertex2f(351.08,136.57);
        glVertex2f(331.67,136.57);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,104,56);
        glVertex2f(346.68,222.04);
        glVertex2f(365.26,222.04);
        glVertex2f(365.26,187.27);
        glVertex2f(346.68,187.27);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,104,56);
        glVertex2f(375.74,206.49);
        glVertex2f(403.32,206.49);
        glVertex2f(403.32,187.27);
        glVertex2f(375.74,187.27);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(155,220,247);
        glVertex2f(377.68,189.07);
        glVertex2f(401.38,189.07);
        glVertex2f(401.38,204.69);
        glVertex2f(377.68,204.69);
    glEnd();
}
void tanah(){
    glBegin(GL_QUADS);
    glColor3ub(146,195,62);
    glVertex2f(0,222.04);
    glVertex2f(0,300);
    glVertex2f(750,300);
    glVertex2f(750,222.04);
    glEnd();
}
void background(){

    glBegin(GL_POLYGON);
        glColor3ub(192,239,231);
        glVertex2f(0.0,0.0);
        glVertex2f(750.0,0.0);
        glVertex2f(750.0,300.0);
        glVertex2f(0.0,300.0);
    glEnd();
}
void awan(){
    bulat(100,255,255,255,1.22,14.464,7.66);
    bulat(100,255,255,255,1.22,15.759,8.518);
    bulat(100,255,255,255,1.22,12.904,8.502);
    bulat(100,255,255,255,0.854,11.275,8.793);
    glBegin(GL_POLYGON);
        glVertex2f(94.03,97.31);
        glVertex2f(188.31,97.31);
        glVertex2f(167.86,85.18);
        glVertex2f(104.21,88.93);
    glEnd();
}
void batang(){
    glColor3ub(96,50,35);
    glBegin(GL_POLYGON);
        glVertex2f(48.3,219.37);
        glVertex2f(62.58,219.37);
        glVertex2f(64.96,300);
        glVertex2f(45.92,300);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(681.98,137.23);
        glVertex2f(686.1,137.23);
        glVertex2f(690.63,300);
        glVertex2f(677.46,300);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(563.47,222.04);
        glVertex2f(567.9,222.043);
        glVertex2f(566.37,157.73);
        glVertex2f(564.99,157.73);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(161.85,222.04);
        glVertex2f(174.22,222.043);
        glVertex2f(172.68,166.06);
        glVertex2f(163.39,166.06);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(459.67,222.04);
        glVertex2f(472.81,222.043);
        glVertex2f(471.17,191.69);
        glVertex2f(461.31,191.69);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(274.27,222.04);
        glVertex2f(283.11,222.043);
        glVertex2f(279.86,116.69);
        glVertex2f(277.2,126.69);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(279.65,150.06);
        glVertex2f(291,143.5);
        glVertex2f(291.75,144.55);
        glVertex2f(280.33,152.83);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(259.87,157.75);
        glVertex2f(277.45,168.64);
        glVertex2f(277.45,175.87);
        glVertex2f(257.38,162.65);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(294.73,169.36);
        glVertex2f(295.48,171.42);
        glVertex2f(279.53,188.69);
        glVertex2f(279.2,181.69);
    glEnd();

}
void pagar(){
    glBegin(GL_QUADS);
    glColor3ub(211,146,42);
        glVertex2f(245.49,207.82);
        glVertex2f(245.49,211.52);
        glVertex2f(324.6,211.52);
        glVertex2f(324.6,207.82);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(245.49,214.94);
        glVertex2f(245.49,218.64);
        glVertex2f(324.6,218.64);
        glVertex2f(324.6,214.94);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(244,174,47);
        glVertex2f(250.19,202.29);
        glVertex2f(252.12,204.25);
        glVertex2f(252.12,222.04);
        glVertex2f(248.26,222.04);
        glVertex2f(248.26,204.25);
    glEnd();
    int i;
    for(i=1;i<=6;i++){
        glPushMatrix();
            glTranslatef(11.61*i,0,0);
            glBegin(GL_POLYGON);
            glColor3ub(244,174,47);
                glVertex2f(250.19,202.29);
                glVertex2f(252.12,204.25);
                glVertex2f(252.12,222.04);
                glVertex2f(248.26,222.04);
                glVertex2f(248.26,204.25);
            glEnd();
        glPopMatrix();
    }
}
void display()  {
    glClear(GL_COLOR_BUFFER_BIT);
    background();
    tanah();
    rumah();


    //matahari
    bulat(100,255,202,11,2.0,37.5,6.612);
    bulat(100,255,202,11,2.9,37.5,6.612);
    bulat(100,255,202,11,3.8,37.5,6.612);
    bulat(100,255,202,11,4.8,37.5,6.612);

    batang();


    //pohon1
    bulat(100,0,104,56,1.38,25.738,14.893);
    bulat(100,146,195,62,1.0,30.691,15.231);
    bulat(100,60,162,72,0.68,29.584,17.587);
    bulat(100,60,162,72,0.68,25.349,17.876);
    bulat(100,0,104,56,1.50,30.099,16.226);
    bulat(100,0,104,56,1.38,26.404,18.889);
    bulat(100,146,195,62,1.0,26.404,11.936);
    bulat(100,108,177,68,1.2,28.312,11.576);
    bulat(100,60,162,72,0.8,29.584,13.963);

    //pohon2
    bulat(100,146,195,62,1.0,47.438,11.75);
    bulat(100,146,195,62,1.6,45.559,14.891);
    bulat(100,146,195,62,1.2,45.79,19.818);

    bulat(100,5,147,71,1.4,46.566,10.959);
    bulat(100,5,147,71,2.26,46.631,13.603);
    bulat(100,5,147,71,3.35,46.605,17.35);
    bulat(100,146,195,62,1.24,46.624,14.224);
    bulat(100,108,177,68,1.74,46.45,16.287);
    bulat(100,108,177,68,1.557,47.439,18.068);
    bulat(100,146,195,62,1.029,48.207,19.555);

    //pohon3
    glPushMatrix();
        glScalef(1.35,1.35,1);
        glTranslatef(-420.159,1.164,1);
            bulat(100,146,195,62,1.0,47.438,11.75);
            bulat(100,146,195,62,1.6,45.559,14.891);
            //bulat(100,146,195,62,1.2,45.79,19.818);

            bulat(100,5,147,71,1.4,46.566,10.959);
            bulat(100,5,147,71,2.26,46.631,13.603);
            bulat(100,5,147,71,3.35,46.605,17.35);
            bulat(100,146,195,62,1.24,46.624,14.224);
            bulat(100,108,177,68,1.74,46.45,16.287);
            bulat(100,108,177,68,1.557,47.439,18.068);
        bulat(100,146,195,62,1.029,48.207,19.555);
    glPopMatrix();

    //pohon4
    bulat(100,0,104,56,2.5,65.511,17.474);
    bulat(100,5,147,71,5.1,68.609,19.785);
    bulat(100,5,147,71,1.7,73.085,18.548);
    bulat(100,0,104,56,3.4,69.683,16.511);
    bulat(100,0,104,56,2.7,64.696,20.659);
    bulat(100,0,104,56,2.06,71.311,22.769);
    bulat(100,108,177,68,2.4,70.448,20.655);
    bulat(100,108,177,68,1.2,67.4,19.785);
    bulat(100,60,162,72,1.6,66.711,21.862);
    bulat(100,0,104,56,1.423,73.162,20.54);

    //pohon6
    glPushMatrix();
        glScalef(0.6,0.6,1);
        glTranslatef(-410.159,70.164,1);
            bulat(100,0,104,56,2.5,65.511,17.474);
            bulat(100,5,147,71,5.1,68.609,19.785);
            bulat(100,5,147,71,1.7,73.085,18.548);
            bulat(100,0,104,56,3.4,69.683,16.511);
            bulat(100,0,104,56,2.7,64.696,20.659);
            bulat(100,0,104,56,2.06,71.311,22.769);
            bulat(100,108,177,68,2.4,70.448,20.655);
            bulat(100,108,177,68,1.2,67.4,19.785);
            bulat(100,60,162,72,1.6,66.711,21.862);
            bulat(100,0,104,56,1.423,73.162,20.54);
            bulat(100,146,195,62,1.029,48.207,19.555);
    glPopMatrix();


    //pohon7
    glBegin(GL_TRIANGLES);
        glColor3ub(0,104,56);
        glVertex2f(565.36,187.3);
        glVertex2f(577.93,210.05);
        glVertex2f(552.93,210.05);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(5,147,71);
        glVertex2f(565.36,174.12);
        glVertex2f(577.93,193.31);
        glVertex2f(552.93,193.31);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(108,177,68);
        glVertex2f(565.36,162.82);
        glVertex2f(577.93,179.22);
        glVertex2f(552.93,179.22);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(146,195,62);
        glVertex2f(565.36,153.26);
        glVertex2f(577.93,167.22);
        glVertex2f(552.93,167.22);
    glEnd();

    //semak1
    bulat(50,108,177,68,2.242,11.14,30.0);
    bulat(50,108,177,68,0.98,13.138,30.0);
    bulat(50,0,104,56,1.3,9.26,30.0);
    bulat(50,0,104,56,0.95,10.567,30.0);

    glPushMatrix();
        //glScalef(0.6,0.6,1);
        glTranslatef(450.159,1,1);
            bulat(50,108,177,68,2.242,11.14,30.0);
            bulat(50,108,177,68,0.98,13.138,30.0);
            bulat(50,0,104,56,1.3,9.26,30.0);
            bulat(50,0,104,56,0.95,10.567,30.0);
    glPopMatrix();

    awan();
    glPushMatrix();
        glScalef(0.6,0.6,1);
        glTranslatef(10,10,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.6,0.6,1);
        glTranslatef(40,40,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.6,0.6,1);
        glTranslatef(800,40,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.7,0.7,1);
        glTranslatef(800,40,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.8,0.8,1);
        glTranslatef(800,40,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.7,0.7,1);
        glTranslatef(600,40,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.6,0.6,1);
        glTranslatef(900,40,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.5,0.5,1);
        glTranslatef(700,40,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.8,0.8,1);
        glTranslatef(650,30,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.8,0.8,1);
        glTranslatef(640,30,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.8,0.8,1);
        glTranslatef(150,10,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.8,0.8,1);
        glTranslatef(200,10,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.8,0.8,1);
        glTranslatef(350,10,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.8,0.8,1);
        glTranslatef(5,10,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.8,0.8,1);
        glTranslatef(7,5,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.9,0.9,1);
        glTranslatef(10,10,1);
            awan();
    glPopMatrix();
    glPushMatrix();
        glScalef(0.5,0.5,1);
        glTranslatef(0,100,1);
            awan();
    glPopMatrix();
     glPushMatrix();
        glScalef(0.5,0.5,1);
        glTranslatef(270,100,1);
            awan();
    glPopMatrix();

    pagar();

    glPushMatrix();
        glTranslatef(179.9,0,0);
            pagar();
    glPopMatrix();

glFlush();
}

int main(void)
{
    GLFWwindow* window;
    if (!glfwInit()) exit(EXIT_FAILURE);

    window = glfwCreateWindow(750,300, "RUMAH", NULL, NULL); // size pixel Grid=nama jendelanya,

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glEnable(GL_POINT_SMOOTH);

    while (!glfwWindowShouldClose(window)) // sesuatu yang ditampilkan. // per frame
    {
        setup_viewport(window);

        display();

        glfwSwapBuffers(window);
        glfwPollEvents();



    }
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}
