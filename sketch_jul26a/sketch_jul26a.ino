float xnm1 = 1;
float xn = 2;
float xnp1;
float pi = 3.1416;
int i =3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  xnp1 = 2.0*xn*sin(2*pi*xn) + 2*xn - xnm1;
  Serial.print(i);
  Serial.print("\t");
  Serial.println(xnp1);
  i = ++i;
  xnm1 = xn;
  xn = xnp1;
}
