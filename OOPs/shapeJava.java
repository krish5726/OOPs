import java.util.*;
class ell{
    class ellipse{
        private float major;
        private float minor;
        public ellipse(float ma, float mi){
            this.major = ma;
            this.minor = mi;
        }
        public String area(){
            float pi = (float)Math.PI;
            return String.format("%.2f",(this.major * this.minor * pi));
        }
        public String peri(){
            float pi = (float)Math.PI;
            float a = this.major * this.major;
            float b = this.minor * this.minor;
            float c = (float)Math.sqrt((a + b)/2);
            return String.format("%.2f",c * 2 * pi);
        }
    }

    class circle extends ellipse{
        public circle(float dia){
            super(dia, dia);
        }

    }

    interface Drawable{
        public void draw();
    }
    class drawableCircle extends circle implements Drawable{
        public drawableCircle(float dia){
            super(dia);
        }
        public void draw(){
            System.out.println("Draw Circle");
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        float ma = sc.nextFloat();
        float mi = sc.nextFloat();
        ell x = new ell();
        ellipse e = x.new ellipse(ma, mi);
        circle c = x.new circle(ma);
        for(int i = 0; i<4; i++){
            String s = sc.next();
            if(s.compareTo("AREA_ELLIPSE") == 0){
                System.out.println(e.area());
            }
            else if(s.compareTo("PERIMETER_ELLIPSE") == 0){
                System.out.println(e.peri());
            }
            else if(s.compareTo("AREA_CIRCLE") == 0){
                System.out.println(c.area());
            }
            else if(s.compareTo("PERIMETER_CIRCLE") == 0){
                System.out.println(c.peri());
            }
        }
    }
}