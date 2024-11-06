#include<bits/stdc++.h>
using namespace std;
    class ellipse{
        private:
        float major;
        float minor;
        public:
        ellipse(float ma, float mi){
            this->major = ma;
            this->minor = mi;
        }
        void area(){
            float pi = M_PI;
            cout << fixed << setprecision(2) << this->major * this->minor * pi << endl;
        }
        void peri(){
            float pi = M_PI;
            float a = this->major * this->major;
            float b = this->minor * this->minor;
            float c = sqrt((a + b)/2);
            cout << fixed << setprecision(2) << c * 2 * pi << endl;
        }
    };

    class circle: public ellipse{
        public:
        circle(float dia) : ellipse(dia, dia){
        }
    };

    class Drawable{
        public:
        virtual void draw();
    };

    class drawableCircle: public circle, Drawable{
        drawableCircle(float dia) : circle(dia){
        }
        void draw(){
            cout << "Draw Circle" << endl;
        }
    };


    int main() {
        float ma, mi;
        cin >> ma;
        cin >> mi;
        ellipse e = ellipse(ma, mi);
        circle c = circle(ma);
        for(int i = 0; i<4; i++){
            string s;
            cin >> s;
            if(s == "AREA_ELLIPSE"){
                e.area();
            }
            else if(s == "PERIMETER_ELLIPSE"){
                e.peri();
            }
            else if(s == "AREA_CIRCLE"){
                c.area();
            }
            else if(s == "PERIMETER_CIRCLE"){
                c.peri();
            }
        }
    }