
int xnm1 = 1;
int xn = 2;
int xnp1 = 0;
float pi = 3.1416;
int n = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("n");
  Serial.print("\t");
  Serial.println("x_n");
}

void loop() {
  // put your main code here, to run repeatedly:
  while (n<13){
    xnp1 = 2*pi*sin(2*pi*xn)+2*xn-xnm1;
    Serial.print(n);
    Serial.print("\t");
    Serial.println(xnp1);
    xnm1 = xn;
    xn = xnp1;
    n = n+1;
  }
}
